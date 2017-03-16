#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef vector<PII> VPII;

typedef vector<double> VD;
typedef vector<string> VS;

typedef long long LL;

inline bool isPal(char* s){
    const int l = strlen(s);
    const int lh = l / 2;
    for(int i=0; i<lh; i++){
        // can still be optimized by using j=l-i and doing --j;
        if(s[i] != s[l-i-1])
            return false;
    }
    return true;
}

vector<LL> fairnumbers;

void generate(LL l, LL u){
    const LL start = (LL)sqrt(l);
    const LL end = (LL)sqrt(u) + 10; // better safe than sorry
    
    //cout << start << " -> " << end << endl;
    char buffer[128];
    int cnt = 0;
    for(LL a=start; a<end; a++){
        // check root
        sprintf(buffer,"%lld", a);
        if(!isPal( buffer ))
            continue;
        
        // check square
        const LL sq = a*a;
        sprintf(buffer,"%lld", sq);
        if(!isPal( buffer ))
            continue;
        
        // works! found it!
        fairnumbers.push_back(sq);
        // always sorted
        
        //cout << (cnt++) << "] " << a << " -> " << sq << endl;        
        // "11111 -> 123454321" <3
    }

}

// linear search (fast enough)
int ls(LL key){
    int idx = 0;
    const int s = fairnumbers.size();
    while(idx < s){
        if(fairnumbers[idx] >= key)
            return idx;
        ++idx;
    }
    return idx;
}

int query(LL a, LL b){
    /*int i1 = bs(0, fairnumbers.size(), a);
    int i2 = bs(0, fairnumbers.size(), b);*/
    int i1 = ls(a);
    int i2 = ls(b);
    
    int extra = 0;
    if(fairnumbers[i2] == b)
        ++extra;
      
    //cout << "indexes: " << i1 << "," << i2 << endl;
    
    return i2 - i1 + extra;
}

int main(){ 	
	int cases;
	scanf("%d\n", &cases);
	
	generate(1, 200000000000001);
	
	for(int caseNr = 1; caseNr <= cases; caseNr++){
		// go for it!	
		printf("Case #%d: ", caseNr);
		
		LL a, b;
		scanf("%lld %lld\n", &a, &b);
		printf("%d\n", query(a, b));
		
		fflush(stdout);
	}
	
	return 0;
}
