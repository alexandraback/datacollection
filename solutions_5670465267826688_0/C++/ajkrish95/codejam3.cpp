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
#include<cassert>
#include<time.h>
using namespace std;

int a[10][10];

int main()
{
	int t, l, k, i, j, ans, flag, remx, remy, m = 0;
	cin>>t;
	
	string s1, s;
	
	a[1][1] = 1;
	a[1][2] = 2;
	a[1][3] = 3;
	a[1][4] = 4;

	a[2][1] = 2;
	a[2][2] = -1;
	a[2][3] = 4;
	a[2][4] = -3;

	a[3][1] = 3;
	a[3][2] = -4;
	a[3][3] = -1;
	a[3][4] = 2;

	a[4][1] = 4;
	a[4][2] = 3;
	a[4][3] = -2;
	a[4][4] = -1;
	
	while(t--)
	{
		cin>>l>>k;
		cin>>s1;
		m++;
		
		s = "";
		
		for(i=0;i<k;i++)
		{
			s = s + s1;
		}
				
		l = l*k;
		
//		cout<<s<<endl;
		for(i = 0; i < l; i++)
		{
			if(s[i] == 'i')
			{
				s[i] = '2';
			}

			if(s[i] == 'j')
			{
				s[i] = '3';
			}

			if(s[i] == 'k')
			{
				s[i] = '4';
			}
		}

		flag = 0;
		ans = 1;

		for(i=0;i<l;i++)
		{
			if(ans < 0)
			{
				ans = -a[-ans][s[i] - '0'];
			}	
			
			else
			{
				ans = a[ans][s[i] - '0'];
			}
			
			if(ans == 2)
			{
				flag = 1;
				break;
			}
		}
		
		if(flag == 0)
		{
			cout<<"Case #"<<m<<": "<<"NO\n";
			continue;
		}

		remx = i;

		flag = 0;
		ans = 1;
		
		for(i=l-1;i>=0;i--)
		{
//			cout<<s[i]<<" "<<ans<<endl;
			
			if(ans < 0)
			{
				ans = -a[s[i] - '0'][-ans];
			}	
			
			else
			{
				ans = a[s[i] - '0'][ans];
			}
			
			if(ans == 4)
			{
				flag = 1;
				break;
			}
		}		
		
		remy = i;
		
		if(flag == 0)
		{
			cout<<"Case #"<<m<<": "<<"NO\n";
			continue;
		}
		
		if(remy <= remx)
		{
			cout<<"Case #"<<m<<": "<<"NO\n";
			continue;
		}
		
		ans = 1;
		flag = 0;
		
		for(i=remx+1;i<remy;i++)
		{
			if(ans < 0)
			{
				ans = -a[-ans][s[i] - '0'];
			}	
			
			else
			{
				ans = a[ans][s[i] - '0'];
			}
					
		}
		
		if(ans != 3)
		{
			cout<<"Case #"<<m<<": "<<"NO\n";
			continue;
		}	
		
		cout<<"Case #"<<m<<": "<<"YES\n";
	}
	
	
	return 0;
}
