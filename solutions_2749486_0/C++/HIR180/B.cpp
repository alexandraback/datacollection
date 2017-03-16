//Waai GCJR1C Akari GCJR1C Daisuki
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int main(){
	int t;
	cin >> t;
	for(int q=1;q<=t;q++)
	{
		string ret="";
		int x,y;
		cin >> x >> y;
		int X=abs(x);
		int Y=abs(y);
		for(int i=1;i<=X;i++)
		{
			if(x<0)
			{
				ret+="EW";
			}
			else
			{
				ret+="WE";
			}
		}
		for(int i=1;i<=Y;i++)
		{
			if(y<0)
			{
				ret+="NS";
			}
			else
			{
				ret+="SN";
			}
		}
		printf("Case #%d: ",q);
		cout << ret << endl;
	}
}