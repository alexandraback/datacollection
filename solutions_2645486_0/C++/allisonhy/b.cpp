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

int find_gain(const VI& value, VI effort) {
	int sum=0;	
	for(int i=0; i<value.size(); i++) sum+=value[i]*effort[i];
	return sum;
}

void find(int e, int r, int n, const vector<int>& value, int index, vector<int> effort, int& maxgain, int left) {
	if(index==n) {
		int gain=find_gain(value, effort);
		maxgain=max(maxgain, gain);
		return;
	}
	for(int cur=0; cur<=left; cur++) {	
		int left2=left-cur+r;
		if(left2>e) continue;
		effort[index]=cur;
		find(e, r, n, value, index+1, effort, maxgain, left2);
	}
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    int n;
    fin>>n;
    for(int i=1; i<=n; i++) {
	    int e, r, n;
	    fin>>e>>r>>n;
	    VI value(n, 0);
	    for(int j=0; j<n; j++) fin>>value[j];
	    VI effort(n, 0);
	    int maxgain=0;
	    find(e, r, n, value, 0, effort, maxgain, e);
	    fout<<"Case #"<<i<<": "<<maxgain<<endl;
    }

    fin.close();
    fout.close();
    return 0;
}
