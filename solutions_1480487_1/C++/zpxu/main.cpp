#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int score[201];
double p[201];
bool flag[201];

int main()
{
    ifstream ifs("A-large.in");
    ofstream ofs("A-large.out");
//    ifstream ifs("A-large-attempt0.in");
//    ofstream ofs("A-large-attempt0.out");
    int nCases;
    ifs >> nCases;
    int cas = 1;
    while(nCases--) {
        int nc;
        ifs >> nc;
        double sumScore = 0;
        for(int i = 0; i < nc; i++) {
            ifs >> score[i];
            sumScore += score[i];
            flag[i] = false;
        }
        double avg = 2 * sumScore / nc;
        int n = nc;
        double newScore = 2 * sumScore;
        for(int i = 0; i < nc; i++) {
            if(score[i] >= avg) {
                p[i] = 0;
                flag[i] = true;
                newScore -= score[i];
                n--;
            }
        }
        avg = newScore / n;
        for(int i = 0; i < nc; i++) {
            if(!flag[i])
                p[i] = (avg - score[i]) / sumScore;
        }
        ofs << "Case #" << cas++ << ": ";
        for(int i = 0; i < nc; i++) {
            ofs.setf(ios::fixed, ios::floatfield);
            ofs.precision(6);
            ofs << p[i] * 100 << " ";
        }
        ofs << endl;
    }
}
