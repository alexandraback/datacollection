//
//  main.cpp
//  GCJ
//
//  Created by Keno on 2015/04/11.
//  Copyright (c) 2015年 Keno. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

struct quaternion {
    int r;
    int i;
    int j;
    int k;
};

// input: i, j or k
quaternion atoq(char a) {
    if (a == 'i') {
        return quaternion{0,1,0,0};
    } else if (a == 'j') {
        return quaternion{0,0,1,0};
    } else if (a == 'k') {
        return quaternion{0,0,0,1};
    } else {
        return quaternion{0,0,0,0};
    }
}

// input: +-1, +-i, +-j or +-k. this method is for debug.
string qtos(quaternion q) {
    if (q.i == 1) {
        return "i";
    } else if (q.i == -1) {
        return "-i";
    } else if (q.j == 1) {
        return "j";
    } else if (q.j == -1) {
        return "-j";
    } else if (q.k == 1) {
        return "k";
    } else if (q.k == -1) {
        return "-k";
    } else if (q.r == 1) {
        return "1";
    } else if (q.r == -1) {
        return "-1";
    }
    return "";
}

// multiply
quaternion qByq(quaternion q1, quaternion q2) {
    return quaternion{
        q1.r * q2.r - q1.i * q2.i - q1.j * q2.j - q1.k * q2.k,
        q1.r * q2.i + q1.i * q2.r + q1.j * q2.k - q1.k * q2.j,
        q1.r * q2.j + q1.j * q2.r + q1.k * q2.i - q1.i * q2.k,
        q1.r * q2.k + q1.k * q2.r + q1.i * q2.j - q1.j * q2.i};
}

bool qIsEqual(quaternion q1, quaternion q2) {
    return q1.r == q2.r && q1.i == q2.i && q1.j == q2.j && q1.k == q2.k;
}

int main(int argc, const char * argv[]) {
    
    ifstream fin;
//    fin.open("example.txt", ios::in);
    fin.open("C-large.in.txt", ios::in);
    
    ofstream fout;
    fout.open("output-C-l.txt", ios::out);
    
    string s;
    string out;
    
    // read parameters and calculate
    
    int T;
    fin >> T;
    
    for (int i = 0; i < T; i++) {
        int L;
        fin >> L;
        double X_double;
        fin >> X_double;
        fin >> s;
        
        int X;
        if (X_double > 100) {
            X = 100;
        } else {
            X = (int)X_double;
        }
        
        bool answer = true;
        
        int minimumI = -1;
        
        quaternion resultL = quaternion{1,0,0,0};
        for (int j = 0; j < L; j++) {
            resultL = qByq(resultL, atoq(s[j]));
            if (minimumI == -1 && resultL.i == 1) {
                minimumI = j + 1;
            }
        }
        
        if (resultL.r == 1) {
            answer = false;
        } else if (resultL.r == -1) {
            if ((X_double - 1.0) / 2.0 != ceil((X_double - 1.0) / 2.0)) {
                answer = false;
            }
        } else {
            if (X_double >= 2 && (X_double - 2.0) / 4.0 != ceil((X_double - 2.0) / 4.0)) {
                answer = false;
            } else if (X_double < 2) {
                answer = false;
            }
        }
        
        // search possibility of making i
        if (answer == true && minimumI == -1) {
            quaternion loopInitial = resultL;
            int index = L;
            do {
                for (int j = 0; j < L; j++) {
                    resultL = qByq(resultL, atoq(s[j]));
                    index++;
                    if (resultL.i == 1) {
                        minimumI = index;
                        break;
                    }
                }
            } while (minimumI == -1 && qIsEqual(resultL, loopInitial) == false);
            
            if (minimumI == -1 || minimumI > L * X) {
                answer = false;
            } else {
                cout << "i can be made at " << minimumI << endl;
            }
        }
        
        int minimumK = -1;
        
        // search possibility of making k
        if (answer == true) {
            resultL = quaternion{1,0,0,0};
            quaternion loopInitial = quaternion{0,0,0,0};
            int index = 0;
            while (minimumK == -1 && qIsEqual(resultL, loopInitial) == false) {
                if (qIsEqual(resultL, quaternion{1,0,0,0}) == false &&
                    qIsEqual(loopInitial, quaternion{0,0,0,0})) {
                    loopInitial = resultL;
                }
                
                for (int j = L-1; j >= 0; j--) {
                    resultL = qByq(atoq(s[j]), resultL);
                    index++;
                    if (resultL.k == 1) {
                        minimumK = index;
                        break;
                    }
                }
            }
            
            if (minimumK == -1 || (minimumI + minimumK) >= L * X) {
                answer = false;
                cout << "k could not be made over X " << X << endl;
                cout << s << endl;
            } else {
                cout << "k can be made at -" << minimumK << endl;
            }
        }
        
        fout << "Case #" << (i+1) << ": " << (answer ? "YES" : "NO") << endl;
        
//        continue;
        
//        if (answer == false) {
//            bool originalAnswer = answer;
//            answer = false;
//            quaternion q_i = quaternion{1,0,0,0};
//            int index;
//            int try_ = L * X_double;
//            if (i != 1 && i != 1 && i != 1) {
//                for (int j = 0; j < L * X_double; j++) {
//                    index = j % L;
//                    q_i = qByq(q_i, atoq(s[index]));
//                    if (q_i.i == 1) {
//                        quaternion q_j = quaternion{1,0,0,0};
//                        for (int k = j + 1; k < L * X_double; k++) {
//                            index = k % L;
//                            q_j = qByq(q_j, atoq(s[index]));
//                            if (q_j.j == 1) {
//                                quaternion q_k = quaternion{1,0,0,0};
//                                for (int l = k + 1; l < L * X_double; l++) {
//                                    index = l % L;
//                                    q_k = qByq(q_k, atoq(s[index]));
//                                }
//                                try_--;
//                                if (try_ < 0) {
//                                    answer = false;
//                                    j = L * X_double;
//                                    k = j;
//                                    cout << "exhausted";
//                                    break;
//                                }
//                                if (q_k.k == 1) {
//                                    answer = true;
//                                    j = L * X_double;
//                                    k = j;
//                                    break;
//                                }
//                            }
//                        }
//                    }
//                }
//                if (originalAnswer != answer) {
//                    cout << "nooo" << endl;
//                }
//            }
//        }
    }
    
    fin.close();
    fout.close();
    
    return 0;
}
