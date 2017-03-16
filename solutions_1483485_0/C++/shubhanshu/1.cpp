
#include<malloc.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<cstring>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

char db[255];

int main()
{
	db['y']='a';
	db['n']='b';
	db['f']='c';
	db['i']='d';
	db['c']='e';
	db['w']='f';
	db['l']='g';
	db['b']='h';
	db['k']='i';
	db['u']='j';
	db['o']='k';
	db['m']='l';
	db['x']='m';
	db['s']='n';
	db['e']='o';
	db['v']='p';
	db['z']='q';
	db['p']='r';
	db['d']='s';
	db['r']='t';
	db['j']='u';
	db['g']='v';
	db['t']='w';
	db['h']='x';
	db['a']='y';
	db['q']='z';
	db[' ']=' ';
	int t;
	cin>>t;
		char arr[1000],c;
		scanf("%c",&c);
	rep(i,t)
	{
		cout<<"Case #"<<i+1<<": ";
		scanf("%[^\n]%c",arr,&c);
		int len=strlen(arr);
		rep(j,len)
		{
			cout<<db[arr[j]];	
		}
		cout<<endl;
	}
	return 0;
}
