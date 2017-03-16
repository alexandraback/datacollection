#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
using namespace std;

void f(int a[10]){
	cout << sizeof(a) << endl;
}

int main()
{
	string shy;
	int t, smax;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> smax;
		cin >> shy;
		int need = 0;
		int nowPerson= 0;
		for(int j = 0; j <= smax; j++){
			int shyPerson = shy[j] - '0';
			if (shyPerson > 0){
				if(nowPerson >= j){
					nowPerson = nowPerson + shyPerson;
				}
				else{
					need = need + (j - nowPerson);
					nowPerson = nowPerson + (j - nowPerson);
					nowPerson = nowPerson + shyPerson;
				}
			}
		}
		cout << "Case #" << i << ": " << need << endl;
	}
	return 0;
}