#include<bits/stdc++.h>

using namespace std;

#define eps 1e-7

int main(){
	int n,nc=0;cin>>n;
	double C,F,X;
	while(n--){
		cin>>C>>F>>X;
		double sol = 0;
		double PA  = 2;
		cout<<"Case #"<<++nc<<": ";
		int i=0;
		while(true){
			//cout<<"D: 	"<<X/PA<<" "<< C/PA<<" PA-"<<PA<<endl;
			if(X/PA < C/PA+(X/(PA+F))){
				sol+=X/PA;
				printf("%.7lf\n",sol);
				break;
			}else{	
				
				//cout<<sol<<endl;	
				sol+= C/PA;
				PA += F;	
			}
		}
	}

}
