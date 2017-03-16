#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <cstring>

using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VII;
typedef vector<VS> VSS;

#define PB push_back

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    int n;
    fin>>n;
    for(int i=1; i<=n; i++) {
    	long long r, t;
	fin>>r>>t;
	long double delta=sqrt((2*(long double)r+1)*(2*(long double)r+1.0)+8*(long double)t);
	long double count0=(delta-2.0*(long double)r-1.0)/4.0;
	long long count1=(long long)count0;
	if(count0-count1 <1e-5) count1--;	
	fout<<"Case #" << i <<": "<<count1<<endl;
    }

    fin.close();
    fout.close();
    return 0;
}
