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
#include <stack>
using namespace std;

/*int f1[30], f2[30];
string temp1, temp2;
bool canGet(int s){
	if(s < temp2.length())
		return false;
	for(int i = 0; i < 30; i++){
		if (f2[i] > 0 && f1[i] == 0)
			return false;
	}
	return true;
}

double maxGet(int s){
	double r = 1;
	vector<char> c;
	for(int i = 0; i < temp2.length(); i++){
		c.push_back(temp2[i]);
	}
	int idx = 1;
	while(idx + temp2.length() <= s){
		int si = 0;
		int tmp = idx;
		int num = 0;
		while(tmp < c.size()){
			if(c[tmp] == temp2[si]){
				num++;
				tmp++;
			}
			else
				break;
		}
		if (num == temp2.length()){
			r = r + 1;
			idx += 1;
		}
		else if (num == c.size() - idx){
			r+= 1;
			for(int i = num; i < temp2.length() && c.size() <= s; i++){
				c.push_back(temp2[i]);
			}
			idx += 1;
		}
		else{
			idx++;
		}
	}
	return r;
}

int main()
{
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		int k, l, s;
		cin >> k >> l >> s;
		memset(f1, 0, sizeof(int) * 30);
		memset(f2, 0, sizeof(int) * 30);
		double result = 0;
		cin >> temp1 >> temp2;
		for(int i = 0; i < temp1.length(); i++)
			f1[temp1[i] - 'A']++;
		for(int i = 0; i < temp2.length(); i++)
			f2[temp2[i] -  'A']++;
		if(!canGet(s)){
			cout << "Case #" << tt << ": " << result << endl;
		}
		


		cout << "Case #" << tt << ": ";
		printf("%.8lf\n", result);
	}
	return 0;
}*/


int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		int result = 0;
		int c, d, v;
		cin >> c >> d >> v;
		bool a[1000];
		memset(a, false, 1000 * sizeof(bool));
		a[0] = true;
		for(int i = 0; i < d; i++){
			int temp;
			cin >> temp;
			for(int j = v; j >= temp; --j){
				a[j] = a[j] || a[j-temp];
			}
		}
		for(int i = 0; i <=v; i++){
			if(!a[i]){
				int temp = i;
				for(int j = v; j >= temp; --j){
					a[j] = a[j] || a[j-temp];
				}
				result++;
			}
		}
		cout << "Case #" << i << ": "  << result << endl;
	}
	return 0;
}