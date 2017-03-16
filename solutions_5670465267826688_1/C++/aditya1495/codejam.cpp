//Aditya Shah

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

#define vi vector<int>
#define vs vector<string>
#define vpii vector<pii>
#define all(v) v.begin(), v.end()

#define fr freopen("input.in","r",stdin)
#define fw freopen("output.out","w",stdout)

#define foreach(i,X) for(__typeof((X).begin()) i = (X).begin(); i != (X).end(); i++)
#define forup(i,a,b) for(int i=(a); i<(b); ++i)
#define fordn(i,a,b) for(int i=(a); i>(b); --i)
#define rep(i,a) for(int i=0; i<(a); ++i)

#define gi(x) scanf("%d",&x)
#define gl(x) cin>>x
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf(" %s",x)

#define F first
#define S second

#define pb push_back
#define pf push_front
#define mp make_pair

const int inf=numeric_limits<int>::max();
const LL linf=numeric_limits<LL>::max();

map<pair<string,string>, string> conv;

void gen(){
	conv[mp("1","1")] = "1";
	conv[mp("1","i")] = "i";
	conv[mp("1","j")] = "j";
	conv[mp("1","k")] = "k";

	conv[mp("i","1")] = "i";
	conv[mp("i","i")] = "-1";
	conv[mp("i","j")] = "k";
	conv[mp("i","k")] = "-j";

	conv[mp("j","1")] = "j";
	conv[mp("j","i")] = "-k";
	conv[mp("j","j")] = "-1";
	conv[mp("j","k")] = "i";

	conv[mp("k","1")] = "k";
	conv[mp("k","i")] = "j";
	conv[mp("k","j")] = "-i";
	conv[mp("k","k")] = "-1";
}

string get(string a, string b){
	int sign = 0;
	if(a[0] == '-') {
		a = a.substr(1);
		sign ^= 1;
	}
	if(b[0] == '-') {
		b = b.substr(1);
		sign ^= 1;
	}
	string res = conv[mp(a,b)];
	if(res[0] == '-'){
		res = res.substr(1);
		sign ^= 1;
	}
	if(sign == 1) res = "-" + res;
	return res;
}

bool prefix[1000005], suffix[1000005];

int main(){
	fr;
	fw;
	int test;
	gi(test);
	gen();
	rep(c,test){
		LL l,x;
		printf("Case #%d: ", c+1);
		memset(prefix, false, sizeof prefix);
		memset(suffix, false, sizeof suffix);
		cin >> l >> x;
		string s, med = "";
		cin >> s;
		if(x > 8){
			x = 8 + x%4;
		}
		while(x--){
			med += s;
		}

		s = med;
		int n = s.size();

		string w = "";
		w += s[n-1];

		if(w == "k") suffix[n-1] = true;

		fordn(i,n-2,-1){
			string temp = "";
			temp += s[i];
			w = get(temp, w);
			suffix[i] = (w == "k");
		}

		w = "";
		w += s[0];

		if(w == "i") prefix[0] = true;

		forup(i,1,n){

			string temp = "";
			temp += s[i];

			w = get(w,temp);

			prefix[i] = prefix[i-1] | (w == "i");
		}

		w = ""; w += s[0];
		bool ok = 0;
		forup(i,1,n-1){
			string temp = "";
			temp += s[i];
			w = get(w, temp);
			if(w == "k" && prefix[i-1] && suffix[i+1]){
				ok = true;
				break;
			}
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}