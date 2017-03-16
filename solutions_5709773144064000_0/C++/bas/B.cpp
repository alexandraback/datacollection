#include<iostream>
#include<vector>
#include<string>
#define eps 1e-15
#define ll long long

using namespace std;
	int T;
	double c,f,x;
int main(){

	cin>>T; 
	for(int j=0; j<T; j++){
		cin>>c>>f>>x;
		double res=0;
		double fr=2.0;
		while(c/fr+x/(fr+f)<x/fr){
		    res+=c/fr;
		    fr+=f;
		}
		res+=x/fr;
	    	cout.precision(15);
		cout<<"Case #"<<j+1<<": " <<res<<"\n";
	}
	
}
