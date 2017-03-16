#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

// 012[3456]78
// 9 
string L;
int n;
bool iscon(char c){
 if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u')return true;
return false;
}
long long solve(){
long long ans = 0;
int z = 0 ;
int len = L.length();
int lasti = 0;
for(int i=0;i<len;i++)
 if(iscon(L[i])){
	lasti = i+1;
    while(iscon(L[lasti])&&lasti<len)lasti++;
    if(lasti-i>=n){
	 ans += (long long)(i+1-z)*(long long)(len-lasti+1);
//cout << ans << endl;
     if(lasti-i>n)
      ans += (long long)(i-z)*(long long)(lasti-i-n)+(long long)(len-lasti)*(long long)(lasti-i-n)+(long long)(lasti-i-n+1+1)*(long long)(lasti-i-n+1)/2LL-1;
/*cout << lasti-i-n+1+1 << ' ' << (lasti-i-n+1) << endl;     
cout <<
(long long)(lasti-i-n+1+1)*(long long)(lasti-i-n+1)/2LL-1<< endl;*/
     z=lasti-n+1;
     //cout << z<< ' ' << L << endl;
     i = lasti;
    }
 }
return ans;
}
int main(){
 freopen("A.in","r",stdin);freopen("AC.out","w",stdout);
int T;
cin >> T;
for(int i=0;i<T;i++)
{
  cin >> L >> n;
  cout << "Case #"<< i+1 << ": "<< solve() << endl;
}
return 0;
}
