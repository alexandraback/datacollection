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
  outfile.open ("phonenumber.out");
  std::ifstream infile;
  infile.open ("data.in", std::ifstream::in);
  std::string   line;
  getline(infile, line);
  std::stringstream  lineStream(line);
  int T;
  lineStream>>T;
  for(int k=0;k<T;k++){
	int z=0,o=0,w=0,t=0,r=0,v=0,x=0,s=0,g=0,i=0;
	string letter;
	getline(infile, line);
	std::stringstream  Stream1(line);	
	Stream1>>letter;
	for(int j=0;j<letter.length();j++){
		char c=letter[j];
		if(c=='Z') z++;
		if(c=='O') o++;
		if(c=='W') w++;
		if(c=='T') t++;
		if(c=='R') r++;
		if(c=='V') v++;
		if(c=='X') x++;
		if(c=='S') s++;
		if(c=='G') g++;
		if(c=='I') i++;
	}
	vector<int> digits;
	digits.assign(10,0);
	digits[0]=z;
	r=r-z;
	o=o-z;
	digits[2]=w;
	o=o-w;
	t=t-w;
	digits[6]=x;
	s=s-x;
	i=i-x;
	digits[8]=g;
	i=i-g;
	t=t-g;
	digits[3]=t;
	r=r-t;
	digits[7]=s;
	v=v-s;
	digits[5]=v;
	i=i-v;
	digits[4]=r;
	o=o-r;
	digits[9]=i;
	digits[1]=o;
	outfile<<"Case #"<<k+1<<": ";
	for(int counter=0;counter<10;counter++){
		for(int counter2=0;counter2<digits[counter];counter2++){
			outfile<<counter;
		}
	}
	outfile<<endl;
  }		
  
  infile.close();
  outfile.close();
  return 0;
}


