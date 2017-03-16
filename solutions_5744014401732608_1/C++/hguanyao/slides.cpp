#include <iostream>
#include <queue>  
#include <vector>   
#include <set>
#include <utility>
#include <math.h>       /* atan */
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <stack>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
#define foreach(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846 
long double diff = 1e-10;

vector<ull> power;

//return the index of power which is <= M

int BS(ull M){
	int start = 0;
	int end = power.size();
	while(start<end){
		int middle = (start+end+1)/2;
		if(power[middle] > M){
			end = middle-1; 
		}
		else
			start = middle;
	}
	return start;
}
int main(int argc, char** argv) {
	int T;
	cin>>T;
	
	ull base = 1;
	for(int i=0; i<63; i++){
		power.push_back(base);
		if(base>base*(ull)2)
			cout<<"end "<<i<<endl;
		base = base*(ull)2;
	}
	foreach(itest, T){
		ull B; ull M;
		cin>>B; cin>>M;
		//cout<<"input "<<B<<":"<<M<<":"<<power[B-1]<<endl;
		cout<<"Case #"<<itest+1<<": ";
		if(M>power[B-2]){
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		cout<<"POSSIBLE"<<endl;
		int result[B][B];
		for(int i=0; i<B; i++)
			for(int j=0; j<B; j++)
				result[i][j] = 0;
				
		int searchindex = BS(M); //return the index of power which is <= M
		//populate all the 1 to seachindex+1;
		M -= power[searchindex];
		if(M == 0){
			for(int i=0; i<=searchindex; i++){
				for(int j=i+1; j<=searchindex; j++){
					result[i][j] = 1;
				}
				result[i][B-1] = 1;	
			}	
		}
		else{
			for(int i=0; i<=searchindex; i++){
				for(int j=i+1; j<=searchindex+1; j++){
					result[i][j] = 1;
				}
			}	
			result[searchindex+1][B-1] = 1;
		}
		while(M>0){
			int newindex = BS(M);
			//now link from newindex+1 to last one
			result[newindex+1][B-1] = 1;
			M -= power[newindex];
		}
		
		for(int i=0; i<B; i++){
			for(int j=0; j<B; j++)
				cout<<result[i][j];
			cout<<endl;
		}
	}
	return 0;
}
