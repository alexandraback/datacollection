#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>


using namespace std;

int reverse (int i){
	if(i%10==0)
		return i;
	stringstream r("");
	while(i!=0){
		int l=i/10;
		int s=i%10;
		r<<s;
		i=l;
	}
	int f;
	r>>f;
	return f;
}

int main(){
	ifstream in("in");
	ofstream out("out");
	int casenum=0;
	in>>casenum;
	int n;
	int bignum=1000100;
	int sol[bignum];
	for(int i=0;i<bignum;i++)
		sol[i]=0;
	
	for(int i=1;i<bignum-1;i++){
		sol[i]=i;
	}
	for(int i=2;i<1000001;i++){
		if(sol[i]>min(sol[i-1],sol[reverse(i)])+1){
			sol[i]=min(sol[i-1],sol[reverse(i)])+1;
						
			}	
	}
//	for(int i=0;i<10;i++)
//		cout<<i<<" "<<sol[i]<<endl;
	for (int c=0;c<casenum;c++){
		in>>n;
		cout<<"Case #"<<c+1<<": "<<sol[n]<<endl;	
	
		
	}
	
	return 0;
	
}
