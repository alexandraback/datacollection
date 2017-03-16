#include<bits/stdc++.h>
using namespace std;

#define sz size()
#define pb push_back
#define len length()
#define clr clear()

#define eps 0.0000001
#define PI  3.14159265359

int n;
bool mark[5555];
char ps1[5555],ps2[5555];
string s1[5555],s2[5555];
map<string,int> mapa1, mapa2;

void init() {
    for(int i=0; i<n; i++) mark[i] = false;
    mapa1.clear();
    mapa2.clear();
}

bool ima1(string s){
    return (mapa1.find(s) != mapa1.end() && mapa1[s] > 1);
}

bool ima2(string s) {
    return (mapa2.find(s) != mapa2.end() && mapa2[s] > 1);
}

void ubaci1(string s) {
    if (mapa1.find(s) != mapa1.end()) {
        mapa1[s]++;
    } else {
        mapa1[s] = 1;
    }
    //printf("mapa1 -> %s -> %d\n", s.c_str(), mapa1[s]);
}

void ubaci2(string s) {
    if (mapa2.find(s) != mapa2.end()) {
        mapa2[s]++;
    } else {
        mapa2[s] = 1;
    }
    //printf("mapa2 -> %s -> %d\n", s.c_str(), mapa2[s]);
}

void izbaci1(string s) {
    mapa1[s]--;
}

void izbaci2(string s) {
    mapa2[s]--;
}

int main() {

    FILE *ff=fopen("C-small-attempt1.in", "r"), *gg=fopen("C-small-attempt1.out", "w");

    int i,j,g,tt,br,res,ttt,mask;
    bool bb,b1,b2;

    fscanf(ff,"%d", &ttt);
    for(tt=1;tt<=ttt;tt++) {
        fprintf(gg,"Case #%d: ", tt);

        init();

        fscanf(ff,"%d", &n);

        res = 0;
        for(i=0; i<n; i++) {
            fscanf(ff,"%s%s", ps1, ps2);
            s1[i].assign(ps1);
            s2[i].assign(ps2);
        }

        g = (1<<n);
        for(mask = 0; mask < g; mask++) {
            bb = true;
            br = 0;
            for(i=0; i<n; i++) {
                if (mask & (1<<i)) {
                    br++;
                    b1 = false;
                    b2 = false;
                    for(j=0; j<n; j++) {
                        if ((mask & (1<<j)) == 0) {
                            if (s1[j] == s1[i]) b1 = true;
                            if (s2[j] == s2[i]) b2 = true;
                        }
                    }
                    if (!b1 || !b2) {
                        bb = false;
                        break;
                    }
                }
            }
            if (bb) {
                if (br > res) res = br;
            }
        }


//
//            ubaci1(s1[i]);
//            ubaci2(s2[i]);
//
//            for(j=0; j<=i; j++) if(!mark[j]) {
//                if (ima1(s1[j]) && ima2(s2[j])) {
//                    //printf("u %d brisem %s %s\n", i, s1[j].c_str(), s2[j].c_str());
//                    res++;
//                    mark[j] = true;
//                    izbaci1(s1[j]);
//                    izbaci2(s2[j]);
//                }
//            }
//
//        }

        fprintf(gg, "%d\n", res);
    }

    fclose(ff); fclose(gg);

    return 0;
}
