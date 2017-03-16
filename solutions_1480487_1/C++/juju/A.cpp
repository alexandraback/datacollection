#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;


int main()
{
    freopen("A_large.in", "r", stdin);
    freopen("a_small.out", "w", stdout);

    int T , a , i , n , c , final_n;
    double sum , b , d , e;
    double v[210];
    double vvv[210];

    scanf("%d", &T);
	for( c = 1 ; c <= T ; ++c )
	{
		scanf("%d", &n);
		sum = 0;
		for( i = 0 ; i < n ; ++i )
		{
        	scanf("%d", &a);
        	//cout << a << " ";
        	v[i] = a;
        	sum += a*1.0;
		}
		b = sum*2;
		//cout << endl << "b = " << b << endl;
		d = b/n;	//每個人最後應得的分數 
		final_n = n;
		for( i = 0 ; i < n ; ++i )
		{
			if( v[i] > d )
			{
				final_n--;
				b = b-v[i];
			}
		}

		e = b/final_n;
		printf( "Case #%d: ", c );
		for( i = 0 ; i < n ; ++i )
		{
			//cout << endl << "e = " << e << "   v[i] = " << v[i] << endl;
			vvv[i] = e - v[i];
			vvv[i] = 100.0*vvv[i]/sum;
			//cout << endl << "vvv[i] = " << vvv[i] << " aaa " << endl; 
			if( vvv[i] < 0.0 )
			{
				printf("%.8lf ", 0.0);
			}
			else
			{
				printf("%.8lf ", vvv[i]);
			}
			
		}
        printf("\n");
    }
    return 0;
}

