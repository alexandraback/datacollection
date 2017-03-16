/*
ID: xiaoche4
PROG: skidesign
LANG: C++
*/
//#include "TC.cpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int T,S;
string s;
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("Ans.out","w",stdout);
	//ifstream fin("dict.out");
	//ofstream fout("Ans.out");
	//FILE *fin=fopen("table.txt","r");
	//FILE *fout=fopen("Ans.out","w");
	cin>>T;
	for(int k=1;k<=T;k++){
		cin>>S>>s;
		int ans=0,tot=s[0]-'0';
		for(int i=1;i<s.length();i++){
			if(tot>=i)
				tot+=s[i]-'0';
			else{
				ans+=i-tot;
				tot=i;
				tot+=s[i]-'0';
			}
		}
		cout<<"Case #"<<k<<": "<<ans<<endl;
	}

	return 0;
}