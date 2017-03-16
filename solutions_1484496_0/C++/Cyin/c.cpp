#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
map <int,int> h;
int n,a[30],sum;
int ax[30],ay[30];
int main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int ca,cc=0;
    int i,j,k;
    scanf("%d",&ca);
    while (ca--){
        scanf("%d",&n);
        for (i=0;i<n;i++) scanf("%d",&a[i]);
        h.clear();
        sum=0;
        for (i=1;i<(1<<n);i++){
            sum=0;
            for (j=0;j<n;j++)
                if (i&j) sum+=a[j];
            if (!h[sum]) h[sum]=i;
            else {
                int t=h[sum];
                for (j=0;j<n;j++)
                    if (t&j) ax[j]=a[j];
                    else ax[j]=-1;
                t=i;
                for (j=0;j<n;j++)
                    if (t&j) ay[j]=a[j];
                    else ay[j]=-1;
                break;
            }
        }
        cc++;
        printf("Case #%d:\n",cc);
        j=n-1;while (ax[j]<0) j--;
        for (i=0;i<j;i++) 
            if (ax[i]>0) printf("%d ",ax[i]);
        printf("%d\n",a[j]);
        j=n-1;while (ay[j]<0) j--;
        for (i=0;i<j;i++) 
            if (ay[i]>0) printf("%d ",ay[i]);
        printf("%d\n",a[j]);
    }
    return 0;
}
            
            
