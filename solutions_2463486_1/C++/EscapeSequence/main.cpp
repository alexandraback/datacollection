#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>

using namespace std;

vector<string> fsq;

void goDo(int i, int indep, bool odd, int dig[]) {
    int sqr[i*2-1];
    for(int j = 0; j < i*2; j++) sqr[j] = 0;

    // Number has sum dig[n]*(10^(indep-n-1) + 10^(indep+n [-1 if odd])) with only one in middle for odd case
    for(int j = 0; j < indep; j++) {
        for(int k = 0; k < indep; k++) {
            #define DO(ind) { sqr[ind] += p; /*if(sqr[ind] > 9) { cout << "!!!" << endl; good = false; }*/ }
            int p = dig[j]*dig[k];
            DO(2*indep+j+k-(odd ? 2 : 0))
            if(k != 0 || !odd) DO(2*indep+j-k-(odd ? 2 : 1));
            if(j != 0 || !odd) {
                DO(2*indep-j+k-(odd ? 2 : 1));
                if(k != 0 || !odd) DO(2*indep-j-k-2);
            }
        }
    }

    string s = "";
    for(int j = 2*i-2; j >= 0; j--) {
        s += ('0' + sqr[j]);
    }
    //cout << s << endl;

    fsq.push_back(s);
}

void generate(int len) {
    fsq.push_back("1");
    fsq.push_back("4");
    fsq.push_back("9");
    for(int i = 2; i <= len; i++) {
        cout << "Length " << i << endl;
        bool odd = (i%2 == 1);
        int indep = (i + (odd ? 1 : 0))/2;

        int dig[indep]; // Reverse of first indep digits
        for(int j = 0; j < indep; j++) dig[j] = 0;
        //dig[indep-1] = 1;

        int centralOut = 0;
        int count2 = 0;

        for(int fst = 1; fst <= 2; fst++) {
            dig[indep-1] = fst;
            centralOut += (odd && i == 1 ? 1 : 2) * fst*fst;
            if(fst == 2) count2++;

            goDo(i, indep, odd, dig);

            for(int j1 = 0; j1 <= indep-2; j1++)
            for(int n1 = 1; n1 <= (count2 ? 1 : 2); n1++) {
                dig[j1] = n1;
                centralOut += (odd && j1 == 0 ? 1 : 2) * n1*n1;
                if(centralOut <= 9) {
                count2 += (n1 == 2 ? 1 : 0);

                goDo(i, indep, odd, dig);

                if(centralOut <= 8)
                for(int j2 = 0; j2 < j1; j2++)
                for(int n2 = 1; n2 <= (count2 ? 1 : 2); n2++) {
                    dig[j2] = n2;
                    centralOut += (odd && j2 == 0 ? 1 : 2) * n2*n2;
                    if(centralOut <= 9) {
                    count2 += (n2 == 2 ? 1 : 0);

                    goDo(i, indep, odd, dig);

                    if(centralOut <= 8)
                    for(int j3 = 0; j3 < j2; j3++)
                    for(int n3 = 1; n3 <= (count2 ? 1 : 2); n3++) {
                        dig[j3] = n3;
                        centralOut += (odd && j3 == 0 ? 1 : 2) * n3*n3;
                        if(centralOut <= 9) {
                        count2 += (n3 == 2 ? 1 : 0);

                        goDo(i, indep, odd, dig);

                        if(centralOut <= 8)
                        for(int j4 = 0; j4 < j3; j4++)
                        for(int n4 = 1; n4 <= (count2 ? 1 : 2); n4++) {
                            dig[j4] = n4;
                            centralOut += (odd && j4 == 0 ? 1 : 2) * n4*n4;
                            if(centralOut <= 9) {
                            count2 += (n4 == 2 ? 1 : 0);

                            goDo(i, indep, odd, dig);


                            count2 -= (n4 == 2 ? 1 : 0);
                            }
                            centralOut -= (odd && j4 == 0 ? 1 : 2) * n4*n4;
                            dig[j4] = 0;
                        }

                        count2 -= (n3 == 2 ? 1 : 0);
                        }
                        centralOut -= (odd && j3 == 0 ? 1 : 2) * n3*n3;
                        dig[j3] = 0;
                    }

                    count2 -= (n2 == 2 ? 1 : 0);
                    }
                    centralOut -= (odd && j2 == 0 ? 1 : 2) * n2*n2;
                    dig[j2] = 0;
                }


                count2 -= (n1 == 2 ? 1 : 0);
                }
                centralOut -= (odd && j1 == 0 ? 1 : 2) * n1*n1;
                dig[j1] = 0;
            }

            centralOut -= (odd && i == 1 ? 1 : 2) * fst*fst;
        }

            /*int inc = 0; while(dig[inc] == 2 && inc < indep) { centralOut -= (odd && inc == 0 ? 1 : 2)*4; dig[inc] = 0; inc++;}
            if(inc == indep) break;
            if(dig[inc] == 0)
                centralOut += (odd && inc == 0 ? 1 : 2)*1;
            else
                centralOut += (odd && inc == 0 ? 1 : 2)*3;
            dig[inc]++;*/

    }
}

// -1 === X < Y etc.
int compare(string X, string Y) {
    if(X.length() < Y.length()) return -1;
    if(X.length() > Y.length()) return +1;

    for(int k = 0; k < X.length(); k++) {
        if(X[k] < Y[k]) return -1;
        if(X[k] > Y[k]) return +1;
    }
    return 0;
}

int find(string X, bool errAbove) {
    int imax = fsq.size()-1, imin = 0;
    while(imax >= imin) {
        int imid = (imin + imax)/2;
        int comp = compare(fsq[imid], X);
        if(comp == 0) return imid;
        if(comp < 0) { imin = imid + 1; }
        else { imax = imid - 1; }
    }

    if(!errAbove && imin >= fsq.size()) { imin = fsq.size()-1; }

    //cout << "Found " << X << " [" << errAbove << "] to lie at " << (imin >= fsq.size() ? "OUT OF RANGE" :fsq[errAbove ? imin : imax]) << endl;
    return errAbove ? imin : imax;
}

int main() {
    string fn = "in.txt";
    ifstream in(fn.c_str());
    ofstream out("out.txt");

    int n;

    in >> n;

    generate(51);
    cout << "M-1 " << fsq[fsq.size()-2] << endl;
    cout << "MAX " << fsq[fsq.size()-1] << endl;
    cout << "Total of " << fsq.size() << " palindromic squares found." << endl << "----------" << endl << endl;
    //for(int i = 0; i < fsq.size(); i++) cout << fsq[i] << endl;

    for(int i = 0; i < n; i++) {
        string A, B; in >> A >> B;

        // Need to count the number of sets such that:
        //  Odd total length 2m+1:      Central digit 0, 1, 2    m other digits 0, 1, 2.
        //                              Contribution  0, 1, 4                   0, 2, 8
        //                 Hence                      0          [2], [1], [1, 1], [1, 1, 1], [1, 1, 1, 1]
        //                                            1          [2], [1], [1, 1], [1, 1, 1], [1, 1, 1, 1]
        //                                            2          [1], [1, 1]

        int firstAbove = find(A, true);
        int lastBelow = find(B, false);
        int ans = (lastBelow - firstAbove + 1); if(ans < 0) ans = 0;

        cout << "Case #" << (i+1) << ": " << ans << endl;
        out << "Case #" << (i+1) << ": " << ans << endl;
    }

    return 0;
}
