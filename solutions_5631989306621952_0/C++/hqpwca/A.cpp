#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <queue>
#include <functional>
#include <list>
#include <set>
#include <sstream>
#define ll long long

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	//while(cin>>n)

	int T;
	cin>>T;
	for(int cas=1;cas<=T;cas++)
	{
		string s,t;
		cin>>s;

		t+=s[0];
		for(int i=1;i<s.size();i++)
		{
			if(s[i]>=t[0])t=s[i]+t;
			else t=t+s[i];
		}

		cout<<"Case #"<<cas<<": "<<t<<endl;;
		//cout<<"Case "<<cas<<": ";
	}

	return 0;
}
