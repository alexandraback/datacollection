#include <cstdlib>
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;


int maxi = 0;
unsigned int V[10001];

void dfs(int val,int R,int E,int rem,int N,int k){

	if(k==N-1){
		val += rem * V[k];
		if(val > maxi) maxi = val;
	}
	else{
		for(int i=0;i<=rem;i++){
			int remT = rem - i + R < E ? rem - i + R : E;
			dfs(val + i*V[k], R ,E, remT, N, k + 1);
		}
	}

}

int main(){

	ifstream in;
	in.open("B.in");
	//in.open("A-large.in");
	
	ofstream out;
	out.open("out.txt");
	
	int T;
	in>>T;
	

	
	for(int u=0;u<T;u++){
				
		
		unsigned int E;
		unsigned int R;
		unsigned int N;
		in>>E>>R>>N;
		
		
		
		for(int i=0;i<N;i++){
			in>>V[i];
		}
		
		maxi = 0;
		dfs(0,R,E,E,N,0);
		
		//cout<<ret<<endl;
		//cout<<"Case #"<<(u+1)<<": "<<maxi<<endl;
		out<<"Case #"<<(u+1)<<": "<<maxi<<endl;
		cout<<(u+1)<<endl;
		
    }
	in.close();
	out.close();
	
    return 0;
}