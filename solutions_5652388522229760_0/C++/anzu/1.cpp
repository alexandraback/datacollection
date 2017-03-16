#include<iostream>
#include<set>
#include<fstream>
using namespace std;

set<int >a ; 

void operate(long long n){
	while(n){
		a.insert(n%10);
		n/=10;
	}
}

int main(){
	//ifstream cin("A-small-attempt2.in");
	//ofstream cout("1.txt");
	long long n,t,q;
	cin>>t;
	for(int i=1;i<=t;++i){
		a.clear();
		cin>>n;
		q=n;
		cout<<"Case #"<<i<<": ";
		if(q==0)
			cout<<"INSOMNIA"<<'\n';
		else 
		{
			while(a.size()<10){
				operate(q);
				q+=n;
			}
			cout<<q-n<<'\n';	
		}
	}
}