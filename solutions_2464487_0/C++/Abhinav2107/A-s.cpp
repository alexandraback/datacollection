#include <iostream>
/*#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>*/
#include <fstream>
using namespace std;
int main() {
ifstream fi;
ofstream fo;
fi.open("A-s.in");
fo.open("A.in");
int T;
fi >> T;
int i,j;
int v;
int n;
int r;
int t;
for(i = 1; i <= T; i++) {
fi >> r;
fi >> t;
cout << r << " " << t << endl;
v = 0;
n = 0;
for(j = 0; v <= t; j++) {
v += (r+2*j+1)*(r+2*j+1) - (r+2*j)*(r+2*j);
n++;
}  
fo << "Case #" << i << ": " << n-1 << endl; 
}
fi.close();
fo.close();
}
