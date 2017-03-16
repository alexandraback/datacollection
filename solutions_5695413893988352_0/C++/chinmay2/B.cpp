#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define MOD 1000000007

#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d %d", &x, &y)
#define print(x) printf("%d\n", x)

#define scan_lli(x) scanf("%lld", &x)
#define print_lli(x) printf("%lld\n", x)

#define scanc(x) scanf("%c", &x)
#define printc(x) printf("%c", x)

#define scans(x) scanf("%s", x)
#define prints(x) fscanf(out, "%s\n", x)

#define for_up(v, s, e) for (int v=s; v<e; v++)
#define for_down(v, s, e) for (int v=s; v>=e; v--)

#define vi vector<int>
#define pii pair<int, int>
#define vpii vector< pair<int, int> >

#define pb push_back
#define mp make_pair

#define fs first
#define sc second

string c, j;
int n;

void funcc (int i, vector<int> &sc) {
	
	if (i == n) {
		sc.pb(atoi(c.c_str()));
	}
	
	else {
		if (c[i] == '?') {
			for_up (k, 0, 10) {
				c[i] = '0' + k;
				funcc(i+1, sc);
			}
			c[i] = '?';
		}
		else {
			funcc(i+1, sc);
		}
	}
	
}

void funcj (int i, vector<int> &sj) {
	
	if (i == n) {
		sj.pb(atoi(j.c_str()));
	}
	
	else {
		if (j[i] == '?') {
			for_up (k, 0, 10) {
				j[i] = '0' + k;
				funcj(i+1, sj);
			}
			j[i] = '?';
		}
		else {
			funcj(i+1, sj);
		}
	}
	
}

int main()
{
	freopen("B-small-attempt3.in", "r", stdin);
    freopen("B-small-attempt3.out", "w", stdout);
	
	//freopen("B-large.in", "r", stdin);
    //freopen("B-large.out", "w", stdout);
	
    int T;
    scan(T);

    for_up (t, 1, T+1) {
		cin >> c >> j;
		n = c.length();
		
		
		vector<int> sc, sj;
		
		funcc(0, sc);
		funcj(0, sj);
		
		int ans_c = INT_MAX;
		int ans_j = INT_MAX;
		int min_diff = INT_MAX;
		
		for_up (i, 0, sc.size()) {
			for_up (k, 0, sj.size()) {
				if (abs(sc[i]-sj[k]) < min_diff) {
					min_diff = abs(sc[i]-sj[k]);
					ans_c = sc[i];
					ans_j = sj[k];
				}
			}
		}
		
		printf("Case #%d: ", t);
		
		string ac, aj;
		while (n--) {
			ac += ans_c%10 + '0';
			aj += ans_j%10 + '0';
			ans_c /= 10;
			ans_j /= 10;
		}
		
		reverse(ac.begin(), ac.end());
		reverse(aj.begin(), aj.end());
		
		cout << ac << " " << aj << endl;
	}
	
	//fclose(stdin);
	//fclose(stdout);

	return 0;
}

