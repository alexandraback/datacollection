#include <cstdio>

int r, c;
int k;

char deck[50][50];

int main()
{
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T; ++cas)
    {
        scanf("%d %d %d", &r, &c, &k);
        k = r*c - k;
        for(int i=0; i<r; ++i)
            for(int j=0; j<c; ++j)
                deck[i][j] = '*';

        printf("Case #%d:\n", cas);
        if(k==1) goto print;
        if(r==1 or c==1)
        {
            for(int i=0, g=0; i<r && g<k; ++i)
                for(int j=0; j<c && g<k; ++j, ++g)
                    deck[i][j] = '.';
        }
        else if(r==2 or c==2)
        {
            if(k%2!=0 or k==2) goto impossible;
            if(r==2)
                for(int i=0; i<k/2; ++i)
                    deck[0][i] = deck[1][i] = '.';
            else
                for(int i=0; i<k/2; ++i)
                    deck[i][0] = deck[i][1] = '.';
        }
        else
        {
            if(k==2 or k==3 or k==5 or k==7) goto impossible;
            if(k < 2*c)
            {
                if(k%2 != 0)
                {
                    k-=3;
                    deck[2][0] = deck[2][1] = deck[2][2] = '.';
                }
                for(int i=0; i<k/2; ++i)
                    deck[0][i] = deck[1][i] = '.';
            }
            else
            {
                bool flag = (k%c==1);
                int rr = k/c;
                for(int i=0; i<r && k>0; ++i)
                    for(int j=0; j<c && k>0; ++j, --k)
                        deck[i][j] = '.';
                if(flag)
                {
                    deck[rr][1] = '.';
                    deck[rr-1][c-1] = '*';
                    if(rr == 2)
                    {
                        deck[rr][2] = '.';
                        deck[rr-2][c-1] = '*';
                    }
                }
            }
        }
        print:
            deck[0][0] = 'c';
            for(int i=0; i<r; ++i)
            {
                for(int j=0; j<c; ++j)
                    printf("%c", deck[i][j]);
                putchar('\n');
            }
            continue;
        impossible:
            puts("Impossible");
    }
    return 0;
}
