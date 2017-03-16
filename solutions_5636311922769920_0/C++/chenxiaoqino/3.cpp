#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h> 
#include <stdlib.h> 
#include <vector>
using namespace std;

void calc(int K, int C, int S){
	if(S*C<K)
	{
		cout<<"IMPOSSIBLE";
		return;
	}

	//string zeros="";
	//for(int i=0;i<C;i++)
	//	zeros+="0";

	int ptr=0;
	for(int i=0;i<S;i++){
		long long res=0, power=1;
		for(int i=0;i<C;i++){
			res+=power*(ptr%K);
			ptr++;
			power*=K;
		}
		res+=1;
		cout<<res<<" ";
		if(ptr>=K)break;
	}
}

int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		cout<<"Case #"<<(i+1)<<": ";
		int K,C,S;
		cin>>K>>C>>S;
		calc(K,C,S);
		cout<<endl;
	}

	return 0;
}