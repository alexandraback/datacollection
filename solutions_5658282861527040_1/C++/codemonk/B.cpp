/* Code Jam 2014
@Author: Jugesh Sundram
*/

#include <iostream>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iomanip> // for setprecision()

#define f(i,a,b) for (int i = (a); i < (b); i++)
#define r(i,x) for (int i = 0; i<x ;i++)

// Datatypes
#define d double
#define ll long long


using namespace std;

bool isint(float x)
{
     return (x - int(x)>0)?0:1;
}

int main(){

freopen("B-large.in", "r", stdin);
freopen("B-large.out", "w", stdout);

//  cout << setprecision(12);
  
  int test_count;
  cin >> test_count;


r(idx,test_count)
{
 ll a,b,k;
 int count = 0;
 
 cin>>a>>b>>k;
 
 f(i,k,a)
  f(j,k,b)
    if ((i&j) >= k)
     count++;
   
cout << "Case #" << idx + 1 << ": "<<a*b - count<<endl;

}

	return 0;
}

