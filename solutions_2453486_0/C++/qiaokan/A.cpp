#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <sstream>
using namespace std ;
string st[4] ;
bool check(char ch)
{
	int sum1,sum2 ;
	for (int i=0;i<4;i++)
	{
		sum1 = 0 ;
		sum2 = 0 ;
		for (int j=0;j<4;j++)
		{
			if (st[i][j]==ch) sum1++ ;
			if (st[i][j]=='T') sum2++ ;
		}
		if (sum1==3&&sum2==1) return 1 ;
		if (sum1==4) return 1 ;
	}
	for (int j=0;j<4;j++)
	{
		sum1 = 0 ;
		sum2 = 0 ;
		for (int i=0;i<4;i++)
		{
			if (st[i][j]==ch) sum1++ ;
			if (st[i][j]=='T') sum2++ ;
		}
		if (sum1==3&&sum2==1) return 1 ;
		if (sum1==4) return 1 ;
	}
	sum1 = sum2 = 0 ;
	for (int i=0;i<4;i++)
	{
		if (st[i][i]==ch) sum1++ ;
		if (st[i][i]=='T') sum2++ ;
	}
	if (sum1==3&&sum2==1) return 1 ;
	if (sum1==4) return 1 ;
	sum1 = sum2 = 0 ;
	for (int i=0;i<4;i++)
	{
		int j = 3 - i ;
		if (st[i][j]==ch) sum1++ ;
		if (st[i][j]=='T') sum2++ ;	
	}
	//cout<<sum1<<" "<<sum2<<endl ;
	if (sum1==3&&sum2==1) return 1 ;
	if (sum1==4) return 1 ;
	return 0 ;
	
}
int main()
{
	int cs ;
	cin>>cs ;
	for (int t=1;t<=cs;t++)
	{
		cout<<"Case #"<<t<<": " ;
		for (int i=0;i<4;i++)
			cin>>st[i] ;

		bool resx = check('X') ;
		bool reso = check('O') ;
		if (resx)
		{
			cout<<"X won"<<endl ;
			continue ;
		}
		if (reso)
		{
			cout<<"O won"<<endl ;
			continue ;
		}
		bool flag = true ;
		for (int i=0;i<4;i++)
			for (int j=0;j<4;j++)
				if (st[i][j]=='.')
				{
					flag = false ;
					break ;
				}
		if (!flag)
		{
			cout<<"Game has not completed"<<endl ;
			continue ;
		}
		cout<<"Draw"<<endl ;
	}
}