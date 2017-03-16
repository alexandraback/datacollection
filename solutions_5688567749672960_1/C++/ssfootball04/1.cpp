#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>    // std::sort

using namespace std;


long long int vals[10000001];

long long int solve(long long int x){
	// cout << x << endl;
	// if(vals[x]>0)
	// 	return vals[x];
	// else {
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
			// cout << x << " " << y << " " << z << endl;
			if(z<x && x%10!=0)
			{
				val=1+solve(z);
				// vals[x]=val;
				return val;
			}
			else
			{
				val=1+solve(x-1);
				// vals[x]=val;
				return val;
			}
		}
	// }
}

long long int power(int a){
	if(a==0)
		return 1;
	else
		return 10*power(a-1);
}

long long int rev(long long int x){
	long long int y=x;long long int z=0;long long int val;int d=1;
			while(y >= 10) {
				z=10*z+y%10;y=y/10;d++;
			}
			z=10*z+y%10;
			return z;
}

long long int solve2(long long int x){
	// cout << x << endl;
	// if(vals[x]>0)
	// 	return vals[x];
	// else {
			cout << x << endl;
			if(x<10)
				return x;
			long long int y=x;long long int z=0;long long int val;int d=0;
			while(y >= 10) {
				z=10*z+y%10;y=y/10;d++;
			}
			z=10*z+y%10;
			int r;
			if(d%2==0) r=d/2+1;
			else r=(d+1)/2;
			if(x<=power(d)+power(r)){
				// cout << power(d) << endl;
				return x-power(d)+1+solve2(power(d)-1);
			}
			else {
				return ((x-1)%power(r))+1+solve2(rev(x-(x-1)%power(r)));
			}
}

int main(int argc,char* argv[]){
	freopen(argv[1],"r",stdin);
	fstream output("output");
	string line;
	// for(int i=1;i<=1000000;i++){
	// 	if(i==1)
	// 	vals[i]=1;
	// 	else{
	// 		long long int y=i;long long int z=0;//long long int val;
	// 		while(y >= 10) {
	// 			z=10*z+y%10;y=y/10;
	// 		}
	// 		z=10*z+y%10;
	// 		if(z<i && i%10!=0)
	// 		{
	// 			vals[i]=min(1+vals[z],1+vals[i-1]);
	// 		}
	// 		else
	// 			vals[i]=1+vals[i-1];
	// 	}
	// 	// output << i << " " << vals[i] << endl;
	// }
	getline(cin,line);
	long long int T=(atoi(line.c_str()));
	int i,N; 
	for(i=0;i<T;i++){
		// cout << i << endl;
		getline(cin,line);int j;
		long long int N=atoll(line.c_str());
		// cout << "Solving " << endl;

		int	ans=solve2(N);
		printf("Case #%d: %d\n",i+1,ans);
		output << "Case #" << i+1 <<": " << ans << "\n" ;
	}
	output.close();
	return 0;
}

