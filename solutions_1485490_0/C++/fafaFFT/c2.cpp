#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

#define MP make_pair
typedef long long LL;
typedef pair<LL,LL> PI;
#define PB push_back
#define typ second
#define num first

int t,n,m;
vector<PI> wartN;
vector<PI> wartM;
LL dynamik[110][110];

void brut() {
	for(int i=0;i<=wartM.size();i++) for(int i2=i;i2<=wartM.size();i2++)  for(int i3=i2;i3<=wartM.size();i3++) {
		
	
	}

}

LL pojebaniec(int a, int b, LL pozostalosc, int ktory) {
	LL best = 0;
	LL akt = 0;

	if(a>=n||b>=m) return 0;
	if(ktory == 0) {
		while(a<n && b < m) {
			if(wartN[a].typ == wartM[b].typ) {
				if(pozostalosc > wartM[b].num) {
					akt+=wartM[b].num;
					pozostalosc -= wartM[b].num;
					best = max(best,akt);
					b++;
				}
				else if(pozostalosc < wartM[b].num) {
					akt+=pozostalosc;
					akt+=pojebaniec(a+1,b,wartM[b].num - pozostalosc,1);
					// koniec
					best = max(best,akt);
					break;
				}
				else if(pozostalosc == wartM[b].num) {
					akt+=pozostalosc;
					akt+=dynamik[a+1][b+1];
					// koniec
					best = max(best,akt);
					break;
				}
			}
			else {
				best = max(best,akt+dynamik[a+1][b]);
				b++;
			}
			// koncz to
		}		
	}
	else {
		while(a<n && b < m) {
			if(wartN[a].typ == wartM[b].typ) {
				if(pozostalosc > wartN[a].num) {
					akt+=wartN[a].num;
					pozostalosc -= wartN[a].num;
					best = max(best,akt);
					a++;
				}
				else if(pozostalosc < wartN[a].num) {
					akt+=pozostalosc;
					akt+=pojebaniec(a,b+1,wartN[a].num - pozostalosc,0);
					// koniec
					best = max(best,akt);
					break;
				}
				else if(pozostalosc == wartN[a].num) {
					akt+=pozostalosc;
					akt+=dynamik[a+1][b+1];
					// koniec
					best = max(best,akt);
					break;
				}
			}
			else {
				best = max(best,akt+dynamik[a][b+1]);
				a++;
			}
			// koncz to
		}		
	}
	return best;
}

int main() {
	scanf("%d",&t);
	for(int ind = 1;ind<=t;ind++) {
		scanf("%d%d",&n,&m);
		wartN.clear();
		wartM.clear();
		for(int i=0;i<n;i++) {
			LL a,b;scanf("%I64d%I64d",&a,&b); b--;
			wartN.PB(MP(a,b));
		}
		for(int i=0;i<m;i++) {
			LL a,b;scanf("%I64d%I64d",&a,&b); b--;
			wartM.PB(MP(a,b));
		}
		printf("Case #%d: ", ind);
		
		for(int i=0;i<=m;i++) for(int i2=0;i2<=n;i2++) dynamik[i2][i] = 0;
		//for(int i=0;i<n;i++) dynamik[i][m] = 0;
		
		for(int i=n-1;i>=0;i--) for(int i2=m-1;i2>=0;i2--){
			if(wartN[i].typ == wartM[i2].typ) {
				if(wartN[i].num > wartM[i2].num) {
					dynamik[i][i2] = wartM[i2].num + pojebaniec(i,i2+1,wartN[i].num - wartM[i2].num,0);
				}
				else if(wartN[i].num < wartM[i2].num) {
					dynamik[i][i2] = wartN[i].num + pojebaniec(i+1,i2,wartM[i2].num - wartN[i].num,1);
				}
				else if(wartN[i].num == wartM[i2].num) {
					dynamik[i][i2] = wartM[i2].num + dynamik[i+1][i2+1];
				}
			}
			else {
				dynamik[i][i2] = max(dynamik[i+1][i2],dynamik[i][i2+1]);
			}
		}
		printf("%I64d\n", dynamik[0][0]);
	}
	return 0;
}
