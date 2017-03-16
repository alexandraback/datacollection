#include <iostream>
#include <cstdio>
using namespace std;
struct par {
    int a,b;
    par(){};
    par(int _a, int _b) { a = _a; b = _b; }
};


int n;

int typescount1, typescount2;
string types1[20], types2[20];
par elem[20];

bool inc[20];

int gettype1(string s) {
    for (int i = 0; i<typescount1; i++) if (types1[i] == s) return i;
    types1[typescount1++] = s;
    return typescount1-1;
}
int gettype2(string s) {
    for (int i = 0; i<typescount2; i++) if (types2[i] == s) return i;
    types2[typescount2++] = s;
    return typescount2-1;
}

int ans = -1;


bool x[20]; bool y[20];

void checksol() {
    for (int i = 0; i<20; i++) { x[i] = false; y[i] = false; }

    //printf("checking\n");

    int c = 0;
    for (int i = 0; i<n; i++) {
        if (!inc[i]) { c++; continue; }

        //printf("included: %d\n", i);

        x[elem[i].a] = true; y[elem[i].b] = true;
    }

    for (int i = 0; i<typescount1; i++) {
        if (!x[i]) return;
    }
    for (int i = 0; i<typescount2; i++) {
        if (!y[i]) return;
    }

    //printf("accepted as %d\n", c);

    ans = max(ans, c);
}

void bt(int k) {
    if (k == n+1) {
            checksol(); return;
    }
    inc[k] = false;
    bt(k+1);
    inc[k] = true;
    bt(k+1);
    inc[k] = false;
}




int main()
{
    int db; scanf("%d\n", &db);
    for (int cas = 1; cas <=db; cas++) {
        scanf("%d", &n);
        typescount1 = 0;
        typescount2 = 0;
        for (int i = 0; i<n; i++) {
            char c;
            string a = "";
            string b = "";
            scanf("%c", &c);
            while (c != ' ') {
                a+=c;
                scanf("%c", &c);
            }


            scanf("%c", &c);

            while (c != '\n') {
                b+=c;
                scanf("%c", &c);
            }

            elem[i] = par(gettype1(a), gettype2(b));
            //printf("%d %d\n", elem[i].a, elem[i].b);
        }

        for (int i = 0; i<20; i++) inc[i] = false;

        //printf("tc %d %d\n", typescount1, typescount2);

        ans=-1;

        bt(0);

        printf("Case #%d: %d\n", cas, ans);

    }
    return 0;
}
