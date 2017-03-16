#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {

    if(argc != 3) return -1;

    fstream infile;
    fstream outfile;

    infile.open(argv[1], ios::in);
    outfile.open(argv[2], ios::out);

    int T;
    int N;
    vector<long> vM(1);

    long total;
    float required;
    float average;
    float ans;
    float grandtotal;

    int count;
    int smallest;
    float newaverage;
    float newgrandtotal;

    int lastcount;
    int newN;

    infile >> T;

    outfile.precision(7);
    //outfile.setf(ios::fixed,ios::floatfield);

    for(int i=0; i!=T; ++i) {

        infile >> N;
        
        vM.clear();
        vM.resize(N);

        total = 0;
        grandtotal = 0;
        for(int j=0; j!=N; ++j) {
            infile >> vM[j];
            total += vM[j];
        }

        grandtotal = total * 2;
        average = grandtotal / N;
        lastcount = 0;
        count = 0;

        newgrandtotal = grandtotal;
        newaverage = average;
        newN = N;

        do {
        count = 0;
        smallest = 101;

        for(int j=0; j!=N; ++j) {
            if((newaverage < vM[j]) && (vM[j] != -1)) {
                ++count;
                newgrandtotal -= vM[j];
                vM[j] = -1;
                smallest = (smallest > vM[j])? vM[j] : smallest;
            }
        }

        //cout << "count = " << count << endl;

        if(count > 0) {
            newN = newN - count;
            newaverage = newgrandtotal / newN;
        }

        //cout << "new average = " << newaverage << endl;
//        cout << "small number
        }while(count != 0);

        outfile << "Case #" << i+1 << ": ";

        for(int j=0; j!=N; ++j) {
            if((vM[j] != -1)) { //(newaverage > vM[j]) && 
                required = newaverage - vM[j];
                ans = required / total * 100;
            }
            else
            {
                ans = 0.0;
            }
            
            outfile << ans << " ";

        }

        outfile << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
