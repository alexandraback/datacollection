#include <iostream>
using namespace std;


#define LL long long
#define N 105

LL a[N],b[N], t[2][N][N],ans,x, g[N][N][2][N],f[N][N][2][N],s[2][N][N],ra,rb;

int A[N],B[N],next[2][N][N],n,m;

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	
LL MAX =1;
	MAX = (MAX<<62);
	int testcase;
	scanf("%d",&testcase);
	for (int ttt=1; ttt<=testcase; ttt++)
	{
		printf("Case #%d: ",ttt);
		scanf("%d%d",&n,&m);
		for (int i=1; i<=n; i++)
		{
			scanf("%lld%d",&a[i],&A[i]);
			
			for (int k=1; k<=100; k++)
				if (k==A[i]) s[0][i][k]=s[0][i-1][k]+a[i];
				else s[0][i][k]=s[0][i-1][k];
		}
		
		for (int i=1; i<=m; i++)
		{
			scanf("%lld%d",&b[i],&B[i]);
			
			for (int k=1; k<=100; k++)
				if (k==B[i]) s[1][i][k]=s[1][i-1][k]+b[i];
				else s[1][i][k]=s[1][i-1][k];
		}
		
		for (int i=1; i<=n; i++){
			for (int k=1; k<=100; k++)
			{
				next[0][i][k]=n+1;
				for (int j=i+1; j<=n; j++)
					if (A[j]==k) { next[0][i][k]=j; break; }
			}
		}
		for (int i=1; i<=m; i++){
			for (int k=1; k<=100; k++)
			{
				next[1][i][k]=m+1;
				for (int j=i+1; j<=m; j++)
					if (B[j]==k) { next[1][i][k]=j; break; }
			}
		}
		for (int i=1; i<=n; i++){
			for (int k=1; k<=n; k++) t[0][i][k]=MAX;
			t[0][i][0]=0;
			int j=i-1;
			for (int k=1; k<=n; k++)
			{
				while (j>0 && A[j]!=A[i]) j--;
				if (j<=0) break;
				t[0][i][k]=s[0][i-1][A[i]]-s[0][j-1][A[i]];
				j--;
			}
			
		}
		
		for (int i=1; i<=m; i++){
			for (int k=1; k<=m; k++) t[1][i][k]=MAX;
			t[1][i][0]=0;
			int j=i-1;
			for (int k=1; k<=m; k++)
			{
				while (j>0 && B[j]!=B[i]) j--;
				if (j<=0) break;
				t[1][i][k]=s[1][i-1][B[i]]-s[1][j-1][B[i]];
				j--;
			}
			
		}
		
		for (int i=1; i<=n+1; i++)
			for (int j=1; j<=m+1; j++)
				for (int s=0; s<=1; s++)
					for (int k=0; k<=100; k++)
						f[i][j][s][k]=-MAX;
		
		
		f[1][1][0][0]=0; g[1][1][0][0] = 0;
		ans =0;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				for (int s=0; s<=1; s++)
					for (int k=0; k<=min(i,j); k++)
					{
						x = f[i][j][s][k];
						if (x<0) continue;
			//			cout << " "<< i<<" "<<j<<" "<<s<<" "<<k<<" "<<x<<endl;
						if (A[i]==B[j])
						{
							if (s==0) ra = a[i]-g[i][j][s][k];
							else ra = a[i];
							if (s==1) rb = b[j]-g[i][j][s][k];
							else rb = b[j];
							if (ra<0 || rb<0) continue;
				//			cout << x<<" "<<rb<<endl;
							if (ra<rb) {
								if (x+ra>f[i+1][j][1][(s==0)?1:k+1]){
									f[i+1][j][1][(s==0)?1:k+1] = x+ra;
									g[i+1][j][1][(s==0)?1:k+1] = (s==0)? ra : g[i][j][s][k]+ra;
								}
							}
							else if (ra==rb) {
								if (x+ra>f[i+1][j][0][0]){
									f[i+1][j][0][0] = x+ra;
									g[i+1][j][0][0] = 0;
								}
							}
							else {
								if (x+rb>f[i][j+1][0][(s==1)?1:k+1]){
									f[i][j+1][0][(s==1)?1:k+1] = x+rb;
									g[i][j+1][0][(s==1)?1:k+1] = (s==0)? g[i][j][s][k]+rb :rb;
								}
							}
						}
						else {
							int ii = next[0][i][B[j]];
							if (s==1) {
								if (x>f[ii][j][s][k]) {
									f[ii][j][s][k] = x;
									g[ii][j][s][k] = g[i][j][s][k];
								}
							}
							else {
								if (x>f[ii][j][0][0]) {
									f[ii][j][0][0] = x;
									g[ii][j][0][0] = 0;
									}
							}
						
							int jj = next[1][j][A[i]];
							if (s==0) {
								if (x>f[i][jj][s][k]) {
									f[i][jj][s][k] = x;
									g[i][jj][s][k] = g[i][j][s][k];
								}
							}
							else {
								if (x>f[i][jj][0][0]){
									f[i][jj][0][0] = x;
									g[i][jj][0][0] = 0;
								}
							}
						}
					}
		for (int i=1; i<=n+1; i++)
			for (int j=1; j<=m+1; j++)
				for (int s=0; s<=1; s++)
					for (int k=0; k<=min(i,j); k++)
						if (f[i][j][s][k]>ans) ans= f[i][j][s][k];
		
		
		cout << ans<<endl;
		
		
	}
}