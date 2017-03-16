#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<sstream>
using namespace std;
#define S(a) scanf("%d",&(a))
int main(){
int test,count=1,ans,n,c;
string str;
freopen("A-small-attempt0.in","r",stdin);
freopen("output.txt","w",stdout);
S(test);
while(test--){
ans=0;
cin>>str;
S(n);
for(int i=0;i<str.length();i++)
for(int j=i+n;j<=str.length();j++){
c=0;
for(int k=i;k<j;k++){

if(str[k]=='a' || str[k]=='e' || str[k]=='i'|| str[k]=='o' || str[k]=='u')
c=0;
else
c++;
if(c>=n){
ans++;
break;
}
}
}

printf("Case #%d: %d\n",count++,ans);
}
}
