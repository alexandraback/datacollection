#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <set>
using namespace std;

struct attack{
    int day;
    int westInterval;
    int eastInterval;
    int strength;
};
typedef struct attack Attack;

int walls[10000];

int main () {
	
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
    	int N;
        cin >> N;
        int success = 0;
        set<int> theDays;
        int d, n, w, e, s, dd, dp, ds;
        vector<Attack> attacks;
        for (int i=0; i<N; i++) {
            scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
            for (int j=0; j<n; j++) {
                Attack xdd;
                xdd.day = d + j*dd;
                xdd.westInterval = w + j*dp;
                xdd.eastInterval = e + j*dp;
                xdd.strength = s + j*ds;
                attacks.push_back(xdd);
                theDays.insert(xdd.day);
            }
        }
        for (int i=0; i<10000;i++) walls[i] = 0;
        int* theWall = walls + 5000;
        //printf("%d\n", attacks.size());
        for (set<int>::iterator it=theDays.begin(); it!=theDays.end(); it++) {
            int theday = *it;
            //int miniStr = 0;
            // check for all attack
            for (int i=0; i<attacks.size(); i++) {
                if (attacks[i].day == theday) {
                    for (int j=attacks[i].westInterval; j < attacks[i].eastInterval; j++) {
                        if (theWall[j] < attacks[i].strength) {
                            // attack succeed
                            success++;
                            //printf("%d success, str = %d\n", theday, attacks[i].strength);
                            break;
                        }
                    }
                }
            }
            for (int i=0; i<attacks.size(); i++) {
                if (attacks[i].day == theday) {
                    for (int j=attacks[i].westInterval; j < attacks[i].eastInterval; j++) {
                        if (theWall[j] < attacks[i].strength) {
                            // attack succeed
                            theWall[j] = attacks[i].strength;
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d\n", t, success);
    }
    return 0;
}