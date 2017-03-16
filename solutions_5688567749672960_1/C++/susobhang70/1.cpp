#include<iostream>
#include<cmath>
#include <stdlib.h>
using namespace std;

long long reverse(long long num)
{
    long long rev_num = 0;
    while(num > 0)
    {
        rev_num = rev_num*10 + num%10;
        num = num/10;
    }
    return rev_num;
}

long long digit(long long s)
{
	long long count=0;
	while(s>0)
	{
		s/=10;
		count++;
	}
	return count;
}

long long sto[]={0,0,10,29,138,337,1436,3435,14434,34433,144432,344431,1444430,3444429,14444428,34444427};

int main()
{
	int t,it;
	cin>>t;
	for(it=1;it<=100;it++)
	{
		long long s;
		cin>>s;
		cout<<"Case #"<<it<<": ";
		long long digits,rev,i,ans=0;
		digits=digit(s);
		//cout<<digits<<endl;
		ans+=sto[digits];
		//cout<<ans<<endl;
		long long form=pow(10,digits-1);
		long long x=(digits+1)/2;
		long long div=pow(10,x);
		long long rest=digits-x;
		rev=pow(10,rest);
		if(s<=20)
		{
			cout<<s<<endl;
			continue;
		}
		if(s<=form+div)
		{
			ans+=(s-form);
			cout<<ans<<endl;
		}
		else
		{
			if(s%div==0)
			{
				ans++;
				s--;
			}
			long long temp1=s/rev;
			//cout<<temp1<<endl;
			long long temp2=reverse(temp1);
			//cout<<temp2<<endl;
			ans+=temp2;
			temp1=s%rev;
			ans+=temp1;
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
