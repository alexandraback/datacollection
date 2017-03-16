#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;
typedef vector<pi> vpi;

#define fi          first
#define se          second
#define mp 			make_pair
#define pb          push_back
#define forall(i,a,b)               for(int i=a;i<b;++i)
#define max(a,b)                    ( (a) > (b) ? (a) : (b))
#define min(a,b)                    ( (a) < (b) ? (a) : (b))
#define mes(a,b)					memset(a,b,sizeof a)
#define endl			    		"\n"
#define ll 							long long
const int oo = 1000000009;
const double eps = 1e-9;
const int mod = 1000000007;

int main(){
	int t;cin >> t;
	forall(test,0,t){
		int b,m;cin >> b >> m;
		cout << "Case #" << test+1 << ": "; 
		if(b==2 && m>1) cout << "IMPOSSIBLE" << endl;
		else if(b==2){
			cout << "POSSIBLE" << endl;
			cout << "01" << endl;
			cout << "00" << endl;
		}
		else{
			int ct=0,mat[20][20],y[20];
			forall(i,0,20) forall(j,0,20) mat[i][j]=0;
			forall(i,0,20) y[i]=0;
			y[1]=1;++ct;mat[1][b]=1;
			for(int i=2;i<b&&ct<m;++i){
				mat[1][i]=1;mat[i][b]=1;
				++ct;
				y[i]++;
				for(int j=i-1;j>1&&ct<m;--j){
					if(ct+y[j]<=m) {
						mat[i][j]=1;
						ct+=y[j];
						y[i]+=y[j];
					}
				}
			}
			if(m!=ct) cout << "IMPOSSIBLE" << endl;
			else{
				cout << "POSSIBLE" << endl;
				forall(i,1,b+1){
					forall(j,1,b+1){
						cout << mat[i][j];
					}
					cout << endl;
				}
			}
		}
	}
}