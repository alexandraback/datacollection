#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <bitset>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <functional>
#include <utility>
#include <ctime>
#include <numeric>
#include <iomanip>
#include <stdexcept>
#include <cmath>
#include <algorithm>

using namespace std;

#define LINT long long

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("B1.out","w",stdout);

   LINT T;
   cin>>T;
   
   LINT i,j,k;

   for(k =0; k <T; k++)
   {
     LINT r,t;
     cin>>r>>t;
//     cout<<r<<" "<<t<<endl;
     LINT b = (2*r-1);
//     cout<<b<<endl;
     LINT A = (LINT)0-b;
     LINT B = b*b + 4 * 2 * t;
//     cout<<B<<endl;
     LINT X = (LINT)sqrt((long double)B);
//     cout<<X<<endl;

     LINT soln = (LINT)(( A + X )/((double)4.0));

//     LINT B1 = 4 * 2 * t;
//     cout<<B1<<endl;
//     LINT X1 = (LINT)sqrt((double)B1);
//     cout<<X1<<endl;

//     LINT soln1 = (LINT)(( X1)/((long long double)4.0));

  
     cout<<"Case #"<<k+1<<": "<<soln<<endl;
   }

  return 0;
	}

