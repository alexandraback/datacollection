#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 105,MAXA = 30;
int dic[MAXA],kk,l,s,now,last,mx,p[MAXN],q;
char bd[MAXN],aim[MAXN];
bool f[MAXN][MAXN][MAXN];
double pr[MAXN][MAXN][MAXN],expt;

int main(){
	freopen("input","r",stdin); freopen("output","w",stdout);
	int __;
	scanf("%d",&__);
	for(int Cas = 1;Cas <= __;++ Cas){
		printf("Case #%d: ",Cas);
		scanf("%d%d%d",&kk,&l,&s);
		scanf("%s",bd);
		memset(dic,0,sizeof(dic));
		for(int i = 0;i < kk;++ i)
			++ dic[bd[i] - 'A'];
		scanf("%s",aim + 1);
		p[1] = 0; q = 0;
		for(int i = 2;i <= l;++ i){
			while(q && aim[q + 1] != aim[i]) q = p[q];
			if(aim[q + 1] == aim[i]) ++ q;
			p[i] = q;
		}
		memset(f,0,sizeof(f));
		memset(pr,0,sizeof(pr));
		f[0][0][0] = 1; pr[0][0][0] = 1.0;
		for(int i = 0;i < s;++ i)
			for(int j = 0;j < l && j <= i;++ j)
				for(int k = 0;k <= i;++ k)
					for(int ch = 0,q;ch < 26;++ ch)
					if(dic[ch]){
						q = j;
						while(q && aim[q + 1] - 'A' != ch) q = p[q];
						if(aim[q + 1] - 'A' == ch) ++ q;
						if(f[i][j][k]){
							if(q == l){
								pr[i + 1][p[l]][k + 1] += pr[i][j][k] * (double(dic[ch]) / double(kk));
								f[i + 1][p[l]][k + 1] = true;
							}else{
								pr[i + 1][q][k] += pr[i][j][k] * (double(dic[ch]) / double(kk));
								f[i + 1][q][k] = true;
							}
						}
					}
		expt = 0.0;
		for(int k = 0;k <= s;++ k){
			double pp = 0.0;
			for(int j = 0;j < l;++ j){
				pp += pr[s][j][k];
				if(f[s][j][k]) mx = k;
			}
			expt += pp * k;
		}
		printf("%.8lf\n",double(mx) - expt);
	}
	return 0;
}
