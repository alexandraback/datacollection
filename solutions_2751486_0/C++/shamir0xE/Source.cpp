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
 const long long maxn = 1000 * 1000 + 100, MOD = 1000 * 1000 * 1000 + 7;
 

 long long sum[maxn];
 char vow[] = {'a', 'e', 'i', 'o', 'u'};

 void Make_sum(string str){
	long long i, temp, j;
	temp = 0;
	bool flag;
	
	for(i = str.size() - 1; i >= 0; i--){
		flag = false;
		for(j = 0; j < 5; j++)
			if(vow[j] == str[i])
				flag = true;
		if(!flag)
			temp++;
		else
			temp = 0;
		sum[i] = temp;
	}


 }


 long long Count(long long n, string str){
	 long long ans, l, b, e;
	 ans = 0;
	 l = str.size();
	 e = 0;
	 for(b = 0; b < str.size(); b++)
	 {
		 e = max(e, b);
		 while(e < str.size() && sum[e] < n)
			 e++;

		 if(sum[e] >= n)
			 ans += (l - e + 1 - n);
	 }

	 return ans;
 }

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long t, n, test;
	string str;

	cin >> test;
	t = 0;
	while(test--){
		cin >> str >> n;
		memset(sum, 0, sizeof sum);
		Make_sum(str);
		cout << "Case #" << ++t << ": " << Count(n, str) << endl;
	}

	
	
	return 0;
}

