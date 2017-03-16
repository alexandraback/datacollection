#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>    // std::sort

using namespace std;


long long int vals[1000001];

long long int solve(long long int x){
	cout << x << endl;
	if(vals[x]>0)
		return vals[x];
	else {
		if(x==1){
			vals[1]=1;
			return 1;
		}
		else{
			long long int y=x;long long int z=0;long long int val;
			while(y >= 10) {
				z=10*z+y%10;y=y/10;
			}
			z=10*z+y%10;
			cout << x << " " << y << " " << z << endl;
			if(z<x && x%10!=0)
			{
				val=min(1+solve(z),1+solve(x-1));
				vals[x]=val;
				return val;
			}
			else
			{
				val=1+solve(x-1);
				vals[x]=val;
				return val;
			}
		}
	}
}

int main(int argc,char* argv[]){
	freopen(argv[1],"r",stdin);
	fstream output("output");
	string line;
	for(int i=1;i<=1000000;i++){
		if(i==1)
		vals[i]=1;
		else{
			long long int y=i;long long int z=0;//long long int val;
			while(y >= 10) {
				z=10*z+y%10;y=y/10;
			}
			z=10*z+y%10;
			if(z<i && i%10!=0)
			{
				vals[i]=min(1+vals[z],1+vals[i-1]);
			}
			else
				vals[i]=1+vals[i-1];
		}
	}
	getline(cin,line);
	int T=(atoi(line.c_str()));
	int i,N; 
	for(i=0;i<T;i++){
		getline(cin,line);int j;
		N=atoi(line.c_str());
		// cout << "Solving " << endl;
		int ans=vals[N];
		printf("Case #%d: %d\n",i+1,ans);
		output << "Case #" << i+1 <<": " << ans << "\n" ;
	}
	output.close();
	return 0;
}

