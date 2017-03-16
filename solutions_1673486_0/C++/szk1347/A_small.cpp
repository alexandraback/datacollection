/*
 * Author: szk1347
 * Created Time:  2012/4/28 9:16:27
 * File Name: A_small.cpp
 */
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

double p[20];
double expection[20];
double ans;
int res;
int A,B;
int T;
int main() {
    freopen("A_in.txt","r",stdin);
    freopen("A_out.txt","w",stdout);
    cin >> T;
    for(int cas = 1;cas <= T;++cas){
        memset(expection,0,sizeof(expection));
        ans = 100000000;
        cin >> A >> B;
        for(int i = 1;i <= A;++i){
            cin >> p[i];
        }
        switch(A){
            case 1:
                expection[0] = B*p[1] + (2*B + 1)*(1 - p[1]);
                expection[1] = B + 2;
                expection[2] = B + 2;
                for(int i = 0;i <= 2;++i){
                    if(expection[i] < ans){
                        ans = expection[i];
                        res = i;
                    }
                }
                break;
            case 2:
                expection[0] = (B - 2 + 1)*p[1]*p[2] + (B - 2 + 1 + B + 1)*( 1 - p[1]*p[2]);
                expection[1] = (1 + B - 1 + 1)*p[1] + (1 + B - 1 + 1 + B + 1)*(1 - p[1]);
                expection[2] = (B + 2 + 1);
                expection[3] = B + 2;
                for(int i = 0;i <= 3;++i){
                    if(expection[i] < ans){
                        ans = expection[i];
                        res = i;
                    }
                }
                break;
            case 3:
                expection[0] = (B - 3 + 1)*p[1]*p[2]*p[3] + 
                    (B - 3 + 1 + B + 1)*(1 - p[1]*p[2]*p[3]);
                expection[1] = (1 + B - 2 + 1)*p[1]*p[2] + (1 + B - 2 + 1 + B + 1)*(1 - p[1]*p[2]);
                expection[2] = (2 + B - 1 + 1)*p[1] + (2 + B - 1 + 1 + B + 1)*(1 - p[1]);
                expection[3] = 3 + B + 1;
                expection[4] = 1 + B + 1;
                for(int i = 0;i <= 4;++i){
                    if(expection[i] < ans){
                        ans = expection[i];
                        res = i;
                    }
                }
                break;
        }
        printf("Case #%d: %.6lf\n",cas,ans);
        //cout << res << endl;
    }
                
    return 0;
}

