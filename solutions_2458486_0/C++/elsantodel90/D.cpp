#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)

#define forall(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)

#define esta(x,c) ((c).find(x) != (c).end())

int keyCount[64];
int neededKey[64];
vector<int> chestKeys[64];

bool dp[1<<21];
int tK;
map<int,int> _keyMap;

int keyMap(int key)
{
    if (!esta(key,_keyMap))
    {
        keyCount[tK] = 0;
        _keyMap[key] = tK++;
    }
    return _keyMap[key];
}

int main()
{
    int TT; cin >> TT;
    forn(tt,TT)
    {
        tK = 0;
        _keyMap.clear();
        int K,N; cin >> K >> N;
        forn(i,K)
        {
            int k; cin >> k;
            keyCount[keyMap(k)]++;
        }
        forn(i,N)
        {
            cin >> neededKey[i];
            neededKey[i] = keyMap(neededKey[i]);
            chestKeys[i].clear();
            int T; cin >> T;
            forn(j,T)
            {
                int key; cin >> key;
                chestKeys[i].push_back(keyMap(key));
            }
        }
        
        dp[0] = 1;
        forsn(mask,1,1<<N)
        {
            forn(j,N)
            if (!((1<<j) & mask))
            {
                forall(key, chestKeys[j]) keyCount[*key]++;
                keyCount[neededKey[j]]--;
            }
            
            dp[mask] = 0;
                        
            forn(j,N)
            if (((1<<j) & mask) && keyCount[neededKey[j]] > 0)
                dp[mask] |= dp[mask - (1<<j)];
            
            forn(j,N)
            if (!((1<<j) & mask))
            {
                forall(key, chestKeys[j]) keyCount[*key]--;
                keyCount[neededKey[j]]++;
            }
        }
        
        cout << "Case #" << tt+1 << ": ";
        int mask = (1<<N)-1;
        if (dp[mask])
        {
            bool first = true;
            while (mask != 0)
            {
                forn(i,N)
                if (((1<<i) & mask) && keyCount[neededKey[i]] > 0 && dp[mask - (1<<i)])
                {
                    keyCount[neededKey[i]]--;
                    forall(key, chestKeys[i]) keyCount[*key]++;
                    if (first) first = false; else cout << " ";
                    cout << i+1;
                    mask -= (1<<i);
                    break;
                }
            }
        }
        else
        {
            cout << "IMPOSSIBLE";
        }
        cout << endl;
    }
    return 0;
}
