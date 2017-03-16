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
map<int,int> ma;
map<int,int>::iterator it;
int main(void){
	ifstream cin("B-small-attempt0.in");
	ofstream cout("output.txt");
	std::ios::sync_with_stdio(false);cin.tie(0);
	int t,T;
	int i,j,n;
	int x;
	cin>>T;
	for(t=1;t<=T;t++)
	{
		cin>>n;
		ma.clear();
		for(i=0;i<2*n-1;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>x;
				ma[x]++;
			}
		}
		cout<<"Case #"<<t<<":";
		for(it=ma.begin();it!=ma.end();++it)
		{
			if(it->second%2==1)
				cout<<' '<<it->first;
		}
		cout<<'\n';
	}
	system("pause");
	return 0;
}