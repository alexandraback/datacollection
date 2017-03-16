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
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    std::ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int qwe = 0; qwe < T; qwe ++){
       int x,y;
       string ans = "";
       cin >> x >> y;
       int step = 1;
       int cx=0,cy=0;
       if(x > 0){
         while(cx+step <= x){
            cx += step;
            ans += 'E';
            step ++;
         }
       }else{
         while(cx-step >= x){
           cx -= step;
           ans += 'W';
           step ++;
         }
       }
       if(y > 0){
         while(cy+step <= y){
           cy += step;
           ans += 'N';
           step ++;
         }
       }else{
         while(cy-step >= y){
           cy -= step;
           ans += 'S';
           step ++;
         }
       }
       if(x > 0){
         while(cx < x){
           ans += "WE";
           cx++;
         }
       }else{
         while(cx > x){
           ans += "EW";
           cx --;
         }
       }
       if(y > 0){
         while(cy < y){
            ans += "SN";
            cy ++;
         }
       }else{
         while(cy > y){
            ans += "NS";
            cy --;
         }
       }

       printf("Case #%d: %s\n",qwe+1,ans.c_str());
    }
}
