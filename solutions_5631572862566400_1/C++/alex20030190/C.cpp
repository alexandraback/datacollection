#include <bits/stdc++.h>

#define FI(i,a,b) for(int i=(a);i<=(b);i++)
#define FD(i,a,b) for(int i=(a);i>=(b);i--)

#define LL long long
#define PI 3.141592653589793238

#define PII pair<int,int>
#define PLL pair<LL,LL>
#define mp make_pair
#define fi first
#define se second

using namespace std;

int tc,fd[1005],n;
int tail[1005];
bool cp2[1005];

int res;

int main(){
	
	freopen("C-large.in","r",stdin);
	freopen("Cl.out","w",stdout);
	
	scanf("%d",&tc);
	FI(t,1,tc){
		scanf("%d",&n);
		FI(i,1,n) scanf("%d",&fd[i]);
		res=0;
		//case 1: biggest cycle
		FI(i,1,n){
			int cur=i;
			FI(j,1,n){
				cur=fd[cur];
				if(cur==i){
					res=max(res,j);
					break;
				}
			}
		}
		//case 2: 2-cpts
		FI(i,1,n){
			if(fd[fd[i]]==i) cp2[i]=true;
			else cp2[i]=false;
			tail[i]=0;
		}
		FI(i,1,n){
			if(cp2[i]) continue;
			int cur=i;
			FI(j,1,n){
				cur=fd[cur];
				if(cp2[cur]){
					tail[cur]=max(tail[cur],j);
					break;
				}
			}
		}
		
//		FI(i,1,n) printf("%d: CP? %d, tail %d\n",i,cp2[i],tail[i]);
		
		int summ=0;
		FI(i,1,n) if(cp2[i]) summ+=1+tail[i];
		
		res=max(res,summ);
		printf("Case #%d: %d\n",t,res);
	}
	return 0;
}

