#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>

using namespace std;


typedef long long i64;


int main() {
//	freopen("debug\\in.txt","r",stdin);
	freopen("debug\\A-small-attempt0.in","r",stdin);
	freopen("debug\\out.txt","w",stdout);
	int testcases, R, C, W, res,k;
	cin>>testcases;

	for (int i=0; i<testcases; i++) {

		cin>>R;
		cin>>C;
		cin>>W;


		cout<<"Case #"<<i+1<<": ";

		int block = ceil((double)C/W);

		if (block>(int)(C/W)){
			block--;
			k=block*R;
			res = k+W;
		}
		else{
			k=block*R;
			res = k+W-1;
		}
//		int k=block*R;

		cout<<res<<endl;


		
	}


	return 0;
}