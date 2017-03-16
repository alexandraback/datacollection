#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


double a[2000];
double b[2000];
int main()
{
    freopen("C://Users//Jo//Downloads//D-large.in","r",stdin);
    freopen("d://out.txt","w",stdout);
    int t;
    int n;
    cin>>t;

    for(int cas=1;cas<=t;cas++){

        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lf",&a[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%lf",&b[i]);
        }
        sort(a,a+n);
        sort(b,b+n);
        int ans1=0,ans2=0;
        int h1,t1,h2,t2;
        h1=h2=n-1;
        t1=t2=0;
        for(int i=0;i<n;i++){
            if(a[h1]>b[h2]){
                ans1++;
                h1--;h2--;
            }
            else {
                t1++,h2--;
            }
        }
        h1=h2=n-1;
        t1=t2=0;
        for(int i=0;i<n;i++){
            if(a[h1]>b[h2]){
                ans2++;
                h1--;t2++;
            }
            else{
                h1--;h2--;
            }
        }
        printf("Case #%d: %d %d\n",cas,ans1,ans2);
    }
    return 0;
}
