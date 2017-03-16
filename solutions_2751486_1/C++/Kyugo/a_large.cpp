#include<iostream>
using namespace std;

const int MAX = 1000010;
int data[MAX];

bool isV(char c){
   if(c == 'a'|| c == 'i' || c == 'u'|| c == 'e' || c == 'o')return true;
   return false;
}

void solve(){
   string str;
   int n;
   cin >> str >> n;

   int res = 0;

   int cnt1 = 0;
   int cnt2 = -1;

   for(int i = 0 ; i < str.size() ; i++){
      data[i] = -1;
   }


   for(int i = (int)str.size()-1 ; i >= 0 ; i--){      
      //cout << "i = "<<  i << " cnt1 = " << cnt1 << " cnt2 = " << cnt2 << endl;
      if(isV(str[i])){
	 cnt1 = 0;
	 if(cnt2 != -1)cnt2++;
      }
      else {
	 cnt1++;
	 if(cnt1 < n && cnt2 != -1)cnt2++;
      }

      if(cnt1 == n)cnt2 = cnt1;
      if(cnt2 >= n)data[i] = cnt2-1;
      else data[i] = -1;
   }

   for(int i = 0 ; i < str.size() ; i++){
      //cout << data[i] << ' ';
      if(data[i] != -1)res += (str.size() - (i + data[i]));
   }
   //cout << endl;
   
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
