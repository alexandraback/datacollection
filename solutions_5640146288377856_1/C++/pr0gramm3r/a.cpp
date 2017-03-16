//in the name of god!
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <fstream>
using namespace std;
#define pb push_back
#define x first
#define y second
#define mk make_pair
ifstream fin("1.in");
ofstream fout("1.out");
int T,r,c,w;
int main(){	
  fin>>T;
  for(int t=0;t<T;t++){
    fin>>r>>c>>w;
    int ans = (r-1)*(c/w) + ((c+w-1)/w + w - 1);
    
    fout<<"Case #"<<t+1<<": "<<ans<<endl;
  }
  return 0;
}

