#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <set>
using namespace std;
#define oo 1000000007
long long int gcd(long long int a,long long int b){
      if(b==0)return a;
      return gcd(b,a%b);
}

long long int l,s,k;
char keys[10];
char tar[10];
char str[20];
long long int maxi=0;
long long int func(int sx,char strx[])
{
	if(sx==s)
	{
		int len=strlen(strx);
		for (int i = l; i < l+len ; ++i)
		{
			str[i]=strx[i-l];
		}
		str[l+len]='\0';
		len=strlen(str);
        vector <long long int> Z(len+1);

        for(long long int i=1,lx=0,r=0;i<len;i++)
        {
        	if(i<=r)
        		Z[i]=min(Z[i-lx],r-i+1);
        	while(Z[i]+i<len && str[Z[i]]==str[Z[i]+i])
        		Z[i]++;
        	if(Z[i]+i-1>r)
        		lx=i,r=Z[i]+i-1;
        }
       long long  int cx=0;
        for (int i = l; i <len; ++i)
        {
        	if(Z[i]>=l)
        	cx++;
        }
      maxi=max(maxi,cx);
        return cx;
	}
	long long int ans=0;
	for (int i = 0; i <k; ++i)
	{
		char z[10];
		int len=strlen(strx);
		//cout<<len<<strx<<endl;
		for (int j = 0; j<len; ++j)
		{	
			z[j]=strx[j];
		}
		z[len]=keys[i];
		z[len+1]='\0';
		ans=ans+func(sx+1,z);
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		cin>>k>>l>>s;
		cin>>keys;
		cin>>tar;
		strcpy(str,tar);
		char aa[10];

		aa[0]='\0';
		maxi=0;
		long long int ans=func(0,aa);
		long double zz=ans;
		for (int j = 0; j <s; ++j)
		{
			zz=zz/k;
		}

		cout<<"Case #"<<i+1<<": ";
		cout<<setprecision(9)<<maxi-zz<<endl;

	}
	return 0;
}