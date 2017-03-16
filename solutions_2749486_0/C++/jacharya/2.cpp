#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>
#include<map>

#define LOOP(t,T) for(t=0; t< (T); t++)
#define LOOPT(t,T) for(t=1; t<= (T); t++)

using namespace std;


int main(){
  long T, i, j, k,t, l, answer, index;
  long X,Y, sx, sy, step, diff, cross, tx, ty;
  cin >> T;   
  LOOP(t,T) {
    cout << "Case #" << t+1 << ": ";    
    cin >> X>>Y;
    sx=1;
    sy=1;
    if (X<0){
      sx=-1;
      X=-X;
    }

    if (Y<0){
      sy=-1;
      Y=-Y;
    }

    tx=0;
    ty=0;
    step=1;
    cross=0;
    while(tx<X){
      tx+=step;
      step++;
      cout<<((sx>0)?('E'):('W'));
    }
    diff = tx-X;
    LOOP(i, diff){
      step++;
      step++;
      tx--;
      cout<<((sx>0)?("EW"):("WE"));
      if (tx==X)
	break;
    }
    
    while(ty<Y){
      ty+=step;
      step++;
      cout<<((sy>0)?("N"):("S"));
    }
    diff = ty-Y;
    LOOP(i, diff){
      step++;
      step++;
      ty--;      
      cout<<((sy>0)?("NS"):("SN"));
      if (ty==Y)
	break;
    }
    cout<<endl;
	 
    
  }
  return 0;
}



