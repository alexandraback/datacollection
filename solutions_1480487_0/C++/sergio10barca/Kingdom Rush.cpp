#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cstdio>
#define x first
#define y second
#define IN(x, n) (0 <= (x) && (x) < n)
#define MAX 2010
#define MOD 1000000007
#define EPS 0.0001
#define INF 9223372036854775807LL
using namespace std;

typedef long long int entero;
typedef pair<int, int> Point;

pair<bool, bool> u[MAX];

double maxi, Z, suma, total, s[MAX], p[MAX];

int main(){
    int i, k, N, T, r, q;
    cin >> T;
    for(k = 1; k <= T; k++){
        cin >> N;
        maxi = suma = 0;
        for(i = 0; i < N; i++){
			cin >> s[i];
			maxi = max(s[i], maxi);
			suma+=s[i];
		}
		total = 0;
		for(Z = maxi; ; Z++){
			total = p[0] = (Z-s[0])/suma;
			for(i = 1; i < (N-1); i++){
				p[i] = (Z-s[i])/suma;
				total+=p[i];
			}
//			printf("%lf %lf\n", Z, total);
			if(total <= 1.0)
				p[i] = 1.0-total;
			else{
				Z--;
				p[0] = (Z-s[0])/suma;
				for(i = 1; i < (N-1); i++){
					p[i] = (Z-s[i])/suma;
					total+=p[i];
				}
				break;
			}
			r = (int)floor((s[i]+suma*p[i])+EPS);
			q = (int)Z;
//			printf("%d %d\n", r, q);
			if(r == q){
				break;
			}
//			printf("%d %lf %lf\n", i, (s[i]+suma*p[i]), p[i]);
			total = 0;
			for(i = 0; i < N; i++){
				total+=p[i];
			}
//			printf("%lf %lf\n\n", Z, total);
		}
		printf("Case #%d:", k);
		for(i = 0; i < N; i++)
			printf(" %lf", p[i]*100.0);
		printf("\n");
    }
    return 0;
}
