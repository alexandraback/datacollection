#include <iostream>
#include <map>
#include <stdio.h>
#include <set>
#include <stack>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <sstream>
#include <list>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;
/**
 * @author:	Shamir14 -- Amirhossein Shapoori
 * lordamir14@gmail.com
 * ACM team: AnotherChorMangz
 * Tehran, Iran
 * Still listening to Mark Knopfler...
 * :P
 */
 typedef long long lli;
 const int maxn = 300 + 10, MOD = 1000 * 1000 * 1000 + 7;
 
 int mote[maxn];

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, test, t, A, N, mini, sum, cur;

	cin >> test;
	t = 0;
	while(test--){
		cin >> A >> N;
		for(i = 0; i < N; i++)
			cin >> mote[i];
		sort(mote, mote + N);


		mini = N;
		if(A != 1){
			sum = 0;
			for(i = 0; i < N; i++){
				//mini = min(N - i, mini);
				while(A <= mote[i] && (A - 1)){
					A += A - 1;
					sum++;
				}
				if(A > mote[i])
					A += mote[i];
				mini = min(mini, sum + N - i - 1);
			}
		}
		cout << "Case #" << ++t << ": " << mini << endl;
	}

	
	return 0;
}

