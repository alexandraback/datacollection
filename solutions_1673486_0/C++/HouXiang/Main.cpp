#include <assert.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

/*
int ElapsedTime(const vector<int>& vecButtons, int index) {
	return abs(vecButtons[index] - vecButtons[index - 1]);
}
*/


int main(int argc, char* argv[]) {
    
	if (argc != 2) {
		cerr << "wrong number of parameter" << endl;
		return -1;
	}

	ifstream inf(argv[1]);
	if (!inf) {
		cerr << "cannot open file " << argv[1] << endl;
		return -1;
	}

	string ln;  
    char buf[200] = {0};
    inf.getline(buf, 200);

    int n = atoi(buf);
    
	for (int i=0; i<n; i++) 
    {
        int A = 0, B = 0;
        double p[100001] = {0};

        string buf;
        inf >> buf; A = atoi(buf.c_str());
        inf >> buf; B = atoi(buf.c_str());

        for (int j=0; j<A; j++) {
            inf >> buf;
            p[j] = atof(buf.c_str());
        }

        // find solution
        double best = B + 2; // enter directly 
        double record = 0; 

        for (int nn=0; nn<=A; nn++)
        {
            double pp = 1;
            for (int nnn=0; nnn<(A-nn); nnn++) {
                pp *= p[nnn];
            }

            double exp = pp * (B-A + nn * 2 + 1) + (1 - pp) * (B - A + nn * 2 + 1 + B + 1);
            if (exp < best) best = exp;
        }

        printf("Case #%d: %f\n", i+1, best);
        // cout << "Case #" << i+1 << " " << best << endl;
	}

	return 0;
}

