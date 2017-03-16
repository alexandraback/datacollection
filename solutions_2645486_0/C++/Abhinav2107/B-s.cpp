#include <iostream>
/*#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>*/
#include <fstream>
using namespace std;
int min(int a, int b) {
if(a < b)
return a;
else
return b;
}
int E;
int R;
int N;
int v[10];
int solve(int e, int i) {
if(i == N)
return 0;
int j;
int max = 0;
int gain;
for(j = 0; j <= e; j++) {
gain = v[i]*j + solve(min(E, e+R-j), i+1);
if(gain > max)
max = gain;
}
return max;
}
int main() {
ifstream fi;
ofstream fo;
fi.open("B-s.in");
fo.open("B.in");
int T;
fi >> T;
int i;
int j;
for(i = 1; i <= T; i++) {
fi >> E >> R >> N;
for(j= 0; j < N; j++)
fi >> v[j];
fo << "Case #" << i << ": " << solve(E, 0) << endl;
}
fi.close();
fo.close();
}
