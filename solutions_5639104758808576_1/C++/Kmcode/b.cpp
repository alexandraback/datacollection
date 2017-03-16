#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
#include<valarray>
using namespace std;
int t;
int main(){
	scanf("%d", &t);
	int r = 0;
	while (t--){
		r++;
		int n;
		scanf("%d", &n);
		int wait = 0;
		int countt = 0;
		int stoo = 0;
		bool ok = false;
		string s;
		cin >> s;
		for (int i = 0; i < n + 1; i++){
			int a;
			//scanf("%d", &a);
			a = s[i] - '0';
			if (a){
				ok = true;
				if (i > stoo){
					countt += i - stoo;
					stoo = i;
				}
				stoo += a;
			}
		}
		printf("Case #%d: ", r);
		if (ok){
			printf("%d\n", countt);
		}
		else{
			printf("%d\n", 1);
		}
	}
	return 0;
}