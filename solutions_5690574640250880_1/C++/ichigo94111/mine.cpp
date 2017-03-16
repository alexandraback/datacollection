#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N = 52; //
int T;
int round=0;
int mapd[N][N];
int r,c,m;
int fin;
int change;

void deal_with()
{
	int s=m/c;
	for(int j=s;j>=0;j--){
		int k=m-j*c;
		if(k<=c-2 && j<=r-3){
			fin=1;
			//print
			for(int t1=1;t1<=j;t1++)
				for(int t2=1;t2<=c;t2++)
					mapd[t1][t2]=-1;
			for(int t1=1;t1<=k;t1++)
				mapd[j+1][t1]=-1;
			break;
		}
		if(j<=max(0,r-2) && k%(r-j)==0 && k/(r-j)<=max(0,c-2)){
			fin=1;
			for(int t1=1;t1<=j;t1++)
				for(int t2=1;t2<=c;t2++)
					mapd[t1][t2]=-1;
			for(int t1=j+1;t1<=r;t1++)
				for(int t2=1;t2<=k/(r-j);t2++)
					mapd[t1][t2]=-1;
			break;
		}
		if(j<=r-3){
			for(int i=min(c-2,k);i>=1;i--){
				int q=k-i;
				if(q<=i && j+2<=r-2){
					fin=1;
					for(int t1=1;t1<=j;t1++)
						for(int t2=1;t2<=c;t2++)
							mapd[t1][t2]=-1;
					for(int t1=1;t1<=i;t1++)
						mapd[j+1][t1]=-1;
					for(int t1=1;t1<=q;t1++)
						mapd[j+1][t1]=-1;
					break;
				}
				if(q%(r-j-1)==0 && q/(r-j-1)<=max(0,c-2) && q/(r-j-1)<=i){
					fin=1;
					for(int t1=1;t1<=j;t1++)
						for(int t2=1;t2<=c;t2++)
							mapd[t1][t2]=-1;
					for(int t1=1;t1<=i;t1++)
						mapd[j+1][t1]=-1;
					for(int t1=j+2;t1<=r;t1++)
						for(int t2=1;t2<=q/(r-j-1);t2++)
							mapd[t1][t2]=-1;
					break;
				}
			}
			if(fin) break;
		}
	}
}

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("mine.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(mapd,0,sizeof(mapd));
		fin=0;
		change=0;
		scanf("%d%d%d",&r,&c,&m);
		printf("Case #%d:\n",++round);
		if(r*c==m+1){
			for(int i=1;i<=r;i++){
				for(int j=1;j<=c;j++){
					if(i==r && j==c) printf("c");
					else printf("*");
				}
				printf("\n");
			}
			continue;
		}
		deal_with();
		if(!fin){
			swap(r,c);
			change=1;
		}
		deal_with();
		if(!fin) printf("Impossible\n");
		else{
			if(!change){
				for(int i=1;i<=r;i++){
					for(int j=1;j<=c;j++){
						if(i==r && j==c) printf("c");
						else if(mapd[i][j]==-1) printf("*");
						else printf(".");
					}
					printf("\n");
				}
			}
			else{
				for(int i=1;i<=c;i++){
					for(int j=1;j<=r;j++){
						if(i==c && j==r) printf("c");
						else if(mapd[j][i]==-1) printf("*");
						else printf(".");
					}
					printf("\n");
				}
			}
		}
	}
	return 0;
}