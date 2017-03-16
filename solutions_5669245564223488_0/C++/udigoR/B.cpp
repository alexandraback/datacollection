#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const __int64 mod = 1000000007;

#define ADD(x,y) x=(x+y)%mod

void rm(string &cur)
{
    char s = cur[0], f=cur[cur.size()-1];

    while(cur[cur.size()-1]==f)
    {
        cur.erase(cur.size()-1,1);
        if(cur.size() == 0)
            break;
    }
}

bool checkInternal(vector<char> used, string cur)
{
    char s = cur[0], f=cur[cur.size()-1];

    while(cur[0]==s)
    {
        cur.erase(0,1);
        if(cur.size() == 0)
            break;
    }

    //while(cur[cur.size()-1]==f)
    //{
    //    cur.erase(cur.size()-1,1);
    //}

    for(int i=0; i<cur.size(); i++)
        if(find(used.begin(), used.end(), cur[i]) != used.end())
            return false;

    return true;
}

bool checkUsed(vector<char> used, string cur)
{
    for(int i=0; i<cur.size(); i++)
        if(find(used.begin(), used.end(), cur[i]) != used.end())
            return false;

    return true;
}

__int64 solve(string cur, vector<char> used, vector<string> str)
{
    char s = cur[0], f=cur[cur.size()-1];
    __int64 count = 0;

    if(str.size() == 0)
        return 1;

    for(int i=0 ;i<str.size(); i++)
    {
        if(f == str[i][0])
        {
            if(checkInternal(used, str[i]))
            {
                vector<char> _used = used;
                vector<string> _str = str;

                _str.erase(_str.begin() + i);
                string s = str[i];
                rm(s);

                for(int i=0; i<s.size(); i++)
                    if(find(_used.begin(), _used.end(), s[i]) == _used.end())
                    {
                        _used.push_back(s[i]);
                    }

                ADD(count,solve(cur+str[i],_used, _str));
            }
            
        }
    }

    if(count == 0)
    {
        for(int i=0; i<cur.size(); i++)
            if(find(used.begin(), used.end(), cur[i]) == used.end())
            {
                used.push_back(cur[i]);
            }

        bool intern=true;

        for(int i=0 ;i<str.size(); i++)
        {
            if(!checkUsed(used, str[i]))
            {
                intern = false;
                break;
            }
        }

        if(intern)
        {
            for(int i=0 ;i<str.size(); i++)
            {
                vector<string> _str = str;
                _str.erase(_str.begin() + i);

                string s = str[i];
                rm(s);

                used.erase(used.begin(), used.end());

                for(int i=0; i<s.size(); i++)
                    if(find(used.begin(), used.end(), s[i]) == used.end())
                    {
                        used.push_back(s[i]);
                    }

                ADD(count,solve(cur+str[i],used, _str));
            }
            
        }
    }

    return count;
}

void main()
{
    int T = 0;

    ifstream in("B-small-attempt0.in");
    ofstream out("B-small-attempt0.out");

    in >> T;

    for(int i=0; i<T; ++i)
    {
        int N;

        in >> N;

        vector<string> str(N);

        for(int i=0; i<N; i++)
        {
            in >> str[i];
        }

        __int64 count = 0;

        for(int i=0 ;i<str.size(); i++)
        {
            vector<string> _str = str;
            _str.erase(_str.begin() + i);

            string s = str[i];
            rm(s);

            vector<char> used;

            for(int i=0; i<s.size(); i++)
                if(find(used.begin(), used.end(), s[i]) == used.end())
                {
                    used.push_back(s[i]);
                }

            count += solve(str[i], used, _str);
        }

        out << "Case #" << i+1 << ": "<< count;



        out << endl;
    }
}