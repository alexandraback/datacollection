#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int ttt=0;
	cin>>ttt;
	int a[1000004];
	for ( int ty = 1; ty<=ttt; ty++)
	{
		cout<<"Case #"<<ty<<": ";
		int A;
		int n;
		cin>>A>>n;
		for (int i =0 ; i < n; i++) 
			cin>>a[i];

		sort(a,a+n);
		int dis=n;
		int op=0;
		int i = 0;
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
