#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main() {
        
        int t, T;
        float p[10000], y;
        long long int a,b, i,j;
 
        cin >> T;
 
        for ( t = 0; t < T; t++ ) {
 
                cin >> a >> b;
 
                for ( i = 0; i < a; i++ ) {
                        cin >> p[i];
                }
 
                float x = 1.0;
                for ( i = 0; i < a; i++ ) {
                        x = p[i]*x;
                }
                y = x*((float)(b-a+1)) + (1-x)*((float)(b-a+1+b+1));
 
                float min = y;
 
                if ( ((float)(b+2)) < float(y) )
                        min = (float)(b+2);
 
                x = 1;
                for ( i = 1; i < a; i++ ) {
 
                        for ( j = 0; j < (a-i); j++ ) {
                                x = p[j]*x;
                        }
                        y = x*((float)(b-a+1+(2*i))) + (1-x)*((float)(b-a+1+(2*i)+b+1));

                        if ( y < min )
                                min = y;
 
                }
 
                cout << "Case #"<<t+1<<": ";
                printf("%0.6f", min);
                cout << endl;
 
        }
 
        return 0;
}
