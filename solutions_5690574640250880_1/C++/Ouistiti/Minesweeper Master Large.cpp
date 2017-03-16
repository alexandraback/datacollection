#include <cstdio>
#include <algorithm>

using namespace std;

int r,m,c,mi;
char ans[51][51];

void print ()
{
    if (r<c)
        for (int i=0;i<r;i++)
        {
            for (int j=0;j<c;j++)
                printf ("%c",ans[i][j]);
            printf ("\n");
        }
    else
        for (int i=0;i<r;i++)
        {
            for (int j=0;j<c;j++)
                printf ("%c",ans[j][i]);
            printf ("\n");
        }
}

void solve ()
{
    int cnt=0,cou=0;
    int k = m%mi;
    if (k==mi) k=0;
    m+=mi-m%mi;
    int n = m/mi;
    for (int i=0;i<k;i++,cou++)
    {
        cnt=0;
        for (int j=0;j<n;j++,cnt++)
            ans[cou][cnt] = '.';
        while (cnt++<c)
            ans[cou][cnt] = '*';
    }
    cou--;
    while (cou++<mi-1)
    {
        cnt=0;
        if (k==1&&cou==1)
            for (int j=0;j<n;j++,cnt++)
                ans[cou][cnt] = '.';
        else if (k==1&&cou==mi-1)
            for (int j=0;j<n-2;j++,cnt++)
                ans[cou][cnt] = '.';
        else
            for (int j=0;j<n-1;j++,cnt++)
                ans[cou][cnt] = '.';
        while (cnt++<c)
            ans[cou][cnt] = '*';
    }
    while (cou++<r)
    {
        cnt=0;
        while (cnt++<c)
            ans[cou][cnt] = '*';
    }
    ans[0][0] = 'c';
    print ();
}

int main ()
{
    freopen ("Minesweeper Master24.in","r",stdin);
    freopen ("Minesweeper Master24.out","w",stdout);
    int t;
    scanf ("%d",&t);
    for (int g=1;g<=t;g++)
    {
        for (int i=0;i<50;i++)
            for (int j=0;j<50;j++)
                ans [i][j] = '*';
        int s=1;
        scanf ("%d %d %d",&r,&c,&m);
        m = r*c-m; 
        while (s*s<m) s++;
        mi = min(min(r,c),s);
        printf ("Case #%d:\n",g);
        if (c==1)
        {
            printf ("c\n");
            for (int i=1;i<m;i++)
                printf (".\n");
            for (int i=m;i<r;i++)   
                printf ("*\n");
        }
        else if (r==1)
        {
            printf ("c");
            for (int i=1;i<m;i++)
                printf (".");
            for (int i=m;i<c;i++)   
                printf ("*");
            printf ("\n");
        }
        else if (m==2||m==3||m==5||m==7) printf ("Impossible\n");
        else if (min(r,c)==2&&m%2==1) printf ("Impossible\n");
        else solve ();
    }
    scanf (" ");
    return 0;
}
