#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<sstream>
#include<fstream>
#include<map>   
#include<deque>
using namespace std;


int mem[1000005][105];
deque<int> mot;

int nop(int size, int i){

	if(size>1000000 || i>=mot.size() ) return 0;

	if(mem[size][i]==-1){


		int res= 500;

		if(size>mot[i]) res=nop(size+mot[i],i+1);

		else {
			
			if(size>1) res=min(res,1+nop(2*size-1,i));
			res= min(res, 1+nop(size,i+1));
		}
		mem[size][i]=res;

	}

	return mem[size][i];

}




int main(){
	ifstream cin;
	ofstream cout;
	cin.open("A.in");
	cout.open("out.txt");
	
	int T;
	cin>>T;
	for(int k=0;k<T;k++){
		
		int A; cin>>A;
		int n; cin>>n;
		for(int i=0;i<1000005;i++) for(int j=0;j<105;j++) mem[i][j]=-1;
		mot.clear();
		int pivot;
		for(int i=0;i<n;i++) {cin>>pivot; mot.push_back(pivot);}
		sort(mot.begin(),mot.end());
/*
		while(mot.size() !=0 && A>mot[0]){
			A+= mot[0];
			mot.pop_front();

		}*/

		cout<<"Case #"<<k+1<<": "<<nop(A,0)<<endl;





	}





	return 0;

}


