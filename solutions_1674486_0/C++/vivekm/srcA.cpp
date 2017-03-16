#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <fstream>
#include <cmath>
#include <sstream>
#include <time.h>
#include <iomanip>
using namespace std;

class ancestors
{
private:
	ifstream fin;
	ofstream fout;
	vector<vector<int>> mAnc;
	int T;

public:
	ancestors()
		: fin("D:\\jam.in")
		, fout("D:\\jam.out")
	{
	}

	void recurse(int s1, vector<int>& v)
	{
		v.push_back(s1);
		for(int i=0; i<mAnc[s1].size(); ++i){
			recurse(mAnc[s1][i], v);
		}
	}

	bool checkCommon(int s2, vector<int>& v)
	{
		if( find(v.begin(), v.end(), s2) != v.end()){
			return true;
		}
		for(int i=0; i<mAnc[s2].size(); ++i){
			if(checkCommon(mAnc[s2][i], v)){
				return true;
			}
		}
		return false;
	}

	bool any(int s1, int s2)
	{
		vector<int> v;
		recurse(s1, v);
		return checkCommon(s2, v);
	}

	void start(){
		fin >> T;

		int ncase = 1;

		while(T-- > 0)
		{
			int N;
			fin >> N;

			mAnc.clear();

			for(int i=0; i<N; ++i){
				mAnc.push_back(vector<int>());
			}

			for(int i=0; i<N; ++i){
				int n;
				fin>>n;

				for(int j=0; j<n; ++j){
					int k;
					fin>>k;
					--k;

					//ancestor of k is i
					mAnc[k].push_back(i);
				}
			}

			vector<int> suspects;
			for(int i=0; i<N; ++i){
				if(mAnc[i].size() > 1){ //i has more than 1 incoming arrow.
					suspects.push_back(i);
				}
			}

			//for each suspect find a common ancestor.
			bool bFound = false;
			for(int i=0; i<suspects.size() && !bFound; ++i){

				vector<int> susAnc = mAnc[suspects[i]];
				
				for(int k=0; k<susAnc.size() && !bFound; ++k)
				{
					int s1 = susAnc[k];

					for(int j=i+1; j<susAnc.size() && !bFound; ++j){
						int s2 = susAnc[j];

						//let's check if s1 & s2 have a common node.

						//First we mark all nodes that can be reached from s1.
						//then we smell each node that can be reached from s2 and if one is found, FOUND!
						bFound = any(s1, s2);
					}
				}
			}

			if(bFound){
				fout << "Case #" << ncase << ": " << "Yes" << endl;
				cout << "Case #" << ncase << ": " << "Yes" << endl;
			}else{
				fout << "Case #" << ncase << ": " << "No" << endl;
				cout << "Case #" << ncase << ": " << "No" << endl;
			}
			++ncase;
		}
	}
};

int main()
{
	ancestors a;
	a.start();
	return 0;
}