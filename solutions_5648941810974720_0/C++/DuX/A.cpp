#include<bits/stdc++.h>
using namespace std;

#define sz size()
#define pb push_back
#define len length()
#define clr clear()

#define eps 0.0000001
#define PI  3.14159265359

string broj[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int br[555];
char s[5555],q[5555];
string res;

void smanji(string s) {
    for(int i=0; i<s.size(); i++) {
        br[s[i]]--;
    }
}

int main() {

    int i,n,tt,ttt;

    FILE *ff=fopen("A-small-attempt0.in", "r"), *gg=fopen("A-small-attempt0.out", "w");

    fscanf(ff,"%d", &ttt);
    for(tt=1;tt<=ttt;tt++) {
        fprintf(gg,"Case #%d: ", tt);

        fscanf(ff,"%s", &s);

        for(i='A'; i<='Z'; i++) br[i] = 0;

        n = strlen(s);
        for(i=0; i<n; i++) {
            br[s[i]]++;
        }

        res = "";
        while(br['Z'] > 0) {
            res += '0';
            smanji(broj[0]);
        }

        while(br['W'] > 0) {
            res += '2';
            smanji(broj[2]);
        }

        while(br['X'] > 0) {
            res += '6';
            smanji(broj[6]);
        }

        while(br['G'] > 0) {
            res += '8';
            smanji(broj[8]);
        }

        while(br['H'] > 0) {
            res += '3';
            smanji(broj[3]);
        }

        while(br['S'] > 0) {
            res += '7';
            smanji(broj[7]);
        }

        while(br['V'] > 0) {
            res += '5';
            smanji(broj[5]);
        }

        while(br['I'] > 0) {
            res += '9';
            smanji(broj[9]);
        }

        while(br['R'] > 0) {
            res += '4';
            smanji(broj[4]);
        }

        while(br['O'] > 0) {
            res += '1';
            smanji(broj[1]);
        }

        printf("-> %s\n", res.c_str());

        for(i=0; i<res.size(); i++) {
            q[i] = res[i];
        }

        sort(q,q+res.size());

        q[res.size()] = 0;

        fprintf(gg, "%s\n", q);
    }

    fclose(ff); fclose(gg);

    return 0;
}
