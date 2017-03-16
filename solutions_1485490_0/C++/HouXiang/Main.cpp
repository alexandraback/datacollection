#include <assert.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

/*
int ElapsedTime(const vector<int>& vecButtons, int index) {
	return abs(vecButtons[index] - vecButtons[index - 1]);
}
*/

struct s {
    int v;
    __int64 n; 
};

__int64 findsolution(vector<s> &v1, vector<s> &v2, int n1, int n2) {
    if ((n1 < 0) || (n2 < 0))
        return 0;

    if (v1[n1].v == v2[n2].v) {
        vector<s> nv; __int64 min; 
        if (v1[n1].n < v2[n2].n) {
            nv = v2; nv[n2].n = v2[n2].n - v1[n1].n;
            min = v1[n1].n;
            return min + findsolution(v1, nv, n1-1, n2);
        }
        else {
            nv = v1; nv[n1].n = v1[n1].n - v2[n2].n;
            min = v2[n2].n;
            return min + findsolution(nv, v2, n1, n2-1);
        }
        
    }
    else {
        __int64 max1 = findsolution(v1, v2, n1-1, n2);
        __int64 max2 = findsolution(v1, v2, n1, n2-1);
        return max1 > max2 ? max1 : max2; 
    }
}

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
    inf >> ln;

    int cases = atoi(ln.c_str());
    
	for (int i=0; i<cases; i++) 
    {
        inf >> ln; int N = atoi(ln.c_str());
        inf >> ln; int M = atoi(ln.c_str());
        vector<s> vn, vm; 
        for (int ii=0; ii<N; ii++) {
            inf >> ln; __int64 a = _atoi64(ln.c_str());
            inf >> ln; int A = atoi(ln.c_str());
            s mys; 
            mys.v = A; 
            mys.n = a;
            vn.push_back(mys);
        }
        for (int ii=0; ii<M; ii++) {
            inf >> ln; __int64 b = _atoi64(ln.c_str());
            inf >> ln; int B = atoi(ln.c_str());
            s mys;
            mys.v = B; 
            mys.n = b;
            vm.push_back(mys);
        }

        // find solution


        cout << "Case #" << i+1 << ": " << findsolution(vn, vm, N-1, M-1) << endl;
	}

	return 0;
}

