#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <time.h>       /* time */
#include <algorithm>
#include <list>
#include <utility>


using namespace std;



long long int intpower(long long int a, int b);

int main()
{
  ofstream outfile;
  outfile.open ("solution.out");
  std::ifstream infile;
  infile.open ("data.in", std::ifstream::in);
  std::string   line;
  getline(infile, line);
  std::stringstream  lineStream(line);
  int T;
  lineStream>>T;
  for(int i=0;i<T;i++){
	int K,C,S;
	getline(infile, line);
	std::stringstream  Stream1(line);
	Stream1>>K>>C>>S;
	if(C*S<K) outfile<<"Case #"<<i+1<<": IMPOSSIBLE"<<endl;
	else{
        outfile<<"Case #"<<i+1<<": ";
        int j=0;
        while(j*C<K){
            long long int pos=1;
            for(int r=0;r<C;r++){
                if(j*C+r<K) pos+=intpower(K,r)*(long long int)(j*C+r);
            }
            outfile<<pos<<" ";
            j++;
        }
        outfile<<endl;
	}
  }

  infile.close();
  outfile.close();
  return 0;
}

long long int intpower(long long int a, int b){
    if(b==0) return 1;
    else return a*intpower(a,b-1);
}
