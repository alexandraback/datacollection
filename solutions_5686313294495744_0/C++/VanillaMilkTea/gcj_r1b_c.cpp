#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]){
	int T,nocase;
	int N;

	int i,j,k,num;
	unsigned long long arr[100];
	string S1,S2;

	cin >> T;  // read t. cin knows that t is an int, so it reads it as such.
	//T = 4;
	for (nocase = 1; nocase <= T; ++nocase) {
		vector<pair<string,string>> vec;
		cin >> N;
		
		for(i=0;i<N;i++){
			cin >> S1;
			cin >> S2;
			vec.push_back(make_pair(S1,S2));
		}
		//if(nocase!=4) continue;

		//for(i=0;i<vec.size();i++)cout<< vec[i].first <<" "<<vec[i].second<<endl;cout << endl;

		sort(vec.begin(),vec.end());
		
		//for(i=0;i<vec.size();i++) cout<< vec[i].first <<" "<<vec[i].second<<endl; cout<<endl;

		num=0;
		//printf("vec.size: %d\n",vec.size());
		//
		for(i=vec.size()-1;i>1;i--){
			//printf("i: %d\n",i);
			//cout <<"match: "<< vec[i].first<<endl;
			for(j=0;j<i;j++){

				if(vec[i].first.compare(vec[j].first)){
					continue;
				}
				//cout << vec[j].first <<": "<<endl;;
				for(k=0;k<i;k++){
					if(vec[i].second.compare(vec[k].second)==0){
						//cout << vec[k].second<<endl;
						//cout << vec[j].first<< " "<<vec[k].second<<endl;
						num++;
						j=i;
						break;
					}
				}
			}
		}
		//
		//cin >> K >> C >> S;
		//cout << "(K,C,S): (" << K << ", " << C << ", " << S << ")" << endl;

		cout << "Case #" << nocase << ": " << num << endl;
	}

	return 0;
}