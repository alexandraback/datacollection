#include<iostream>
//#include<set>
using namespace std;

bool check(string s,int n){
   int cnt = 0;
   for(int i = 0 ; i < s.size() ; i++){
      if(s[i] == 'a' || s[i] == 'i' || s[i] == 'u'
	 || s[i] == 'e' || s[i] == 'o'){
	 cnt = 0;
      }
      else cnt++;
      if(cnt == n)return true;
   }
   return false;
}

void solve(){
   string str;
   int n;
   cin >> str >> n;
   int res = 0;
   
   for(int i = 0 ; i < str.size() ; i++){
      for(int j = i ; j < str.size() ; j++){
	 int cnt = 0;
	 string s;
	 for(int k = i ; k <= j ; k++)s += str[k];
	 if(check(s,n)){
	    res++;
	 }
      }
   }
   cout << res << endl;
}

int main(){
   int tc;
   cin >> tc;
   int cnt = 1;
   while(tc--){
      cout << "Case #"  << cnt++ << ": ";
      solve();
   }
   return 0;
}
