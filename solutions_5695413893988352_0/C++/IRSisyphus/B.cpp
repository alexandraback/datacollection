#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int T;

int main(){
    freopen("small.in", "r", stdin);
    freopen("small.out", "w", stdout);
    scanf("%d\n", &T);
    for (int t = 1; t <= T; ++t){
        string c, j;
        cin >> c >> j;
        int siz = c.length();
        bool flag = true;
        for (int i = 0; i < siz && flag; ++i){
            if (c[i] == j [i]){
                if (c[i] =='?'){
                    c[i] = j[i] = '0';
                }
                continue;
            }
            if (c[i] == '?'){


                if (j[i+1] == '?' && c[i+1] != '?'){
                    c[i] = j[i];
                    j[i+1] = c[i+1];
                } else if (j[i+1] == '?' && c[i+1] == '?'){
                    c[i] = j[i];

                    //TODO:Change from here
                    if (c[i+2] == '?' && j[i+2] == '?'){
                        c[i+1] = j[i+1] = c[i+2] = j[i+2] = '0';
                    } else if (j[i+2] == '?'){
                        if (c[i+2] >= '5'){
                            c[i] = c[i] -1;
                            c[i+1] = '9';
                            j[i+1] = j[i+2] = '0';
                        } else {
                            c[i+1] = j[i+1] = c[i+2] = j[i+2] = '0';
                        }
                    } else if (c[i+2] == '?'){
                        c[i+1] = j[i+1] = '0';
                        c[i+2] = j[i+2];

                    } else if ((j[i+2] - c[i+2] > 5)){
                        j[i+1] = '0';
                        c[i+1] = '1';
                    } else if ((c[i+2] - j[i+2] >= 5)){
                        c[i] = c[i] - 1;
                        j[i+1] = '0';
                        c[i+1] = '9';
                    } else {
                        c[i+1] = j[i+1] = '0';
                    }

                    //TODO:Change to here
                    flag = false;



                } else if (j[i+1] != '?' && c[i+1] == '?'){
                    c[i] = j[i];
                    c[i+1] = j[i+1];
                } else {
                    if (j[i+1] - c[i+1] > 5 && j[i] != '9'){
                        c[i] = j[i] + 1;
                        for (int k = i+2; k < siz; ++k){
                            if (j[k] == '?') j[k] = '9';
                            if (c[k] == '?') c[k] = '0';
                        }
                        flag = false;

                    } else if ((j[i+1] - c[i+1] <= 5 && j[i+1] - c[i+1] > 0) || (j[i+1] - c[i+1] > 5 && j[i] == '9')){
                        c[i] = j[i];
                        for (int k = i+2; k < siz; ++k){
                            if (j[k] == '?') j[k] = '0';
                            if (c[k] == '?') c[k] = '9';
                        }
                        flag = false;


                    }  else if ((c[i+1] - j[i+1] <= 5 && c[i+1] - j[i+1] > 0) || (c[i+1] - j[i+1] > 5 && j[i] == '0') ){
                        c[i] = j[i];
                        for (int k = i+2; k < siz; ++k){
                            if (j[k] == '?') j[k] = '9';
                            if (c[k] == '?') c[k] = '0';
                        }
                        flag = false;



                    }  else if (c[i+1] - j[i+1] > 5 && j[i] != '0'){
                        c[i] = j[i] - 1;
                        for (int k = i+2; k < siz; ++k){
                            if (j[k] == '?') j[k] = '0';
                            if (c[k] == '?') c[k] = '9';
                        }
                        flag = false;


                    } else {
                        c[i] = j[i];
                    }
                }

                ++i;
                continue;
            }


            if (j[i] == '?'){
                if (c[i+1] == '?' && j[i+1] != '?'){
                    j[i] = c[i];
                    c[i+1] = j[i+1];
                } else if (c[i+1] == '?' && j[i+1] == '?'){
                    j[i] = c[i];


                    //TODO:Change from here
                    if (c[i+2] == '?' && j[i+2] == '?'){
                        c[i+1] = j[i+1] = c[i+2] = j[i+2] = '0';
                    } else if (c[i+2] == '?'){
                        if (j[i+2] >= '5'){
                            j[i] = j[i] - 1;
                            j[i+1] = '9';
                            c[i+1] = c[i+2] = '0';
                        } else {
                            c[i+1] = j[i+1] = c[i+2] = j[i+2] = '0';
                        }
                    } else if (j[i+2] == '?'){
                        c[i+1] = j[i+1] = '0';
                        j[i+2] = c[i+2];

                    } else if ((c[i+2] - j[i+2] > 5)){
                        c[i+1] = '0';
                        j[i+1] = '1';
                    } else if ((j[i+2] - c[i+2] >= 5)){
                        j[i] = j[i] - 1;
                        c[i+1] = '0';
                        j[i+1] = '9';
                    } else {
                        c[i+1] = j[i+1] = '0';
                    }

                    //TODO:Change to here
                    flag = false;

                } else if (c[i+1] != '?' && j[i+1] == '?'){
                    j[i] = c[i];
                    j[i+1] = c[i+1];
                } else {
                    if (c[i+1] - j[i+1] > 5 && c[i] != '9'){
                        j[i] = c[i] + 1;
                        for (int k = i+2; k < siz; ++k){
                            if (c[k] == '?') c[k] = '9';
                            if (j[k] == '?') j[k] = '0';
                        }
                        flag = false;


                    } else if ((c[i+1] - j[i+1] <= 5 && c[i+1] - j[i+1] > 0) || (c[i+1] - j[i+1] > 5 && c[i] == '9') ){
                        j[i] = c[i];
                        for (int k = i+2; k < siz; ++k){
                            if (c[k] == '?') c[k] = '0';
                            if (j[k] == '?') j[k] = '9';
                        }
                        flag = false;


                    }  else if ((j[i+1] - c[i+1] <= 5 && j[i+1] - c[i+1] > 0) || (j[i+1] - c[i+1] > 5 && c[i] == '0')  ){
                        j[i] = c[i];
                        for (int k = i+2; k < siz; ++k){
                            if (c[k] == '?') c[k] = '9';
                            if (j[k] == '?') j[k] = '0';
                        }
                        flag = false;



                    }  else if (j[i+1] - c[i+1] > 5 && c[i] != '0'){
                        j[i] = c[i] - 1;
                        for (int k = i+2; k < siz; ++k){
                            if (c[k] == '?') c[k] = '0';
                            if (j[k] == '?') j[k] = '9';
                        }
                        flag = false;


                    } else {
                        j[i] = c[i];
                    }
                }
                ++i;
                continue;
            }
            else {
                if (c[i] > j[i]){
                    for (int k = i+1; k < siz; ++k){
                        if (c[k] == '?') c[k] = '0';
                        if (j[k] == '?') j[k] = '9';
                    }
                    flag = false;
                } else {
                    for (int k = i+1; k < siz; ++k){
                        if (c[k] == '?') c[k] = '9';
                        if (j[k] == '?') j[k] = '0';
                    }
                    flag = false;
                }
            }
        }



        printf("Case #%d: ", t);
        cout << c << " " << j;

        printf("\n");
    }
}
