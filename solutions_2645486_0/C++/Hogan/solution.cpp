#include<cstdio>
#include<cstring>
#include<utility>

struct node{
    int v, l, r, m, myMax, tag;
}con[40010];

int T, e, c, n, in[10000], flag;

int Min(int a, int b){return a<b ?a:b;}
int Max(int a, int b){return a<b ?b:a;}

std::pair<int, int> pairMax(const std::pair<int, int> &a, const std::pair<int, int> &b){
    return a.first<b.first ?b :a;
}

void build(int t, int l, int r){
    con[t].l = l, con[t].r = r, con[t].m = (l + r)/2;

    if (l == r){
        con[t].m = con[t].myMax = in[flag];
        con[t].tag = ++flag;
        return;
    }

    build(2*t, l, con[t].m);
    build(2*t+1, con[t].m + 1, r);

    if (con[2*t].myMax < con[2*t + 1].myMax){
        con[t].myMax = con[2*t + 1].myMax;
        con[t].tag = con[2*t + 1].tag;
    }
    else {
        con[t].myMax = con[2*t].myMax;
        con[t].tag = con[2*t].tag;
    }
}

std::pair<int, int> getMax(int t, int l, int r){
    if (con[t].l == l && con[t].r == r){
        return std::pair<int, int>(con[t].myMax, con[t].tag);
    }

    if (r <= con[t].m)  return getMax(2*t, l, r);
    else if (l > con[t].m)  return getMax(2*t + 1, l ,r);
    else    return pairMax(getMax(2*t, l, con[t].m), getMax(2*t + 1, con[t].m + 1, r));
}

int check(int l, int r, int ll, int rr){
    if (l > r)  return 0;
    std::pair<int, int> tmp;

    tmp = getMax(1, l, r);
    //printf("%d %d\n", tmp.first, tmp.second);

    int ans = 0;
    if (ll == -1 && rr == -1)    ans += e * tmp.first;
    else if (ll == -1)  ans += Min(e, (rr - tmp.second) * c - Min((rr - tmp.second - 1) * c, e)) * tmp.first;
    else if (rr == -1)  ans += Min((tmp.second - ll) * c, e) * tmp.first;
    else    ans += Min(Min((tmp.second - ll) * c, e), (rr - tmp.second) * c - Min((rr - tmp.second - 1) * c, e)) * tmp.first;

    ans += check(l, tmp.second - 1, ll, tmp.second);
    ans += check(tmp.second + 1, r, tmp.second, rr);

    return ans;
}

int main(){

    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);

    scanf("%d", &T);

    for (int i=0; i<T; i++){
        scanf("%d%d%d", &e, &c, &n);
        for (int j=0; j<n; j++) scanf("%d", &in[j]);

        memset(con, 0, sizeof(con));
        flag = 0;
        build(1, 1, n);

        int ans = check(1, n, -1, -1);
        printf("Case #%d: %d\n", i+1, ans);
    }
}
