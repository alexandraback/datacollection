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
	int N;
	int fakes=0;
	getline(infile, line);
	std::stringstream  Stream1(line);	
	Stream1>>N;
	vector<pair<string, string> > topics;
	for(int j=0;j<N;j++){
		string s1, s2;
		getline(infile, line);
		std::stringstream  Stream2(line);	
		Stream2>>s1>>s2;
		topics.push_back(make_pair(s1,s2));		
	}
	for(int j=0;j<N;j++){
		bool first=false;
		bool second=false;
		for(int k=0;k<N;k++){
			if(k!=j && topics[k].first==topics[j].first) first=true;
			if(k!=j && topics[k].second==topics[j].second) second=true;
		}
		if(first==true && second==true){
			topics[j]=make_pair(" "," ");
			fakes++;
		}
	}
	outfile<<"Case #"<<i+1<<": "<<fakes<<endl;	
  }		
  
  infile.close();
  outfile.close();
  return 0;
}


