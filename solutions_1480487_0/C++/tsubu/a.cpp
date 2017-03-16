#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int T;
	cin >> T;
	int t = 0;
	while(t++ < T){
		int n;
		cin >> n;
		int s[200];
		int sum = 0;
		for(int i = 0; i < n;i++){
			cin >> s[i];
			sum += s[i];
		}
		cout << "Case #" << t << ":";
		for(int i = 0; i < n; i++){
			long long xu = 100000000;
			long long xd = 0;
			while(xu-xd > 1){
				long long x = (xu+xd)/2;
				long long yi = (long long)s[i]*100000000+x*sum;
				long long sumx = 0;
				for(int j = 0; j < n; j++){
					if(i != j){
						sumx += max((long long)0,yi-(long long)s[j]*100000000);
					}
				}
				if(sumx+x*sum > (long long)sum*100000000) xu = x;
				else xd = x;
			}
			printf(" %.6f",(double)xu/1000000);
		}
		cout << endl;
	}
}
