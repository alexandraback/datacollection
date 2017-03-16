#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;


//#define fin cin
//#define fout cout

int height[120][120];
int maxHR[120];
int maxHC[120];

bool check(int n, int m)
{

    for(int i=0; i<n; ++i)
        maxHR[i] = *max_element( height[i], height[i] + m);
    int tmp[120];
    for(int j=0; j<m; ++j){
        for(int i=0; i<n; ++i){
            tmp[i] = height[i][j];
        }
        maxHC[j] = *max_element(tmp, tmp+n);
    }

    for(int i=0; i<n; ++i)
    for(int j=0; j<m; ++j)
    if( height[i][j] < maxHR[i] && height[i][j] < maxHC[j] )
    return false;
    return true;
}

int main()
{
    int T, M, N;
    fstream fin("B.in");
    fstream fout("B.out", ios_base::out);
    fin>>T;
    for(int ca=1; ca<=T; ++ca){
        fin>>N>>M;
        for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j)
        fin>>height[i][j];

        fout<<"Case #"<< ca << ": ";
        if(check(N, M)) fout<<"YES" << endl;
        else fout<<"NO"<<endl;
    }
    return 0;
}
