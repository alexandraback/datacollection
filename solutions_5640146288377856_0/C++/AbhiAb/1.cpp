//BIG-OH
//prob-
//Algo-
//complexity-
#include<cstdio>
#include<iostream>
#include<cstring>
#include<sstream>
#include<stdlib.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<stack>
#include<queue>
#include<iomanip>
#include<ctype.h>
#include<complex>
#include<utility>
#include<functional>
#include<bitset>
#include<numeric>
#include<cassert>
#include<climits>
#include <fstream> 
using namespace std;
#define ll long long 
#define gc getchar_unlocked
//#define mod 1000000009
#define pq priority_queue
#define vi vector<int>
#define eps 1e-9
#define inf (1 << 28)
#define  MX 1111
#define pi pair<int ,int >

int main()
{
  int t;
  cin>>t;
  int R,C,W;
  for(int z=1;z<=t;z++)
  {
    
    cin>>R>>C>>W;
    int temp= 0;
    temp= C / W *R;
    temp+= W - 1;
    if (C%W != 0) temp++;
    cout << "Case #" <<z<< ": " << temp<< endl;
  }
} 

