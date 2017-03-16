#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>


#define LOOP(t,T) for(t=0; t< (T); t++)

using namespace std;

//double bsrch ( double low, double high, long s[], long i, long sum);
//bool pass( double prc, long s[], long i, long sum);
//long N;

long a, mote[100], N;

long sol(long j);

long sol(long j){
  long m,n,p;
  
  long k=0, changes=0;
  long cumsum=a;
  LOOP(k,j){
    while (cumsum<=mote[k]){
      cumsum = 2*cumsum-1;
      changes++;
    }
    cumsum= cumsum+mote[k];
  }
  changes = changes + (N-j);
  return changes;
  
}

int main(){
  long T, i, j, k,t, l, answer, index;
 	
  cin >> T;   


  LOOP(t,T) {
    cout << "Case #" << t+1 << ": ";    
    cin >>a>> N;
    
    LOOP(i,N){
      cin>>mote[i];
    }
    
    std::sort (mote,mote+N);
    
    answer = 100;
    
    LOOP(j,N+1){
      index=sol(j);
      if (a==1)
	break;
      if (index<answer)
	answer=index;
    }
    if (a==1)
      cout<<N<<"\n";
    else
      cout<<answer<<"\n";
  }
  return 0;
}



