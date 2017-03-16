#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <unordered_set>
#include <stack>

using namespace std;

int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    int T;
    cin >> T;
    int C,D,V;
    vector<int> coins;
    for(int t=0; t<T; t++)
    {
        cin >> C >> D >> V;
        coins.clear();
        int x;
        unordered_set<int> coinsTable;
        stack<int> p;
        for(int i=0; i<D; i++)
        {
            cin >> x;
            coinsTable.insert(x);
            coins.push_back(x);
        }

        int coinsToAdd=0;

        while(V!=0)
        {
            for(int i=coins.size()-1; i>=0; i--)
            {
                if(V<coins[i])
                    continue;
                int mult = min(V/coins[i],C);
                V = max(coins[i]-1,V-mult*coins[i]);
                //cout << V << " ";
                p.push(V);
            }
            //cout << endl;
            if(V==0)
                break;
            else
            {
                bool b = false;
                while(!p.empty())
                {
                    V = p.top();
                    for(int i=C; i>0; i--)
                    {
                        if(coinsTable.count(V/i)==0)
                        {
                            coinsToAdd++;
                            coinsTable.insert(V/i);
                            coins.push_back(V/i);
                            //cout << V/i << endl << endl;
                            sort(coins.begin(),coins.end());
                            b=true;
                            break;
                        }
                    }
                    p.pop();
                    if(b)
                        break;
                }
                if(!b)
                    break;
                V--;
                while(!p.empty())
                    p.pop();
                p.push(V);
            }
        }
        cout << "Case #" << t+1 << ": " << coinsToAdd << endl;
    }

    return 0;
}
