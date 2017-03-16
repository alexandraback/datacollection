#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int dx[4]={0,0,-1,1};
int T,i;
int dy[4]={-1,1,0,0};
char dir[4]={'S','N','W','E'};
int x,y;
bool ans;
string ANS;
int abs_(int x){
 if(x<0)return -x;
return x;
}
map < pair < int , int >, int > mp[150];
void dfs(int X,int Y,int d){
 if(abs_(X)>100 || abs_(Y)>100) return;

if(mp[i][make_pair(X,Y)]==10)return;
 mp[i][make_pair(X,Y)]+= 1;

 if(ans)return;
 if(X==x && Y==y){
 ans = true;
 return;}for(int k=0;k<4;k++)
 {
 dfs(X+dx[k]*d,Y+dy[k]*d,d+1);
 if(ans){
ANS+=dir[k];
 break;
 }
}
}
int main(){
 freopen("A.in","r",stdin);freopen("AC.out","w",stdout);

cin >> T;
for(;i<T;i++)
{
 cin >> x >> y;  ans = false;
ANS = "";
 dfs(0,0,1);
cout << "Case #"<<i+1<<": ";
 for(int i=ANS.length()-1;i>=0;i--)cout<<ANS[i];
 cout << endl;
}
return 0;
}
