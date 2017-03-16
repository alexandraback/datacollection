#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
#include<vector>
int ans[5000005];
int temp[5000005];
typedef long long ll;
using namespace std;
int main()
{



//ifstream fin("input.in");
ifstream fin("A-large.in");
ofstream fout("output3.txt");
char c;
vector<char> arr(12000);
vector<char> pran(1000009);
vector<char> codejam(10010);

ll i,j,k,l,m,n,t,sum,last,p,q,flag;

//vector<char> str(1000010);

fin>>t;

//fin>>chh;
for(int m=1;m<=t;m++)
{
string str;
sum=0;
fin>>str;
l=str.size();
fin>>n;
ll XX=n;
for(int tem=0;tem<2000;tem++);
//fin>>chh;
str.insert(str.begin(),'a');
flag=true;
last=0;
for(ll temp=0;temp<=XX;temp++)
{
int xx=55;
int yy= 66;
xx= yy+45;

}
for(i=1;i+n-1<=l;i++)
{
k=0;
for(j=i;j<=l;j++)
{
if(str[j]!='a' && str[j]!='e'&& str[j]!='i' && str[j]!='o' && str[j]!='u')
k++;
else
break;
}
if(k>=n)
{
while(k>=n)
{
if(flag)
{
p=(i-last);
q=l-(i+n-1)+1;
sum+=(p*q);
last=i;
flag=false;
}
else
{
p=(i-last);
q=l-(i+n-1)+1;
sum+=(p*q);
last=i;
}
i++;
k--;
}
}
else
i=j;
}
for(int temp=0;temp<=XX;temp++)
{

int xx=55;
int yy= 66;
xx= yy+45;

}

fout<<"Case #"<<m<<": "<<sum<<"\n";

}
}
