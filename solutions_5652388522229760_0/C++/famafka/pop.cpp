#include<bits/stdc++.h>
using namespace std;

bool used[10];

void solve(int x)
{
    if(x==0)
        used[0]=1;
    while(x)
    {
        used[x%10]=1;
        x/=10;
    }
}

void go_ans(int t,int x)
{
    cout<<"Case #"<<t<<": "<<x<<"\n";
}

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t=0;
    cin>>t;
    for(int t1=1;t1<=t;t1++)
    {
        int N;
        cin>>N;
        if(N==0)
        {
            cout<<"Case #"<<t1<<": "<<"INSOMNIA\n";
            continue;
        }
        int n=N;
        memset(used,0,sizeof(used));
        for(;;n+=N)
        {
            solve(n);
            bool f=true;
            for(int i=0;i<10;i++)
                if(!used[i])
                {
                    f=false;
                    break;
                }
            if(f)
            {
                go_ans(t1,n);
                break;
            }
        }
    }
}
