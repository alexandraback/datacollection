#include<iostream>	
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cassert>
using namespace std;

int main()
{
	int tc,l,i,j;
	string str;
	map<char,char> mymap;
	mymap['a']='y';mymap['b']='h';mymap['c']='e';mymap['d']='s';mymap['e']='o';mymap['f']='c';mymap['g']='v';mymap['h']='x';mymap['i']='d';mymap['j']='u';mymap['k']='i';
	mymap['l']='g';mymap['m']='l';mymap['n']='b';mymap['o']='k';mymap['p']='r';mymap['q']='z';mymap['r']='t';mymap['s']='n';mymap['t']='w';mymap['u']='j';mymap['v']='p';
	mymap['w']='f';mymap['x']='m';mymap['y']='a';mymap['z']='q';
	scanf("%d\n",&tc);
	for(j=0;j<tc;j++)
	{
		getline(cin,str);
		l=str.size();
		for(i=0;i<l;i++)
		{
			if(mymap.find(str[i])!=mymap.end())
				str[i]=mymap[str[i]];
		}
		printf("Case #%d: ",j+1);
		cout<<str<<endl;
	}
	return 0;
}
