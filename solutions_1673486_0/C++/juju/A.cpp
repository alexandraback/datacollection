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
    freopen("A_small.in", "r", stdin);
    freopen("a_small.out", "w", stdout);

    int T , a , b , c , i;
    double output = 1.0;
    double input[100010];
    double arr[100010];

    scanf("%d", &T);
	for( c = 1 ; c <= T ; ++c )
	{
        scanf("%d %d", &a, &b);
        for( i = 1 ; i <= a ; ++i )
            scanf("%lf", &input[i]);
        
        output = 1.0;
        for( i = 1 ; i <= a ; ++i )
		{
            output *= input[i];
            arr[i] = output*((a-i)+(b-i)+1) + (1.0-output)*((a-i)+(b-i+1)+(b+1));
		}
        
        arr[0] = b+2;	//case 3
        
        output = 10000000.0;
        for( i = 0 ; i <= a ; ++i )
		{
        	if( arr[i] < output )
				output = arr[i];
        }
        printf( "Case #%d: %lf\n", c, output );
    }
    
    return 0;
}

