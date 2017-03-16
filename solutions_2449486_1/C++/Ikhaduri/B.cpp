#include<iostream>
#include<fstream>
using namespace std;
int t,K,i,j,n,m,a[200][200];
bool check(int x, int y)
{int i,j; int p=0,q=0;
for (i=1;i<=n;i++)
if (a[i][y]>a[x][y]) {p=1;break;}
for (i=1;i<=m;i++)
if (a[x][i]>a[x][y]) {q=1;break;}
if (p*q) return false;
return true;
}
int main()
{
freopen("B.txt.txt","r",stdin);
freopen("BB.txt","w",stdout);
cin>>t;
for (K=1;K<=t;K++)
{ bool b=false;
cin>>n>>m;
for (i=1;i<=n;i++)
for (j=1;j<=m;j++)
cin>>a[i][j];    
for (i=1;i<=n;i++)
for (j=1;j<=m;j++)
if (!check(i,j)) b=true; 
if (b) cout<<"Case #"<<K<<": NO"<<endl; else
cout<<"Case #"<<K<<": YES"<<endl;
}   
//system("pause");    
}
