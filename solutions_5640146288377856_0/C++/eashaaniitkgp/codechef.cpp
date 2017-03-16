#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <climits>
using namespace std;

#define INF INT_MAX


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int caseno;
    
    ifstream fin("ipA3.in");
    ofstream fout("opA.out");
    int t,r,c,w;
    fin>>t;
    for(int caseno=1;caseno<=t;caseno++){
        fin>>r>>c>>w;
        if(c%w)
        fout<<"Case #"<<caseno<<": "<<r*(c/w)+(w)<<endl;
        else
        	fout<<"Case #"<<caseno<<": "<<r*(c/w)+(w-1)<<endl;
        //fout<<"Case #"<<caseno<<": "<<r*(c/w)+(w-1)+(c%w)<<endl;
    }
    system("pause");
    return 0;
}
