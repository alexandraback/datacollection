#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define size = 10001
double ms[1000][1000];

int main(){
	ms[0][0]=1.0;
	for(int i=1;i<=1000;i++){
		ms[i][0]=1.0;
		for(int j=1;j<=i;j++)
			ms[i][j]=(ms[i-1][j-1]+ms[i-1][j])/2.0;
	}

	ifstream inp("B-small-attempt1.in");
	ofstream out("output.txt");
	cin.rdbuf(inp.rdbuf());
	cout.rdbuf(out.rdbuf());
	int t; cin>>t;
	for(int i=1;i<=t;i++){
		double res=0.0;
		int n; cin>>n;
		int x,y; cin>>x>>y;
		int a=1, b=1;
		while(n>=a){
			b+=2;
			a+=2*b-1;
		}
		a-=(2*b-1); b-=2;
		if (b<y) {res=0.0; goto end;} 
		int c = b-y+1;
		if (abs(x)<c) {res=1.0;goto end;}
		if (abs(x)>c) {res=0.0; goto end;}
		n-=a;
		res=ms[n][y+1];
end:
		cout<<"Case #"<<i<<": "<<res<<endl;
	}
	return 0;
}