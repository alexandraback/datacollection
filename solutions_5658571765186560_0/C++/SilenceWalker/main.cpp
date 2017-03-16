#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,b,a) for(int i=(b);i>=(a);--i)
#define clr(a,x) memset(a,(x),sizeof(a))
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1

int main()
{
    //Getinput(); return 0;
    #ifdef ACM
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
       // freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif // ACM
    /*int fout = open("out.txt",O_WRONLY|O_CREAT,0777);
    char buff[1024];
    rep(X,1,5) rep(R,1,5) rep(C,R,5) {
        printf("%d %d %d:\n",X,R,C);
        rep(i,0,R) {
            rep(j,0,C) putchar('.');
            puts("");
        }
        int x; cin >> x;
        sprintf(buff,"else if (X == %d && R == %d && C == %d) puts(\"%s\");\n",X,R,C,x == 0 ? "GABRIEL" : "RICHARD");
        int len = strlen(buff);
        write(fout,buff,len);
    }
    close(fout);
    */
    int T; cin >> T;
    rep(cas,1,T+1) {
        int X,R,C;
        cin >> X >> R >> C;
        if (R > C) swap(R,C);
        printf("Case #%d: ",cas);
        if (X == 1 && R == 1 && C == 1) puts("GABRIEL");
        else if (X == 1 && R == 1 && C == 2) puts("GABRIEL");
        else if (X == 1 && R == 1 && C == 3) puts("GABRIEL");
        else if (X == 1 && R == 1 && C == 4) puts("GABRIEL");
        else if (X == 1 && R == 2 && C == 2) puts("GABRIEL");
        else if (X == 1 && R == 2 && C == 3) puts("GABRIEL");
        else if (X == 1 && R == 2 && C == 4) puts("GABRIEL");
        else if (X == 1 && R == 3 && C == 3) puts("GABRIEL");
        else if (X == 1 && R == 3 && C == 4) puts("GABRIEL");
        else if (X == 1 && R == 4 && C == 4) puts("GABRIEL");
        else if (X == 2 && R == 1 && C == 1) puts("RICHARD");
        else if (X == 2 && R == 1 && C == 2) puts("GABRIEL");
        else if (X == 2 && R == 1 && C == 3) puts("RICHARD");
        else if (X == 2 && R == 1 && C == 4) puts("GABRIEL");
        else if (X == 2 && R == 2 && C == 2) puts("GABRIEL");
        else if (X == 2 && R == 2 && C == 3) puts("GABRIEL");
        else if (X == 2 && R == 2 && C == 4) puts("GABRIEL");
        else if (X == 2 && R == 3 && C == 3) puts("RICHARD");
        else if (X == 2 && R == 3 && C == 4) puts("GABRIEL");
        else if (X == 2 && R == 4 && C == 4) puts("GABRIEL");
        else if (X == 3 && R == 1 && C == 1) puts("RICHARD");
        else if (X == 3 && R == 1 && C == 2) puts("RICHARD");
        else if (X == 3 && R == 1 && C == 3) puts("RICHARD");
        else if (X == 3 && R == 1 && C == 4) puts("RICHARD");
        else if (X == 3 && R == 2 && C == 2) puts("RICHARD");
        else if (X == 3 && R == 2 && C == 3) puts("GABRIEL");
        else if (X == 3 && R == 2 && C == 4) puts("RICHARD");
        else if (X == 3 && R == 3 && C == 3) puts("GABRIEL");
        else if (X == 3 && R == 3 && C == 4) puts("GABRIEL");
        else if (X == 3 && R == 4 && C == 4) puts("RICHARD");
        else if (X == 4 && R == 1 && C == 1) puts("RICHARD");
        else if (X == 4 && R == 1 && C == 2) puts("RICHARD");
        else if (X == 4 && R == 1 && C == 3) puts("RICHARD");
        else if (X == 4 && R == 1 && C == 4) puts("RICHARD");
        else if (X == 4 && R == 2 && C == 2) puts("RICHARD");
        else if (X == 4 && R == 2 && C == 3) puts("RICHARD");
        else if (X == 4 && R == 2 && C == 4) puts("RICHARD");
        else if (X == 4 && R == 3 && C == 3) puts("RICHARD");
        else if (X == 4 && R == 3 && C == 4) puts("GABRIEL");
        else if (X == 4 && R == 4 && C == 4) puts("GABRIEL");
    }
    return 0;
}


