#include<iostream>
#include<string>


using namespace std;

long finder (long r, long t, long smaller, long larger); 

int main(){
  long  j,r,t, k, i, l,m, A, B, flag, pin;
  long lay, sum, num, ans, C,N, T, S, p, score, smaller, larger;
  string name;
  long matr[4][4];
  cin >> T;
  j=0;
  for(i=0;i<T;i++){
    cout<<"Case #"<<i+1<<": ";
 
    cin >>r>>t;

    smaller = 1;
    larger = 1;
    k = 1;
    while (k*(2*k+2*r-1)<=t)
      k=2*k;
    larger = k;
    ans = finder (r,t, smaller, larger);
    
    cout<<ans<<"\n";
  }

  return 0;
}

long finder (long r, long t, long smaller, long larger){
  long i,j,k,mid;
  
  if (larger==smaller||larger==smaller+1)
    return smaller;
  mid = (larger+smaller)/2;
  if (mid*(2*mid + 2*r-1)<=t)
    return finder(r,t,mid, larger);
  else 
    return finder (r,t,smaller, mid);
}
