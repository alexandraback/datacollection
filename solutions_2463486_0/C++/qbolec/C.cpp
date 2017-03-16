#include "common.h"
uint64 small[]={
  0ULL,
1ULL,
4ULL,
9ULL,
121ULL,
484ULL,
10201ULL,
12321ULL,
14641ULL,
40804ULL,
44944ULL,
1002001ULL,
1234321ULL,
4008004ULL,
100020001ULL,
102030201ULL,
104060401ULL,
121242121ULL,
123454321ULL,
125686521ULL,
400080004ULL,
404090404ULL,
10000200001ULL,
10221412201ULL,
12102420121ULL,
12345654321ULL,
40000800004ULL,
1000002000001ULL,
1002003002001ULL,
1004006004001ULL,
1020304030201ULL,
1022325232201ULL,
1024348434201ULL,
1210024200121ULL,
1212225222121ULL,
1214428244121ULL,
1232346432321ULL,
1234567654321ULL,
4000008000004ULL,
4004009004004ULL,
100000020000001ULL,
100220141022001ULL,
102012040210201ULL,
102234363432201ULL,
121000242000121ULL,
121242363242121ULL,
123212464212321ULL,
123456787654321ULL,
400000080000004ULL,
10000000200000001ULL,
10002000300020001ULL,
10004000600040001ULL,
10020210401202001ULL,
10022212521222001ULL,
10024214841242001ULL,
10201020402010201ULL,
10203040504030201ULL,
10205060806050201ULL,
10221432623412201ULL,
10223454745432201ULL,
12100002420000121ULL,
12102202520220121ULL,
12104402820440121ULL,
12122232623222121ULL,
12124434743442121ULL,
12321024642012321ULL,
12323244744232321ULL,
12343456865434321ULL,
12345678987654321ULL,
};
const int smallCnt = sizeof(small)/sizeof(small[0]);
bool isPalindrome(const string &x){
  //cout << "checking : " << x << endl;
  for(unsigned int i=0;i<x.length();++i){
    if(x[i]!=x[x.length()-1-i]){
      return false;
    }
  }
  return true;
}
bool isPalindrome(uint64 x){
  strstream buff;
  string s;
  buff<< x;
  buff>> s;
  return isPalindrome(s);
}
void solve(){
  uint64 a,b;
  cin >> a >> b;
  uint64 cnt = 0;
  
  for(int i=0;i<smallCnt;++i){
    if(a<=small[i] && small[i]<=b){
      ++cnt;
    }
  }
  cout << cnt << endl;
  return;
  uint64 a2= sqrt(a);
  uint64 b2= sqrt(b);
  for(uint64 x=a2;x<=b2;++x){
    uint64 x2= x*x;
    if(a<=x2 && x2<=b){
    //  cerr << "check " << x2 << endl;
      if(isPalindrome(x) && isPalindrome(x2)){
        cerr << "x: " << x << " x2: "<< x2 << endl;
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}
int main(){
  int t;
  cin >> t;
  for(int i=1;i<=t;++i){
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}