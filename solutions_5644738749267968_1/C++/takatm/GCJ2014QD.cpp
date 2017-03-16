
//============================================================================
// Name        : GCJ2012QD.cpp
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

int num;

string solve(int n,vector<double> p1,vector<double> p2){
	int ret1=n,ret2=n;

	sort(all(p1));
	sort(all(p2));

	int left=0;
	FORE(i,0,n){
		if(p1[i]<p2[left])ret1--;
		else left++;
	}

	left=0;
	FORE(i,0,n){
		if(p2[i]>p1[left]){
			ret2--;
			left++;
		}
	}

	char ans[10];
	sprintf(ans,"%d %d",ret1,ret2);
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
	    freopen("D-large.in", "rt", stdin);
        freopen("large.out","wt",stdout);
    }

	int N;
	cin>>N;

    vector<string> ans(N);
    ans.clear();

    FORE(i,0,N){
    	cin>>num;
    	vector<double> p1(num),p2(num);
    	FORE(j,0,num)cin>>p1[j];
    	FORE(j,0,num)cin>>p2[j];
    	ans.push_back(solve(num,p1,p2));
    }

    FORE(i,0,N) {
        printf("Case #%d: %s", i+1,ans[i].c_str());
        cout<<endl;
    }

    return 0;
}



