
#include <mutex>
#include <vector>
#include <thread>
#include <string>
#include <sstream>
#include <iostream>
#include <csignal>
#include <fstream>
#include <cstring>

using namespace std;

string* output;
unsigned counter = 0;
unsigned total = 0;
mutex lock_input;
vector<string> words;

bool tryword(const string& s, int& index, int& error, const string& word, int& errc)
{
    int ws = word.size();
    for (int i = 0; i < ws; ++i)
    {
        if (s[index+i] != word[i])
        {
            if ((index+i)-error >= 5)
            {
                error = index+i;
                ++errc;
            }
            else
            {
                return false;
            }
        }
    }
    index += ws;
    return true;
}

unsigned solve(int lookup[5000][10], const string& s, int ss, int index, int error)
{
    if (index == ss) return 0;
    if (index > ss) return -1;
    
    int id = index-error-1;
    if (id > 4) id = 5;
    if (lookup[index][id] != 0)
        return lookup[index][id]-2;
    
    unsigned best = -1;
    for (const string& word : words)
    {
        int newindex = index;
        int newerror = error;
        int errc = 0;
        if (tryword(s, newindex, newerror, word, errc))
        {
            unsigned v = solve(lookup, s, ss, newindex, newerror);
            if (v != -1) best = min(best, v+errc);
            if (best == 0) break;
        }
    }
    
    lookup[index][id] = best+2;
    
    return best;
}


void run()
{
    stringstream result;
    while (true)
    {
        unsigned current;
    
        string s;
    
        {
            lock_guard<mutex> lock(lock_input);
            if (counter == total) return;
            current = counter++;
            cin >> s;
        }
        
        int lookup[5000][10];
        memset(lookup, 0, 5000*10*sizeof(int));
        
        int index = 0;
        int error = -10;
        int ss = s.size();
        
        int r = solve(lookup, s, ss, index, error);
    
        result << "Case #" << current+1 << ": ";
        result << r << endl;
    
        output[current] = result.str();
        result.str("");
    }
}

void sigint_handler(int)
{
    for (int i = 0; i < total; ++i)
    {
        if (output[i].empty()) break;
        cout << output[i] << flush;
    }
    
    exit(1);
}

int main()
{
    signal(SIGINT, sigint_handler);
    constexpr unsigned thcount = 2;
    
    ifstream dict("garbled_email_dictionary.txt");
    words.reserve(521196);
    while (dict)
    {
        string word;
        dict >> word;
        if (!word.empty()) words.push_back(word);
    }

    cin >> total;
    output = new string[total];

    vector<thread> threads;
    for (int i = 0; i < thcount; ++i)
        threads.emplace_back(run);
        
    for (thread& th : threads)
        th.join();
    
    for (int i = 0; i < total; ++i)
        cout << output[i];
    
    cout << flush;
}
