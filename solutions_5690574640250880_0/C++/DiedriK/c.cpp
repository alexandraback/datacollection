#include <bits/stdc++.h>
using namespace std;
#define valid(a,b) ((a)>=0 && (a)<r && (b)>=0 && (b)<c)
char grid[55][55];
int t, r, c, m;

bool dfs(int pi, int pj, int res=0){
	//cout<<"--> "<<pi<<' '<<pj<<endl;
	if(res>m) return false;
	if(res==m){
		//cout<<pi<<' '<<pj<<' '<<res<<endl;
		return true;
	}
	int cnt=0, ps[10][2]={};
	for(int i=pi-1; i<=pi+1; i++){
		for(int j=pj-1; j<=pj+1; j++){
			if(valid(i,j) && grid[i][j]=='*'){
				grid[i][j]='.';
				ps[cnt][0]=i;
				ps[cnt][1]=j;
				cnt++;
				//cout<<"     "<<i<<' '<<j<<' '<<cnt<<endl;
			}
		}
	}
	//cout<<"cnt = "<<cnt<<endl;
	for(int i=0; i<cnt; i++){
		//if(res+cnt<=m)
			if(dfs(ps[i][0], ps[i][1], res+cnt))
				return true;
	}
	for(int i=0; i<cnt; i++){
		grid[ps[i][0]][ps[i][1]]='*';
	}
	return false;
}

int main(){
	
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	
	cin>>t;
	for(int tc=1; tc<=t; tc++){
		cin>>r>>c>>m;
		m=r*c-m;
		//cout<<m<<endl;
		bool sol=false;
		int li=0, lj=0;
		for(int i=0; i<min(r,3) && !sol; i++){
			for(int j=0; j<min(c,3) && !sol; j++){
				//cout<<"caso "<<i<<' '<<j<<endl;
				memset(grid, '*', sizeof grid);
				if(dfs(i, j)){
					sol=true;
					li=i;
					lj=j;
				}
			}
		}
		
		printf("Case #%d:\n", tc);	
		if(sol || m==1){
			grid[li][lj]='c';
			for(int i=0; i<r; i++, printf("\n"))
				for(int j=0; j<c; j++)
					printf("%c", grid[i][j]);
		}else{
			printf("Impossible\n");
		}
	}
	
	return 0;
}
