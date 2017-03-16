#include<iostream>
using namespace std;

inline long long int abs(long long int a){ return a<0?-a:a;}

int main(int agrc, char *argv[]){
  int T; cin>>T;
  for(int tc=1; tc<=T; tc++){
    string a, b; cin >> a >> b;
    long long int mina, minb, maxa, maxb, opta, optb;
    int le = a.length();
    if(a[le-1]!='?'){
      mina = a[le-1] - '0';  maxa = mina; opta = mina;
    }else{
      mina = 0; maxa = 9; opta = 0;
    }
    if(b[le-1]!='?'){
      minb = b[le-1] - '0'; maxb = minb; optb = minb;
    }else{
      minb = 0; maxb = 9; optb = 0;
    }
    if(a[le-1] !='?' || b[le-1] != '?'){
      opta = minb + mina;
      optb = minb + mina;
    }
    long long int pot = 1;
    for(int p=a.length()-2; p>=0; p--){
      pot *= 10;
      long long int an = (a[p]-'0')*pot;
      long long int bn = (b[p]-'0')*pot; 
      //?? -> nothing
      if(a[p]!='?' && b[p]!='?'){
        if(a[p]>b[p]){
          opta = an + mina;
          optb = bn + maxb;
        }
        if(a[p]<b[p]){
          opta = an + maxa;
          optb = bn + minb;
        }
        if(a[p] == b[p]){
          opta += an;
          optb += bn;
        }
      }
      // single ?
      if(a[p] == '?' && b[p]!='?'){
        long long int cmp = 10*pot;
        long long int optanew = opta;
        long long int optbnew = optb;
        if(b[p]>='1' && abs(pot+minb-maxa)<cmp){
          cmp = abs(pot+minb-maxa);
          optbnew = bn + minb;
          optanew = bn+ pot + maxa;
        }
        if(abs(opta-optb)<cmp){
          cmp = abs(opta-optb);
          optbnew = optb + bn;
          optanew = opta + bn;
        }
        if(b[p]<'9' && abs(pot+mina-maxb)<cmp){
          optbnew = bn + maxb;
          optanew = bn + pot + mina;
        }
        opta = optanew;
        optb = optbnew;
      }
      if(a[p] != '?' && b[p]=='?'){
        long long int cmp = 10*pot;
        long long int optanew = opta;
        long long int optbnew = optb;
        if(a[p]>='1' && abs(pot+mina-maxb)<cmp){
          cmp = abs(pot+mina-maxb);
          optanew = an + mina;
          optbnew = an - pot + maxb;
        }
        if(abs(opta-optb)<cmp){
          cmp = abs(opta - optb);
          optbnew = optb + an;
          optanew = opta + an;
        }
        if(a[p]<'9' && abs(pot+minb-maxa)<cmp){
          optanew = an + maxa;
          optbnew = an + pot + minb;
        }
        opta = optanew;
        optb = optbnew;
      }
      // update max, min
      if(a[p]=='?'){
        maxa += 9* pot;
      }else{
        mina += an;  maxa += an;
      }
      if(b[p]=='?'){
        maxb += 9* pot;
      }else{
        minb += bn;  maxb += bn;
      }
    }
    cout<<"Case #"<< tc << ": " << opta << " "<< optb << endl;
  }
  return 0;
}
