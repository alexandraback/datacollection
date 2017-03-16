#include "headers.h"
struct tr{
	int j, p, s;
	tr(int a, int b, int c){
		j =a;
		p =b;
		s =c;
	}
};


int main(){
	int i=0,J,P,S,T,k;
	cin >> T;
	REP(t,T){
		vector <tr> v;
		cout << "Case #" << t+1 << ": ";
		cin >> J >> P >> S >> k;
		REP(j, J){
			REP(p, P){
				REP(s, S){
					tr x(j,p,s);
					v.PB(x);
				}
			}
		}

		int N = (1 << v.size());
		int jp[20], js[20], ps[20];
		int max = 0;
		int best = 0;
		int cnt;
		bool valid;
		if(k>=9){
			best = (1<<v.size())-1;
			max = P*J*S;
		}
		else{
		REP(i, N){
			int temp=0;
			REP(j, v.size()){
				if( i & (1 << j) ) temp++;
			}
			if(temp <= best) continue;
			valid = true;
			cnt = 0;
			REP(j,P*S) jp[j]=js[j]=ps[j] = 0;
			REP(j, v.size()){
				if( i & (1 << j) ){
					cnt++;
					jp[v[j].j * 3 + v[j].p]++;
					if(jp[v[j].j * 3 + v[j].p] > k){
						valid = false;
						break;
					}
					js[v[j].j * 3 + v[j].s]++;
					if(js[v[j].j * 3 + v[j].s] > k){
						valid = false;
						break;
					}
					ps[v[j].p * 3 + v[j].s]++;
					if(ps[v[j].p * 3 + v[j].s] > k){
						valid = false;
						break;
					}
				}
			}
			if(valid){
				if(cnt > max){
					max = cnt;
					best = i;
				}
			}
		}
		}

		cout << max << endl;
		REP(i, v.size()){
			if(best & (1 << i)){
				tr x = v[i];
				cout << x.j + 1 << " " << x.p + 1 << " " << x.s + 1 << endl;
			}
		}
	}
}

