#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool hash[10010];
bool check(int x){
    int c = 0;
    int a[10];
    while(x){
        a[c++] = x%10;
        x/=10;
    }
    for(int i = 0; i < c/2; i++){
        if(a[i] != a[c-i-1]) return false;
    }
    return true;

}
void Init(){
   for(int i = 1; i <= 40; i++){
       if(check(i))
         hash[i*i] = true;
   }
   for(int i = 1; i <= 1000; i++){
       if(check(i)){
           if(hash[i]) hash[i] = true;
           else hash[i] = false;
       }else hash[i] = false;
   }
   /*for(int i = 1; i <= 1000; i++){
       if(hash[i]) cout<<i<<endl;
   }*/
}
int main(){
    freopen("2s.in","r",stdin);
    freopen("oo.txt","w",stdout);
     Init();
     int T,cas = 1;
     cin>>T;
     while(T--){
         int A,B,ans = 0;
         cin>>A>>B;
         for(int i = A; i <= B; i++){
             if(hash[i]) ans++;
         }
         printf("Case #%d: %d\n",cas++,ans);

     }
    return 0;
}
