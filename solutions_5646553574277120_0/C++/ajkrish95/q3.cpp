#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<stack>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<sstream>
#include<climits>
using namespace std;

long long int a[1000], b[1000], c[1000];

int main()
{
	std::ios::sync_with_stdio(false); 
	
	long long int n, i, j, k, l ,t, ct = 0, y, q = 0, d, v, temp, flag,sum;
	
	cin>>t;
	
	while(t--)
	{
		cin>>n>>d>>v;
		++q;
		
		for(i= 0 ; i< 1000;i++)
		{
			a[i] = b[i] = c[i] = 0;
		}
		
		for(i = 0; i < d; i++)
		{
			cin>>a[i];
		}
		
	//	cout<<(1<<d)<<"\n";
		for(i = 0; i < (1<<d); i++)
		{
			temp = i;
			j = 0;
			
			sum = 0;
			
			while(temp != 0)
			{
				b[j] = temp%2;
				temp = temp/2;
			
				sum = sum + b[j]*a[j];
				++j;
			}
			
			c[sum] = 1;
		}	
		
		ct = 0;
		
		while(1)
		{
			flag = 1;
			
			for(k = 1; k <= v; k++)
			{
				if(c[k] == 0)
				{
					a[d] = k;
					d++;
					ct++;
					flag = 0;
					break;
				}
			}
			
			if(flag == 1)
			{
				break;
			}
		
			for(i = 0; i < (1<<d); i++)
			{
				temp = i;
				j = 0;
				
				sum = 0;
				
				while(temp != 0)
				{
					b[j] = temp%2;
					temp = temp/2;
				
					sum = sum + b[j]*a[j];
					++j;

				}
				
				c[sum] = 1;
			}			
		}
		
		cout<<"Case #"<<q<<": "<<ct<<"\n";	
	}
	
	return 0;
}
