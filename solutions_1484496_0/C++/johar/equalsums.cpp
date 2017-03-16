#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<cstring>
#include<string>

using namespace std;
int a[20];
int m[2000001];
int main()
{
    int t,T,n,i,j;
    freopen("C-small-attempt0.in","r",stdin);
   freopen("output.txt","w",stdout);   
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        memset(m,0,sizeof m);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            
        }            
        printf("Case #%d: \n",t);
        for(i=1;i<(1<<n);i++)
        {
            int s=0;
            for(j=0;j<n;j++)
            {
                if(i&(1<<j))
                    s+=a[j];
            }
            if(m[s])
            {
                for(j=0;j<n;j++)
                    if(m[s]&(1<<j))
                        cout<<a[j]<<" ";    
                cout<<endl;
                for(j=0;j<n;j++)
                    if(i&(1<<j))
                        cout<<a[j]<<" ";    
                cout<<endl;
                break;
            }
            else m[s]=i;
        }
        if(i==(1<<n))
            cout<<"Impossible\n";
    }
//system("pause");
    return 0;
}
