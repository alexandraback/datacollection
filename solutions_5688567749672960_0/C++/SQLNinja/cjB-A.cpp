#include<bits/stdc++.h>
using namespace std;
int reverse (int n){
    int ans=0;
    while(n){
        ans=n%10+ans*10;n/=10;
    }
    return ans;
}

int main()
{
   freopen("a.in","r",stdin);
    freopen("out.txt","w",stdout);

    int tc;cin>>tc;
    for(int t=1;t<=tc;t++){

            int n;cin>>n;int ans=0;
            fprintf(stderr, "Case %d :%d \n", t,n);

            cout<<"Case #"<<t<<": ";
            if(n<=20){
                    cout<<n<<endl;
                    continue;
            }
            else  ;//current = 21
            int x=0;int r=0;
            do{
            x=n-10*(n/10)-1;
            ans += x;
            n-=x;
            n=min(n,reverse(n));ans++;
            if(n%10==1&&n!=1){n-=2;ans+=2;}
            }while(n!=1);
            cout<<ans-1<<endl;


    }
}
