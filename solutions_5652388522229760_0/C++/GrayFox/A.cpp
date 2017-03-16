#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
#else
#define DB(x)
#define DBL(x)
#endif

#define ANS(n, r) cout<<"Case #"<<n<<": "<<r<<endl

int main(){
  int t;
  long long n;
  bool b[10];
  cin >> t;
  for(int i=1;i<=t;i++){
    cin >> n;
    if(n==0){
      ANS(i,"INSOMNIA");
      continue;
    }
    memset(b,0,sizeof b);
    int c = 0;
    long long k = 0;
    long long q;
    do{
      k++;
      q = k*n;
      DB(q) DBL(c);
      while(q>0){
        if(!b[q%10]){
          c++;
          b[q%10]=true;
        }
        q/=10;
      }
    } while(c!=10);
    ANS(i,k*n);

  }
}
