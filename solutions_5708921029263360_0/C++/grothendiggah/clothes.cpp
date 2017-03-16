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
	int J,P,S,K;
	getline(infile, line);
	std::stringstream  Stream1(line);	
	Stream1>>S>>P>>J>>K;
	vector<int> vecs, vecj, vecp;
	for(int j=1;j<=J;j++){
		for(int p=1;p<=P;p++){
			for(int s=1;s<=S;s++){
				int co1=0,co2=0,co3=0;
				for(int counter=0;counter<vecs.size();counter++){
					if(vecj[counter]==j && vecp[counter]==p) co1++;
					if(vecj[counter]==j && vecs[counter]==s) co2++;					
					if(vecp[counter]==p && vecs[counter]==s) co3++;
				}
				if(co1<K && co2<K && co3<K){
						vecj.push_back(j);
						vecp.push_back(p);
						vecs.push_back(s);
				}
			}
		}
	}
	outfile<<"Case #"<<i+1<<": "<<vecs.size()<<endl;
	for(int c=0;c<vecs.size();c++){
		outfile<<vecs[c]<<" ";
		outfile<<vecp[c]<<" "<<vecj[c]<<endl;
	}
  }		
  
  infile.close();
  outfile.close();
  return 0;
}


