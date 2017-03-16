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

char str[1010], n;

bool teste(int a, int b){
	int rep = 0, maxi = -1;;
	for(int i = a; i < b; i++){
		if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u'){
			rep++;
			maxi = max(maxi, rep);
			if(maxi >= n){
				return true;
			}
		}else{
			rep = 0;
		}
	}

	return false;
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t, size, resp;
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		printf("Case #%d: ", caso);
		scanf("%s", str);
		scanf("%d", &n);
		size = strlen(str);
		resp = 0;

		for(int i = 0; i < size; i++){
			for(int j = i+n; j <= size; j++){
				if(teste(i, j)){
					resp++;
				}
			}
		}

		printf("%d\n", resp);
	}

	return 0;
}
