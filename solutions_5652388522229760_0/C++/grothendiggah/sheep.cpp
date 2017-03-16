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
  cout<<T<<endl;
  for(int i=0;i<T;i++){
	int N;
	getline(infile, line);
	std::stringstream  Stream1(line);
	Stream1>>N;
	if(N==0){
		outfile<<"Case #"<<i+1<<": INSOMNIA"<<endl;
	}else{
        vector<bool> digits;
        digits.assign(10,false);
        int r=0;
        bool check=true;
        while(check){
            r++;
            int K=r*N;
            while(K>0){
                digits[K%10]=true;
                K/=10;
            }
            check=false;
            for(int j=0;j<10;j++){
                if(digits[j]==false) check=true;
            }
        }
		outfile<<"Case #"<<i+1<<": "<<r*N<<endl;
	}
  }

  infile.close();
  outfile.close();
  return 0;
}


