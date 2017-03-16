#include <iostream>
/*#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>*/
#include <fstream>
using namespace std;
int max(int a, int b) {
if(a>b)
return a;
else
return b;
}
int main() {
ifstream fi;
ofstream fo;
fi.open("in.in");
fo.open("out.in");
int T, R, N, M, K;
fi >> T >> R >> N >> M >> K;
int i, j, k;
int a[100][7];
int n2, n3, n4, n5;
cout << "Hello, World" << endl;
for(i = 0; i < R; i++)
for(j=0;j<K;j++)
fi >> a[i][j];
fo << "Case #1:" << endl;
bool found;
int x, y, z;
for(i = 0; i<R; i++) {
n5 = 0;
n2 = 0;
n3 = 0;
n4 = 0;
for(j = 0; j<K; j++) {
switch(a[i][j]) {
case 2:
n2 = max(n2, 1);
break;
case 3:
n3 = max(n3, 1);
break;
case 5:
n5 = max(n5, 1);
break;
case 6:
n2 = max(n2, 1);
n3 = max(n3, 1);
break;
case 9:
n3 = max(n3, 2);
break;
case 10:
n2 = max(n2, 1);
n5 = max(n5, 1);
break;
case 15:
n3 = max(n3, 1);
n5 = max(n5, 1);
break;
case 18:
n3 = max(n3, 2);
n2 = max(n2, 1);
break;
case 24:
n3 = max(n3, 1);
n2 = max(n2, 1);
n4 = max(n4, 1);
break;
case 25:
n5 = max(n5, 1);
break;
case 30:
n3 = max(n3, 1);
n2 = max(n2, 1);
n5 = max(n5, 1);
break;
case 32:
n2 = max(n2, 1);
n4 = max(n4, 2);
break;
case 40:
n5 = max(n5, 1);
n2 = max(n2, 1);
n4 = max(n4, 1);
break;
case 50:
n2 = max(n2, 1);
n5 = max(n5, 2);
break;
case 75:
n3 = max(n3, 1);
n5 = max(n5, 2);
break;
case 27:
n3 = max(n3, 3);
break;
case 36:
n3 = max(n3, 2);
n4 = max(n4, 1);
break;
case 45:
n3 = max(n3, 2);
n5 = max(n5, 1);
break;
case 48:
n3 = max(n3, 1);
n4 = max(n4, 2);
break;
case 60:
n3 = max(n3, 1);
n5 = max(n5, 1);
n4 = max(n4, 1);
break;
case 100:
n5 = max(n5, 2);
n4 = max(n4, 1);
break;
case 125:
n5 = max(n5, 3);
break;
case 64:
n4 = max(n4, 3);
break;
case 80:
n5 = max(n5, 1);
n4 = max(n4, 2);
break;
}
if(n2 + n3 + n4 + n5 == 3) {
break;
}
}
for(k=0; k<n2; k++)
fo << "2";
for(k=0; k<n3; k++)
fo << "3";
for(k=0; k<n4; k++)
fo << "4";
for(k=0; k<n5; k++)
fo << "5";
for(k=0; k<(3-n2-n3-n4-n5); k++)
fo << "2";
fo << endl;
}
fi.close();
fo.close();
}
