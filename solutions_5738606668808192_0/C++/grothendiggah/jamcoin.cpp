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


  /*
  The key observation is that if the alternating sum of digits is 0 then string taken in base b is divisible by b+1.
  Therefore we only need to construct enough number with alternating sum of digits 0 which is a bit technical but not
  really a computational challenge.
  For the specific numbers of N and J it is even simple because it is sufficient to use only number consisting of blocks of the type
  11 and 00.
  */

using namespace std;



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
	int N,J;
	getline(infile, line);
	std::stringstream  Stream1(line);
	Stream1>>N>>J;
	outfile<<"Case #"<<i+1<<":"<<endl;
    for(int j=0;j<J;j++){
            int r=j;
            if(N%2==0) outfile<<"11";
            else outfile<<"110";
            for(int m=0;m<(N-4)/2;m++){
                if(r%2==0)outfile<<"11";
                else outfile<<"00";
                r/=2;
            }
            outfile<<"11\t";
            for(int l=3;l<12;l++) outfile<<l<<"\t";
            outfile<<endl;
    }

  }

  infile.close();
  outfile.close();
  return 0;
}


