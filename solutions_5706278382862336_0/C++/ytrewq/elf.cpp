#include<iostream>
#include<math.h>
#include<fstream>

using namespace std;

long long int gcd(long long int a,long long int b) {

    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int findpow(long long int q)
{
	int i=1;
	while(i<=40)
	{
		if(pow(2,i)==q)
		{
			return i;
		}
		i++;
	}
	return -1;
}

int main()
{
	fstream fout;
	fout.open("opt1.txt",fstream::out);
	long long int p,q,fact;
	int t,num,ct;
	char c;
	cin>>t;
	int count =1;
	while(count <=t)
	{
		cin>>p>>c>>q;
		fact=gcd(p,q);
		p/=fact;
		q/=fact;
		
		num=findpow(q);
		ct=num;
	if(num==-1)
	{
		fout<<"Case #"<<count<<":"<<" Impossible\n";
	}
	else
	{
		while(pow(2,num)>p)
		{
			num--;	
		}
		fout<<"Case #"<<count<<": "<<ct-num<<endl;
	}
	count++;
	}
}
















