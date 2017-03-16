#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include<climits>
#include<unordered_map>
#include<unordered_set>

using namespace std;

vector<int> pk(1001,0);
int main(int argc, char** argv){
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	int n;
	fin>>n;
	for(int i=0;i<n;i++){
		int l;
		fin>>l;
		int mx=0;
		int mn=INT_MAX;
		int avg = 0;
		for(int j=0;j<l;j++){
			int temp;
			fin>>temp;
			pk[j]=temp;
			avg+=temp;
			if(temp>mx){
				mx = temp;
			} 
			if(temp<mn){
				mn = temp;
			};
		}
		avg/=l;
		int start = floor(sqrt(mn));
		int end = ceil(sqrt(mx));
		int mcost = INT_MAX;
		for(int j=start;j<mx+1;j++){
			int ccost=j;
			for(int m = 0;m<l;m++){
				int cut = ceil((pk[m]+0.0)/j);
				ccost+=cut-1;
			}
			if(ccost<mcost){
				mcost=ccost;
			}
		}
		fout<<"Case #"<<(i+1)<<": "<<mcost<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

