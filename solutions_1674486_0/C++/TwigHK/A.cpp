#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;


int main(int argc, char *argv[]){
	fstream fin (argv[1], fstream::in);

	int T;
	fin >> T;
	for (int t = 0; t != T; ++t){
		int N;
		fin >> N;
		vector< vector <int> > inherits (N);

		for(int i = 0; i !=N; ++i){
			int Mi;
			fin >> Mi;
	
			for(int m = 0; m != Mi; ++m){
				int c;
				fin >>c;
				inherits[i].push_back(c);
			}
		}
	
		bool diamond = false;
		for(int i = 0; i != N && diamond == false; ++i){
		vector <int> infrom(1,i+1);
//			cout << "i" << i << endl;
			for(int j = 0; j != infrom.size()&& diamond == false; ++j){
//				cout << infrom[j];
				auto &inh = inherits.at(infrom[j]-1);
				for (int k = 0; k != inh.size(); ++k){
					if(find(infrom.begin(), infrom.end(), inh[k]) != infrom.end())
					{
//						cout << inh[k];
						diamond = true;
						break;
					}
				}

				
				infrom.insert(infrom.end(),inh.begin(), inh.end());

			}
		}


		cout << "Case #" << t+1<< ": ";
		if(diamond){
			cout <<"Yes";
		} else {
			cout <<"No";
		}
		cout << endl;
	}
	return 0;
}
