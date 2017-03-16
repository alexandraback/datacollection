//
//  main.cpp
//  codejam
//
//  Created by Silas on 2016. 5. 8..
//  Copyright © 2016년 Silas. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

int popcount(int a) {
    int sum = 0;
    for (int i = 0 ; i < 30; i++) {
        if ((1 << i) & a)
            sum++;
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    
    for (int ti = 1; ti <= tc; ti++) {
        int mw = 0;
        int wear = 0;
        int j, p, s, k;
        cin >> j >> p >> s >> k;
        
        int tb[20], ttb[20][3];
        
        int cnt = 0;
        for (int ji = 1; ji <= j; ji++) {
            for (int pi = 1; pi <= p; pi++) {
                for (int si = 1; si <= s; si++) {
  //                  tb[cnt] = 1 << ji;
   //                 tb[cnt] |= 1 << (ji + pi);
    //                tb[cnt] |= 1 << (ji + pi + si);
                    ttb[cnt][0] = ji;
                    ttb[cnt][1] = pi;
                    ttb[cnt][2] = si;
                    cnt++;
                }
            }
        }
        
        for (int i = 0; i < 1 << cnt; i++) {
            if (popcount(i) <= mw) {
                continue;
            }
            bool flag = true;
            for (int ji = 1; ji <= j; ji++) {
                for (int pi = 1; pi <= p; pi++) {
                    int cnt_k = 0;
                    for (int l = 0; l < cnt; l++) {
                        if ((i & (1 << l)) && ttb[l][0] == ji &&
                            ttb[l][1] == pi) {
                            cnt_k++;
                            if (cnt_k > k)
                                goto end;
                        }
                    }
                    

                }
            }
            
            for (int ji = 1; ji <= j; ji++) {
                for (int si = 1; si <= s; si++) {
                    int cnt_k = 0;
                    for (int l = 0; l < cnt; l++){
                        if ((i & (1 << l)) && ttb[l][0] == ji && ttb[l][2] == si) {
                            cnt_k++;
                            if (cnt_k > k)
                                goto end;
                        }
                    }
                }
            }
            
            for (int pi = 1; pi <= p; pi++) {
                for (int si = 1; si <= s; si++) {
                    int cnt_k = 0;
                    for (int l = 0; l < cnt; l++) {
                        if ((i & (1 << l)) && ttb[l][1] == pi && ttb[l][2] == si) {
                            cnt_k++;
                            if (cnt_k > k)
                                goto end;
                        }
                    }                }
            }
            
            if (flag) {
                mw = popcount(i);
                wear = i;
            }
        end:
            int pp = 2;
        }
        
        printf("Case #%d: %d\n", ti, mw);
        for (int i = 0; i < 30; i++) {
            if (wear & (1 << i)) {
                printf("%d %d %d\n", ttb[i][0], ttb[i][1], ttb[i][2]);
            }
        }
    }
}