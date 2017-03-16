#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int ttt=0;
	cin>>ttt;
	long long int a[1000004];
	for ( int ty = 1; ty<=ttt; ty++)
	{
		cout<<"Case #"<<ty<<": ";
		long long int A;
		long long int n;
		cin>>A>>n;
		for (int i =0 ; i < n; i++) 
			cin>>a[i];

		sort(a,a+n);
		long long int dis=n;
		long long int op=0;
		long long int i = 0;
		if ( A == 1 )
			cout<<n<<endl;
		else
		{
			while  ( i < n )
			{
				if ( a[i] < A )
				{
					A+=a[i];
					if ( dis  >  op + n-i-1 )
						dis = op + n-i-1;
					if ( A > a[n-1]+1)
						A=a[n-1]+1;
				}
				else
				{
					while ( A <= a[i] )
					{
						op++;
						A+=(A-1);
					}
					A+=a[i];
					if ( A > a[n-1]+1)
						A=a[n-1]+1;
                                        if ( dis <= op )
					{
						break;
					}
					if ( dis  >  op + n-i-1 )
						dis = op + n-i-1;
				}
				i++;
			}

					if ( dis  >  op  )
						dis = op ;
		cout << dis << endl;
		}
	}
}
