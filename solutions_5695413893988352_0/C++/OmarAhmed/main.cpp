#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector<string> v1,v2;
int sz,t;
string c,j;
void bk(int pos,string s){
if(pos>=sz){v1.push_back(s);return;}
if(s[pos]!='?'){bk(pos+1,s);return;}
    string temp=s;
for(int i=0;i<=9;i++){
    temp[pos]=i+'0';
    bk(pos+1,temp);
temp[pos]='?';
}
}
inline int com(string a, string b){
    if(a.size()!=b.size()){
        return a.size()<b.size();
    }
  for(int i=0;i<a.size();i++){
    if(a[i]!=b[i]){return a[i]<b[i];}
  }
  return -1;
}
int main()
{
    //freopen("in.txt","r",stdin);
       // freopen("out.txt","w",stdout);

scanf("%d",&t);
for(int tt=1;tt<=t;tt++){
    v1.clear();v2.clear();
    cin>>c>>j;
    sz=c.size();
    bk(0,c);
    swap(v1,v2);
    bk(0,j);
    string ans1,ans2;
    long long mn=100000000;
    for(int i=0;i<v1.size();i++){
       for(int j=0;j<v2.size();j++){
long long dif=0;
int x,y;
x=y=0;
for(int k=0;k<sz;k++){
        x*=10;y*=10;
  x+=v1[i][k]-'0';y+=v2[j][k]-'0';

}
dif+=abs(x-y);    if(dif==mn){
    int ret=com(v2[j],ans1);
if(ret==1){ans1=v2[j];ans2=v1[i];}
if(ret==-1&&com(v1[i],ans2)==1){ans2=v1[i];}
}
if(dif<mn){mn=dif;ans1=v2[j];ans2=v1[i];}

        }

    }

    printf("Case #%d: %s %s",tt,ans1.c_str(),ans2.c_str());
    printf("\n");
}

    return 0;
}
