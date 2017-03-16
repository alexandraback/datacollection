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
  cin >> t;
  string s;
  for(int i=1;i<=t;i++){
    int start_plus;
    int minus=0;
    cin >> s;
    start_plus=(s[0]=='+')?1:0;
    int j=0;
    while(j<s.size()){
      if(s[j]=='-'){
        minus++;
        while(s[j]=='-')
          j++;
      } else {
        j++;
      }
    }
    ANS(i,((minus-1)*2)+1+start_plus);
  }

}
