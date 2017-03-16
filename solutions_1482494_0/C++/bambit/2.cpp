#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

int main(){
	int T;
	cin >> T;

	for(int t=1; t<=T; t++){
	/*
	Code per test goes here
	*/	
		int N;
		cin >> N;

		vector<int> A(N);
		vector<int> B(N);
		vector<int> which(N);

		for(int i=0; i<N; i++){
			cin >> A[i] >> B[i];	
			which[i] = 1;	
		}

		int stars = 0;
		int score = 0;
		bool fail = false;
		bool done = false;
		while(true){
			int tgt = -1;
			int ptgt = -1;
			int gtgt = -1;
			int mode = 0;
			for(int i=0; i<N; i++){
				if((stars >= B[i])&&(which[i]!=3)){
					if(which[i]==2) stars++;
					else if(which[i]==1) stars+=2;	
					score++;
					which[i]=3;			
				}			
			}	
			for(int i=0; i<N; i++){
				if( which[i]==2 ){
					gtgt = i;
					if(stars >= B[i]){
						mode = 2;
						break;
					}	
				}
			}
			if(mode == 2) continue;
			for(int i=0; i<N; i++){		
				if(which[i]==1){
					gtgt = i;
					if( stars >= A[i] ){ 
						ptgt = i;
						mode = 1;
						break;
					}				
				}
				if(i == N-1){
				/*
				Nothing else possible
				*/			
					if(gtgt!=-1) fail = true;
					else done = true;
				}	
			}	
			if(fail || done) break;
			else if(mode == 1) {	
				stars++;
				score++;
				which[ptgt] = 2;			
			}						
		}
		
	
	if(fail) cout << "Case #" << t <<  ": Too Bad" << endl;
	else cout << "Case #" << t <<  ": " << score << endl;
	}
}
