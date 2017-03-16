#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


// data define

const int maxn=1000+5;

vector<int> v[maxn];
bool vis[maxn];
bool vising[maxn];

bool cr[maxn][maxn];

int n;
bool suc;


void Init()
{
    memset(cr,0,sizeof cr);
    memset(vis,0,sizeof vis);
    memset(vising,0,sizeof vising);    
    for(int i=0;i<=n;++i)v[i].clear();
}

void CR(int from, int cur, int step)
{
    if(!step){
        cr[from][cur]=true;
    }
    if(vising[cur] || vis[cur] )return ;
    
    vising[cur]=true;
    for(int i=0;i<v[cur].size();++i){
        CR(from,v[cur][i],step+1);
    }
    
    vis[cur]=true;
    vising[cur]=false;
}


bool DFS(int from, int tar)
{
    if(vis[from]){
        //suc=true;
        return cr[from][tar]? false : true;
    }
    if(vising[from]){
        return false;    
    }
    
    vising[from]=true;
    
    for(int i=0;i<v[from].size();++i){
        if(DFS( v[from][i], tar))
            return true;
    }

   
    vising[from]=false;
    vis[from]=true;
    
    return false;
}


bool solve()
{
    for(int i=1;i<=n;++i){
        memset(vis,0,sizeof vis);
        memset(vising,0,sizeof vising);  
        CR(i,i,0);
        
        memset(vis,0,sizeof vis);
        memset(vising,0,sizeof vising);  
          
        if ( DFS(i,i) )
            return true;    
    }
    
    return false;
}


int main()
{

//	freopen("a.in","r",stdin);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);

	int testcase;
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		Init();
        scanf("%d",&n);
        
        for(int i=1;i<=n;++i){
            int ct;
            scanf("%d",&ct);
            while(ct--){
                int j;
                scanf("%d",&j);    
                v[i].push_back(j);
            }    
        }

		printf("Case #%d: ",case_id);
        if( solve() )
            puts("Yes");
        else
            puts("No");
               
    }
	return 0;
}
