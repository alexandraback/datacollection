#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

// label 1,i,j,k as 0,1,2,3 respectively
pair<int,int> qm(int a, int b){
    int res,sign=1;
    if (a == 0 || b == 0){
        res = a + b;
    }else if (a == b){
        res = 0;
    }else{
        for (int q = 1; q < 4; q++){
            if (q != a && q != b){
                res = q;
            }
        }
    }
    if (a == 1){
        if (b == 1 || b == 3){
            sign = -1;
        }
    }else if (a == 2){
        if (b == 1 || b == 2){
            sign = -1;
        }
    }else if (a == 3){
        if (b == 2 || b == 3){
            sign = -1;
        }
    }
    return make_pair(sign,res);
}


int main(){

    /* 
    for (int i =0; i< 4;++i){
        for (int j =0;j<4;++j){
            cout << qm(i,j).first << " " << qm(i,j).second << "\t";
        }
        cout << endl;
    }
    */

    string line;
    int L,X;
    getline(cin,line);

    int num = atoi(line.c_str());
    for (int i =0 ; i < num; ++i){
        getline(cin,line);
        stringstream ss(line);
        ss >> L >> X;
        getline(cin,line);
        vector<int> s;
        for (int j=0;j<X; ++j){
            for (auto it = line.begin(); it != line.end(); ++it){
                s.push_back(*it - 'h');
            }
        }
        /*
        for (auto it = s.begin(); it != s.end(); ++it){
            cout << *it << " ";
        }*/

        int sign_i=1,sign_j=1,sign_k=1;
        int val_i = 0, val_j=0, val_k=0;
        pair<int,int> ret_i,ret_j,ret_k;
        bool yes=false;

        for (auto it = s.begin(); it != s.end(); ++it){
            ret_i = qm(val_i, *it);
            sign_i *= ret_i.first;
            val_i = ret_i.second;
            if (sign_i == 1 && val_i == 1){
                for (auto it2 = it + 1; it2 != s.end(); ++it2){
                    ret_j = qm(val_j,*it2);
                    sign_j *= ret_j.first;
                    val_j = ret_j.second;
                    if (sign_j == 1 && val_j == 2){
                        for (auto it3 = it2 +1; it3 != s.end(); ++it3){
                            ret_k = qm(val_k, *it3);
                            sign_k *= ret_k.first;
                            val_k = ret_k.second;
                        }
                        if (sign_k == 1 && val_k == 3) yes = true;
                        break;
                    }
                }
                break;
            }
        }


        string out = "NO";
        if (yes) out = "YES";
        cout << "Case #" << i+1 << ": " << out << endl;

    }
    return 0;
} 
