#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

long long solve(int A, int B)
{
	int res = 0;
	for(int n=A ; n<=B ; n++) {
		char str[20];
		sprintf(str,"%d",n);
		string s = string(str);
		
		set<int> done;
		int  l = (int)s.size()-1;
		for(int i=l ; i>=1 ; i--) {
			string t = s.substr(i) + s.substr(0,i);
			
			if(t[0] == '0') continue;

			int m = atoi(t.c_str());
			if(m>n && m>=A && m<=B && !done.count(m)) {
				done.insert(m);
				res++;
			}
		}
	}
	return res;
}

int main()
{
	int Te;
	cin >> Te;
	for(int te=1 ; te<=Te ; te++) {
		int A,B;
		cin >> A >> B;
		cout << "Case #" << te << ": " << solve(A,B) << endl;
	}
}
