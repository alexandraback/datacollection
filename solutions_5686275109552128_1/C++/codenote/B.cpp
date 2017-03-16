#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1000
#define MAX 1000
int a[N + 5];
int main()
{
    int tc,t;
    freopen("C:\\Users\\dell\\Downloads\\inputb.txt","r",stdin);
    freopen("C:\\Users\\dell\\Desktop\\temp\\CODING\\REPOSITORY\\GCJ\\2015\\Qualifing Round\\outputB.txt","w",stdout);
    scanf("%d",&tc);
    for(t = 1 ; t<=tc ; t++)
    {
        int ans=10000000,n,tot=0;
        scanf("%d",&n);

        for(int i = 1 ; i<=n ; i++) scanf("%d",&a[i]);

        for(int j = 1 ; j<=MAX ; j++)
        {
            int cand = j;
            for(int i = 1 ; i<=n ; i++)
            {
                cand = cand + (a[i] - 1)/j;
            }
            ans = min(ans,cand);
        }
        // Printing Starts here for the Test Case
        printf("Case #%d: ",t);
        // Print the result of the code here
        printf("%d",ans);
        //Don't do anything after this.
        printf("\n");
    }
    return 0;
}
