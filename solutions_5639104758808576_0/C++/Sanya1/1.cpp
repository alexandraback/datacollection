#include <bits/stdc++.h>
#include <unordered_map>
#include <initializer_list>
#include <memory>
#include <vector>
#define mp make_pair
#define pb push_back
#define lo int
#define li long long int
#define db double

#define sz(a) (lo)(a).size()
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
#define DEB(...) fprintf(stderr, __VA_ARGS__)

//=======================
//#define pi 3.14159265358979323
#define eps 1e-9
#define INF 2e9
#define MN 2010
#define SM 2000
//=====================================================




int main()
{
#ifdef MYLOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("matan.in", "r", stdin);
//    freopen("matan.out", "w", stdout);
#endif
    int T;
    cin >> T;
    for(int i = 1; i <= T;i++){
    	int n;
    	scanf("%d", &n);
    	string s;
    	cin >> s;
    	int ans = 0;
    	int cnt = 0;
    	FOR(i, sz(s)){
    		if(s[i] != '0'){
				ans += max(0, i - cnt - ans);
				cnt += s[i] - '0';
    		}
    	}
    	printf("Case #%d: %d\n", i, ans);
    }
};

