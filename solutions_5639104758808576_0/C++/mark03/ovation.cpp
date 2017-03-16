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

int T,maxs;
string S;

int main()
{
    fin>>T;
    for(int t=0;t<T;++t)
    {
        fin>>maxs>>S;
        //cerr<<maxs<<" "<<S<<endl;
        int conta=0, sol=0;
        for(int i=0;i<=maxs;++i)
        {
            if(S[i]=='0') continue;
            if(conta<i) sol+=i-conta , conta+=i-conta;
            conta+=S[i]-'0';
        }
        fout<<"Case #"<<t+1<<": "<<sol<<endl;
    }
}
