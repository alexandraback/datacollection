#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
bool isvowel(char c){
  return (c == 'a')||(c == 'o')||(c == 'e')||(c == 'i')||(c == 'u');
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    std::ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int qwe = 0; qwe < T; qwe ++){
       string s;
       cin >> s;
       int n;
       cin >> n;
       vector<int> mass(s.size(),0);
       int bal = 0;
       int j = 0;
       long long ans=0;
       int prevl= -1;
       for(int i = 0;i < (int)s.size(); i ++){

         if(!isvowel(char(s[i]))){
            bal ++;
         }else{
            if(prevl != -1){
                ans += (prevl+1);
            }
            j = i;
            bal = 0;
            continue;
         }
         if(bal < n){
            if(prevl != -1){
                ans += (prevl+1);
            }
            continue;
         }
         while((bal > n) || isvowel(s[j])){
            if(!isvowel(s[j])){
              bal --;
            }
            j ++;
         }
         prevl = j;
         ans += (j+1);
       }
       printf("Case #%d: %I64d\n",qwe+1,ans);
    }
}
