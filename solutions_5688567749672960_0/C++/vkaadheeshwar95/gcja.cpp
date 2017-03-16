#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
int rev(int n)
	{
		int rem,sum=0;
		while(n!=0){
			rem=n%10;
			sum = (sum*10+rem);
			n/=10;
		}	
		return sum;
	}
	
int main()
{
	int i, n, T;    
	cin>>T ;
    int cnt = 1;
    
	
    while(T--)
    {

		int ans = 0;
		cin >> n;
		if(n<=20) ans=n;
		else{
			int n1=n;
			while(n1>0)
			{
				int reve=rev(n1);
				if(reve > 0 && reve < n1 && n1%10 != 0)
				{
					n1=reve;
				}
				else n1--;
				ans++;	
			}
		}
		cout<<"Case #"<<cnt++<<": "<<ans<<endl ;
    }
    return 0 ;
}


