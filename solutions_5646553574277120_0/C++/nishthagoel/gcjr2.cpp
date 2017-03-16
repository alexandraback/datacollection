#include<bits/stdc++.h>
using namespace std;
int t,c,d,v,arr[35],x,i,j,cnt,temp,k;
int main()
{ freopen("C-small-attempt1.in","r",stdin);
freopen("out.txt","w",stdout);
cin>>t;
for(int j=1;j<=t;j++)
    {

cin>>c>>d>>v;
memset(arr,0,sizeof(arr));
arr[0]=1;
std::queue<int>que;
for(i=0; i<d; i++)
{ cin>>temp;
for(k=0; temp+k<=v; k++)
if(arr[k]==1)
que.push(temp+k);
while(!que.empty())
{ arr[que.front()]=1;
que.pop();
} }
cnt=0;
for(i=1; i<=v; i++)
{ if(arr[i]==0)
{ cnt++;
for(k=0; i+k<=v; k++)
if(arr[k]==1)
que.push(i+k);
}
while(!que.empty())
{ arr[que.front()]=1;
que.pop();
} }
printf("Case #%d: %d\n",j,cnt);
}
return 0;
}
