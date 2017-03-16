#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <deque>
#include <string>
#include <cstdio>

using namespace std;

ifstream in("Din.txt");
FILE * out=fopen("Dout.txt","w");

int main() {
    int T;
    in >> T;
    for( int TC= 1; TC <=T; TC++ ) {
        int N;
        vector<double> tA, tB;

        in >> N;
        for( int i=0; i<N; i++ ) { double t; in >> t; tA.push_back(t); }
        for( int i=0; i<N; i++ ) { double t; in >> t; tB.push_back(t); }
        sort(tA.begin(), tA.end());
        sort(tB.begin(), tB.end());
        deque<double> A(tA.begin(),tA.end()), B(tB.begin(),tB.end());
        cout << tA.front() << " " << A.front() << endl;
        //regular war
        int RscoreA = 0;

        for( int r=0; r<N; r++ ) {
            bool found=false;
            for( int i=0; i<B.size(); i++ ) {
                if( B[i] > A[r] ) {
                    B.erase(B.begin()+i);
                    found = true;
                    break;
                }
            }
            if( !found ) RscoreA++;
        }


        //deceitful war
        int DscoreA = 0;
        A = deque<double>(tA.begin(),tA.end());
        B = deque<double>(tB.begin(),tB.end());

        for( int r=0; r<N; r++ ) { //step through each round
            if(A.front() < B.front()) { //sacrifice lowest for highest
                A.pop_front();
                B.pop_back();
            }
            else { //go for the win
                A.pop_front();
                B.pop_front();
                DscoreA++;
            }
        }


        fprintf(out,"Case #%d: %d %d\n", TC, DscoreA, RscoreA);
    }
    return 0;
}
