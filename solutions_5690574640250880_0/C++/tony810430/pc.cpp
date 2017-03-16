#include<stdio.h>


int T,cas,R,C,M;
char m[100][100];
int tag;

void init()
{
    for( int i = 0; i < R; i++ )
        for( int j = 0; j < C; j++ )
            m[i][j] = '*';
    tag = 0;
}

void solveA()
{
    int cnt = R*C-M;
    for( int i = 0; i < cnt; i++ )
        m[i%R][i/R] = '.';
    m[0][0] = 'c';
}

void solveB()
{
    int cnt = R*C-M;
    for( int i = 0; i < cnt; i++ )
        m[i/C][i%C] = '.';
    m[0][0] = 'c';
}

void print()
{
    printf("Case #%d:\n",cas);
    if( tag != 0 )puts("Impossible");
    else{
        for( int i = 0; i < R; i++ ){
            for( int j = 0; j < C; j++ )
                printf("%c",m[i][j]);
            puts("");
        }
    }
}

void solveC()
{
    int cnt = R*C-M;
    if( cnt%2 == 0 ){
        for( int i = 0; i < cnt/2; i++ )
            for( int j = 0; j < 2; j++ )
                m[i][j] = '.';
    }else{
        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                m[i][j] = '.';
        cnt -= 9;
        for( int i = 3; i < 3+cnt/2; i++ )
            for( int j = 0; j < 2; j++ )
                m[i][j] = '.';
    }
    m[0][0] = 'c';
}

void solve()
{
    int cnt = R*C-M;
    if( cnt < C*2 ){
        solveC();
    }else if( cnt == C*2+1 ){
        for( int i = 0; i < C-1; i++ )
            m[0][i] = m[1][i] = '.';
        cnt -= 2*(C-1);
        m[2][0] = m[2][1] = m[2][2] = '.';
        m[0][0] = 'c';
    }else{
        solveB();
        if( cnt%C == 1 ){
            m[cnt/C][cnt%C] = '.';
            m[(cnt-2)/C][(cnt-2)%C] = '*';
        }
    }
}

int main()
{
    freopen("C-small-attempt2.in","r",stdin);
    freopen("pc.small","w",stdout);
    scanf(" %d",&T);

    for( cas = 1; cas <= T; cas++ ){
        scanf(" %d %d %d",&R,&C,&M);
        init();
        int tmp = R*C-M;
        if( tmp == 1 ){
            m[0][0] = 'c';
        }else if( R == 1 || C == 1 ){
            if( R == 1 ) solveA();
            else    solveB();
        }else if( tmp < 4 || tmp == 5 || tmp == 7 ){
            tag = -1;
        }else if( ( R == 2 || C == 2 ) && tmp%2 == 1 ){
            tag = -1;
        }else{
            solve();
        }
        print();
    }
    return 0;
}
