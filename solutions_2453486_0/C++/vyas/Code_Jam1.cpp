#include<iostream>
#include<cstdio>
#include<climits>
#include<utility>
#include<vector>
#include<map>
#include<stack>
#include<deque>
#include<queue>
#include<set>
#include<map>
#include<list>
#include<bitset>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<fstream>
using namespace std;
#define REP(i,a,b) for(long long int i=a;i<b;i++)
#define R return
inline void INPUT(long long int *a){
register char c=0;
while (c<33) c=getchar_unlocked();
*a=0;
while (c>33)
{
*a=*a*10+c-'0';
c=getchar_unlocked();
}
}
inline void INPUT(int *a){
register char c=0;
while (c<33) c=getchar_unlocked();
*a=0;
while (c>33)
{
*a=*a*10+c-'0';
c=getchar_unlocked();
}
}
inline void SWAP(int &a, int &b){
a=b+a-(b=a);
}

/* Code from here
Author : Vedavyas Chigurupati
IIIT - Allahabad
*/

int main(){
long long int i,j,k,n,t,m,x,y,o,tc,e;
char ch;
int flag=0;
INPUT(&t);
e=0;
string arr[4];
k=0;
while(t--){
k++;
e=0;
flag=0;
REP(i,0,4){
cin>>arr[i];
}
REP(i,0,4){
x=o=tc=0;
REP(j,0,4){
ch=arr[i][j];
if(ch=='X') x++;
else if(ch=='O') o++;
else if(ch=='T') tc++;
else e++;
}
if(x+tc>=4 && x>0) {flag=1;cout<<"Case #"<<k<<": X won\n";break;}
else if(o+tc>=4 && o>0) {flag=2;cout<<"Case #"<<k<<": O won\n";break;}
}
if(flag>0) continue;
REP(j,0,4){
x=o=tc=0;
REP(i,0,4){
if(arr[i][j]=='X') x++;
else if(arr[i][j]=='O') o++;
else if(arr[i][j]=='T') tc++;
else e++;
}
if(x+tc>=4 && x>0) {flag=1;cout<<"Case #"<<k<<": X won\n";break;}
else if(o+tc>=4 && o>0) {flag=2;cout<<"Case #"<<k<<": O won\n";break;}
}
if(flag>0) continue;
x=o=tc=0;
REP(i,0,4){
if(arr[i][i]=='X') x++;
else if(arr[i][i]=='O') o++;
else if(arr[i][i]=='T') tc++;
}
if(x+tc>=4 && x>0) {flag=1;cout<<"Case #"<<k<<": X won\n";}
else if(o+tc>=4 && o>0) {flag=2;cout<<"Case #"<<k<<": O won\n";}
if(flag>0) continue;
x=o=tc=0;
for(m=3,y=0;m>=0;m--,y++){
if(arr[m][y]=='X') x++;
else if(arr[m][y]=='O') o++;
else if(arr[m][y]=='T') tc++;
}
if(x+tc>=4 && x>0) {flag=1;cout<<"Case #"<<k<<": X won\n";}
else if(o+tc>=4 && o>0) {flag=2;cout<<"Case #"<<k<<": O won\n";}
if(flag>0) continue;
if(e>0) cout<<"Case #"<<k<<": Game has not completed\n";
else cout<<"Case #"<<k<<": Draw\n";
}
R 0;
}

