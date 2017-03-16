#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector<bool> used;
bool charUsed[128];
long long int sol;

void doIt(vector<string>& vs, int index, char lastChar, int level)
{
    vector<char> posUsed;
    for(int i=0; i<(int)vs[index].size(); i++)
    {
        if(lastChar!=vs[index][i])
        {
            charUsed[(int)lastChar]=true;
            posUsed.push_back(lastChar);
            lastChar=vs[index][i];
            if(charUsed[(int)lastChar])
            {
                for(int j=0; j<(int)posUsed.size(); j++)
                {
                    charUsed[(int)posUsed[j]]=false;
                }
                return;
            }
        }
    }
    if(level==(int)vs.size())
    {
        sol=(sol+1LL)%1000000007LL;
        for(int j=0; j<(int)posUsed.size(); j++)
        {
            charUsed[(int)posUsed[j]]=false;
        }
        return;
    }
    used[index]=true;
    for(int i=0; i<(int)vs.size(); i++)
    {
        if(!used[i])
        {
            doIt(vs, i, lastChar, level+1);
        }
    }
    used[index]=false;
    for(int j=0; j<(int)posUsed.size(); j++)
    {
        charUsed[(int)posUsed[j]]=false;
    }
    return;
}

int main(int argc, char* argv[])
{
    (void)argc; (void)argv;
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int t;
    cin >> t;
    for(int caso=1; caso<=t; caso++)
    {
        vector<string> vs;
        int n;
        cin >> n;
        for(int i=0; i<n; i++)
        {
            string temp;
            cin >> temp;
            vs.push_back(temp);
        }
        sol=0;
        memset(charUsed, 0, sizeof(bool)*128);
        used.clear();
        used.resize(vs.size(), false);
        for(int i=0; i<n; i++)
        {
            doIt(vs, i, '\0', 1);
        }
        cout << "Case #" << caso << ": " << sol;
        if(caso!=t)
            cout << endl;
    }
    return 0;
}
