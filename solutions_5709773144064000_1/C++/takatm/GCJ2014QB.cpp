//============================================================================
// Name        : GCJ2012QA.cpp
// Author      : Takatomo Honda
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
using namespace std;

#define all(c) (c).begin(),(c).end()
#define FORE(i,d,e) for(int i=d;i<e;i++)
#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

double C,F,X;

string solve(){
	double ret=0.0;
	double cookie=2.0;

	if(C>=X){
		ret+=X/cookie;
		goto next;
	}

	while(1){
		ret+=C/cookie;
		if((X-C)/cookie<=X/(cookie+F)){
			ret+=(X-C)/cookie;
			break;
		}
		cookie+=F;
	}

	next:;
	char ans[10];
	sprintf(ans,"%0.7lf",ret);

	return ans;
}

int main(int argc, char *args[]) {
	FILE *stream;

	if ( argc==2 && strcmp(args[1], "small")==0 ) {
		if( (stream=freopen("test.bsmall.txt","rt",stdin))==NULL){
			printf("file open error");
		}
        //freopen("small.out","wt",stdout);
    }
    else if (argc == 2 && strcmp(args[1], "large") == 0) {
        freopen("large.in","rt",stdin);
        freopen("large.out","wt",stdout);
    }
    else {
	    freopen("B-large.in", "rt", stdin);
        freopen("large.out","wt",stdout);
    }

	int N;
	cin>>N;

    vector<string> ans(N);
    ans.clear();

    FORE(i,0,N){
    	cin>>C>>F>>X;
    	ans.push_back(solve());
    }

    FORE(i,0,N) {
        printf("Case #%d: %s", i+1,ans[i].c_str());
        cout<<endl;
    }

    return 0;
}



