#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N=109;
int n,m,a[N][N],x[N],y[N];
int init()
{
    memset(x,-1,sizeof(x));
    memset(y,-1,sizeof(y));
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        scanf("%d",&a[i][j]);
        x[i]=max(x[i],a[i][j]);
        y[j]=max(y[j],a[i][j]);
    }
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++) if(x[i]>a[i][j]&&y[j]>a[i][j]) return 0;
    return 1;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int w,cnt=1;
    cin>>w;
    while(w--)
    {
        printf("Case #%d: ",cnt++);
        printf("%s\n",init()?"YES":"NO");
    }
//    cout << "Hello world!" << endl;
    return 0;
}
