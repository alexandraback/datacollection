#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<string.h>
#include<fstream>
using namespace std;
int to_num(string s)
{
	int k=0,f=1;
	for(int i=s.length()-1;i>=0;i--)
	{
		k+=(s[i]-'0'*f);
		f*=10;
	}
	return k;
}
int result(int cX,int cO,int cT)
{
    if(cX+cT==4)
	{
		return 1;
	}
	else if(cO+cT==4)
	{
		return 2;
	}
	else
	return -1;
}
int main()
{
    freopen ("A-small.in", "rt", stdin);
    freopen ("output_3.txt", "wt", stdout);
    ifstream f;
    f.open ("A-small.in");
    ofstream ff;
	
	int test;
	cin>>test;
	//t++;
	int g=0;
	//scanf("%d",&g);
	
	ff.open ("output_3.txt");
	//cout<<test<<endl;
	for(int ii=1;ii<=test;ii++)
	{
		//cout<<ii<<endl;
		
		printf("Case #%d: ",ii);
		string arr[4];
		bool final=true;
		for(int i=0;i<4;i++)
		{
            cin>>arr[i];
			for(int j=0;j<4;j++)
			{
				if(arr[i][j]=='.')
				final=false;
			}
		}
		
		int flag=0;
		int cX=0,cO=0,cT=0;
		for(int i=0;i<4;i++)
		{
			cX=0,cO=0,cT=0;
			for(int j=0;j<4;j++)
			{
				if(arr[i][j]=='X')
				cX++;
				else if(arr[i][j]=='O')
				cO++;
				else if(arr[i][j]=='T')
				cT++;
			}
			if(result(cX,cO,cT)==1)
			{
				flag=1;
				printf("X won\n");
				break;
			}
			else if(result(cX,cO,cT)==2)
			{
				flag=1;
				printf("O won\n");
				break;
			}
		}
		if(flag==1)
		continue;
		for(int i=0;i<4;i++)
		{
			cX=0,cO=0,cT=0;
			for(int j=0;j<4;j++)
			{
				if(arr[j][i]=='X')
				cX++;
				else if(arr[j][i]=='O')
				cO++;
				else if(arr[j][i]=='T')
				cT++;
			}
			if(result(cX,cO,cT)==1)
			{
				flag=1;
				printf("X won\n");
				break;
			}
			else if(result(cX,cO,cT)==2)
			{
				flag=1;
				printf("O won\n");
				break;
			}
		}
		if(flag==1)
		continue;
		cX=0,cO=0,cT=0;
		for(int i=0;i<4;i++)
		{
				if(arr[i][i]=='X')
				cX++;
				else if(arr[i][i]=='O')
				cO++;
				else if(arr[i][i]=='T')
				cT++;
		}
		if(result(cX,cO,cT)==1)
		{
				flag=1;
				printf("X won\n");
				
		}
		else if(result(cX,cO,cT)==2)
		{
				flag=1;
				printf("O won\n");
				
		}
		if(flag==1)
		continue;
		cX=0,cO=0,cT=0;
		for(int i=3,j=0;i>=0,j<4;i--,j++)
		{
            	if(arr[i][j]=='X')
				cX++;
				else if(arr[i][j]=='O')
				cO++;
				else if(arr[i][j]=='T')
				cT++;
		}
        if(result(cX,cO,cT)==1)
		{
				flag=1;
				printf("X won\n");
				
		}
		else if(result(cX,cO,cT)==2)
		{
				flag=1;
				printf("O won\n");
				
		}
		if(flag==1)
		continue;
		if(final==true)
		{
			printf("Draw\n");
		}
		else
		{
			printf("Game has not completed\n");
		}
	}
	//system("pause");
	return 0;
}




