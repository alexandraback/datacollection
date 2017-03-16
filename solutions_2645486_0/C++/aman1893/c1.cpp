#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
#define s(n) scanf("%d",&n)
#define pb push_back
#define ii pair<int,int>
#define mp make_pair
#define S second
#define F first
#define LL long long
using namespace std;
LL val[10000011];
LL val2[10000011];

int main()
{
    int t;
    cin>>t;int c=0;
    while(t--)
    {
        c++;
        int n,r,e;
        cin>>e>>r>>n;
        int arr[n+1];
        for(int i=1;i<n+1;i++)s(arr[i]);
        for(int i=0;i<=e;i++)
        {
            val[i]=1LL*i*arr[n];
        }
        
        int flag=0;
        for(int i=n-1;i>=1;i--)
        {
            if(!flag)
            {
                for(int j=0;j<=e;j++)
                {
                    LL m=-1,temp;
                    for(int k=0;k<=j;k++)
                    {
                        temp=1LL*k*arr[i]+val[min(j-k+r,e)];
                        m=max(temp,m);
                    }
                    val2[j]=m;
                }
                
                flag=1-flag;
            }
            else
             {
                for(int j=0;j<=e;j++)
                {
                    LL m=-1,temp;
                    for(int k=0;k<=j;k++)
                    {
                        temp=k*arr[i]+val2[min((j-k+r),e)];
                        m=max(temp,m);
                    }
                    val[j]=m;
                }
                
                flag=1-flag;
            }
        }
        if(flag)cout<<"Case #"<<c<<": "<<val2[e]<<endl;
        else
        cout<<"Case #"<<c<<": "<<val[e]<<endl;
    }
}           
            
            
        
        
                
        
