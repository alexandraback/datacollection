#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <string>
#include <iostream>
#include <algorithm>

#include <vector>
#include <map>
#include <set>
#include <queue>

#define dbg(a) cout << a << endl

using namespace std;

char str[1000100], n;

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t;
	long long resp, size, rep, a, b, last;
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		printf("Case #%d: ", caso);
		scanf("%s", str);
		scanf("%d", &n);
		size = strlen(str);
		resp = 0;
		last = -1;
		rep = 0;

		for(int i = 0; i < size; i++){
			if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u'){
				rep++;
				if(rep >= n){
					b = i;
					a = i-n+1;
					resp += (a-last)*(size-b);
					last = a;
					//cout << a << " ---- " << b << endl;
					//cout << resp << endl;
				}
			}else{
				rep = 0;
			}
		}

		printf("%lld\n", resp);
	}

	return 0;
}
