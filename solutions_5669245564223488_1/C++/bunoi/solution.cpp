#include<cstdio>
#include<cstring>

int co[30][30];

int mid[30];

char tr[110];

const long long M = 1000000007;

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.txt","w",stdout);
    int T,n,l,p,d,a1,a2,kn;
    long long cal = 1;
    long long ans;
    scanf("%d",&T);
    for ( int x=1 ; x<=T ; x++ )
    {
        long long sol2=0;
        ans = 1;
        scanf("%d",&n);
        for ( int c=0 ; c<26 ; c++ )
        {
            for ( int d=0 ; d<26 ; d++ )    co[c][d] = 0;
            mid[c] = 0;
        }
        for ( int c=1 ; c<=n ; c++ )
        {
            kn = 0;
            scanf("%s",tr+1);
            l = strlen(tr+1);
            co[tr[1]-'a'][tr[l]-'a']++;
            for ( d=2 ; d<=l-1 ; d++ )
            {
                if ( tr[d] != tr[d-1] )
                {
                    //p = d;
                    break;
                }
            }
            for (  ; d<=l-1 ; d++ )
            {
                if ( tr[d] != tr[d+1] ) mid[tr[d]-'a']++,kn=1;
            }
            if ( tr[1] == tr[l] and kn == 1 )
            {
                ans = 0;
            }
        }
        if ( ans == 0 )
        {
            printf("Case #%d: 0\n",x);
            continue;
        }
        printf("Case #%d: ",x);
        //printf("/ ");
        /*for ( int c=0 ; c<26 ; c++ )    printf("%c ",c+'a');
        printf("\n");
        for ( int c=0 ; c<26 ; c++ )    printf("%c %d ",c+'a',mid[c]);
        printf("\n");
        for ( int c=0 ; c<26 ; c++ )
        {
            printf("%c ",c+'a');
            for ( int d=0 ; d<26 ; d++ )
            {
                printf("%d ",co[c][d]);
            }
            printf("\n");
        }*/
        //printf("%d\n",mid['p'-'a']);
        int pp;
        for ( int c=0 ; c<26 ; c++ )
        {
            //pp = mid[c];
            if ( mid[c] == 0 )
            {
                pp = 0;
                for ( int d=0 ; d<26 ; d++ )
                {
                    if ( c != d )
                    {
                        pp += co[c][d];
                    }
                }
                if ( pp > 1 )
                {
                    goto e0;
                }
                pp = 0;
                for ( int d=0 ; d<26 ; d++ )
                {
                    if ( c != d )
                    {
                        pp += co[d][c];
                    }
                }
                if ( pp > 1 )   goto e0;
            }
            else if ( mid[c] == 1 )
            {
                pp = 0;
                for ( int d=0 ; d<26 ; d++ )
                {
                    pp += co[c][d];
                    pp += co[d][c];
                }
                if ( pp > 0 )   goto e0;
            }
            else
            {
                goto e0;
            }
        }
        cal = 1;
        ans = 1;
        for ( int c=0 ; c<26 ; c++ )
        {
            cal = 1;
            for ( long long d=2 ; d<=co[c][c] ; d++ )
            {
                cal = (cal*d) % M;
            }
            ans = (ans*cal)%M;
        }
        for ( int c=0 ; c<26 ; c++ )
        {
            a1 = 0 , a2 = 0;
            for ( int d=0 ; d<26 ; d++ )
            {
                if ( c!=d )
                {
                    a1 += co[c][d];
                    a2 += co[d][c];
                }
            }
            if ( a1 == 0 and co[c][c] != 0 )    a1 = 1;
            if ( a1 == 1 and a2 == 0 )  sol2++;
        }
        if ( sol2 == 0 )    ans = 0;
        for ( long long c=2 ; c<=sol2 ; c++ ) ans = (ans * c) % M ;
        printf("%I64d\n",ans);
        continue;
        e0:;
        printf("0\n");
    }
}
