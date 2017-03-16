#include<iostream>
using namespace std;
int main()
{
	int N;
	int res ;
	int T , A[1005] , B[1005] , d = 1;
	cin >> T;
	while( T-- )
	{
		cin >> N;
		int visited[1005];
		for(int i = 0; i < N; ++i)
		{
			cin >> A[i] >> B[i];
			visited[i] = 0;
		}
		int x = 0;
		res = 0;
		int c = 0;
		bool f = true;
		while( c != N )
		{
			int index = -1 ,  use = 0;
			for(int i = 0; i < N; ++i)
				if( visited[i] != 2)
					if( B[i] <= x )
						index = i , use = 1;
			if( index == -1 )
			{
					for(int i = 0; i < N; ++i)
						if( visited[i] < 1)
							if( A[i] <= x )
							{
								if( index != -1)
								{
									if( B[i] > B[index] )
										index = i;
								}
								else
									index = i;
							}
			}
			if( index == -1 ) { f = false;break; }
			if( use == 0 )
			{
				visited[index] = 1;
				res++;
				x += 1;
			}
			else
			{
				if( visited[index] == 1) x += 1;
				else x +=2 ;
				visited[index] = 2;
				c++;
				res++;
			}	
		}
		cout <<"Case #"<<d++<<": ";
		if( f ) cout << res << "\n";
		else cout << "Too Bad\n";
	}
	return 0;
}
