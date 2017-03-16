#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <vector>



using namespace std;

const int MAX = 1e5;
const int MOD = 1000000007;
const double EPS = 1e-9;

int T, n;
list<string> a;
int cnt = 0;

long long fact(int n)
{
    long long out = 1;
    for(int i = n; i > 1; --i)
        out = (out * i) % MOD;
    return out;
}

long long rec()
{
    a.clear();
    int end[200], fst[200], all[200], center[200];
    bool f[200];
    
    for(int i = 'a'; i <= 'z'; ++i)
            end[i] = fst[i] = all[i] = center[i] = 0;
        
    bool flag = true;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 'a'; j <= 'z'; ++j)
            f[j] = false;
        string str;
        cin >> str;
        char c = str[0];
        f[c] = true;
        int scnt = 0;
        for(int j = 1; j < str.size(); ++j)
        {
            if(str[j] != c)
            {
                c = str[j];
                if(f[c] == true)
                {
                    flag = false;                    
                }
                f[c] = true;
                ++scnt;
            }
        }
        if(scnt == 0)
        {
            ++all[c];
        }
        else
        {
            for(int j = 'a'; j <= 'z'; ++j)
            {
                if(!f[j])
                    continue;
                if(j == str[0])
                    ++fst[j];
                else if(j == str[str.size() - 1])
                    ++end[j];
                else
                    ++center[j];
            }
        }
        a.push_back(str);
    }
    
    for(int i = 'a'; i <= 'z'; ++i)
    {
        if(!flag || center[i] > 1 || end[i] > 1 || fst[i] > 1 ||
                (center[i] == 1 && (end[i] > 0 || fst[i] > 0 || all[i] > 0)))
            return 0;
    }
    
    for(int i = 'a'; i <= 'z'; ++i)
    {
        string current = "";
        if(end[i] == 1)
        {
            list<string>::iterator it = a.begin();
            for(;it != a.end(); ++it)
            {
                int l = (*it).size() - 1;
                if((*it)[l] == i && (*it)[0] != i)
                {
                    current += (*it);
                    a.erase(it);
                    break;
                }
            }            
        }
        if(all[i] > 0)
        {
            int r = all[i];
            for(int k = r; k > 0; --k)
            {
                list<string>::iterator it = a.begin();
                for(;it != a.end(); ++it)
                {
                    int l = (*it).size() - 1;
                    if((*it)[l] == i && (*it)[l] == (*it)[0])
                    {
                        current += (*it);
                        a.erase(it);
                        break;
                    }
                }
            }
        }
        if(fst[i] > 0)
        {
            list<string>::iterator it = a.begin();
            for(;it != a.end(); ++it)
            {
                if((*it)[0] == i)
                {
                    current += (*it);
                    a.erase(it);
                    break;
                }
            }
        }
        if(current.length() > 0)
            a.push_back(current);
    }
    long long answ = fact(a.size());
    for(int i = 'a'; i <= 'z'; ++i)
    {
        answ = (answ * fact(all[i])) % MOD;
    }
    return answ;
}

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("outpu.txt", "w", stdout);
    cin >> T;
    
    
    
    for(int Ti = 1; Ti <= T; ++Ti)
    {
        cnt = rec();
        
        cout << "Case #" << Ti << ": " << cnt << "\n";
    }

    return 0;
}

