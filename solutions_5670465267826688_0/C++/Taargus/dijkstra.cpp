#include <iostream>
#include <fstream>

using namespace std;

bool findIJK(string str, int quat[][4], int rep, int iter, int start) {
    int curr = 1;
    bool neg = false;

    while(rep > 0) {
        for(int i = start; i < str.length(); i++) {
            curr = quat[curr - 1][str[i] - 104];
            
            if(curr < 0) {
                neg = !neg;
                curr = -curr;
            }

            if((curr - 1 == iter) && !neg) {
                if(iter == 3 && rep == 1 && (i + 1 == str.length())) {
                    return true;
                }

                else if(iter != 3) {
                    if(findIJK(str, quat, rep, iter + 1, i + 1)) {
                        return true;
                    }
                }
            }
        }

        rep -= 1;
        start = 0;
    }
    return false;
}

int main() {
    ifstream fin("C-small.in");
    ofstream fout("C-small.out");

    int quat [4][4] = {{1, 2, 3, 4},
                       {2, -1, 4, -3},
                       {3, -4, -1, 2},
                       {4, 3, -2, -1}};

    int cases;
    fin >> cases;

    for(int i = 0; i < cases; i++) {
        int len, rep;
        fin >> len >> rep;
        string str;
        fin >> str;

        bool works = findIJK(str, quat, rep, 1, 0);
        fout << "Case #" << i + 1;

        if(works) {
            fout << ": YES\n";
        }

        else {
            fout << ": NO\n";
        }
    }
}



