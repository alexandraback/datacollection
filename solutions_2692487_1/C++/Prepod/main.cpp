#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
	ifstream inp("A-large.in");
	ofstream out("output.txt");
	cin.rdbuf(inp.rdbuf());
	cout.rdbuf(out.rdbuf());
	int t; cin>>t;
	for(int i=1;i<=t;i++){
		__int64 a;
		int n; cin>>a>>n;
		vector<int> ms(n);
		for(int j=0;j<n;j++)
			cin>>ms[j];
		sort(ms.begin(),ms.end());
		int res=n, add=0;
		for(int j=0;j<=n;j++){
			int b = add+n-j;
			res=min(res,b);
			if (j==n) break;
			if (a>ms[j]) a+=ms[j];
			else{
				if (a==1) break;
				a=2*a-1;
				add++; j--;
			}
		}
		cout<<"Case #"<<i<<": "<<res<<endl;
	}
	return 0;
}