#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>

using namespace std;
ofstream out("A.txt");

char name[1000001];
int checkval ( int a, int b, long long n )
{
	//cout<<endl<<"entered func";
	int i, j;
	long long check=0;
	for ( i=a; i<b; i++ )
	{
		if ( name[i]=='a' || name[i]=='e' || name[i]=='i' || name[i]=='o' || name[i]=='u' )
		{
			check=0;
		}
		else check++;
		if ( check==n ) return 1;
	}
	return 0;
}


int main()
{
	long long tcases, n, sum;
	cin>>tcases;
	long long i, j, k;
	int cases=1;
	while ( tcases-- )
	{
		cin>>name;
		cin>>n;
		sum=0;
		for ( i=0; name[i]!='\0'; i++ );
	//	cout<<"len "<<i;
		long long len=i;
		long long x=len-n;
		for ( i=0; i<=x; i++ )
		{
	//		cout<<"loop"<<endl;
			for ( j=i+n; j<=len; j++ )
			{
	//			cout<<"i "<<i<<" j "<<j<<endl;
				sum+=checkval(i,j,n);
			}
		}
		out<<"Case #"<<cases<<": "<<sum<<endl;
		cases++;	
	}

	return 0;
}
