#include<iostream>
#include<fstream>
using namespace std;
int n,m,i,j,t,K; bool wrt=false;
char a[10][10];
bool ch(char x, char y)
{
if (x==y) return true;
if (x=='T'&&y!='.') return true;
if (y=='T'&&x!='.') return true;
return false;
}
bool winx()
{
if (ch(a[1][1],'X')&&ch(a[3][3],'X')&&ch(a[2][2],'X')&&ch(a[4][4],'X')) {/*cout<<"X diag1 "<<endl;*/ return true;}
if (ch(a[4][1],'X')&&ch(a[2][3],'X')&&ch(a[3][2],'X')&&ch(a[1][4],'X')) {/*cout<<"X diag2 "<<endl;*/return true;}
for (i=1;i<=4;i++)
if (ch(a[i][1],'X')&&ch(a[i][2],'X')&&ch(a[i][3],'X')&&ch(a[i][4],'X')) {/*cout<<"X vert "<<i<<endl;*/return true;}
for (i=1;i<=4;i++)
if (ch(a[1][i],'X')&&ch(a[2][i],'X')&&ch(a[4][i],'X')&&ch(a[3][i],'X')) {/*cout<<"X horiz "<<i<<endl;*/return true;}
return false;
}
bool wino()
{
if (ch(a[1][1],'O')&&ch(a[3][3],'O')&&ch(a[2][2],'O')&&ch(a[4][4],'O')) {/*cout<<"O diag1 "<<endl; */return true;}
if (ch(a[4][1],'O')&&ch(a[2][3],'O')&&ch(a[3][2],'O')&&ch(a[1][4],'O')) {/*cout<<"O diag2 "<<endl;*/return true;}
for (i=1;i<=4;i++)
if (ch(a[i][1],'O')&&ch(a[i][2],'O')&&ch(a[i][3],'O')&&ch(a[i][4],'O')) {/*cout<<"O vert "<<i<<endl;*/return true;}
for (i=1;i<=4;i++)
if (ch(a[1][i],'O')&&ch(a[2][i],'O')&&ch(a[4][i],'O')&&ch(a[3][i],'O')) {/*scout<<"O horiz "<<i<<endl;*/return true;}
return false;
}
int main()
{
freopen("A.in","r",stdin);
freopen("A.out","w",stdout);
cin>>t;
for (K=1;K<=t;K++)
{wrt=false;
for (i=1;i<=4;i++)
for (j=1;j<=4;j++)
{cin>>a[i][j]; if (a[i][j]=='.') wrt=true;}
if (winx()) {cout<<"Case #"<<K<<": "<<"X won"<<endl; continue;}
if (wino()) {cout<<"Case #"<<K<<": "<<"O won"<<endl; continue;}
if (wrt) {cout<<"Case #"<<K<<": "<<"Game has not completed"<<endl; continue;}
cout<<"Case #"<<K<<": "<<"Draw"<<endl;
}
//system("pause");


}
