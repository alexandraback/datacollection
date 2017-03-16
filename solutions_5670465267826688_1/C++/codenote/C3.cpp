
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
    int tc,t;
    freopen("C:\\Users\\dell\\Downloads\\inputc.txt","r",stdin);
    freopen("C:\\Users\\dell\\Desktop\\temp\\CODING\\REPOSITORY\\GCJ\\2015\\Qualifing Round\\outputC3.txt","w",stdout);
    //FILE *fp = fopen("C:\\Users\\dell\\Desktop\\temp\\CODING\\REPOSITORY\\GCJ\\2015\\Qualifing Round\\outputC2.txt","r");
    scanf("%d",&tc);
    for(t = 1 ; t<=tc ; t++)
    {
        int ans=0,l;
        ll X;
        scanf("%d %lld",&l,&X);
        ll P = X%4 + 20;
        int x = (int)min(X,P);
        scanf("%s",s+1);

        for(int i = l+1 ; i<=l*x ; i++)
        {
            s[i] = s[i-l];
        }
        s[l*x +1] = 0;
        l = l*x;

        pref[0] = 0;
        for(int i = 1 ; i<=l ; i++)
        {
            ar[i] = s[i] - 'i' + 1;
            pref[i] = Mult(pref[i-1],ar[i]);
        }
        int save[8] = {0};
        save[0] = 1;
        suff[l+1] = 0;
        for(int i = l ; i>0 ; i--)
        {
            suff[i] = Mult(ar[i],suff[i+1]);
            save[suff[i]]++;
        }
        save[suff[1]]--;
        int val = pref[l];
        for(int i = 1 ; i<=l-2 ; i++)
        {
            save[suff[i+1]]--;

            if(pref[i] == I && save[K] >= 1)
            {
                int v = Mult(I,J);
                v = Mult(v,K);
                if(v == val) ans = 1;
            }
        }
        /*char temp[5];
        fscanf(fp,"%s",temp);
        if(temp[0] == 'Y' && ans == 0)
        {
            printf("%d %d %s\n",l,x,s+1);
        }
        if(temp[0] == 'N' && ans == 1)
        {
            printf("%d %d %s\n",l,x,s+1);
        }*/

        //Printing Starts here for the Test Case
        printf("Case #%d: ",t);
        // Print the result of the code here
        if(ans == 0)printf("NO");
        else printf("YES");
        //Don't do anything after this.
        printf("\n");
    }

    return 0;
}


