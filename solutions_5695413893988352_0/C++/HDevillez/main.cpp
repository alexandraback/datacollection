#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <bitset>
#include <cstdio>
#include <sstream>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <cctype>
#include <iomanip>
#include <list>
#include <cstring>

#define INF 2000000000
#define ull double
#define vi vector<int>
#define vii vector<ii>

#define UNVISITED 0
#define OPENED 1
#define CLOSED 2

#define NBNODE 2000


using namespace std;



string s1, s2; 

int s1Best;
int s2Best;
string currBest1;
string currBest2;
string rep1;
string rep2;

void dfs(int ipos1, int ipos2, int v1, int v2) {
    
    if(ipos1 == s1.size() && ipos2 == s2.size()) {
        if(abs(v1-v2) <= abs(s1Best - s2Best)) {
            if(abs(v1-v2) == abs(s1Best - s2Best)) {
                if(v2 == s2Best) {
                    if(v1 < s1Best) {
                        s1Best= v1;
                        s2Best = v2;
                        rep1 = currBest1;
                        rep2 = currBest2;
                    }
                }
                else if(v2 < s2Best) {
                    s1Best = v1;
                    s2Best = v2;
                        rep1 = currBest1;
                        rep2 = currBest2;
                }
            }
            else {
                s1Best = v1;
                s2Best = v2;   
                        rep1 = currBest1;
                        rep2 = currBest2;
            }      
        }

    }
    else {
        
        unsigned long long int best= INF;

        if(ipos1 < s1.size()) {
            if(s1[ipos1] != '?') {
                int a = (int) (s1[ipos1] - '0');
                currBest1[ipos1] = a+'0';
                dfs(ipos1+1, ipos2, v1*10+a, v2);
            }
            else {
                for(int i= 0; i <= 9; i++) {
                    currBest1[ipos1] = i + '0';
                  dfs(ipos1+1, ipos2, v1*10+i, v2);   
                } 
            }
        }
    
        if(ipos2 < s2.size()) {
            if(s2[ipos2] != '?') {
                int a = (int) (s2[ipos2] - '0');
                currBest2[ipos2] = a+'0';
                dfs(ipos1, ipos2+1, v1, v2*10+a);
            }
            else {
                for(int i= 0; i <= 9; i++) {
                    currBest2[ipos2] = i + '0';
                    dfs(ipos1, ipos2+1, v1, v2*10+i);   
                } 
            }
        }
    }


}


int main () {  

    int nCase;
    cin >> nCase;

    for(int iCase= 0; iCase < nCase; iCase++) {
        cin >> s1 >> s2;

        s1Best = INF;
        s2Best = 0;
        currBest1 = s1;
        currBest2 = s2;

        dfs(0,0,0,0);
        printf("Case #%d: ", iCase+1);
        cout << rep1 << " " << rep2 << endl;
    }
      
        
    
    return 0;
}
