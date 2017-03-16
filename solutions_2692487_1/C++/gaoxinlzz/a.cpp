#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int T,A,N;
    freopen("A-large.in","r",stdin);
    freopen("A-large.txt","w",stdout);
    while(cin>>T)
    {
        for(int t=1;t<=T;t++)
        {
            cin>>A>>N;
       //     cout<<A<<endl;
            int a[200];
            for(int i=0;i<N;i++)
            {
                cin>>a[i];
            }
            sort(a,a+N);
            int ans=0;
            if(A==1)
            {
                ans=N;
            }
            else
            {
                for(int i=0;i<N;)
                {
                    if(A>a[i])
                    {
                        A+=a[i];
                        i++;
                    }
                    else if(A+A-1>a[i])
                    {
                        ans++;
                        A=A+A-1;
                    }
                    else
                    {
                        int t=0;
                        int B=A;
                        while(B+B-1<=a[i])
                        {
                            t++;
                            B=B+B-1;
                        }
                        t++;
                        A=B+B-1;
                        if(t>=N-i)
                        {
                            ans+=N-i;
                            break;
                        }
                        else
                        {
                            ans+=t;
                  //          cout<<"t=="<<t<<endl;
                        }
                    }
                }
            }
        //    for(int i=0;i<N;i++)cout<<a[i]<<"  ";
         //   cout<<endl;
            if(ans>N)
            {
                ans=N;
            }
            cout<<"Case #"<<t<<": "<<ans<<endl;
        }
    }
    return 0;
}
/*

            for(int i=0;i<N;i++)
            {
                cout<<a[i]<<"  ";
            }
            cout<<endl;
*/
