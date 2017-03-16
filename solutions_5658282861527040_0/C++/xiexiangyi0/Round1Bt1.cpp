#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

 int Lottery(unsigned int a, unsigned int b, unsigned int k){
	 int count=0;
	 for(unsigned int i=0;i<a;++i){
		 for(unsigned int j=0;j<b;++j){
			 if((i&j)<k)
				 count++;
		 }
	 }
	 return count;
 }

int main(int argc, const char* argv[]){
	ifstream infile;
	infile.open("B-small-attempt1.in");
    ofstream outfile;
	outfile.open("B-small1.out");
	
    int T;
    infile >> T;
  for(int i=0; i<T; i++) {
    int a, b, k;
	infile >> a >> b >> k;
	int num = Lottery(a,b,k);
	
	outfile <<"Case #" <<i+1<<": "<<num<<endl;
  }
}