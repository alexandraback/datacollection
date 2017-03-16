/* attention to overflow */
#include <bits/stdc++.h>

#define dump(x) cerr<< #x << " = " << x <<endl
#define ALL(container) (container).begin(),(container).end()

using namespace std;
const int INF = 1 << 25;
void io() { cin.tie(0); ios::sync_with_stdio(false);}
template <class S,class T> ostream& operator<<(ostream& os, const pair <S,T> &s){return os<<'('<<s.first<<','<<s.second<<')';}
/*printf("%.9Lf\n",cf);*/
const int MOD = 1000000007;
const double EPS=1e-8;

string cs(int n){ return "Case #"+to_string(n)+": "; }

int main() {
	io();
	int T;
	cin>>T;
	string bad="IMPOSSIBLE";
	for(int tr=1;tr<=T;tr++){
		long long K,C,S;
		cin>>K>>C>>S;

		if(C*S<K){
			cout<<cs(tr)<<bad<<endl;
		}else{
			vector <long long> pos(S,1);
			long long up=pow(K,C);
			long long tmp=up;
			long long now=0;
			while(now<K){
				tmp/=K;
				for(long long i=0;i<S;i++){
					pos[i]+=tmp*now;
					now++;
					if(now==K) break;
				}
			}
			cout<<cs(tr);
			for(int i=0;i<pos.size();i++){
				cout<<pos[i];
				if(i!=pos.size()-1) cout<<' ';
			}
			cout<<endl;
		}
		/*if(C*S<K){
			cout<<cs(tr)<<bad<<endl;
		}else{
			long long up=pow(K,C);
			//cout<<"up: "<<up<<endl;
			vector <long long> val;
			cout<<cs(tr);
			for(long long i=0;i<S;i++){
				long long tmp=up;
				long long pos=0;
				for(long long j=i*C;j<(i+1)*C;j++){
					tmp/=K;
					//cout<<j<<' '<<tmp<<' '<<j*tmp<<endl;
					if(j*tmp>up) break;
					pos+=j*tmp;
					if(pos>up || j+1==K) break;
				}
				if(pos>up) break;
				val.push_back(pos+1);
				if((i+1)*C>=K) break;
			}
			for(int i=0;i<val.size();i++){
				cout<<val[i];
				if(i!=val.size()-1) cout<<' ';
			}
			cout<<endl;
		}*/
	}


	return 0;
}
