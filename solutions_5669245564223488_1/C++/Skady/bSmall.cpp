#include <bits/stdc++.h>
using namespace std;
#define msg(x) cout<<#x<<" = "<<x<<endl;
#define N 110
#define NN 1000
#define MOD 1000000007LL
#define WHITE false
#define GREY true
typedef long long int LL;
string s[N];
LL fac[N], tmp;
int vl[NN], vr[NN], vt[NN];
int n;
pair<char, char> v[N];
bool color[N];
void f(int pos) {
	color[pos] = GREY;
	tmp = (tmp * fac[vt[v[pos].second]]) % MOD;
	for(int i=0 ; i<n ; i++) if( v[i].first == v[i].second && v[i].first == v[pos].second ) color[i] = GREY;
	for(int i=0 ; i<n ; i++) {
		if( i == pos ) continue;
		if( v[i].first == v[pos].second && color[i] == WHITE ) f(i);
	}
}
int main() {
	fac[0] = 1LL;
	for(int i=1 ; i<N ; i++ ) fac[i] = (fac[i - 1] * (LL)i) % MOD;
    ios_base::sync_with_stdio(0);
   	int T;
   	cin>>T;
   	for(int caso=1 ; caso<=T ; caso++) {
   		cin>>n;
   		for(int i=0 ; i<n ; i++) cin>>s[i];
   		bool flag = true;
   		for(char c='a' ; c<='z' ; c++) {
   			int left = 0, rigth = 0, center = 0, total = 0;
   			for(int i=0 ; flag && i<n ; i++) {
   				int len = s[i].size();
   				if( s[i][0] == c && s[i][len - 1] != c ) {
   					for(int k=0 ; k<len ; k++) {
   						if( s[i][k] != c ) {
   							for(int j=k+1 ; j<len ; j++) {
   								if( s[i][j] == c ) {
   									flag = false;
   									break;
   								}
   							}
   							break;
   						}
   					}
   					left++;
   				} else {
   					if( s[i][0] != c && s[i][len - 1] == c ) {
   						for(int k=len-1 ; k>=0 ; k--) {
	   						if( s[i][k] != c ) {
	   							for(int j=k-1 ; j>=0 ; j--) {
	   								if( s[i][j] == c ) {
	   									flag = false;
	   									break;
	   								}
	   							}
	   							break;
	   						}
	   					}
	   					rigth++;
	   				} else {
	   					if( s[i][0] == c && s[i][len - 1] == c ) {
	   						for(int k=0 ; k<len ; k++) if( s[i][k] != c ) { flag = false; break; }
	   						total++;
	   					} else {
	   						for(int k=0 ; flag && k<len ; k++) {
	   							if( s[i][k] == c ) { 
	   								for(int j=k+1 ; j<len ; j++) {
	   									if( s[i][j] != c ) {
	   										for(int z=j+1 ; z<len ; z++) {
	   											if( s[i][z] == c ) {
	   												flag = false;
	   												break;
	   											}
	   										}
	   										break;
	   									}
	   								}
	   								center++;
	   								break;
	   							}
	   						}
	   					}
	   				}	
   				}
   			}
   			if( flag ) {
   				if( center > 1 ) {
   					flag = false;
   				} else {
   					if( center == 1 ) {
   						if( left + rigth + total >= 1 ) flag = false;
   					} else {
   						if( left > 1 || rigth > 1 ) flag = false;
   					}
   				}
   			}
   			if( flag ) {
   				vl[c] = left;
   				vr[c] = rigth;
   				vt[c] = total;
   			} else {
   				break;
   			}
   		}
   		for(int i=0 ; i<n ; i++) {
   			v[i] = make_pair(s[i][0], s[i][s[i].size() - 1]);
   			//cout<<v[i].first<<" "<<v[i].second<<endl;
   		}
   		if( flag == false ) {
   			cout<<"Case #"<<caso<<": "<<0<<endl;	
   			continue;
   		}
   		bool sw = false;
   		LL ans = 1LL;
   		int cntComp = 0;
   		memset(color, WHITE, sizeof(color));
   		for(int i=0 ; i<n ; i++) {
   			if( color[i] == WHITE ) {
	   			if( v[i].first != v[i].second ) {
	   				if( vr[v[i].first] == 0 && vt[v[i].first] == 0 ) {
	   					sw = true;
	   					tmp = 1LL;
	   					f(i);
	   					ans = (ans * tmp) % MOD;
	   					//cout<<"ini "<<i<<" "<<tmp<<endl;
	   					cntComp++;
	   				}
	   			} else {
	   				if( vr[v[i].first] == 0 ) {
	   					sw = true;
	   					tmp = 1LL;
	   					f(i);
	   					ans = (ans * tmp) % MOD;
	   					//cout<<"ini "<<i<<" "<<tmp<<endl;
	   					cntComp++;
	   				}
	   			}
   			}
   		}
   		if( sw == false ) {
   			cout<<"Case #"<<caso<<": "<<0<<endl;	
   			continue;
   		}
   		ans = (ans * fac[cntComp]) % MOD;
   		cout<<"Case #"<<caso<<": "<<ans<<endl;
   	}
    return 0;
}