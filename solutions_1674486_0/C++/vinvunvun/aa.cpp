#include <ctime>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>
#include <fstream>
#include <iomanip>
#include<bitset>


using namespace std;

typedef long long int64;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define sz(x) ((int) (x).size())
#define pb push_back

int main() {
    ifstream fin ("A");
    ofstream fout ("A.out.txt");
    int T; fin>>T;
    forn(i,T){
        int N;
        fin>>N;
        vector <int> number(N);
        vector <vector <int> > parent(N);
        int temp;
        forn (i,N)
        {
            fin >> number[i];
            forn (j,number[i])
            {
                fin >> temp;
                parent[i].push_back(temp);
            }
        }

        bool status = false;
        forn (i, N)
        {
            vector <bool> inherited(N);
            vector <int> next;
            int k = 0, current=0;
            forn (j, number[i])
            {
                next.push_back(parent[i][j]);
                inherited[parent[i][j]-1] = true;
            }
            k =number[i];

            while (current<k)
            {
                forn (j, number[next[current]-1])
                {
                    if (inherited[parent[next[current]-1][j]-1])
                    {
                        status = true;
                        break;
                    }
                    else{
                        inherited[parent[next[current]-1][j]-1] = true;
                        next.push_back(parent[next[current]-1][j]);
                        k++;
                    }
                }
                current++;
            }

            if (status==1) break;
        }

        fout << "Case #" << i+1 << ": ";
        if (status==1) fout << "Yes" << endl;else fout << "No" << endl;
    }

}


