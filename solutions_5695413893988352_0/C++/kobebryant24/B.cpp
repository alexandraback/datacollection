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

string l,m;

bool mat(string a,string b,int k){
	if(b.size()>a.size()) return false;
	else if(b.size()<a.size()) {
		b='0'+b;
		return mat(a,b,k);
	}
	else{
		if(k==0) l=b;
		else m=b;
		forall(i,0,a.size()) {
			if(a[i]=='?' || b[i]=='?') continue;
			else if(a[i]==b[i]) continue;
			else return false;
		}
	}
	return true;
}

int main(){
	int t;cin >> t;
	forall(test,0,t){
		cout << "Case #" << test+1 << ": ";
		int papa=100000000;
		string x,y,a,b;cin >> a >> b;
		forall(i,0,1000){
			forall(j,0,1000){
				if(mat(a,to_string(i),0) && mat(b,to_string(j),1) && abs(i-j) < papa){
					papa=abs(i-j);
					x=l;
					y=m;
				}
			}
		}
		cout << x << ' ' << y << endl;
	}
}