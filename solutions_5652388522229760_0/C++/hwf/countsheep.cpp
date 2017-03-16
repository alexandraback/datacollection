#include<iostream>
#include<fstream>
using namespace std;

int countsheep(int n){
	int notseen=10,c=1;
	bool isseen[10];
	for(int i=0;i<10;i++){
		isseen[i]=false;
	}

	if(n==0) return -1;

	int num;
	while(notseen>0){
		num=c*n;
		while(num>0){
			if(!isseen[num%10]){
				notseen--;
				isseen[num%10]=true;
			}
			num/=10;
		}
		c++;
	}

	return --c*n;
}

void main(){

	fstream infile,outfile;
	int testnum,num,c;
	infile.open("A-small-attempt0.in",ios::in);
	outfile.open("output.dat",ios::out);	
	infile>>testnum;
	for(int i=1;i<=testnum;i++){
		infile>>num;
		c=countsheep(num);
		if(c==-1){
			outfile<<"Case #"<<i<<": INSOMNIA\n";
		}else{
			outfile<<"Case #"<<i<<": "<<countsheep(num)<<'\n';
		}
	}
}