#include <cstdio>
#include <cstdlib>

typedef long long int int64;

//   1  i  j  k
// 1 1  i  j  k
// i i -1  k -j
// j j -k -1  i
// k k  j -i -1

struct ele{ int id, e; };

// 0 1 2 3
// 1 i j k

bool operator==(ele a, ele b){
    return a.id == b.id and a.e == b.e;
}

bool operator!=(ele a, ele b){
    return not(a == b);
}

ele operator*(ele a, ele b){
    ele ret;
    ret.id = a.id*b.id;
    if(a.e*b.e == 0)
        ret.e = a.e + b.e;
    else if(a.e == b.e)
        ret.e = 0, ret.id *= -1;
    else if(a.e + b.e == 3)
        ret.e = 3, ret.id *= (a.e == 1) ? 1 : -1;
    else if(a.e + b.e == 5)
        ret.e = 1, ret.id *= (a.e == 2) ? 1 : -1;
    else if(a.e + b.e == 4)
        ret.e = 2, ret.id *= (a.e == 3) ? 1 : -1;
    return ret;
    // assert(0)
}

void printele(ele a){
    if(a.id == -1) printf("-");
    if(a.e == 0) printf("1");
    if(a.e == 1) printf("i");
    if(a.e == 2) printf("j");
    if(a.e == 3) printf("k");
    return;
}

ele ele_1 = {1, 0};
ele ele_i = {1, 1};
ele ele_j = {1, 2};
ele ele_k = {1, 3};
ele ch2ele(char c){
    if(c == 'i') return ele_i;
    if(c == 'j') return ele_j;
    if(c == 'k') return ele_k;
    return ele_1;
}

char tmp[20000];

ele eles[200000];
int getptr(int s, int len, ele tar){
    ele val = ele_1;
    //printf("---\n");
    for(int lx = s;lx < len;lx++){
        val = val*eles[lx];
        //printele(eles[lx]); printf("->"); printele(val); puts("");
        if(val == tar)
            return lx;
    }
    return -1;
}

int main(){
    int T; scanf("%d", &T);
    for(int lt = 1;lt <= T;lt++){
        int64 L, X; scanf("%lld %lld", &L, &X);
        if(X > 8){
            X %= 8;
            X += 8;
        }
        int total = (int)L*X;
        scanf("%s", tmp);
        for(int lx = 0;lx < X;lx++)
            for(int ly = 0;ly < L;ly++)
                eles[lx*L + ly] = ch2ele(tmp[ly]);
        int i_ptr = getptr(0, total, ele_i);
        //printf("i_ptr = %d\n", i_ptr);
        if(i_ptr == -1){ printf("Case #%d: NO\n", lt); continue; }
        int j_ptr = getptr(i_ptr+1, total, ele_j);
        //printf("j_ptr = %d\n", j_ptr);
        if(j_ptr == -1){ printf("Case #%d: NO\n", lt); continue; }
        int k_ptr = getptr(j_ptr+1, total, ele_k);
        //printf("k_ptr = %d\n", k_ptr);
        if(k_ptr == -1){ printf("Case #%d: NO\n", lt); continue; }
        ele gg = ele_1;
        for(int lx = k_ptr+1;lx < total;lx++){
            gg = gg*eles[lx];
            //printele(eles[lx]); puts("");
        }
        if(!(gg == ele_1)){ printf("Case #%d: NO\n", lt); continue; }
        printf("Case #%d: YES\n", lt);
    }
    return 0;
}
