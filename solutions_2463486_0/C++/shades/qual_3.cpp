#include <iostream>
#include<stdio.h>
using namespace std;

bool palindrome(long long int a)
{
	char str[50];
    sprintf(str,"%lld",a);
    int b=0;
	int e=strlen(str)-1;
	while ( b < e )
	{
	if(str[b]!=str[e])
		return 0;
	b++;
	e--;
	}
	return 1;

}

int main()
{
int T;
cin>>T;
long long int a[1000];
long long int count=0;
for ( long long int i=1; i < 10000003; i++ )
{
	long long int prod=i*i;
	if  ( palindrome(i) && palindrome(prod) )
{
	a[count++]=prod;
	//cout<<prod<<endl;
}
}
for ( int ttt = 1; ttt <= T; ttt++ )
{
	long long int b,e;
	cin>>b>>e;
    int ans = 0;
	for ( int i = 0;i < count; i++ )
	{
	if(a[i] > e  )   break;
	if(a[i] >= b ) ans++;
	}

	cout<<"Case #"<<ttt<<": "<<ans<<endl;


}

}