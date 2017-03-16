#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int WORDS = 521196;
const int BYTES = 3844492;
const int MAXN = 50;

char dict[BYTES + WORDS + 1];

vector<string> read_dict()
{
    vector<string> dict(WORDS);
    FILE* pin = fopen("garbled_email_dictionary.txt", "rt");
    for(auto& s : dict)
    {
        char buf[10000];
        fscanf(pin, "%s", buf);
        s = buf;
    }
    
    return dict;
}

int solve(const string& s, const vector<string>& dict)
{
    int n = s.size();
    int resp[MAXN+1][5];
    
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<5;++j)
        {
            resp[i][j] = n;
        }   
    }
    
    for(int j=0;j<5;++j)
    {
        resp[0][j] = 0;
    }
    
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<5;++j)
        {
            for(auto& d : dict)
            {
                if(i+d.size() > n)
                {
                    continue;
                }
                
                int lastchange = i - j - 1;
                int diff = 0;
                for(int k=0;k<d.size();++k)
                {
                    if(d[k] != s[i+k])
                    {
                        if(i+k - lastchange >= 5)
                        {
                            ++diff;
                            lastchange = i+k;
                        }
                        else
                        {
                            diff = n;
                            break;
                        }
                    }
                }
                
                int nj = min(4, static_cast<int>(i+d.size()-1-lastchange));
                resp[i+d.size()][nj] = min(resp[i+d.size()][nj], resp[i][j] + diff);
            }
        }
    }
    
    int ret = n;
    for(int j=0;j<5;++j)
    {
        ret = min(ret, resp[n][j]);
    }
    
    return ret;
}

int main()
{
    auto dict = read_dict();
    int t;
    cin >> t;
    for(int lp=1;lp<=t;++lp)
    {
        string s;
        cin >> s;
        auto resp = solve(s, dict);
        cout << "Case #" << lp << ": " << resp << "\n";
    }
    
    return 0;
}
