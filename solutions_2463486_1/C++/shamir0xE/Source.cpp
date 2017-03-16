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
 
 const int maxn = 1000 * 1000 * 10 + 1;
 
 bool Is_pal(long long n){
	 long long number, i, nn;
	 number = 0;
	 nn = n;
	 while(nn > 0){
		number = number * 10 + nn % 10;
		nn /= 10;
	 }
	 if(number == n)
		 return true;
	 return false;
 }

 vector <long long> pal;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test, t, i, cnt;
	long long A, B;
	
	for(i = 1; i < maxn; i++)
		if(Is_pal(i) && Is_pal(i * 1ll * i))
			pal.push_back(i * 1ll * i);
	
	t = 0;
	cin >> test;
	while(test--){
		cin >> A >> B;
		cnt = 0;
		for(i = 0; i < pal.size(); i++)
			if(A <= pal[i] && B >= pal[i])
				cnt++;
		cout << "Case #" << ++t << ": " << cnt << endl;
	}
	
	return 0;
}

