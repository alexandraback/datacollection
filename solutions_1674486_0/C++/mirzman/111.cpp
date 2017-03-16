#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>
#include <set>
#include <string.h>
using namespace std;

int n;
int a[1024][1024];
bool f2[1024];
bool f3[1024];
bool fDiam;



void GG(int v)
{
	if (f2[v]) {
		f2[v] = false;
		f3[v] = false;
		for (int i = 1; i <= a[v][0]; ++i) {
			GG(a[v][i]);
		}
	} else {
		fDiam = true;
	}
}


int main()
{
    int nn;
    scanf("%d\n", &nn);
    for (int ii = 1; ii <= nn; ++ii) {
    	scanf("%d", &n);
    	//cout << n << " ";
    	for (int i = 1; i <= n; ++i) {
    		scanf("%d", &a[i][0]);
    		for (int j = 1; j <= a[i][0]; ++j) {
    			scanf("%d", &a[i][j]);
    		}
    	}
    	memset(f3, true, sizeof f3);
    	fDiam = false;

    	for (int i = 1; i <= n; ++i) {
    		if (f3[i]) {
    	    	memset(f2, true, sizeof f2);
    			GG(i);
    		}
    	}
    	if (fDiam) {
        	printf("Case #%d: Yes\n", ii);
    	} else {
        	printf("Case #%d: No\n", ii);
    	}
    }

	return 0;
}
