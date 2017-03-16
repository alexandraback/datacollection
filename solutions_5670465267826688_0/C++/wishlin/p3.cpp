#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int cas;
long long L, X;
string str, str4;

int conv(const char& c) {
  if (c=='i') return 1;
  if (c=='j') return 2;
  if (c=='k') return 3;
  return 0;
}
int mulc[4][4]={
                 {0,1,2,3},
                 {1,0,3,2},
                 {2,3,0,1},
                 {3,2,1,0}
                           };
int sign[4][4]={
                 {0,0,0,0},
                 {0,1,0,1},
                 {0,1,1,0},
                 {0,0,1,1}
                           };

int checkSUM() {
  int res_s=0, res_d=0;
  for (int i=0; i<L; ++i) {
    res_s ^= sign[res_d][conv(str[i])];
    res_d = mulc[res_d][conv(str[i])];
  }
  if (X%4==0) return 0;
  if (X%4==1) return res_s==1 && res_d==0;
  if (X%4==2) return res_d!=0;
  if (X%4==3) return res_s==1 && res_d==0;
  return 0;
}

int checkI() {
  int res_s=0, res_d=0;
  for (int i=0; i<str4.length(); ++i) {
    res_s ^= sign[res_d][conv(str4[i])];
    res_d = mulc[res_d][conv(str4[i])];
    if (res_s==0 && res_d==1) return i+1;
  }
  return -1;
}

int checkK() {
  int res_s=0, res_d=0, cc=0;
  for (int i=str4.length()-1; i>=0; --i) {
    res_s ^= sign[conv(str4[i])][res_d];
    res_d = mulc[conv(str4[i])][res_d];
    ++cc;
    if (res_s==0 && res_d==3) return cc;
  }
  return -1;
}

int sol() {
  long long cnt=X>4? 4:X;
  str4="";
  for (int i=0; i<cnt; ++i) str4=str4+str;
  int iI, iK;
  iI=checkI(); iK=checkK();
  long long iL = X*L-iI-iK;
  return iL>0 && iI>0 && iK>0;
}

int main() {
  cin>>cas;
  for (int k=1; k<=cas; ++k) {
    cin>>L>>X>>str;
    if (checkSUM() && sol()) printf("Case #%d: YES\n", k);
    else printf("Case #%d: NO\n", k);
  }
  return 0;
}
