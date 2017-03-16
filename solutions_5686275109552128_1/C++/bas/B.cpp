#include<iostream>
#include<vector>

using namespace std;
	int T;
	int D;
	vector<int> P;
int main(){

	cin>>T; 
	for(int j=0; j<T; j++){
		cin>>D;
		P.clear(); P.resize(D);
		for(int i=0; i<D; i++){
		    cin>>P[i];
		}
		int  res=10000000;
		for(int k=1; k<=1000; k++){
		    int sum=0;
		    for(int i=0; i<D; i++){
			if(P[i]>k){
			    sum+=(P[i]-1)/k;
			}
		    }
		    sum+=k;
//		    cout<<sum<<"\n";
		    if (sum<res)res=sum;
		}
		cout<<"Case #"<<j+1<<": " <<res<<"\n";
	}
	
}
