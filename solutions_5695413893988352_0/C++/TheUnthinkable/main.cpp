/*
  Author:       Dean Hirsch
  Date:         April 30th, 2016
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>

#define DO(n) for(int i=0; i < n; i++)

using namespace std;

#define INPUT_FILENAME      "B-small-attempt5.in"
#define OUTPUT_FILENAME     "output.out"

typedef unsigned long long int u64;
typedef long long int i64;

vector<string> compute(string C, string J);
i64 str_to_int(string s);
vector<string> compute_C_smaller(string C, string J);
vector<string> compute_J_smaller(string C, string J);
i64 abs_i64(i64 n);

bool c_is_left;
vector<string> choose_best(const vector<string>& v1, const vector<string>& v2);

int main()
{
    ifstream fin;
    ofstream fout;

    fin.open(INPUT_FILENAME);
    if(!fin.is_open()){
        cout << "Error: failed to open input file\n";
        return 1;
    }
    fout.open(OUTPUT_FILENAME, ios::trunc);
    if(!fout.is_open()){
        cout << "Error: failed to open output file\n";
        return 1;
    }

    int T;
    fin >> T;
    for(int line_num=1; line_num<=T; line_num++){
        if(fin.eof()){
            cout << "Error: fewer lines than what was promised!\n";
            fout << "Error: fewer lines than what was promised!\n";
            break;
        }
        string C, J;
        fin >> C;
        fin >> J;

        vector<string> ret = compute(C,J);
        cout << "Case #" << line_num << ": ";
        fout << "Case #" << line_num << ": ";

        C = ret[0];
        J = ret[1];

        cout << C << " " << J;
        fout << C << " " << J;

        cout << "\n";
        fout << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}

vector<string> compute(string C, string J)
{
    string best_C;
    string best_J;

    c_is_left = true;
    vector<string> ret1 = compute_C_smaller(C,J);

    c_is_left = false;
    vector<string> ret2 = compute_J_smaller(C,J);

    c_is_left = true;

    return choose_best(ret1, ret2);
}

vector<string> compute_C_smaller(string C, string J){
    vector<string> ret, ret2;
    bool smaller = false;

    for(int i=0; i < C.size(); i++){
        if(C[i] == '?' && J[i] == '?'){
            C[i] = '0';
            J[i] = '0';
            ret = compute_C_smaller(C,J);

            J[i] = '1';
            ret2 = compute_C_smaller(C,J);
            return choose_best(ret, ret2);
        }
        if(C[i] == '?' && J[i] != '?'){
            C[i] = J[i];
            ret = compute_C_smaller(C,J);
            if(J[i] != '0'){
                C[i] = J[i]-1;
                ret2 = compute_C_smaller(C,J);
            }
            return choose_best(ret,ret2);
        }
        if(C[i] != '?' && J[i] == '?'){
            J[i] = C[i];
            ret = compute_C_smaller(C,J);
            if(C[i] != '9'){
                J[i] = C[i]+1;
                ret2 = compute_C_smaller(C,J);
            }
            return choose_best(ret,ret2);;
        }
        if(C[i] > J[i])
            return vector<string>();
        if(C[i] < J[i]){
            smaller = true;
            for(int j=i+1; j < C.size(); j++){
                if(C[j] == '?')
                    C[j] = '9';
                if(J[j] == '?')
                    J[j] = '0';
            }
            ret.push_back(C);
            ret.push_back(J);
            return ret;
        }
    }

    ret.push_back(C);
    ret.push_back(J);
    return ret;
}

vector<string> compute_J_smaller(string C, string J){
    vector<string> ret = compute_C_smaller(J, C);
    if(!ret.empty())
        ret[0].swap(ret[1]);
    return ret;
}

i64 str_to_int(string s){
    u64 ret=0;
    for(int i=0; i<s.size(); i++){
        ret = ret*10 + (s[i]-'0');
    }

    return ret;
}


i64 abs_i64(i64 n){
    return n>=0 ? n : -n;
}

vector<string> choose_best(const vector<string>& v1, const vector<string>& v2){
    if(v1.size() == 0)
        return v2;
    if(v2.size() == 0)
        return v1;

    i64 diff = abs_i64(str_to_int(v1[0]) - str_to_int(v1[1])) -
       abs_i64(str_to_int(v2[0]) - str_to_int(v2[1]));

    if(diff < 0)
        return v1;
    if(diff > 0)
        return v2;

    if(v1[0] < v2[0] || (v1[0]==v2[0] && v1[1]<v2[1]))
        return c_is_left ? v1 : v2;
    return c_is_left ? v2 : v1;
}
