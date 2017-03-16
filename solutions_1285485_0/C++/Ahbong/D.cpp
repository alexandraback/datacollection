#include <cstdio>
#include <utility>

    using std::make_pair;
    using std::pair;

    int T, H, W, D;
    char m[30][31];

pair<int, int>
find_X() {
    for(int i=0; i<H; ++i) {
        for(int j=0; j<W; ++j) {
            if(m[i][j]=='X') {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

pair<int, int>
traverse(pair<int, int> X, int rel_y, int rel_x)
{
    int dy = (rel_y<0)?(-1):(1), dx = (rel_x<0)?(-1):(1);
    rel_y *= dy;
    rel_x *= dx;
    int ty = 0, tx = 0;
    while(ty!=rel_y || tx!=rel_x) {
        if((ty+1)*(rel_x+1)==(tx+1)*(rel_y+1)) { // traverse_xy
            ++tx, ++ty;
            if(m[X.first+dy][X.second+dx]=='#') {
                if(m[X.first+dy][X.second]=='#' ||
                   m[X.first][X.second+dx]=='#') { // reflect_any
                    if(m[X.first+dy][X.second]=='#') { // reflect y
                        dy = -dy;
                    }
                    else {
                        X.first += dy;
                    }
                    if(m[X.first][X.second+dx]=='#') { // reflect x
                        dx = -dx;
                    }
                    else {
                        X.second += dx;
                    }
                }
                else { // vanish
                    return make_pair(-1, -1);
                }
            }
            else {
                X.first += dy;
                X.second += dx;
            }
        }
        else if((tx+1)*(rel_y+1)<(ty+1)*(rel_x+1)) { // traverse_x
            ++tx;
            if(m[X.first][X.second+dx]=='#') { // reflect_x
                dx = -dx;
            }
            else {
                X.second += dx;
            }
        }
        else if((tx+1)*(rel_y+1)>(ty+1)*(rel_x+1)) { // traverse_y
            ++ty;
            if(m[X.first+dy][X.second]=='#') { // reflect_y
                dy = -dy;
            }
            else {
                X.first += dy;
            }
        }
        //if(OX==X && (ty!=rel_y || tx!=rel_x))
        //    printf("    %d %d   %d %d\n", ty, tx, rel_y, rel_x);
        if(m[X.first][X.second]=='X' && ty*rel_x==tx*rel_y && (ty!=rel_y || tx!=rel_x)) {
            return make_pair(-1, -1);
        }
        //printf("  %d %d\n", X.first, X.second);
    }
    return X;
}

bool
check_ans(pair<int, int> X, int rel_y, int rel_x)
{
    //printf("Soliving %d %d...\n", rel_y, rel_x);
    if(X==traverse(X, rel_y, rel_x)) {
        //printf(" Y\n");
        return true;
    }
    //printf("\n");
    return false;
}

int
main()
{
    //freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    for(int z=1; z<=T; ++z) {
        scanf("%d %d %d", &H, &W, &D);
        for(int i=0; i<H; ++i) {
            scanf("%s", m[i]);
        }
        pair<int, int> X = find_X();
        int ans = 0;
        for(int j=1; j<=D; ++j) { // i = 0
            if(check_ans(X, 0, j)) {
                ++ans;
            }
            if(check_ans(X, 0, -j)) {
                ++ans;
            }
        }
        for(int i=1; i<=D; ++i) {
            if(check_ans(X, i, 0)) {
                ++ans;
            }
            if(check_ans(X, -i, 0)) {
                ++ans;
            }
            for(int j=1; i*i+j*j<=D*D; ++j) {
                if(check_ans(X, i, j)) {
                    ++ans;
                }
                if(check_ans(X, -i, j)) {
                    ++ans;
                }
                if(check_ans(X, i, -j)) {
                    ++ans;
                }
                if(check_ans(X, -i, -j)) {
                    ++ans;
                }
            }
        }
        printf("Case #%d: %d\n", z, ans);
    }
    return 0;
}
