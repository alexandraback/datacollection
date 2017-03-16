#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>
#include <queue>

#include <pthread.h>
using namespace std;

struct Chest
{
    int id;
    short open_type;
    multiset<short> inner_keys;
    bool operator< (const Chest & rhs) const
    {
        return id < rhs.id;
    }
};

bool recurse(multiset<short> &keys, map<short, short> &chests_opened,
             set<short> &chests_remaining,
             set<pair<multiset<short>, set<short> > > &bt,
             const vector<Chest> &chests, map<short,
             vector<Chest> > &chests_by_open_type,
             int open_iter)
{
    if(chests_opened.size() == chests.size())
    {
        return true;
    }
    if(bt.count(make_pair(keys, chests_remaining)))
    {
        return false;
    }
    vector<Chest> chests_to_try;
    for(multiset<short>::iterator it = keys.begin(); it != keys.end(); it = keys.upper_bound(*it))
    {
        vector<Chest> &ot_chests = chests_by_open_type[*it];
        copy(ot_chests.begin(),
             ot_chests.end(),
             back_insert_iterator<vector<Chest> >(chests_to_try));
    }
    sort(chests_to_try.begin(), chests_to_try.end());
    for(vector<Chest>::iterator it = chests_to_try.begin(); it != chests_to_try.end(); ++it)
    {
        if(chests_opened.count(it->id))
            continue;
        
        pair<map<short, short>::iterator, bool> cor = chests_opened.insert(make_pair(it->id, open_iter));
        chests_remaining.erase(it->id);
        
        multiset<short> avail_keys(keys.begin(), keys.end());
        avail_keys.erase(avail_keys.find(it->open_type));
        avail_keys.insert(it->inner_keys.begin(), it->inner_keys.end());
        if(recurse(avail_keys, chests_opened, chests_remaining, bt, chests, chests_by_open_type, open_iter + 1))
        {
            return true;
        }
        
        chests_remaining.insert(it->id);
        chests_opened.erase(cor.first);
        
        bt.insert(make_pair(keys, chests_remaining));
    }
    return false;
}

struct testcase_data {
    int t;
    
    multiset<short> keys;
    vector<Chest> chests;
    map<short, vector<Chest> > chests_by_open_type;
    set<short> remaining;
};

pthread_mutex_t testcase_data_mutex = PTHREAD_MUTEX_INITIALIZER;
queue<testcase_data> testcase_queue;

pthread_mutex_t results_mutex = PTHREAD_MUTEX_INITIALIZER;
map<int, vector<short> > results;

void testcase(int t)
{
    testcase_data data;
    data.t = t;
    
    int K, N;
    cin >> K >> N;
    
    for(int k = 0; k < K; ++k)
    {
        int key_type;
        cin >> key_type;
        data.keys.insert(key_type);
    }
    
    for(int n = 0; n < N; ++n)
    {
        Chest chest;
        chest.id = n + 1;
        cin >> chest.open_type;
        data.remaining.insert(chest.id);
        int K_i;
        cin >> K_i;
        for(int k_i = 0; k_i < K_i; ++k_i)
        {
            int key_type;
            cin >> key_type;
            chest.inner_keys.insert(key_type);
        }
        data.chests.push_back(chest);
        data.chests_by_open_type[chest.open_type].push_back(chest);
    }
    
    testcase_queue.push(data);
}

extern "C" void *thread_func(void *)
{
    for(;;)
    {
        pthread_mutex_lock(&testcase_data_mutex);
        if(testcase_queue.empty())
        {
            pthread_mutex_unlock(&testcase_data_mutex);
            return NULL;
        }
        testcase_data data = testcase_queue.front();
        testcase_queue.pop();
        pthread_mutex_unlock(&testcase_data_mutex);
        
        map<short, short> opened;
        set<pair<multiset<short>, set<short> > > bt;
        
        if(recurse(data.keys, opened, data.remaining, bt, data.chests, data.chests_by_open_type, 0))
        {
            map<short, short> reorder;
            for(map<short, short>::iterator it = opened.begin(); it != opened.end(); ++it)
            {
                reorder.insert(make_pair(it->second, it->first));
            }
            vector<short> myresults;
            for(map<short, short>::iterator it = reorder.begin(); it != reorder.end(); ++it)
            {
                myresults.push_back(it->second);
            }
            pthread_mutex_lock(&results_mutex);
            results.insert(make_pair(data.t, myresults));
            pthread_mutex_unlock(&results_mutex);
        }
    }
}

int main()
{
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t)
    {
        testcase(t + 1);
    }
    vector<pthread_t> threads;
    for(int t = 0; t < 4; ++t)
    {
        pthread_t thread;
        pthread_create(&thread, NULL, thread_func, NULL);
        threads.push_back(thread);
    }
    for(vector<pthread_t>::iterator it = threads.begin(); it != threads.end(); ++it)
    {
        pthread_join(*it, NULL);
    }
    for(int t = 1; t <= T; ++t)
    {
        map<int, vector<short> >::iterator it = results.find(t);
        cout << "Case #" << t << ":";
        if(it == results.end())
        {
            cout << " IMPOSSIBLE" << endl;
        }
        else
        {
            for(vector<short>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
            {
                cout << " " << *jt;
            }
            cout << endl;
        }
    }
}