#include <cstdio>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;



int main() {
	int T;

    string s;
    istringstream iss;
    string filename("B-small-attempt0.in");
    ifstream in(filename, ifstream::in);      
    if(!in){				              // ensure existence of file
        //cout<<"error: file "<<filename<<" does not exist\n";
        exit(-1);
    }
    getline(in, s);
    iss.str(s);
    iss >> T;	   
    //cout << T << " cases"<< endl;
    vector<vector<int> > board(4, vector<int>(4, 0));


    double C, F, X;
	for (int test = 1; test <= T; test++) {
        getline(in, s);
        iss.clear();
        iss.str(s);
        iss >> C >> F >> X;	
        //cout << C << "  "  << F << "  " << X << endl;

        double pre = X, ans = X / 2.0;
        int i = 0;
        while(pre > ans) {
            pre = ans;
            ans = pre - (X / (2 + i*F)) ;
            ans += C / (2.0 + i * F );
            i++;
            ans += X / (2.0 + i * F );
            
            //cout << pre << "vs." << ans << endl;
            
        }
        printf("Case #%d: %.7f\n", test, pre);


    }
}
