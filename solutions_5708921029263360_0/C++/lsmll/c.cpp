#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int tmp,tests,tc,ans,i,j,k,n,a,b,c,d[3][21][21],w[211][3],ts[21][21][21];
int main(){
	for (tc=1,scanf("%d",&tests);tests--;tc++){
		fprintf(stderr,"* %d\n",tc);ans=0;
		scanf("%d%d%d%d",&a,&b,&c,&n);memset(d,0,sizeof(d));memset(ts,0,sizeof(ts));
		for (i=j=k=1;i<=a;i++){
			tmp=0;
			while (tmp<b*c){
				if (max(d[0][i][j],max(d[1][i][k],d[2][j][k]))==n) break;
				d[0][i][j]++;d[1][i][k]++;d[2][j][k]++;
				ans++;tmp++;w[ans][0]=i;w[ans][1]=j;w[ans][2]=k;
				if (ts[i][j][k]) fprintf(stderr,"ERROR!!\n");
				ts[i][j][k]=1;
				if (tmp%min(n,c)==0) j=(j==b)?1:j+1;
				k=(k==c)?1:k+1;
			}
		}
		printf("Case #%d: %d\n",tc,ans);
		for (i=1;i<=ans;i++) printf("%d %d %d\n",w[i][0],w[i][1],w[i][2]);
	}
	return 0;
}
