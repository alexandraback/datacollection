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
	int T, N;

    string s;
    istringstream iss;
    string filename("D-small-attempt0.in");
    ifstream in(filename, ifstream::in);      
    if(!in){				              // ensure existence of file
        ////cout<<"error: file "<<filename<<" does not exist\n";
        exit(-1);
    }
    getline(in, s);
    iss.str(s);
    iss >> T;	   
    ////cout << T << " cases"<< endl;


	for (int test = 1; test <= T; test++) {
        getline(in, s);
        iss.clear();
        iss.str(s);
        iss >> N;	
        //cout << N << endl;

        vector<float> p1(N);
        vector<float> p2(N);
        ////cout << one << endl;
        getline(in, s);
        iss.clear();
        iss.str(s);
        for(int i = 0; i < N; i++) {
            iss >> p1[i];
            //cout << p1[i] << "  ";
        }
        //cout << endl;
        getline(in, s);
        iss.clear();
        iss.str(s);
        for(int i = 0; i < N; i++) {
            iss >> p2[i];
            //cout << p2[i] << "  ";
        }
        //cout << endl;
        sort(p1.begin(), p1.end());
        sort(p2.begin(), p2.end());

        int ans1 = 0, t = 0, s = N-1;
        for(int i = 0; i < N; i++) {
            if(p1[i] > p2[t]) {
                ans1 ++;
                t ++;
            }
            else {
                s --;
            }
        }

        int ans2 = 0;
        t = s = 0;

        for(int i = 0; i < N; i++) {
            int found = 0;
            for(int j = t; j < N; j++) {
                if(p1[i] < p2[j]) {
                    found = 1;
                    t = j + 1;
                    break;
                }
            }
            if(!found) {
                ans2 = N - i;
                break;
            }
        }


        printf("Case #%d: %d %d\n", test, ans1, ans2);
    }
}
