#include<bits/stdc++.h>
#define SIZE 100005
using namespace std;
int visited[1000010],Distance[1000100];
int freverse(int n)
{
    int temp=0;
    while(n>0)
    {
        temp=(temp*10)+n%10;
        n=n/10;
    }
    return temp;
}
int BFS(int n)
{
    queue<int>q;
    visited[1]=1;
    Distance[1]=1;
    int temp,k;
    q.push(1);
    while(!q.empty())
    {
        temp=q.front();
        //cout<<temp<<" ";
        q.pop();
        if(temp==n)return Distance[temp];
        if(!visited[temp+1]&&temp<=1000000)
        {
            visited[temp+1]=1;
            Distance[temp+1]=Distance[temp]+1;
            q.push(temp+1);
        }
        k=freverse(temp);
         if(!visited[k]&&k<=1000000)
        {
            visited[k]=1;
            Distance[k]=Distance[temp]+1;
            q.push(k);
        }
    }
}
int main()
{
     freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int j=0,i,t,res=0,n;
	cin>>t;
	while(t--)
    {
        memset(visited,0,sizeof(visited));
        cin>>n;
        res=BFS(n);
            j++;
            cout<<"Case #"<<j<<": "<<res<<"\n";
    }
	return 0;
}
