
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 2000000
#define I 1
#define J 2
#define K 3
int ar[N + 5];
int pref[N+5],suff[N+5];
char s[N + 5];
const int mat[4][4] = {{0,1,2,3},{1,4,3,6},{2,7,4,1},{3,2,5,4}};
int Mult(int a,int b)
{
    int f = 0;
    if(a >= 4)
    {
        f++;
        a = a - 4;
    }
    if(b >= 4)
    {
        f++;
        b = b - 4;
    }
    int c = mat[a][b];
    if(f == 1) c = c^4;
    return c;
}
int main()
{
    int mat[4][4] = {{1,2,2,2},{2,2,3,2},{2,3,3,4},{2,2,4,4}};
    int tc,t;
    freopen("C:\\Users\\dell\\Downloads\\inputd.txt","r",stdin);
    freopen("C:\\Users\\dell\\Desktop\\temp\\CODING\\REPOSITORY\\GCJ\\2015\\Qualifing Round\\outputD.txt","w",stdout);
    scanf("%d",&tc);
    for(t = 1 ; t<=tc ; t++)
    {
        int x,r,c,ans = 0;
        scanf("%d %d %d",&x,&r,&c);
        if(x <= mat[r-1][c-1] && (r*c)%x == 0) ans = 1;
        //Printing Starts here for the Test Case
        printf("Case #%d: ",t);
        // Print the result of the code here
        if(ans == 0)printf("RICHARD");
        else printf("GABRIEL");
        //Don't do anything after this.
        printf("\n");
    }

    return 0;
}


