#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void go(int cur, int wer, int &times,vector<int> *home){
		//cout<<cur<<" ";
	if(times>=2) return;
	if(cur==wer){
		times++;
		//cout<<"\ntime++\n";
		return;
	}

	for(int i=0;i<home[cur].size();i++){
		go(home[cur].at(i),wer,times,home);
	}
}

bool cheker(int N1,int N2, vector<int> *home){
	//cout<<endl<<N1<<" "<<N2<<" :\n";
	int times=0;
	go(N1,N2,times,home);
	if(times>=2) return true;
	return false;
}

int main(){
	ifstream input;
	ofstream output;
	input.open("d:/input.in");
	output.open("d:/output.in");
	int T;
	input>>T;
	for(int i=1;i<=T;i++){
		vector<int> home[1000];
		int N;
		input>>N;
		for(int j=0;j<N;j++){
			int Mi;
			input>>Mi;
			for(int k=0;k<Mi;k++){
				int mi2;
				input>>mi2;
				home[j].push_back(mi2-1);
			}
		}
		bool chk=false;
		for(int j=0;j<N;j++){
			if (chk==true) break;
			for(int k=0;k<N;k++){
				if(k==j) continue;
				chk=cheker(j,k,home);
				if (chk==true) break;
			}
		}
		cout<<"Case #"<<i<<": ";
		output<<"Case #"<<i<<": ";
		if (chk==true) cout<<"Yes"<<"\n"; else cout<<"No"<<"\n";
		if (chk==true) output<<"Yes"<<"\n"; else output<<"No"<<"\n";
	}
	system("pause");
	return 0;
}