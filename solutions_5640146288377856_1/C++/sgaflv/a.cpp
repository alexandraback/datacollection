


#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <set>

using namespace std;

#define EPS 0.000000001
#define INF 1000000000

#define N 1000000
#define ll 100000000000001LL

int c, r, w;



int solve (int c, int w) {
	if (w==1) return c;
	if (c==w) return c;
	
	if (c-w<w) {
		return w+1;
	}
	
	return 1+solve(c-w, w);
	
}

int solve (int r, int c, int w) {
	return (r-1)*c/w+solve(c, w);
}


int main() {
	
	
	
	int T;
	cin>>T;
	int n;
	
	int caseNum=0;
	
	while (T-->0)
	{
		cin>>r>>c>>w;
		
		cout<<"Case #"<<++caseNum<<": "<<solve(r, c,w)<<endl;
	}
	
	return 0;
}

