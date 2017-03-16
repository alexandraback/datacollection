#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int n;
int a[300];

double res[300];
double sum = 0;

bool lose ( int pos, double mid ) {

    double hasRes = a[pos] + mid * sum;
    
    double temp = 0;
    
    //printf ("%lf has hasREs ", hasRes );
    for ( int i = 0; i < n; ++i )
        if ( i != pos ) {
        
            temp += max ( 0.0, (double)(hasRes - a[i])/sum );
        }
    
   // printf ( "for %d %lf we got %lf %lf\n", pos, mid, temp, temp + mid );
    
    if ( temp + mid < 1.0 + 1e-7 ) return true;
    return false;
}
void solve () {

    static int testN = 0;
    
    //double sum = 0;

    sum = 0;
    scanf ( "%d", &n );
    for ( int i = 0; i < n; ++i ) {
        scanf ( "%d" , &a[i] );
        sum += a[i];
    }
    
    //double ans = 0;
  //  sum = 0;
    for ( int i = 0; i < n; ++i ) {
    
        double left, right, mid;
        left = 0;
        right = 1;
        
        //int maxa = 0;
        
        //for ( int j = 0; j < n; ++j )
         //   if ( i != j ) maxa = max ( maxa, a[j] );
            
        //cout << maxa << " "<<sum<<endl;
        
       // ans = 0;
        
        while ( left + 1e-9 <= right ) {
        
            mid = (left + right ) / 2;
            
            if ( !lose(i, mid) ) {
                right = mid; 
            }
            else {left = mid;}
            
            //cout<<mid<<"\n";
        }
        
        res[i] = left * 100.0;
       // printf ("g\n");
    }
    printf ( "Case #%d:", ++testN );
    for ( int i = 0; i < n; ++i )
        printf ( " %.6lf", res[i] );
    printf ( "\n" );
}
int main () {

    int t;
    scanf ( "%d", &t );
    
    for ( int i = 0; i < t; ++i ) solve ();
    return 0;
}
