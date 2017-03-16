#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <typeinfo>
#include <set>
#include <cctype>
#include <locale>
#include <utility>
#include <map>
#include <iterator>
#include <cstring>
using namespace std;


const long long INF = 1ll<<62;
const double eps = 1e-6;

int in() {
	int a;
	scanf("%d", &a);
	return a;
}

double din() {
	double a;
	scanf("%lf", &a);
	return a;
}

int gcd(int a, int b) {
	while (b) {
		a%=b;
		swap (a, b);
	}
	return a;
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

vector < vector <int> > g;
vector <bool> used;

void dfs(int v, int &s, bool &ch) {
        if(v != s && used[v]) {
                ch = 1;
                return;
        }
        used[v] = 1;
        for(int i = 0; i < g[v].size(); ++i) {
                dfs(g[v][i], s, ch);
        }
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T = in();
	for(int i = 1; i <= T; ++i){
		bool ch = 0;
		int n = in(), l, s;
        g.assign(n, vector <int> ());
        for(int j = 0; j < n; ++j) {
                l = in();
                g[j].resize(l);
                for(int k = 0; k < l; ++k) {
                        g[j][k] = in() - 1;
                }
        }
		string res = "No";
        for(int j = 0; j < n; ++j) {
                s = j;
                used.assign(n, 0);
                used[s] = 1;
                dfs(j, s, ch);
                if(ch) {
                        res = "Yes";
                        break;
                }
        }
		printf("Case #%d: ", i);
		cout<<res<<endl;
	}
	return 0;
}
