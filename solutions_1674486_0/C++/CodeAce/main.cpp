#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;


int t;
int met[1002];
int n;
vector<int> m[1001];
bool answer;

void go(int x)
{
    if (met[x] >= 1)
        answer = true;
    
	met[x]++;

	int v;
    for (int i=0; i<m[x].size(); i++) {
		v = m[x][i]; 
        go(v);
	}
}

int main() {

    ifstream fin("a1.in");
    ofstream fout("a1.out");


    fin >> t;


    for (int tc=0; tc<t; tc++) {
        fin >> n;
        for (int i=0; i<n; i++) {
            int mm, x;
            fin >> mm;

            m[i+1].clear();
            for (int j=0; j<mm; j++) {
                fin >> x;
                m[i+1].push_back(x);
            }
        }

        answer = false;
        for (int i=1; i<=n; i++) {
			memset(met, 0, sizeof(met));
            go(i);
		}

        fout << "Case #" << tc+1 << ":";
        if (answer)
            fout << " Yes";
        else
            fout << " No";
		fout << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
