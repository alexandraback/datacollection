#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;
int to_invite(int n, string& str){
	vector<int> hist(n+1,0);
	int sum = 0;
	int to_i = 0;
	
	for(int i=0;i<n+1;i++){
		hist[i]=(int)(str[i]-'0');
		if(sum>=i){
			sum+=hist[i];
		}else{
			to_i += i-sum;
			sum = i;
			sum+=hist[i];
		}
	}
	return to_i;
}
int main(int argc, char** argv){
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	int n;
	string hist;
	fin>>n;
	for(int i=0;i<n;i++){
		int j;
		fin>>j;
		fin>>hist;
		fout<<"Case #"<<i<<": "<<to_invite(j,hist)<<endl;;
	}
	fin.close();
	fout.close();
}
