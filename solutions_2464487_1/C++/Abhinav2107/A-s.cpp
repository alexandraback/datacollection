#include <iostream>
//#include <ctype.h>
#include <math.h>
/*#include <stdio.h>
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
int i;
long double r;
long double t;
long int n;
long double ans;
long double s;
long double check;
for(i = 1; i <= T; i++) {
fi >> r;
fi >> t;
cout << r << " " << t << endl;
s = sqrt(4.0*r*r-4.0*r+8.0*t+1.0);
ans = (s +1.0 - 2.0*r)/4.0;
n = floor(ans);
cout << ans << endl;
check = 2.0*ans*ans + (2.0*r - 1.0)*ans;
if(check > t)
n--;
fo << "Case #" << i << ": " << n << endl; 
}
fi.close();
fo.close();
}
