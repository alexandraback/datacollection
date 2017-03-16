#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> ii;
typedef vector<int> vi;

int k,n,curkey,keyToChest[500],insideKey;
vector<vector<int> >keysInside;
int init[500];

void print(int *open,int h)
{
    cout<<open[0];
    for(int i=1;i<h;i++)
    {
        cout<<" "<<open[i];
    }
}

int main()
{
    //freopen("sb6.in","r",stdin);
    //freopen("sb6.out","w",stdout);
    int t,x=0;
    cin>>t;
    while(t--)
    {
        x++;
        cin>>k>>n;
        keysInside.clear();
        keysInside.resize(n+1);
        memset(init,0,sizeof(init));
        for(int i=0;i<k;i++)
        {
            cin>>curkey;
            init[curkey]++;
        }
        for(int i=0;i<n;i++)
        {
            cin>>curkey>>insideKey;
            keyToChest[i+1]=curkey;
            for(int j=0;j<insideKey;j++)
            {
                cin>>curkey;
                keysInside[i+1].pb(curkey);
            }
        }
        //processing ;)
        bool ans=0;
        int open[n*2],h=0;
       for(int i=1;i<=n;i++)
        {
            //if i dont have the keys try another chest
            if(init[keyToChest[i]]==0) continue;
            //selecting this as the first key
            //declaring and initialising done[] and keys[]
            int done[n+1];
            int keys[501];
            for(int j=1;j<=n;j++) done[j]=0;
            for(int j=0;j<=500;j++) keys[j]=init[j];

            keys[keyToChest[i]]--;
            done[i]=1;
            for(int j=0;j<keysInside[i].size();j++) keys[keysInside[i][j]]++;
            h=0;
            open[h]=i;
            h++;
            for(int repeat=1;repeat<=(n+2);repeat++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(done[j]) continue; //already opened chest
                    if(keys[keyToChest[j]]>0)
                    {
                        keys[keyToChest[j]]--;
                        done[j]=1;
                        for(int k=0;k<keysInside[j].size();k++) keys[keysInside[j][k]]++;
                        open[h]=j;
                        h++;
                        break;
                    }
                }
            }
            if(h==n)
            {
                ans=1;
                break;
            }
        }
        if(ans)
        {cout<<"Case #"<<x<<": ";
        print(open,h);
        cout<<"\n";
        }
        else cout<<"Case #"<<x<<": "<<"IMPOSSIBLE\n";
    }
    return 0;
}
