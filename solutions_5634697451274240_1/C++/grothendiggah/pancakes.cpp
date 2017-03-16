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
  for(int i=0;i<T;i++){
	string s;
	getline(infile, line);
	std::stringstream  Stream1(line);
	Stream1>>s;
	char c=s[0];
	int counter=0;
	for(int j=1;j<s.length();j++){
        if(s[j]!=c) counter++;
        c=s[j];
	}
	if(c=='-') counter++;
	outfile<<"Case #"<<i+1<<": "<<counter<<endl;
  }

  infile.close();
  outfile.close();
  return 0;
}


