#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <bitset>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <deque>
#include <ctime>
#define SET(p)      memset(p,-1,sizeof(p))
#define CLR(p)      memset(p,0,sizeof(p))
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define LL long long
#define ULL unsigned long long
#define R freopen("in","r",stdin)
#define W freopen("out","w",stdout)
using namespace std;

int main()
{
    R;W;
    int t;cin>>t;
    int kase=0;
    while(t--)
    {
        kase++;
        printf("Case #%d: ",kase);
        
        
        int v,e;
        cin>>v>>e;
        vi gp[10];
        ii my[10];
        
       
        for(int i=0;i<v;i++)
        {
            int temp;
            cin>>temp;
            my[i]=mp(temp,i);
        }
        int Arr[11][11];
        CLR(Arr);
        sort(my,my+v);
        map<int,int> mm;
        for(int i=0;i<v;i++)
        {
            mm[my[i].S]=i;
        }
        for(int i=0;i<e;i++)
        {
            int a,b;
            cin>>a>>b;
            a--;b--;
            a=mm[a];
            b=mm[b];
            gp[a].pb(b);
            gp[b].pb(a);
            Arr[a][b]=1;
            Arr[b][a]=1;
        }
        vector<int> prr;
        for(int i=0;i<v;i++)prr.pb(i);
        do
        {
            int flag2=1;
            //int st=prr[0];
            int mark[11];
            CLR(mark);
            int pr[11];
            SET(pr);
            for(int i=0;i<v-1;i++)
            {
                int flag=1;
                int st=prr[i];
                int ds=prr[i+1];
                while(1){
                if(Arr[st][ds])
                {
                    pr[ds]=st;
                    break;
                    
                }
                    else
                    {
                        if(pr[st]==-1){flag=0;break;}
                        else st=pr[st];
                        
                    }
                }
                if(flag==0){flag2=0;break;}
                else
                {
                    continue;
                }
                
            }
            if(flag2)
            {
                for(int i=0;i<v;i++)cout<<my[prr[i]].F;
                break;
            }
            
        }
        while(next_permutation(prr.begin(),prr.end()) );
        cout<<endl;
        
        
        
    }
}
