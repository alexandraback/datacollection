#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include<iomanip>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <bitset>
using namespace std;
#define MOD 1000000007
string s;
string re,temp;
int main(void){
	ifstream cin("A-large.in");
	ofstream cout("output.txt");
	std::ios::sync_with_stdio(false);cin.tie(0);
	int t,T;
	int i,n;
	cin>>T;
	for(t=1;t<=T;t++)
	{
		cin>>s;
		cout<<"Case #"<<t<<": ";
		n=s.size();
		re=s[0];
		for(i=1;i<n;i++)
		{
			re=max(re+s[i],s[i]+re);
		}
		cout<<re;
		cout<<'\n';
	}
	system("pause");
	return 0;
}