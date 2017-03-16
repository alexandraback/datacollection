#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <limits>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;
#define pb push_back

#include <fstream>
ifstream fin("input.txt");
ofstream fout("output.txt");
#define MAXN 1010
int T,D,a[MAXN];

int main()
{
    fin>>T;
    for(int t=1;t<=T;++t)
    {
        fin>>D;
        for(int i=0;i<D;++i) fin>>a[i];
        int sol=1000000000;
        for(int i=1;i<=1000;++i)
        {
            int temp=i;
            for(int j=0;j<D;++j) temp+=(a[j]-1)/i;
            sol=min(sol,temp);
        }

        fout<<"Case #"<<t<<": "<<sol<<endl;
    }
}
