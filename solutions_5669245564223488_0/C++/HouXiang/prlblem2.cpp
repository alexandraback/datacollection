// prlblem2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>
#include <string>

using namespace std; 

bool isvalid(string s) {
    vector<bool> visited(26, false); 
    char pre = s[0]; 
    visited[pre - 'a'] = true;
    for (int i=1; i<s.size(); i++) {
        if (s[i] != pre && visited[ s[i] - 'a' ]) return false;
        pre = s[i]; 
    }
    return true;
}

const int BI = 1000000007; 

int a[101][101]; 
int charnum[26]; 
vector<string> vs; 

int pi[101]; 
bool visited[101];
long long ans = 0; 
bool goodstr(int n) {
    vector<bool> cv(26, false);
    char pre = vs[ pi[0] ][ vs[ pi[0] ].size() - 1];
    for (int j=0; j<vs[ pi[0] ].size(); j++) {
        cv[ vs[ pi[0] ][j] - 'a'] = true;
    }
    
    for (int i=1; i<n; i++) {
        int seq = pi[i]; 
        if (vs[seq][0] != pre ){
            for (int j=0; j<vs[seq].size(); j++) {
                if (cv[ vs[seq][j] - 'a'])
                    return false;
            }
        }
        else {
            for (int j=0; j<vs[seq].size(); j++) {
                if (cv[ vs[seq][j] - 'a'] && vs[seq][j] != pre)
                    return false;
            }
        }

        for (int j=0; j<vs[seq].size(); j++) {
            cv[ vs[seq][j] - 'a'] = true;
        }

        pre = vs[seq][vs[seq].size() - 1];
    }
    return true;
}
void findp(int p, int n) {
    if (p == n) {
        if (goodstr(n)) 
            ans++;
    }
    else {
        for (int i=0; i<n; i++) {
            if (!visited[i]) {
                pi[p] = i; 
                visited[i] = true;
                if (goodstr(p+1))
                    findp(p+1, n);
                visited[i] = false;
            }
        }
    }
}
string prostr(string& s) {
    string bs; 
    char pre = s[0]; 
    bs.push_back(pre);

    for (int i=1; i<s.size(); i++) {
        if (s[i] == pre) continue;

        pre = s[i];
        bs.push_back(pre);
    }
    return bs;
}

long long jiecheng(int n) {
    long long res = 1; 
    for (int i=1; i<=n; i++) {
        res *= i; 
        res %= BI; 
    }
    return res; 
}


int _tmain(int argc, _TCHAR* argv[])
{
    ifstream inf(argv[1]); 
    // ifstream inf("D:\\codejam\\prlblem2\\Debug\\test.txt"); 

    int n = 0; 
    inf >> n; 
    for (int ca=1; ca<=n; ca++) {
        int m = 0; 
        inf >> m; 

        vs.clear(); 
        ans = 0; 
        for (int i=0; i<101; i++) visited[i] = false;

        int k = 0; 
        while (k < m) {
            string s; 
            inf >> s; 
            vs.push_back(s);
            k++;
        }

        memset(a, 0, sizeof(a));
        memset(charnum, 0, sizeof(charnum));
        
        bool ok = true; 
        for (int i=0; i<m; i++) {
            if (!isvalid(vs[i]) ) {
                cout << "Case #" << ca << ": " << 0 << endl; 
                ok = false;
                break;
            }
        }
        if (!ok) continue;

        for (int i=0;i<m; i++) {
            vs[i] = prostr(vs[i]);
        }

        
        for (int i=m-1; i>=0; i--) {
            if (vs[i][0] == vs[i][vs[i].size() - 1]) {

                charnum[vs[i][0] - 'a']++;

                if (charnum[vs[i][0] - 'a'] > 1) {
                    vs.erase(vs.begin() + i);
                }
            }
        }
        /*
        for (int i=0; i<vs.size(); i++) {
            for (int j=0; j<vs.size(); j++) {
                if (i == j) continue;
                if (vs[i][0] == vs[j][ vs[j].size() - 1]) a[j][i] = 1;
                if (vs[j][0] == vs[i][ vs[i].size() - 1]) a[i][j] = 1;
            }
        }

        vector<int> nv(vs.size(), false);
        */

        findp(0, vs.size());

        for (int i=0; i<26; i++) {
            if (charnum[i] > 1) {
                ans *= jiecheng(charnum[i]);
                ans %= BI; 
            }
        }


        cout << "Case #" << ca << ": " << ans << endl; 
    }

	return 0;
}

