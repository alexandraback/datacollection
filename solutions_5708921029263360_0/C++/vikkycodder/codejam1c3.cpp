#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define mem(a, v) memset(a, v, sizeof(a))
#define PI 3.14159265358979323846
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<VI> matrix;
const ll MOD = 1000000007LL;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	srand(time(NULL));
	scanf("%d", &t);
	for(int tc = 1; tc <= t; tc++){
		printf("Case #%d: ", tc);
		int a, b, c, d;
		vector<pair<int, PII> > v, ans, ans1;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for(int i=1; i<=a; i++){
			for(int j=1; j<=b; j++){
				for(int k=1; k<=c; k++){
					v.pb(mp(i, mp(j, k)));
				}
			}
		}
		int mx = -1;
		for(int chk = 1; chk <= 10; chk++){
			map<PII, int> M;
			random_shuffle(v.begin(), v.end());
			for(int i=0; i<v.size(); i++){
				int a = v[i].ft;
				int b = v[i].sd.ft;
				int c = v[i].sd.sd;
				if(M[mp(a, 100 + b)] == d || M[mp(100 + b, 1000 + c)] == d || M[mp(a, 1000 + c)] == d){
					continue;
				}
				if(!M[mp(a, 100 + b)]){
					M[mp(a, 100 + b)] = 1;
				}
				else{
					M[mp(a, 100 + b)]++;
				}
				if(!M[mp(100 + b, 1000 + c)]){
					M[mp(100 + b, 1000 + c)] = 1;
				}
				else{
					M[mp(100 + b, 1000 + c)]++;
				}
				if(!M[mp(a, 1000 + c)]){
					M[mp(a, 1000 + c)] = 1;
				}
				else{
					M[mp(a, 1000 + c)]++;
				}
				ans.pb(mp(a, mp(b, c)));
			}
			if(mx == -1){
				mx = ans.size();
				ans1.clear();
				ans1 = ans;
			}
			else{
				if(ans.size() > mx){
					//assert(false);
					ans1.clear();
					ans1 = ans;
				}
			}

			ans.clear();
		}
		printf("%d\n", ans1.size());
		for(int i=0; i<ans1.size(); i++){
			printf("%d %d %d\n", ans1[i].ft, ans1[i].sd.ft, ans1[i].sd.sd);
		}
	}
	return 0;
}