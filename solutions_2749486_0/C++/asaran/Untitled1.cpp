#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
//#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int main()
{
	int t,k=1;
	string str = "";
	freopen("a.in","r",stdin);
	freopen("bb.txt","w",stdout);
	cin>>t;
	while(k <= t)
	{
		str = "";
		long long x,y;
		cin>>x>>y;
		string s1 = "WE";
		string s2 = "SN";
		
		if(x <0){
			x *= -1;
			s1 = "EW";
		}
		if(y <0){
			y *= -1;
			s2 = "NS";
		}
		for(int i = 1; i<=x; i++){
			str += s1;
		}
			
		for(int i = 1; i<=y; i++){
			str += s2;
		}
			
		cout<<"Case #"<<k<<": "<<str<<endl;
		k++;
	}
}
