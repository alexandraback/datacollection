#include<bits/stdc++.h>
using namespace std;
char x[2005];
int ile[30], numer[10];
string S[10];
int F(int nr, char z){  
  numer[nr]=ile[z-'A'];
  for(int i=0;i<S[nr].size();i++){
    ile[S[nr][i]-'A']-=numer[nr];
  }
}
int main(){
  S[0]="ZERO";
  S[1]="ONE";
  S[2]="TWO";
  S[3]="THREE";
  S[4]="FOUR";
  S[5]="FIVE";
  S[6]="SIX";
  S[7]="SEVEN";
  S[8]="EIGHT";
  S[9]="NINE";

  int test;
  scanf("%d",&test);
  for(int t=1;t<=test;t++){
    scanf(" %s", x);
    for(int i=0;x[i];i++){
      int lit=x[i]-'A';
      ile[lit]++;
    }
    F(0,'Z');
    F(2,'W');
    F(8,'G');
    F(6,'X');
    F(4,'U');
    F(1,'O');
    F(5,'F');
    F(7,'V');
    F(9,'I');
    F(3,'R');
    printf("Case #%d: ", t );
    for(int i=0;i<10;i++){
      for(int j=1;j<=numer[i];j++) printf("%d", i);
      numer[i]=0;
    }
    puts("");
  }
  for(int i=0;i<30;i++) ile[i]=0;
  return 0;
}