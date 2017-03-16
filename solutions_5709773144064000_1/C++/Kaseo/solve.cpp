#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>
 
using namespace std;
 
const long long INF = 1000000007;
typedef pair <int, int> ii;

int a[5][5], b[5][5], c[18];

int main(){// freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int r=1; r<=T; r++){
		double c, f, x, p = 2.0, res, t = 0.0;
		scanf("%lf %lf %lf", &c, &f, &x);

		res = x/p;
		for(int i=1; i<=200000; i++){
			t = t + c/p;
			p = p + f;
			res = min( res, t + x/p );
			if( x < t ) 
				break;
		}
			
		
		printf("Case #%d: ", r);
		printf("%.10f\n", res);

	}

}