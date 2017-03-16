#include <iostream>
#include <cmath>

using namespace std;

int T, N, A;
double D;
double tajm;
double a[300], t[3000], x[3000];
double mypos,otpos,myvel;
bool finis;

int main(){
  cout.precision(20);
  scanf("%d", &T);
  
  for (int tt=0; tt<T; tt++) {
    
    
    scanf("%lf %d %d", &D, &N, &A);
    
    for (int i=0; i<N; i++) {
      scanf("%lf %lf", &t[i], &x[i]);
    }
    
    for (int i=0; i<A; i++) {
      scanf("%lf",&a[i]);
    }
    
   
    cout << "Case #" << tt+1 << ":" << endl;
    for (int ia=0; ia<A; ia++) {
      
      tajm = 0.0;
      mypos = 0.0;
      myvel = 0.0;
      otpos = x[0];
      
      finis = false;
      
      for(int i=1; i<N; i++){
        if (mypos+myvel*(t[i]-t[i-1])+0.5*(t[i]-t[i-1])*(t[i]-t[i-1])*a[ia] >= x[i] - 1e-10) {
          
          
          
          if(abs(x[i]-D) < 1e-8){
            //exactly at finish
            finis = true;
          } else if(x[i] > D){
            finis = true;
            //other pos: D, time of this position(t2): (D-x[i-1])/((x[i]-x[i-1])/(t[i]-t[i-1]))
            double t2 = (D-x[i-1])/((x[i]-x[i-1])/(t[i]-t[i-1]));
            if (mypos+myvel*(t2-t[i-1])+0.5*(t2-t[i-1])*(t2-t[i-1])*a[ia] > D) {
              tajm = t2;
              break;
            } else {
              tajm = (-1*myvel + sqrt(myvel*myvel +2*a[ia]*(D-mypos))/a[ia]);
              break;
            }
            //over finish, count exact time
          }
          
          myvel = (x[i]-x[i-1])/(t[i]-t[i-1]);
          //what if we stop :)
          if(sqrt(2*a[ia]*(x[i]-x[i-1]))/a[ia] > t[i]-t[i-1]){
            double vz = (sqrt(2*a[ia]*(x[i]-x[i-1]))/a[ia] - t[i]-t[i-1]) *a[ia];
            myvel = -1 * vz + sqrt(vz*vz+2*a[ia]*(x[i]-x[i-1]));
          }
          if(sqrt(2*a[ia]*(x[i]-x[i-1])) > myvel)
            myvel = sqrt(2*a[ia]*(x[i]-x[i-1]));
          
          mypos = x[i];
          tajm += (t[i]-t[i-1]);
          //cout << 2*a[ia]*(x[i]-x[i-1]) << endl;
        } else {
          
          if(abs(mypos+myvel*(t[i]-t[i-1])+0.5*(t[i]-t[i-1])*(t[i]-t[i-1])*a[ia] -D) < 1e-12){
            finis = true;
          } else if(mypos+myvel*(t[i]-t[i-1])+0.5*(t[i]-t[i-1])*(t[i]-t[i-1])*a[ia] > D){
             tajm = (-1*myvel + sqrt(myvel*myvel +2*a[ia]*(D-mypos))/a[ia]);
            finis = true;
            break;
          }
          
          mypos = mypos+myvel*(t[i]-t[i-1])+0.5*(t[i]-t[i-1])*(t[i]-t[i-1])*a[ia];
          myvel = myvel + a[ia]*(t[i]-t[i-1]);
          tajm += (t[i]-t[i-1]);
          //cout << mypos << endl;
        }
        
        if(finis) break;
      
        
      } 
      //cout << "A" << endl;
      if(finis){
        
        cout << tajm << endl;
      } else {
        cout << tajm+(-1*myvel + sqrt(myvel*myvel +2*a[ia]*(D-mypos))/a[ia]) << endl;
      }
      

    }
    
  }
  
    
  
  
  return 0;
}