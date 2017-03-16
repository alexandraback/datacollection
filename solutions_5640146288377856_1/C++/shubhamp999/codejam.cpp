#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<fstream>
#include<cstring>
#include<stack>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#define ll long long int
using namespace std;
int main()
{
	ifstream cin;
	ofstream cout;
	cin.open("C:\\Users\\Admin\\Downloads\\14.in");
	cout.open("C:\\Users\\Admin\\Downloads\\out.txt");
	int t,x=1;
	cin>>t;
	while(t--){
		int r,c,w,ans;
		cin>>r>>c>>w;
		ans=c/w*r;
		ans+=w-1;
		if(c%w!=0)
			ans++;
		cout<<"Case #"<<x++<<": "<<ans<<endl;
	}
	
	return 0;
} 