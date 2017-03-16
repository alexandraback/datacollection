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


int main()
{
	long long int t, l, k, i, j, ans, flag, remx, remy, m = 0, store, ans1, ans2, ans3, ans4, temp, u;
	long long int a[10][10];

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
		
		if(k <= 10)
		{
			for(i=0;i<k;i++)
			{
				s = s + s1;
			}
					
			l = l*k;
			
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
		
		else
		{
			s = "";
			
			for(i = 0; i < 4; i++)
			{
				s = s + s1;
			}
			
			store = l;
			
			l = l*4;

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
			
//			cout<<remx<<" "<<remy<<endl;

			ans1 = 1;
			
			for(i = remx + 1; i < l; i++)
			{
				if(ans1 < 0)
				{
					ans1 = -a[-ans1][s[i] - '0'];
				}	
				
				else
				{
					ans1 = a[ans1][s[i] - '0'];
				}
			}
			
			ans2 = 1;

			for(i = 0; i < remy; i++)
			{
				if(ans2 < 0)
				{
					ans2 = -a[-ans2][s[i] - '0'];
				}	
				
				else
				{
					ans2 = a[ans2][s[i] - '0'];
				}
			}
				
			ans3 = 1;
			
			for(i = 0; i < store; i++)
			{
				if(ans3 < 0)
				{
					ans3 = -a[-ans3][s[i] - '0'];
				}	
				
				else
				{
					ans3 = a[ans3][s[i] - '0'];
				}			
			}
			
			temp = k%4;
			
//			cout<<ans1<<" "<<ans3<<" "<<ans2<<endl;
			if(ans3 != -1 && ans3 != 1)
			{
				if(temp == 2)
				{
					ans3 = -1;
				}
			
				else if(temp == 3)
				{
					ans3 = -ans3;
				}
			
				else if(temp == 0)
				{
					ans3 = 1;
				}
			}
			
			else
			{
				if(ans3 == -1)
				{
					if(temp == 2)
					{
						ans3 = 1;
					}
				
					else if(temp == 3)
					{
						ans3 = -1;
					}
				
					else if(temp == 0)
					{
						ans3 = 1;
					}							
				}
			}
			
			u = 0;
			
//			cout<<ans1<<" "<<ans2<<endl;
			if(ans1 < 0)
			{
				u++;
				ans1 = -ans1;
			}
			
			if(ans3 < 0)
			{
				u++;
				ans3 = -ans3;
			}
			
			if(ans2 < 0)
			{
				u++;
				ans2 = -ans2;
			}
			
			ans1 = a[ans1][ans3];
		
			if(ans1 < 0)
			{
				u++;
				ans1 = -ans1;
			}
			
			ans1 = a[ans1][ans2];
			
			if(u%2 != 0)
			{
				ans1 = -ans1;
			}
			
			if( ans1 == 3)
			{
				cout<<"Case #"<<m<<": "<<"YES\n";
			}
			
			else
			{
				cout<<"Case #"<<m<<": "<<"NO\n";
			}
		}
	}
	
	
	return 0;
}
