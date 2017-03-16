//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 2147483647
#define PI 3.1415926535897932384626433832795
#define all(cont) cont.begin(),cont.end()
#define init(a,val) memset(a,val,sizeof(a))
#define F first
#define S second
#define mp make_pair
//GLOBAL
pair<int,int> ch[100];
vector<int> g[100];
int val[100],stac[100];
int n;

bool dfs(int root)
{
    int it,toch,stop,i,len,found,no;
    stac[0]=root;
    toch=1;
    stop=0;
    while(toch<n){

    for(it=stop;it>=0;it--)
    {
        found=0;
        no=stac[it];
        len=g[no].size();
        for(i=0;i<len;i++)if(val[g[no][i]]==ch[toch].F)
        {
            toch++;stop=it+1;stac[stop]=g[no][i];found=1;break;
        }
        if(found)break;
    }
    if(it==-1)return false;
    }
    return true;
}

int main()
{
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    int test_cases,Testno;
    int x,y,m,i;

    cin>>test_cases;
    for(Testno=1;Testno<=test_cases;Testno++)
    {
        printf("Case #%d: ",Testno);
//___________________________________________
        cin>>n>>m;
        for(i=0;i<n;i++)
                cin>>val[i];
        for(i=0;i<m;i++)
        {
            cin>>x>>y;
            g[x-1].push_back(y-1);
            g[y-1].push_back(x-1);
        }
        for(i=0;i<n;i++)ch[i]=mp(val[i],i);;
        sort(ch,ch+n);
        //fir=ch[0].S;
        do
        {
            //init(vis,0);
            if(dfs(ch[0].S))break;

        }while(next_permutation(ch,ch+n));
        for(i=0;i<n;i++)cout<<ch[i].F;

        for(i=0;i<n;i++)g[i].clear();
//___________________________________________
        Done: printf("\n");
    }

return 0;
}
