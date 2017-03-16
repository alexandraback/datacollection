#if 01
/*******************************************************************************
* Author       : Aman Taneja
* email        : aman (dot) taneja (dot) 2008 (at) gmail (dot) com
* copyright    : 2014 - 2016
* date         : 04 - 04 - 2016
* Judge Status : 
* Problem Category : 
* file name    : findCycle.cpp
* version      : 1.0
*
* TERMS OF USE - Write a mail to the author before copying or reusing the content of this file 
* seeking our permission for the same.
* Copying/reuse of the below code without the permission of the author is prohibited and illegal.
*
* All rights reserved by Aman Taneja.
******************************************************************************/
/*******************************************************************************
* some pointers on the logic/idea - 
*	
* .............
*******************************************************************************/

#if 01
#include<iostream>
#include <time.h>
using namespace std;


/*	input -
3
3 3
1 2
2 3
3 1
3 2
1 2
1 3
4 3
1 2
2 3
1 4 

output -
Case #1
1
Case #2
0
Case #3
0

*/

#define GEN_TEST_CASES 0
#define PRINT_TIME 01
#define MAT_SIZE 105
typedef pair<int,int> P_II;
#define MKP(a,b) make_pair(a,b)
typedef long long int LLI;

int DX4[]={1,-1,0,0};
int DY4[]={0,0,-1,1};
#define in_bounds(x,y,r,c) (x>=0 && x<r && y>=0 && y<c)

int g[MAT_SIZE][MAT_SIZE];
P_II dfs(int g[MAT_SIZE][MAT_SIZE],int vis[MAT_SIZE],int n,int u,int pred){
	vis[u]=1;

	for(int v=0;v<n;++v){
		if(g[u][v]){
			if(vis[v]){
				if(u==2 && v==9 || u==9 && v==2)
					int d=0;
				return MKP(v,u);
			}
			P_II x=dfs(g,vis,n,v,u);
			if(x.first!=-1 && x.second!=-1)
				return x;
		}
	}
	return MKP(-1,-1);
}

int cntVis(int vis[],int n){
	int c=0;
	for(int i=0;i<n;++i){
		if(vis[i])++c;
	}
	return c;
}

int main(){

#if PRINT_TIME
	clock_t ct = clock();
#endif

#if 01
	FILE *in=freopen("G:\\DUMP\\input.in","r",stdin);
	FILE *out=freopen("G:\\DUMP\\output.out","w",stdout);
#endif

	int t,tc;
	scanf("%d",&t);
	tc=t;
	while(t--){

		int n;
		cin>>n;

		int vis[MAT_SIZE]={0}, a[MAT_SIZE];

		for(int i=0;i<n;++i)for(int j=0;j<n;++j)g[i][j]=0;

		for(int i=0;i<n;++i){
			int u,v;
			scanf("%d",&u);
			a[i]=u;
			if(!u)
				int d=0;
			--u;
			g[i][u]=1;
		}
		int mx=0;
		P_II y;
		
		int indep=0;
		bool dbl=0,fin=0;
		for(int i=0;i<n;++i){
			memset(vis,0,sizeof vis);
			y=dfs(g,vis,n,i,i);
			if(y.first!=-1 && y.second!=-1){
				// either cycle begins at i or cycle terminates at double edge
				if( (1==g[y.first][y.second] && 1==g[y.second][y.first]) || y.first==i ){

					if(1==g[y.first][y.second] && 1==g[y.second][y.first])
						dbl=1;
					else dbl=0;

					int tot=cntVis(vis,n);
					// mutual 
					int extra=0;

					if(1==g[y.first][y.second] && 1==g[y.second][y.first] && tot!=2){
						int v=y.second;
						//if a column of second has 1 - incoming edge, then ++mx
						for(int j=0;j<n;++j){
							if(g[j][v] && !vis[j])
								extra=1;
						}
					}
					if(1==g[y.first][y.second] && 1==g[y.second][y.first] && tot==2){
						// mutual with size 2
							int u=y.first;
							int v=y.second;
							bool f=1;
							for(int j=0;j<n;++j){
								if( (g[j][u] && j!=v) || ((g[j][v] && j!=u)) ){
									f=0;
									break;
								}
							}
							if(f)++indep;

						}

					if(mx<extra+tot){
						mx=extra+tot;
					
						if(dbl)
							fin=1;
						else fin=0;
					}
					//mx=max(mx,extra+tot);
				}
			}
		}
#if 0
		cout<<endl<<endl;
		cout<<n<<endl;
		for(int i=0;i<n;++i){
			cout<<a[i]<<" ";	
		}
		cout<<endl;
#endif
		indep/=2;
		if(fin){
			if(indep>1)mx+=2*(indep-1);
		}else{
			mx=max(mx,indep*2);
		}
		cout<<"Case #"<<tc-t<<": "<<mx<<endl;


	}

#if PRINT_TIME
	ct = clock() - ct;
	// printf("time = %Ld", (double)t/CLOCKS_PER_SEC);
	//cout << "time = " << (double)ct/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}
#endif

#endif