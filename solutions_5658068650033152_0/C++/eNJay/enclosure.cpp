#include<iostream>


using namespace std;


int main()
{
	int numTestCases;
	int N,M,K;
	int stn = 0;
	cin>>numTestCases;
	
	int lines = 0;
	for(int i = 0; i < numTestCases; i++){
		cin>>N;
		cin>>M;
		cin>>K;
		
		int prevline  = 0;
		int line = (K+1) / 2;
		int in_inter = 0;
		
		bool flag = false;
		
		if(N-2 <= 0 || M-2 <= 0){
			
			cout<<"Case #"<<(i+1)<<": "<<K<<"\n";
			continue;
			
		}
		
		
		while(line>=2){
			
			//cout<<"\n line"<<line;
			int k = 1, l = line - k ;
			
			flag = false;
			bool flag2 = false;
			while(l - k >= 0){
				
				//cout<<"\n k and l "<<k<<" "<<l;
				if(k <= N-2 && l <= M-2){
				
					flag2 = true;
				//cout<<"\n check with "<<k<<" "<<l;
				in_inter = l* k;
				if(in_inter+ line*2 >= K){
				 	flag = true;
				 	prevline = line;
				 	//cout<<" yes";
				}
				
				}
				
				k++;
				l = line - k;
			
			}
			
			if(flag == false && flag2 == true){
			 break;	
			}
		
			
			line--;
		}
		
		if(K<=4 || prevline == 0)
		cout<<"Case #"<<(i+1)<<": "<<K<<"\n";
		else 
		cout<<"Case #"<<(i+1)<<": "<<(prevline*2)<<"\n";
	
	
	}


}

