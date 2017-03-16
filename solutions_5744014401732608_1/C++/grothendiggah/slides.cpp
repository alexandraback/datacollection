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

long long int power(long long int a, long long int b);

int main()
{
  ofstream outfile;
  outfile.open ("slides.out");
  std::ifstream infile;
  infile.open ("data.in", std::ifstream::in);
  std::string   line;
  getline(infile, line);
  std::stringstream  lineStream(line);
  int T;
  lineStream>>T;
  for(int i=0;i<T;i++){
	long long int B,M;
	getline(infile, line);
	std::stringstream  Stream1(line);	
	Stream1>>B>>M;
	if(M>power(2,B-2)) outfile<<"Case #"<<i+1<<": IMPOSSIBLE"<<endl;
	else{
		outfile<<"Case #"<<i+1<<": POSSIBLE"<<endl;
		if(M==power(2,B-2)){
			outfile<<"0";
			for(int j=0;j<B-1;j++) outfile<<"1";
			outfile<<endl;
		}else{
			vector<int> base2;
			base2.assign(B-2,0);
			long long int dec=M;
			int index=0;
			while(dec>0){
				if(dec%2==1) base2[index]=1;
				else base2[index]=0;
				dec/=2;
				index++;
			}
			outfile<<"0";
			for(int j=0;j<B-2;j++) outfile<<base2[B-3-j];
			outfile<<"0"<<endl;
		}
		for(int z=2;z<=B;z++){
			for(int r=1;r<=z-1;r++) outfile<<"0";
			outfile<<"0";
			for(int r=z+1;r<=B;r++) outfile<<"1";
			outfile<<endl;
		}
	}
	
  }		
  
  infile.close();
  outfile.close();
  return 0;
}



long long int power(long long int a, long long int b){
	if(b==0) return 1;
	else return a*power(a,b-1);
}

