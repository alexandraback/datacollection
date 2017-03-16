#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

bool ans;
int tT,t,i,j,now;
int f[500];
char a[5][5];

void O()
 {
  if (ans) return;
  ans=true;
  cout<<"O won"<<endl;
 }

void X()
 {
  if (ans) return;
  ans=true;
  cout<<"X won"<<endl;
 }

void check(int x,int y,int x1,int y1)
 {
  f['O']=0;
  f['X']=0;
  f['T']=0;
  for (int i1=x;i1<=x1;i1++)
   for (int i2=y;i2<=y1;i2++)
    f[a[i1][i2]]++;
  if (f['T']+f['O'] == 4) O();
  if (f['T']+f['X'] == 4) X();
 }

main()
 {
  freopen("input.txt","r",stdin);
  freopen("text.out","w",stdout);
  
  cin>>tT;
  for (t=1;t<=tT;t++)
   {
    cout<<"Case #"<<t<<": ";
    now=0;
    for (i=1;i<=4;i++)
     for (j=1;j<=4;j++)
      { 
       cin>>a[i][j];
       if(a[i][j] == '.') now++;
      }
    ans=false;
    for (i=1;i<=4;i++)
     {
      if (!ans) check(i,1,i,4);
      if (!ans) check(1,i,4,i);
     }
    f['O']=0;
    f['X']=0;
    f['T']=0;
    for (i=1;i<=4;i++)
     f[a[i][i]]++;
   if (!ans && f['T']+f['O'] == 4) O();
   if (!ans && f['T']+f['X'] == 4) X();
   f['O']=0;
   f['X']=0;
   f['T']=0;
    for (i=1;i<=4;i++)
     f[a[i][4-i+1]]++;
    if (!ans && f['T']+f['O'] == 4) O();
    if (!ans && f['T']+f['X'] == 4) X();
    if (!ans)
     {
      if (now != 0) cout<<"Game has not completed"<<endl; else
                    cout<<"Draw"<<endl;
     }
   }
  
 }
