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

map< pair<string, string> , string> product;

void set_table(){
	string rowStrings[8] = {"-1","1","i","j","k","-i","-j","-k"};
	string colStrings[3] = {"i","j","k"};
	string table[8][3] = {
		{"-i","-j","-k"},
		{"i","j","k"},
		{"-1","k","-j"},
		{"-k","-1","i"},
		{"j","-i","-1"},
		{"1","-k","j"},
		{"k","1","-i"},
		{"-j","i","1"}
	};
	for(int i=0;i<8;i++)
		for(int j=0;j<3;j++)
			product[make_pair(rowStrings[i],colStrings[j])] = table[i][j];
}

int main(){
	ios::sync_with_stdio(false);
	freopen("gcj3.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,c=1, n , x, i;
	string str,str2;
	cin>>t;
	set_table();
	while(t--){
		cout<<"Case #"<<c++<<": ";
		cin>>n>>x>>str;
		str2="";
		for(i=0;i<n*x;i++)
			str2 += str[i%n];
		string val="1";
		//find first i
		for(i=0;i<n*x-2;i++)
		{
			val = product[make_pair(val, string(1,str2[i]))];
			if(val == "i")
				break;
		}

		if(val != "i"){
			cout<<"NO\n";
			continue;
		}
	
		for(i++;i<n*x-1;i++)
		{
			val = product[make_pair(val, string(1,str2[i]))];
			if(val == "k")
				break;
		}

		if(val != "k"){
			cout<<"NO\n";
			continue;
		}

		for(i++;i<n*x;i++)
		{
			val = product[make_pair(val, string(1,str2[i]))];
		}

		if(val != "-1")
			cout<<"NO\n";
		
		else cout<<"YES\n";

	}

	return 0;
}