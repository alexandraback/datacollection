#include <cstdio>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int
rec(vector< vector<int> > v, int j, int k)
{
        if (j == k)
                return 1;
        vector<int> &ds = v[j];
        int result = 0;
        for (size_t i = 0; i < ds.size(); i++)
                result += rec(v, ds[i], k);
        return result;
}


int
main(int argc, char **argv)
{
        int T;

        string lineT;
        getline(cin, lineT);
        stringstream ssT(lineT);
        ssT >> T;

        for (int i = 0; i < T; i++) {

                string lineN;
                getline(cin, lineN);
                stringstream ssN(lineN);
                int N;
                ssN >> N;

                vector< vector<int> > cs;

                for (int j = 0; j < N; j++) {

                        string line;
                        getline(cin, line);
                        stringstream ss(line);

                        int dd;
                        ss >> dd;
                        vector<int> ds;
                        for (int k = 0; k < dd; k++) {
                                int d;
                                ss >> d;
                                ds.push_back(d-1);
                        }
                        cs.push_back(ds);
                }

                for (int j = 0; j < N; j++) {
                        vector<int> &ds = cs[j];
                        for (size_t k = 0; k < ds.size(); k++) {
                                cerr << " " << ds[k];
                        }
                        cerr << endl;
                }

                bool dia = false;
                for (int j = 0; j < N; j++) {
                        for (int k = 0; k < N; k++) {
                                if (rec(cs, j, k) > 1) {
                                        dia = true;
                                        goto out;
                                }
                        }
                }

out:
                cout << "Case #" << i+1 << ": " << (dia ? "Yes" : "No") << endl;

        }

        return 0;
}
