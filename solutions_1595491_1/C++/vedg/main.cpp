#define IDBG
//#undef IDBG

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <sstream>

using namespace std;


int main() {
#ifdef IDBG
    freopen("cin", "r", stdin);
	freopen("out", "w", stdout);
#endif
	
	int cases;
	cin>>cases;
	for (int cas=1;cas<=cases;++cas){		
		cout<<"Case #"<<cas<<": ";
		
		int n, surprise, p;
		cin>>n>>surprise>>p;
		if (p == 1)
			surprise = 0;
		int p3=p*3-2;
		int count = 0;
		for (int i=0;i<n;++i){
			int q;
			cin>>q;
			if (q >= p3)
				++count;
			else if (surprise > 0 && q >= p3 - 2) {
				--surprise;
				++count;
			}
		}
		cout<<count;		
		
		cout<<endl;
	}
		
#ifdef IDBG
	putchar('\n');
    fclose(stdin);
	fclose(stdout);    
#endif
}

