#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> numbers;
char s[20];
int N,J;
vector<ll> divisors = {3, 2, 3, 2, 7, 2, 3, 2, 3};
void gen(int i, int odds, int evens){
  if(odds+evens > i || J<=0)
    return;
  if(i==0){
    /* numbers.push_back(strtol(s,0,2));
    for(int b=2;b<=10;b++){
      ll n = strtol(s,0,b);
      if(n%divisors[b-2]!=0)
	cerr<<" WTF\n";
	}*/
    J--;
    cout<<s<<" 3 2 3 2 7 2 3 2 3\n";
    
    return;
  }
  s[N-i-1] = '0';
  gen(i-1, odds, evens);
  if((N-i-1)%2==0 && evens!=0){
    s[N-i-1] = '1';
    gen(i-1, odds, evens-1);
  }
  else if((N-i-1)%2==1 && odds!=0){
    s[N-i-1] = '1';
    gen(i-1, odds-1, evens);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  int T;
  cin>>T;
  cout<<"Case #"<<1<<":\n";
  cin>>N>>J;
  s[0] = s[N-1] = '1';
  s[N] = 0;
  for(int bits=2;bits<N;bits++){
    if(bits%6==0)
      gen(N-2, bits/2-1, bits/2-1);
  }
  // number of 1s is divisible by 2 (=> in Base 3,5,7,9 div. by 2)
  // number of 1s is divisible by 3 (=> in Base 4,10 div. by 3)
  // number of odd 1s = even 1s (=> in Base 6 div. by 7)(=> in Base 8 div. by 3) (=> in Base 2 div. by 3)
  return 0;
}
