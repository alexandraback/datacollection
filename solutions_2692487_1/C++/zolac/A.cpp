#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef unsigned long long ul;

int main(){
	int N ; 
	cin>> N;

	for(int T = 1 ; T <= N ; T++) {
		int ret = 0;
		int a, n;
		cin>> a>>n;

		vector<int> m(n) ; 
		for(int i = 0 ;i < n ; i++)
			cin >> m[i] ; 

		ret = n;
		if( a== 1) {
			ret = n;
		}
		else {
			int temp = 0;
			sort(m.begin(), m.end());
			for(int i = 0 ; i < n ; i++) {
				if( a > m[i] ) a+= m[i] ; 
				else {
					a = a + (a-1);
					if( a<= m[i]) {
						ret = min(ret, temp + (n-i));
					}
					temp++; 
					i--;
				}
			}
			ret = min(ret, temp);
		}
		cout<<"Case #"<<T<<": "<<ret<<endl;
	}
	return 0;
}