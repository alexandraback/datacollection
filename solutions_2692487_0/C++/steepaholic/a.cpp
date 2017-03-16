#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

map<multiset<int>, int> results;

bool solvable(int A, multiset<int> &motes)
{
    // check solvable (return 0)
    bool yes = true;
    //cerr << "Motes:";
    for(multiset<int>::iterator it = motes.begin(); it != motes.end() && yes; ++it)
    {
        yes = yes && *it < A;
        A += *it;
        //cerr << " " << *it;
    }
    //cerr << endl;
    return yes;
}

int failpoint(int A, multiset<int> &motes)
{
    for(multiset<int>::iterator it = motes.begin(); it != motes.end(); ++it)
    {
        if(*it >= A)
        {
            return A;
        }
        A += *it;
    }
    abort();
    return -1;
}

int recurse(int A, multiset<int> &motes)
{
    if(solvable(A, motes)) return 0;
    map<multiset<int>, int>::iterator prev = results.find(motes);
    if(prev != results.end()) return prev->second;
    
    // try removing largest
    multiset<int>::iterator back = motes.find(*motes.rbegin());
    int val = *back;
    motes.erase(back);
    //cout << "erasing " << back << endl;
    int min_ = recurse(A, motes) + 1;
    motes.insert(val);
    // try adding failpoint
    int failpoint_ = failpoint(A, motes) - 1;
    if(failpoint_ > 0)
    {
        motes.insert(failpoint_);
        min_ = min(min_, recurse(A, motes) + 1);
        motes.erase(motes.find(failpoint_));
    }
    results.insert(make_pair(motes, min_));
    return min_;
}

void testcase(int tst)
{
    int A, N;
    cin >> A >> N;
    multiset<int> motes;
    for(int n = 0; n < N; ++n)
    {
        int n_i;
        cin >> n_i;
        motes.insert(n_i);
    }
    // add or remove
    //sort(motes.begin(), motes.end());
    cout << "Case #" << tst << ": " << recurse(A, motes) << endl;
    results.clear();
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        testcase(t);
    }
    return 0;
}
