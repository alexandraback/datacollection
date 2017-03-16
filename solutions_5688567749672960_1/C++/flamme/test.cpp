/*#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;


int main()
{
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		int r, c, n;
		cin >> r >> c >> n;
		int result = 0;
		if (r == 1){
			int temp1 = c / 2 + c % 2;
			if (temp1 >= n)
				cout << "Case #" << tt << ": " <<  0 << endl;
			else{
				for(int i = 0; i < c / 2 && temp1 < n; i++){
					result += 2;
					temp1++;
				}
				cout << "Case #" << tt << ": " <<  result << endl;
			}	
			continue;
		}
		if (c == 1){
			int temp1 = r / 2 + r % 2;
			if (temp1 >= n)
				cout << "Case #" << tt << ": " <<  0 << endl;
			else{
				for(int i = 0; i < r / 2 && temp1 < n; i++){
					result += 2;
					temp1++;
				}
				cout << "Case #" << tt << ": " <<  result << endl;
			}
			continue;
		}
		int sum = 0;
		int temp = 1;
		for(int i = 0; i < r; i++){
			sum += c / 2 ;
			if(temp == 1)
			{
				sum += c % 2;
				temp = 0;
			}
			else
				temp =  1;
		}
		if (sum >= n)
			cout << "Case #" << tt << ": " <<  0 << endl;
		else{
			int r1 = 0, c1 = 1;
			while(true){
				if(sum < n){
					result += 3;
					if ((r1 == 0 && c1 == c - 1) || (r1 == r - 1 && c1 == 0) || (r1 == r - 1 && c1 == c - 1))
						result--;
					sum++;
					c1 += 2;
					if (c1 >= c){
						r1++;
						c1 = (c1 - 1) / c;
					}
				}
				else{
					break;
				}
			}
			cout << "Case #" << tt << ": " << result << endl;
		}
	}
	return 0;
}
*/


#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

map<long long, int> mymap;

long long reverse(long long  k){
	long long temp = 0;
	while(k > 0){
		temp = temp * 10 + k % 10;
		k = k / 10;
	}
	return temp;
}

long long calc(long long k){
	if(k <= 10)
		return k;
	long long weishu = 0;
	long long temp = k;
	while(temp >0 ){
		weishu++;
		temp = temp / 10;
	}
	long long tenTimes = 1;
	for(int i = 0; i < (weishu + 1) / 2; i++)
		tenTimes *= 10;
	long long k1 = k / tenTimes, k2 = k % tenTimes;
	if (k2 == 0)
		return calc(k - 1) + 1;
	
	long long temp1 = 1;
	for(int i = 0; i < weishu - 1; i++)
		temp1 *= 10;
	return mymap[temp1] + min(k - temp1, reverse(k1) + k2);
}

int main()
{
	int t;
	cin >> t;
	long long temp[] ={1, 10, 29,138,337,1436,3435,14434,34433,144432,344431,1444430,3444429,14444428,34444427};
	long long tmp = 1;
	for(int i = 0; i <= 14; i++){
		mymap[tmp] = temp[i];
		tmp *= 10;
	}
	for(int tt = 1; tt <= t; tt++){
		long long result;
		long long n;
		cin >> n;
		cout << "Case #" << tt << ": " << calc(n) << endl;
	}
	return 0;
}