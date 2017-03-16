#include<bits/stdc++.h>
using namespace std;

#define scl(x) scanf("%lld",&x)
#define sc(x)  scanf("%d",&x)
#define ll long long
#define lop(i,n) for(int i=0;i<n;++i)
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

int n,t;
vector<vector<int> > vec;
int grid[12][12],idxsebto,isrow,out[12];
bool comp(vector<int> &a,vector<int> &b){
	return a[0]<b[0];
}
bool used[22];
bool solve(int idxcol,int idxvec,int adeto){
	if(2*n-1-idxvec+(!adeto)<n-idxcol)return 0;
	if(idxcol==n){
		bool zabato=adeto;
		int j=0;
		for(int i=1;i<n;++i){
			while(j<2*n-1&&used[j])++j;
			if(j==2*n-1){
				if(adeto)return 0;
				lop(k,n){
					out[k]=grid[i][k];
					if(k&&grid[i][k]<=grid[i][k-1])return 0;
				}
				return 1;
			}
			if(vec[j][0]==grid[i][0]){
				lop(k,n){
					if(adeto&&!isrow&&idxsebto==k){
						grid[i][k]=vec[j][k];
					}
					if(vec[j][k]!=grid[i][k])return 0;
				}
			}
			else {
				if(adeto)return 0;
				adeto=1;
				idxsebto=i;
				isrow=1;
				lop(k,n){
					out[k]=grid[i][k];
					if(k&&out[k]<=out[k-1])return 0;
				}
				--j;
			}
			++j;
		}
		if(zabato){
			lop(k,n)out[k]=grid[k][idxsebto];
		}
		return 1;
	}
	if(idxvec==2*n-1){
		idxsebto=idxcol;
		isrow=0;
		return solve(idxcol+1,idxvec,1);
	}

	if(solve(idxcol,idxvec+1,adeto))return 1;
	if(!adeto){
		idxsebto=idxcol;
		isrow=0;
		if(solve(idxcol+1,idxvec,1))return 1;
	}
	if(grid[0][idxcol]==vec[idxvec][0]){
		used[idxvec]=1;
		lop(i,n)grid[i][idxcol]=vec[idxvec][i];
		if(solve(idxcol+1,idxvec+1,adeto))return 1;
		used[idxvec]=0;
	}
	return 0;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("i.txt","r",stdin);
	freopen("o.txt","w",stdout);
#endif
	sc(t);
	lop(C,t){
		sc(n);
		vec.clear();
		vec.resize(2*n-1);
		memset(used,0,sizeof used);
		lop(i,2*n-1){
			vec[i].clear();
			lop(j,n){
				int v;sc(v);
				vec[i].push_back(v);
			}
		}
		sort(vec.begin(),vec.end(),comp);
		lop(i,n)grid[0][i]=vec[0][i];
		used[0]=1;
		solve(0,1,0);
		printf("Case #%d:",C+1);
		lop(i,n)printf(" %d",out[i]);
		puts("");
	}
}
