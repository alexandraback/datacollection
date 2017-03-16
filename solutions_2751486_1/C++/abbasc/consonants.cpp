#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
int nVal[1000000][2];

int main()
{
	freopen("conl.in","r",stdin);
	//freopen("con.txt","w", stdout);
	int t,x;
	cin>>t;
	for(x = 1; x <= t; x++)
	{
		string name,str;
		long long int n,value = 0,a = 0,i,left,right;
		int count = 0;
		cin>>name>>n;
		for(i = 0; i < name.length(); i++)
		{
			if(name[i] != 'a' && name[i] != 'e' && name[i] != 'i' && name[i] != 'o' && name[i] != 'u')
				count++;
			else count = 0;
			if(count == n)
			{
				nVal[a][0] = i - n + 1;
				nVal[a][1] = i;
				a++;
				count--;
			}
		}
		for(i = 0; i < a; i++)
		{
			right = name.length() - nVal[i][1];
			if(i > 0)
			{
				left = nVal[i][0] - nVal[i-1][0];
			}
			else left = nVal[i][0] + 1;
			value += left*right;
		}
		cout<<"Case #"<<x<<": "<<value<<endl;
	}
	return 0;
}
