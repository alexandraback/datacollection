#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int neededType(int Alen, int Blen, int wrongPos, int bkNum)
{
    if (wrongPos == 0){
        return 2 * bkNum + Blen - Alen + 1;
    }
    if (bkNum + wrongPos < Alen + 1){
        return (bkNum * 2 + 2 + 2 * Blen - Alen);
    }
    else{
        return 2 * bkNum + Blen - Alen + 1;
    }
}

int neededTypeEnter(int Blen)
{
    return Blen + 2;
}

int main(void)
{
    int T;
    cin >> T;

    for(int t = 0; t < T; ++t){
        int A, B;
        cin >> A >> B;
        vector<double> ps;
        for(int i = 0; i < A; ++i){
            double tmp;
            cin >> tmp;
            ps.push_back(tmp);
        }

        double exp = neededTypeEnter(B);
        //cout << "exp = " << exp << endl;

        for(int bk = 0; bk <= A; ++bk){
            double tmpExp = 0.0;
            for(int wrongPos = 0; wrongPos <= A; ++wrongPos){
                double prob = 1.0;
                if(wrongPos == 0){
                    for(int j = 0; j < ps.size(); ++j){
                        prob *= ps[j];
                    }
                }
                else{
                    for(int j = 0; j < wrongPos - 1; ++j){
                        prob *= ps[j];
                    }
                    prob *= (1 - ps[wrongPos-1]);
                }

                //cout << "  pos = " << wrongPos << ", prob = " << prob << ", type = " << neededType(A, B, wrongPos, bk) << endl;
                tmpExp += prob * neededType(A, B, wrongPos, bk);
            }
            if (tmpExp < exp){
                exp = tmpExp;
            }
            //cout << "bk " << bk << ", exp = " << tmpExp << endl;
        }
        printf("Case #%d: %7.6f\n", (t+1), exp);
    }

    return 0;
}
