// created by Marchecnko Vadim [midav7]
// I did it just for fun =)
// v 0.5

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <conio.h>
#include <cmath>
#include <map>
#include <set>
#include <climits>

#define foread freopen("input.txt","r",stdin)
#define fowrite freopen("output.txt","w",stdout)
#define pi 3.141592

using namespace std;
int mas[200];
int main(){
int n;
foread;
fowrite;
string ans[5];
int flag;
ans[0]="O won";
ans[1]="X won";
ans[2]="Draw";
ans[3]="Game has not completed";
string s[6];
scanf("%d \n",&n);
for (int kk=1; kk<=n; ++kk) {
  for (int j=1; j<=4; ++j) {
    getline(cin,s[j]);
    scanf("\n");
    }
  flag=2;
  printf("Case #%d: ",kk);
  for (int i=1; i<=4; ++i) {
    for (int j=1; j<=120; ++j) mas[j]=0;
    for (int j=0; j<4; ++j) ++mas[s[i][j]];
    if (mas['O']==4 || (mas['O']==3 && mas['T']==1)) flag=0;
    if (mas['X']==4 || (mas['X']==3 && mas['T']==1)) flag=1;
  }
  for (int i=0; i<4; ++i) {
    for (int j=1; j<=120; ++j) mas[j]=0;
    for (int j=1; j<=4; ++j) ++mas[s[j][i]];
    if (mas['O']==4 || (mas['O']==3 && mas['T']==1)) flag=0;
    if (mas['X']==4 || (mas['X']==3 && mas['T']==1)) flag=1;
  }
  for (int j=1; j<=120; ++j) mas[j]=0;
    for (int j=1; j<=4; ++j) ++mas[s[j][j-1]];
    if (mas['O']==4 || (mas['O']==3 && mas['T']==1)) flag=0;
    if (mas['X']==4 || (mas['X']==3 && mas['T']==1)) flag=1;
  for (int j=1; j<=120; ++j) mas[j]=0;
    for (int j=1; j<=4; ++j) ++mas[s[j][4-j]];
    if (mas['O']==4 || (mas['O']==3 && mas['T']==1)) flag=0;
    if (mas['X']==4 || (mas['X']==3 && mas['T']==1)) flag=1;
  if (flag==2) 
    for (int i=1; i<=4; ++i)
      for (int j=0; j<4; ++j)
        if (s[i][j]=='.') flag=3; 
   cout << ans[flag] << endl; 
  scanf("\n");
  }
return 0;
}