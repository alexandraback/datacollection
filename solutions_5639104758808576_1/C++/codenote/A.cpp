#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1000
char str[N + 5];
int main()
{
    int tc,t;
    freopen("C:\\Users\\dell\\Downloads\\inputa.txt","r",stdin);
    freopen("C:\\Users\\dell\\Desktop\\temp\\CODING\\REPOSITORY\\GCJ\\2015\\Qualifing Round\\outputA.txt","w",stdout);
    scanf("%d",&tc);
    for(t = 1 ; t<=tc ; t++)
    {
        int ans=0,n,tot=0;
        scanf("%d %s",&n,str);


        for(int i = 0 ; i<=n ; i++)
        {
            if(i > tot)
            {
                ans += (i - tot);
                tot += (i - tot);
            }
            tot += (str[i] - '0');
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
