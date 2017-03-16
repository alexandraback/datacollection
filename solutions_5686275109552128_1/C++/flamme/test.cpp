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

int fenge[1100][1100];

int main()
{
	string shy;
	int t, smax;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		int result = -1;
		int d;
		int p[2000];
		cin >> d;
		int maxx = 0;
		for(int i = 0; i < d;i++){
			cin >> p[i];
			if(p[i] > maxx)
				maxx = p[i];
		}
		result = maxx;
		for(int i = 1; i < maxx; i++){
			int temp = i;
			for(int j = 0; j < d; j++){
				if(p[j] > i){
					temp = temp + (p[j] / i - (p[j] % i == 0));
				}
			}
			if (temp < result || result == -1){
				result = temp;
			}
		}
		cout << "Case #" << tt << ": " << result << endl;
	}
	return 0;
}