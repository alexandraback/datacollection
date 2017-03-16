//
//  main.cpp
//  typewriter
//
//  Created by Estelle :) on 10/5/15.
//  Copyright (c) 2015 AWESOMENESS. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int keys[26];
pair<int, double> res;
double dp[105][2];
bool vis[105][2];
double word=1.0;
double p=0.0;
int t,k,l,s;

double rec(int ind, bool prev, int words) {
    int a;
    if (prev) a=1;
    else a=0;
    //printf("%d %d %d\n", ind, a, words);
    if (ind==s && prev) return 1;
    if (ind>=s) return 0;
    if (vis[ind][a]) return dp[ind][a];
    vis[ind][a]=true;
    dp[ind][a]+=double(1.0-p)*rec(ind+1,false,words);
    if (res.first==0) dp[ind][a]+=word*rec(ind+l, true,words+1);
    else if (prev==true) dp[ind][a]+=res.second*rec(ind+res.first,true,words+1);
    else {
        dp[ind][a]+=word*rec(ind+l,true,words+1);
    }
    //printf("%d %d %d\n", ind, prev, words);
    return dp[ind][a]+words;
}

int main() {
    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        p=0;
        res.first=0;
        res.second=0;
        for (int j=0; j<105; j++) {vis[j][0]=false; vis[j][1]=false;}
        word=1.0;
        memset(keys,0,sizeof(keys));
        memset(dp,0,sizeof(dp));
        char u;
        scanf("%d%d%d%c", &k, &l, &s, &u);
        for (int j=0; j<k; j++) {
            char c;
            scanf("%c", &c);
            keys[(int)c-65]++;
        }
        string str;
        cin>>str;
        bool pos=true;
        for (int j=0; j<str.length(); j++) {
            if (j==0) p=double(keys[str[j]-65])/double(k);
            if (keys[str[j]-65]==0) {
                pos=false;
                break;
            }
            else {
                word*=(double(keys[str[j]-65])/double(k));
            }
        }
        if (!pos) {
            double ban=0;
            printf("Case #%d: %.7lf\n", i+1, ban);
        }
        else {
            //printf("%lf\n", word);
            for (int j=1; j<str.length(); j++) {
                bool same=true;
                double pr=1.0;
                for (int k=0; k<str.length()-j; k++) {
                    if (str[k]!=str[k+j]) {
                        same=false;
                        break;
                    }
                }
                if (same) {
                    for (int p=j; p<str.length(); p++) {
                        pr*=(double(keys[str[p]-65])/double(k));
                    }
                    res.first=j;
                    res.second=pr;
                    break;
                }
            }
            double ban;
            if (res.first!=0) ban=double(s-l)/double(res.first)+1.0;
            else ban=s/l;
            /*printf("%lf %lf\n", ban, rec(0,false,0));
            printf("%d %lf\n", res.first, res.second);
            for (int i=0; i<s; i++) {
                printf("%lf %lf\n", dp[i][0], dp[i][1]);
            }*/
            printf("Case #%d: %.7lf\n", i+1, ban-rec(0,false,0));
        }
    }
}
