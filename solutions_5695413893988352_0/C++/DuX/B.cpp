#include<bits/stdc++.h>
using namespace std;

#define sz size()
#define pb push_back
#define len length()
#define clr clear()

#define eps 0.0000001
#define PI  3.14159265359

int n;

char s1[555],s2[555];

long long llabs(long long x) { if (x < 0) return -x; else return x; }

long long t,res,res1,res2;

void idar(int x, int raz, long long t1, long long t2) {

    if (x == n) {

        t = llabs(t1-t2);
        if (res == -1 || t < res || (t == res && t1 < res1) || (t == res && t1 == res1 && t2 < res2)) {
            res = t;
            res1 = t1;
            res2 = t2;
        }

        return;
    }

    if (s1[x] == '?' && s2[x] == '?') {
        if (raz == 0) {
            idar(x+1,0,t1*10,t2*10);
            idar(x+1,1,t1*10+1,t2*10);
            idar(x+1,2,t1*10,t2*10+1);
        } else if (raz == 1) {
            idar(x+1,raz,t1*10,t2*10+9);
        } else if (raz == 2) {
            idar(x+1,raz,t1*10+9,t2*10);
        }
    } else if (s1[x] == '?') {
        if (raz == 0) {
            idar(x+1,0,t1*10+(s2[x]-'0'),t2*10+(s2[x]-'0'));
            if (s2[x] < '9') idar(x+1,1,t1*10+(s2[x]-'0'+1),t2*10+(s2[x]-'0'));
            if (s2[x] > '0') idar(x+1,2,t1*10+(s2[x]-'0'-1),t2*10+(s2[x]-'0'));
        } else if (raz == 1) {
            idar(x+1,raz,t1*10,t2*10+(s2[x]-'0'));
        } else if (raz == 2) {
            idar(x+1,raz,t1*10+9,t2*10+(s2[x]-'0'));
        }
    } else if (s2[x] == '?') {
        if (raz == 0) {
            idar(x+1,0,t1*10+(s1[x]-'0'),t2*10+(s1[x]-'0'));
            if (s1[x] < '9') idar(x+1,2,t1*10+(s1[x]-'0'),t2*10+(s1[x]-'0'+1));
            if (s1[x] > '0') idar(x+1,1,t1*10+(s1[x]-'0'),t2*10+(s1[x]-'0'-1));
        } else if (raz == 1) {
            idar(x+1,raz,t1*10+(s1[x]-'0'),t2*10+9);
        } else if (raz == 2) {
            idar(x+1,raz,t1*10+(s1[x]-'0'),t2*10);
        }
    } else {
        if (raz == 0) {
            if (s1[x] > s2[x]) idar(x+1,1,t1*10+(s1[x]-'0'),t2*10+(s2[x]-'0'));
            else if (s2[x] > s1[x]) idar(x+1,2,t1*10+(s1[x]-'0'),t2*10+(s2[x]-'0'));
            else idar(x+1,0,t1*10+(s1[x]-'0'),t2*10+(s2[x]-'0'));
        } else {
            idar(x+1,raz,t1*10+(s1[x]-'0'),t2*10+(s2[x]-'0'));
        }
    }
}

int main() {

    FILE *ff=fopen("B-small-attempt1.in", "r"), *gg=fopen("B-small-attempt1.out", "w");

    int i,tt,raz,ttt;

    fscanf(ff,"%d", &ttt);
    for(tt=1;tt<=ttt;tt++) {
        fprintf(gg,"Case #%d: ", tt);

        raz = 0;
        fscanf(ff,"%s%s", s1, s2);

        n = strlen(s1);

        res = -1;
        idar(0,0,0,0);

//        for(i=0; i<n; i++) {
//            if (s1[i] == '?' && s2[i] == '?') {
//                if (raz == 0) {
//                    s1[i] = '0';
//                    s2[i] = '0';
//                } else if (raz == 1) {
//                    s1[i] = '0';
//                    s2[i] = '9';
//                } else if (raz == 2) {
//                    s1[i] = '9';
//                    s2[i] = '0';
//                }
//            } else if (s1[i] == '?') {
//                if (raz == 0) s1[i] = s2[i];
//                else if (raz == 1) s1[i] = '0';
//                else if (raz == 2) s1[i] = '9';
//            } else if (s2[i] == '?') {
//                if (raz == 0) s2[i] = s1[i];
//                else if (raz == 1) s2[i] = '9';
//                else if (raz == 2) s2[i] = '0';
//            } else {
//                if (raz == 0) {
//                    if (s1[i] > s2[i]) raz = 1;
//                    else if (s2[i] > s1[i]) raz = 2;
//                }
//            }
//        }

        for(i=n-1; i>=0; i--) {
            s1[i] = '0' + res1%10LL;
            res1/=10LL;
        }

        for(i=n-1; i>=0; i--) {
            s2[i] = '0' + res2%10LL;
            res2/=10LL;
        }

        fprintf(gg, "%s %s\n", s1, s2);
    }

    fclose(ff); fclose(gg);

    return 0;
}
