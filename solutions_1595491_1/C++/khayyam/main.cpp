#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
#define MIN(a,b) (((a)<(b))?(a):(b))
int main(int argc, char *argv[]){
	int T,N,S,p;
	cin>>T;

	for(int c=1;c<=T;++c){
		cin>>N>>S>>p;
		int conditionalCount=0;
		int inconditionalCount=0;
		for(int i=0;i<N;++i){
			int ti;
			cin>>ti;
			if(ti>=3*p){
				++inconditionalCount;
			}else{
				if(ti>=3*p-2){
					if(p>=1){
						++inconditionalCount;
					}
				}else if(ti>=3*p-4){
					if(p>=2){
						++conditionalCount;
					}
				}
			}
		}
		int sol=inconditionalCount+MIN(conditionalCount, S);
		cout<<"Case #"<<c<<": "<<sol<<endl;
	}
	return 0;
}

