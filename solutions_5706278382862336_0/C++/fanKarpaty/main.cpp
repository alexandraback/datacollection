#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x > y ? y : x)

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int T;
	cin>>T;
	
	
	for (int idx = 1; idx <= T; idx++) {
		string s;
		int ans =  1000000;
		cin>>s;
		long long a =0, b=0;
		int id =0;
		while(s[id] != '/') {
			a*=10;
			a+= s[id]-'0';
			id++;
		}
		id++;
		while(id < s.length()) {
			b*=10;
			b+= s[id]-'0';
			id++;
		}
		
		for (long long x = 2; x*x <= b; x++) {
			while (a%x == 0 && b%x== 0) { a/=x; b/=x;}
		}

		if ((b & (b-1)) == 0) {
			ans = 1;
			while (a*2 < b){b/=2;ans++;}
		}
		cout<<"Case #"<<idx<<": ";
		if(ans<10000)cout<<ans;
		else cout<<"impossible";
		cout<<endl;
	}
	return 0;
}