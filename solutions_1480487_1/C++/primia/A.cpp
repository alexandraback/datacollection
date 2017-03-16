#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for(int tc=1;tc<=T;++tc){
    int N;
    cin >> N;
    int s[N];
    int S = 0;
    for(int i = 0; i < N; ++i){
      cin >> s[i];
      S += s[i];
    }

   
    cout << "Case #" << tc <<":";
    double l = 0;
    double r = S+1;
    double m;
    double target = 0;
    int cnt = 0;
    while(cnt++<80){
      m = (l+r)/2.;
      double tt = 0;
      for(int i = 0; i < N; ++i){
        double x = (m-s[i])/S;
        if( x < 0 ) x = 0;
        tt += x;
      }
      if( tt < 1 ) l = m;
      else r = m;
    }
    target = m;

    /*


      double r = 100;
      double l = 0;
      double m;
      int cnt = 0;
      while(cnt++<50){
        m = (r+l)/2.;
        bool ok = false;
        for(int j = 0; j < N; ++j){
          if( i!=j ){
            if( s[i]+S*m > s[j]+S*(1-m) ) ok = true;
          }
        }
        if( ok ) r = m;
        else l = m;
      }
      cout << ' ' << fixed << setprecision(6) << 100*m;
    }
    cout << endl;
    

    double target = 2*S/(double)N;
    double tt = 0;
    bool flag = false;
    int maxi = 0;
    int notc = 0;
    for(int i = 0; i < N; ++i){
      double tmp = 100*(target - s[i])/S;
      // if( tmp < 0 ) flag = true;
      if( tmp < 0 ){
        flag = true;
        maxi = max(s[i],maxi);
      }else{
        tt += 100*(target-s[i])/(double)S;
        notc++;
      }
    }
    
    cout << "Case #" << tc <<":";

    if( tt > 100 ) tt = 100;
    */

    for(int i = 0; i < N; ++i){
      double tmp = 100*(target - s[i])/S;
      //if( flag && tmp < 0 ){
      //tmp = min(tt/(double)notc,100*(maxi-s[i])/(double)S);
      //}
      if(tmp<0)tmp=0;
      cout << " " << fixed << setprecision(6) << tmp;
    }
    cout << endl;
    // cout << flag << ' ' << tt << endl;
    
  }
  return 0;
}
