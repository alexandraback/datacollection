#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
	int  C;
	long long N;
    vector<long long> sav;
long long rev(long long n){
    long long res=0;
    if((n%10)==0)return n;
    while (n>0){
	
	res=res*10+n%10;
	n/=10;
    }
    return res;
}
int main(){
	
	cin>>C; 
	
	for(int j=0; j<C; j++){

		cin>>N;
		sav.clear(); sav.resize(1000001, 1000000);
		long long res=0;
		sav[N]=0;
		while(N>0){
		    long long t = rev(N);
		    if(t<N){
			sav[t] = min(sav[t],sav[N]+1);
		    }
		    sav[N-1] = min(sav[N-1], sav[N]+1);
		    N--;			
		}
		cout<<"Case #"<<j+1<<": " <<sav[0]<<"\n";

	}
	
}
