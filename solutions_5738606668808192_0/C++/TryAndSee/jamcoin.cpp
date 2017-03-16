#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


int main(){
	cout<<"launching function main"<<endl;
	ofstream outputfile("myoutput.txt");
	int T=1, N=16, J=50, pos, npair;
	long long int checkval, checkpow;
	int coin[N];
	outputfile<<"Case #1:"<<endl;
	for(int i=0; i<N; i++)
		coin[i]=0;
	coin[N-1]=1; coin[0]=1; coin[1]=1; coin[2]=1;
	for(int j=0; j<J; j++){
		//write coin
		for(int i=0; i<N; i++)
			outputfile<<coin[i];
		//write proof
		for(int i=2; i<=10; i++)
			outputfile<<" "<<(i+1);
		outputfile<<endl;
		//check if divides
		/*if(j==0){
		for(int i=2; i<=10; i++){
			checkval=0; checkpow=1;
			for(int k=0; k<N; k++){
				checkval=checkval+checkpow*coin[k];
				checkpow*=i;
			}
			cout<<" "<<i;
			if(checkval%(i+1)==0)
				cout<<" ok";
			else
				cout<<endl<<"ERROR !"<<endl;
		}
		cout<<endl;
		}*/
		//find new coin
		pos=1;
		while(coin[2*pos]==1){
			coin[2*pos]=0;
			pos++;
		}
		coin[2*pos]=1;
		npair=0;
		for(int i=1; i<=(N-2)/2; i++)
			npair+=coin[2*i];
		for(int i=0; i<npair; i++)
			coin[2*i+1]=1;
		for(int i=npair; i<=(N-3)/2; i++)
			coin[2*i+1]=0;
	}
}

