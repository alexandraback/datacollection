#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <memory.h>
#include <stack>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <queue>
using namespace std;

typedef long long int ll;
vector<string> car;
int ntimes[50] = {};
int ncar;
ll ans;


int main (int argc, char * const argv[]){
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        freopen("B-large.in", "r", stdin);
        freopen("BL.out", "w", stdout);
    #endif // LOCAL


    int ntest;
    while(cin>>ntest){
        for(int tt=0; tt<ntest; tt++){

            cin >> ncar;
            car.clear();
            for(int i=0; i<ncar; i++){
                string tmp;
                cin >> tmp;
                memset(ntimes, 0, sizeof(ntimes));
                //cout << tmp <<endl;
                for(int k=0; k<26; k++){
                    char c;
                    c = ('a' + k);
                    //cout << c <<endl;
                    fflush(stdout);
                    for(unsigned int m=0; m<tmp.size(); m++){
                        if(tmp[m] == c){
                            ntimes[tmp[m] - 'a']++;
                            break;
                        }
                    }
                }
                car.push_back(tmp);
            }
            bool isok = true;
            for(int i=0; i<26; i++){
                if(ntimes[i] >= 3){
                    isok = false;
                    break;
                }
            }
            if(isok){
                bool isgo = true;
                while(isgo){
                    isgo = false;
                    for(int i=0; i<ncar; i++){
                        for(int k=0; k<ncar; k++){
                            if(car[i][0] == car[k][car[k].size()-1]){
                                unsigned sz = car[i].size();
                                for(unsigned int m=0; m < sz; m++){
                                    car[k] = car[k] + car[i][m];
                                }
                                car.erase(car.begin() + i);
                                isgo = true;
                                ncar--;
                                goto out;
                            }
                        }
                    }
out:;
                }
                ans = 1;
                for(unsigned int i=0; i<car.size(); i++){
                    ans *= (i+1);
                }
                printf("Case #%d: %I64d\n", tt+1, ans);

            }else {
                printf("Case #%d: 0\n", tt+1);
            }




        }

    }





    return 0;
}
