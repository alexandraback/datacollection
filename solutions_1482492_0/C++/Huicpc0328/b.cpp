#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
const int N = 2555;
double a[N];

struct node {
       double t , d;   
       node(){}
       node( double tt,double dd ) : t(tt),d(dd){}    
       void read(){
            scanf("%lf%lf",&t,&d);
       }
};

node b[N];

const double eps = 1e-16;

inline double sq( double x){
       cout<<" x = "<<x<<endl;
        double l = 0 , r = sqrt(x)*2;
         while( l < r-1e-8) {
                double mid = (l+r)/2;
                double tmp = mid*mid - x;
                if( fabs( tmp ) < eps ) return mid;
                else if( tmp > 0 ) l = mid;
                else r = mid;
         }
         return l;
}

inline double root( double a,double b,double c ) { 
       //cout<<a<<" "<<b<<" "<<c<<endl;  
       double tmp = sqrt( b*b - a*c*4 ) - b;
       return tmp*0.5/a;

/*
         double tt = c*2;
         cout<<" tt = "<<tt<<endl;
         double l = 0 , r = 1e10;
         cout<<a<<" "<<b<<" "<<c<<endl;
         cout<<l<<" r = "<<r<<" "<<sqrt(c*2*-1/a)<<endl;
         while( l < r-1e-8) {
                double mid = (l+r)/2;
                double tmp = mid*b + a*mid*mid*0.5 + c ;
                if( fabs( tmp ) < eps ) return mid;
                else if( tmp > 0 ) l = mid;
                else r = mid;
         }
*/
}

double get( double ac , double d ,int n ) {
       double v = 0 , t = 0 , dist = 0; 
       int i ,flag = 0 ;
       for( i = 0 ; i < n-1;i++ ) {
            double carv = (b[i+1].d-b[i].d)/(b[i+1].t-b[i].t);
            double nextd = b[i+1].d;
            if( b[i+1].d >= d ) {
                flag = 1;
                nextd = d;
            }
            double curt = (nextd-b[i].d)/carv;
            double dc = dist - b[i].d;
            double db = v - carv;
            double needt = root( ac/2 , db , dc );
            
            if( needt < curt ) {
                dist += (v*needt+0.5*ac*needt*needt); 
                v = carv;   
                t += needt;
                t += ( nextd - dist )/carv;
                dist = nextd;
               // cout<<"A"<<endl;
            } else {
                   dist += (v*curt+ac*curt*curt*0.5);                
                   v += ac * curt;
                   //printf("%lf %lf\n",t,curt);
                   //cout<<" t = "<<t<<" curt "<<curt<<endl;
                   t = t + curt;
                  // printf("%lf %lf\n",t,curt);
                  // cout<<"B"<<" t "<<t<<endl;
            }
            //cout<<v<<" t = "<<t<<" curt = "<<curt<<"  d = "<<dist<<endl;
            if( flag ) break;
       }   
       
       if( dist < d ) {
           double tmp = root( ac*0.5,v,dist-d);
           tmp = 140.97;
           double ans = tmp * v + ac*tmp*tmp/2;
           
           //cout<<" ans = "<<ans<<" tmp = "<<tmp<<endl;
             
           t = t + root( ac*0.5,v,dist-d);
       }
           
       return t;
}


int main(){
    int test, i , j, n , A;
    double d;
    scanf("%d",&test);
    for( int tc = 1; tc <= test; tc++) {
         scanf("%lf%d%d",&d,&n,&A);
         for( i = 0 ; i < n;i++ ) {
              b[i].read();
         }
         for( i = 0 ; i < A;i++ ) scanf("%lf",&a[i]);
         

         printf("Case #%d:\n",tc);
         for( i = 0 ; i < A;i++ ) {
              printf("%lf\n",get( a[i] , d,  n ));
         }
    }
    //while(1);
    return 0;         
}
