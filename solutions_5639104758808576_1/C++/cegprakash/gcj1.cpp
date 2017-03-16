#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <sstream>
#include <set>
#include <cstring>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false);

	freopen("gcj1.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t,c=1;
	cin>>t;

	int maxx,i,standing,extra;
	string s;
	while(t--){
		cout<<"Case #"<<c++<<": ";
		cin>>maxx>>s;
		standing = extra = 0;
		for(i=0;i<=maxx;i++){
			if(s[i]-'0' != 0 && standing + extra < i)
				extra += i - (standing+extra);
			standing += s[i]-'0';
		}
		cout<<extra<<endl;
	}

	return 0;
}