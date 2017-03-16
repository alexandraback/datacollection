#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <cassert>
#define MAX 1123456

using namespace std;

typedef long long ll;

string s;
int n, L;

int main(){
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++){
		cin >> s;
		scanf("%d", &n);
		bool eh[MAX];
		for(int i = 0; i < MAX; i++)
			eh[i] = false;
		L = (int)s.size();
		int b = 0;
		for(int i = 0; i < L; i++){
			if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u'){
				if(i-b+1 >= n){
					eh[b] = true;
					b++;
				}
			}
			else
				b = i+1;
		}
		b = 0;
		ll r = 0;
		for(int i = 0; i < L; i++){
			if(eh[i]){
				ll pr = r;
				r += (ll)(i-b+1LL)*((ll)L-(i+n-1));
				assert(pr <= r);
				b = i+1;
			}
		}
		printf("Case #%d: %lld\n", t, r);
	}
	return 0;
}
