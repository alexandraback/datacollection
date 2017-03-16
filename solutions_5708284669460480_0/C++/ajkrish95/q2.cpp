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
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<cmath>
#include<iomanip>
#include<climits>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); 
	
	long long int n, i, j, k, l ,t, ct = 0, y, q,a1,a2,a3,a4,a5,a6,a7,s1,m,flag,total,maxi,temp;
	long double ans;
	string a,b,s;
	
	cin>>t;
	q = 0;
	while(t--)
	{
		++q;
		cin>>k>>l>>s1;
		
		cin>>a;
		cin>>b;
		
//		cout<<a[0]<<endl;
//		cout<<a<<" "<<b<<endl;

		ct = 0;
		s = "";
		maxi = 0;
		
		if(s1 == 7)
		{
			for(a1 = 0; a1 < k; a1++)
			for(a2 = 0; a2 < k; a2++)
			for(a3 = 0; a3 < k; a3++)
			for(a4 = 0; a4 < k; a4++)
			for(a5 = 0; a5 < k; a5++)
			for(a6 = 0; a6 < k; a6++)
			for(a7 = 0; a7 < k; a7++)
			{
				s = "";
				s = s + a[a1] + a[a2] + a[a3] + a[a4] + a[a5] + a[a6] + a[a7];
				
				temp = 0;
				
				for(i = 0; i <= s1 - l; i++)
				{
					m = 0;
					flag = 1;
			
					for(j = i; ;j++)
					{
						if(s[j] != b[m])
						{
							flag = 0;
							break;
						}
						
						++m;
						
						if(m == l)
						{
							break;
						}
					}
					
					if(flag == 1)
					{
						ct++;
						temp++;
					}
				}
				
				if(maxi < temp)
				{
					maxi = temp;
				}
			}			
			
			total = pow(k, s1);
			ans = ct;
			
			ans = ct/total;
		}

		if(s1 == 6)
		{
			for(a1 = 0; a1 < k; a1++)
			for(a2 = 0; a2 < k; a2++)
			for(a3 = 0; a3 < k; a3++)
			for(a4 = 0; a4 < k; a4++)
			for(a5 = 0; a5 < k; a5++)
			for(a6 = 0; a6 < k; a6++)
			{
				s = "";
				s = s + a[a1] + a[a2] + a[a3] + a[a4] + a[a5] + a[a6];
				
				temp = 0;
				
				for(i = 0; i <= s1 - l; i++)
				{
					m = 0;
					flag = 1;
			
					for(j = i; ;j++)
					{
						if(s[j] != b[m])
						{
							flag = 0;
							break;
						}
						
						++m;
						
						if(m == l)
						{
							break;
						}
					}
					
					if(flag == 1)
					{
						ct++;
						temp++;
					}
				}
				
				if(maxi < temp)
				{
					maxi = temp;
				}
			}			
			
			total = pow(k, s1);
			ans = ct;
			
			ans = ct/total;
		}

		if(s1 == 5)
		{
			for(a1 = 0; a1 < k; a1++)
			for(a2 = 0; a2 < k; a2++)
			for(a3 = 0; a3 < k; a3++)
			for(a4 = 0; a4 < k; a4++)
			for(a5 = 0; a5 < k; a5++)
			{
				s = "";
				s = s + a[a1] + a[a2] + a[a3] + a[a4] + a[a5];
				
				temp = 0;
				
				for(i = 0; i <= s1 - l; i++)
				{
					m = 0;
					flag = 1;
			
					for(j = i; ;j++)
					{
						if(s[j] != b[m])
						{
							flag = 0;
							break;
						}
						
						++m;
						
						if(m == l)
						{
							break;
						}
					}
					
					if(flag == 1)
					{
						ct++;
						temp++;
					}
				}
				
				if(maxi < temp)
				{
					maxi = temp;
				}
			}			
			
			total = pow(k, s1);
			ans = ct;
			
			ans = ct/total;
		}

		if(s1 == 4)
		{
			for(a1 = 0; a1 < k; a1++)
			for(a2 = 0; a2 < k; a2++)
			for(a3 = 0; a3 < k; a3++)
			for(a4 = 0; a4 < k; a4++)
			{
				s = "";
				s = s + a[a1] + a[a2] + a[a3] + a[a4];
				
				temp = 0;
				
				for(i = 0; i <= s1 - l; i++)
				{
					m = 0;
					flag = 1;
			
					for(j = i; ;j++)
					{
						if(s[j] != b[m])
						{
							flag = 0;
							break;
						}
						
						++m;
						
						if(m == l)
						{
							break;
						}
					}
					
					if(flag == 1)
					{
						ct++;
						temp++;
					}
				}
				
				if(maxi < temp)
				{
					maxi = temp;
				}
			}			
			
			total = pow(k, s1);
			ans = ct;
			
			ans = ct/total;
		}

		if(s1 == 3)
		{
			for(a1 = 0; a1 < k; a1++)
			for(a2 = 0; a2 < k; a2++)
			for(a3 = 0; a3 < k; a3++)
			{
				s = "";
				s = s + a[a1] + a[a2] + a[a3];
				
				temp = 0;
				
				for(i = 0; i <= s1 - l; i++)
				{
					m = 0;
					flag = 1;
			
					for(j = i; ;j++)
					{
						if(s[j] != b[m])
						{
							flag = 0;
							break;
						}
						
						++m;
						
						if(m == l)
						{
							break;
						}
					}
					
					if(flag == 1)
					{
						ct++;
						temp++;
					}
				}
				
				if(maxi < temp)
				{
					maxi = temp;
				}
			}			
			
			total = pow(k, s1);
			ans = ct;
			
			ans = ct/total;
		}		

		if(s1 == 2)
		{
			for(a1 = 0; a1 < k; a1++)
			for(a2 = 0; a2 < k; a2++)
			{
//				cout<<a1<<" "<<a2<<endl;
				s = "";
				s = s + a[a1] + a[a2];
				
//				cout<<s<<"\n";
				temp = 0;
				
				for(i = 0; i <= s1 - l; i++)
				{
					m = 0;
					flag = 1;
			
					for(j = i; ;j++)
					{
						if(s[j] != b[m])
						{
							flag = 0;
							break;
						}
						
						++m;
						
						if(m == l)
						{
							break;
						}
					}
					
					if(flag == 1)
					{
						ct++;
						temp++;
					}
				}
				
				if(maxi < temp)
				{
					maxi = temp;
				}
			}			
			
			total = pow(k, s1);
			ans = ct;
			
			ans = ct/total;
		}
	
		if(s1 == 1)
		{
			for(a1 = 0; a1 < k; a1++)
			{
				s = "";
				s = s + a[a1];
				
				temp = 0;
				
				for(i = 0; i <= s1 - l; i++)
				{
					m = 0;
					flag = 1;
			
					for(j = i; ;j++)
					{
						if(s[j] != b[m])
						{
							flag = 0;
							break;
						}
						
						++m;
						
						if(m == l)
						{
							break;
						}
					}
					
					if(flag == 1)
					{
						ct++;
						temp++;
					}
				}
				
				if(maxi < temp)
				{
					maxi = temp;
				}
			}			
			
			total = pow(k, s1);
			ans = ct;
			
			ans = ans/total;
		}
		
		ans = ct;
		ans = ans/total;
		ans = maxi - ans;
		
//		cout<<ct<<" "<<maxi<<" "<<total;
		
		cout<<"Case #"<<q<<": "<<fixed<<setprecision(6)<<ans<<"\n";	
	}	
	
	return 0;
}
