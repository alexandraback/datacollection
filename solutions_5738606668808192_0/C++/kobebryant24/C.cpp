#include <bits/stdc++.h>
using namespace std;

#define forall(i,a,b)   for(int i=a;i<b;++i)
#define ll 				long long

ll x[11][17];
void create_array(){
	forall(i,2,11){
		ll temp=1,num=i;
		forall(j,0,17){
			x[i][j]=temp;
			temp*=num;
		}
	}
}

int main(){
	int t;cin >> t;
	create_array();
	forall(test,0,t){
		cout << "Case #" << test+1 << ": " << endl;
		int n,k,res=0;cin >> n >> k;
		forall(i,1,8){
			forall(j,i+1,8){
				++res;
				forall(k,0,n) {
					if(k==0 || k==n-1) cout << '1';
					else if(k==15-i || k==15-j) cout << '1';
					else if(k==j || k==j-i) cout << '1';
					else cout << '0';
				}
				forall(k,2,11) cout << ' ' << x[k][0]+x[k][i]+x[k][j] ;
				cout << endl;
			}
		}
		forall(i,1,8){
			forall(j,i+1,8){
				forall(t,j+1,8){
					++res;
					forall(k,0,n) {
						if(k==0 || k==n-1) cout << '1';
						else if(k==15-i || k==15-j || k==15-t) cout << '1';
						else if(k==t || k==t-i || k==t-j) cout << '1';
						else cout << '0';
					}
					forall(k,2,11) cout << ' ' << x[k][0]+x[k][i]+x[k][j]+x[k][t] ;
					cout << endl;
					if(res==k) return 0;
				}
			}
		}
	}
}