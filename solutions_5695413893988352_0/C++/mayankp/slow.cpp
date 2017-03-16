#include <bits/stdc++.h> 
#define X first
#define Y second
#define mp make_pair
#define pb push_back

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
template<class T> inline T maxm(T& a, T b){return a = a < b ? b : a;}
template<class T> inline T minm(T& a, T b){return a = a > b ? b : a;}

int p10[] = {1, 10, 100, 1000};

pss solve(string s1, string s2){

    int N = s1.size();
    pair<int, pss> ans = mp(1e9, mp("", ""));
    for(int i = 0; i < p10[N]; ++i){
	for(int j = 0; j < p10[N]; ++j){
	    string c1 = to_string(i);
	    string c2 = to_string(j);
	    while(c1.size() < N) c1 = "0" + c1;
	    while(c2.size() < N) c2 = "0" + c2;
	    //cout << "considering " << c1 << 
	    bool f = 0;
	    for(int k = 0; k < N; k++)
		if((s1[k] != '?' && s1[k] != c1[k]) || (s2[k] != '?' && s2[k] != c2[k])){
		    f = 1;
		    break;
		}
	    if(f) continue;
	    minm(ans, mp(abs(stoi(c1) - stoi(c2)), mp(c1, c2)));

	}
    }

    return ans.Y;

}

int main(){

    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;

    for(int i = 0; i < T; ++i){
    
	string s1, s2;
	cin >> s1 >> s2;
	int N = s1.size();

	pss ans = solve(s1, s2);
	cout << "Case #" << i + 1 << ": " << ans.X << ' ' << ans.Y << '\n';
    }

    return 0;

}

