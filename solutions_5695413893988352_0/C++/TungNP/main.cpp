//
//  main.cpp
//  B
//
//  Created by ianto on 4/30/16.
//  Copyright © 2016 TungNguyen. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

typedef vector<int> veci;
typedef vector<string> vecs;

veci read_int(int N){
    veci vi(N);
    for (int i = 0; i < N; i++) {
        cin >> vi[i];
    }
    return vi;
}

vecs read_string(int N){
    vecs vs(N);
    for (int i = 0; i < N; i++) {
        cin >> vs[i];
    }
    return vs;
}

void fill (string *C, string *J, int index){
    string c = *C, j = *J;
    if (c[index] == j[index]) {
        bool csmaller = false;
        bool isEqual = true;
        for (int i = index + 1; i < c.size(); i++) {
            if (c[i] != '?' && j[i] != '?' && c[i] != j[i]) {
                isEqual = false;
                csmaller = c[i] < j[i];
                break;
            }
        }
        if (isEqual) {
            for (int i = 0; i < c.length(); i++) {
                if (c[i] == '?' && c[i] == '?') {
                    c[i] = c[i] = '0';
                }
                else{
                    c[i] = c[i] == '?' ? c[i] : c[i];
                    c[i] = c[i] == '?' ? c[i] : c[i];
                }
            }
        }
        else{
            for (int i = index; i < c.size(); i++) {
                c[i] = c[i] == '?' ? (csmaller ? '9' : '0') : c[i];
                j[i] = j[i] == '?' ? (csmaller ? '0' : '9') : j[i];
            }
        }
        
    }
    else{
        bool csmaller = c[index] < j[index];
        for (int i = index; i < c.size(); i++) {
            c[i] = c[i] == '?' ? (csmaller ? '9' : '0') : c[i];
            j[i] = j[i] == '?' ? (csmaller ? '0' : '9') : j[i];
        }
    }
    *C = c;
    *J = j;
}

int main(int argc, const char * argv[]) {
//    freopen("B-small-attempt2.in.txt", "r", stdin);
    
    int T; cin >> T;
    for (int Case = 1; Case <= T; Case++) {
        string C, J; cin >> C >> J;
        
        bool isEqual = true;
        int c0 = -1, j0 = -1;
        for (int i = 0; i < C.length(); i++) {
            if (c0 == -1 && C[i] != '?') {
                c0 = i;
            }
            if (j0 == -1 && J[i] != '?') {
                j0 = i;
            }
            if (C[i] != '?' && J[i] != '?' && C[i] != J[i]) {
                isEqual = false;
                break;
            }
        }
        if (isEqual) {
            for (int i = 0; i < C.length(); i++) {
                if (C[i] == '?' && J[i] == '?') {
                    C[i] = J[i] = '0';
                }
                else{
                    C[i] = C[i] == '?' ? J[i] : C[i];
                    J[i] = J[i] == '?' ? C[i] : J[i];
                }
            }
        }
        else{
            int index = -1;
            for (int i = 0; i < C.length(); i++) {
                if (C[i] != '?' && J[i] != '?') {
                    index = i - 1;
                    break;
                }
                else if (C[i] != '?' || J[i] != '?'){
                    index = i;
                    break;
                }
            }
            for (int i = 0; i < index; i++) {
                C[i] = J[i] = '0';
            }
            if (index == -1) {
                bool csmaller = C[0] < J[0];
                for (int i = 0; i < C.length(); i++) {
                    C[i] = C[i] == '?' ? (csmaller ? '9' : '0') : C[i];
                    J[i] = J[i] == '?' ? (csmaller ? '0' : '9') : J[i];
                }
            }
            else{
                if (C[index] == '?' && J[index] == '?') {
                    string c1 = C;  c1[index] = '0'; string j1 = J;  j1[index] = '0';
                    string c2 = C;  c2[index] = '0'; string j2 = J;  j2[index] = '1';
                    string c3 = C;  c3[index] = '1'; string j3 = J;  j3[index] = '0';
                   
                    fill(&c1, &j1, index); long long a1 = abs(atoll(c1.c_str()) - atoll(j1.c_str()));
                    fill(&c2, &j2, index); long long a2 = abs(atoll(c2.c_str()) - atoll(j2.c_str()));
                    fill(&c3, &j3, index); long long a3 = abs(atoll(c3.c_str()) - atoll(j3.c_str()));
                    
                    string cr = c1, jr = j1;
                    long long a = a1;
                    if (a2 < a) {
                        cr = c2; jr = j2;
                        a = a2;
                    }
                    else if (a2 == a){
                        if (atoll(c2.c_str()) < atoll(cr.c_str())) {
                            cr = c2; jr = j2;
                            a = a2;
                        }
                        else if (atoll(j2.c_str()) < atoll(jr.c_str())){
                            cr = c2; jr = j2;
                            a = a2;
                        }
                    }
                    if (a3 < a) {
                        cr = c3; jr = j3;
                        a = a3;
                    }
                    else if (a3 == a){
                        if (atoll(c3.c_str()) < atoll(cr.c_str())) {
                            cr = c3; jr = j3;
                            a = a3;
                        }
                        else if (atoll(j3.c_str()) < atoll(jr.c_str())){
                            cr = c3; jr = j3;
                            a = a3;
                        }
                    }
                    C = cr;
                    J = jr;
                }
                else{
                    char f = C[index] == '?' ? J[index] : C[index];
                    vector<char> tries;
                    if (f == '0') {
                        tries.push_back('0');
                        tries.push_back('1');
                    }
                    else if (f == '9'){
                        tries.push_back('8');
                        tries.push_back('9');
                    }
                    else{
                        tries.push_back(f-1);
                        tries.push_back(f);
                        tries.push_back(f+1);
                    }
                    long long a = 0;
                    string cr = C, jr = J;
                    for (int i = 0; i < tries.size(); i++) {
                        string c = C, j = J;
                        c[index] = c[index] == '?' ? tries[i] : c[index];
                        j[index] = j[index] == '?' ? tries[i] : j[index];
                        fill(&c, &j, index);
                        if (i == 0 || a > abs(atoll(c.c_str()) - atoll(j.c_str()))) {
                            a = abs(atoll(c.c_str()) - atoll(j.c_str()));
                            cr = c;
                            jr = j;
                        }
                        else if (a == abs(atoll(c.c_str()) - atoll(j.c_str()))){
                            if (atoll(c.c_str()) < atoll(cr.c_str())) {
                                cr = c;
                                jr = j;
                            }
                            else if (atoll(j.c_str()) < atoll(jr.c_str())){
                                cr = c;
                                jr = j;
                            }
                        }
                    }
                    
                    C = cr;
                    J = jr;
                }
            }
        }
        
        cout << "Case #" << Case << ": " << C << " " << J << endl;
    }
    
    return 0;
}
