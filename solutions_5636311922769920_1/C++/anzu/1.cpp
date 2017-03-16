#include<iostream>
#include<set>
#include<fstream>

using namespace std;

long long pow[110];

int main(){
	//ifstream cin("D-large.in");
	//ofstream cout("1.txt");
	
	int t,n;
	cin>>t;
	long long q;
	long long k,c,s,kil;
	long long pos=0;
	for(int i=1;i<=t;++i){
		cout<<"Case #"<<i<<": ";
		cin>>k>>c>>s;
		kil = (k+c-1)/c;
		if ( kil>s ) 
			cout<< "IMPOSSIBLE\n";
		else {
			pow[0]=1;
			for(int j=1;j<=c;++j)
				pow[j]=pow[j-1]*k;
			
			pos=1;
			q=0;
			for(int j=0;j<kil;++j){
				pos =1;
				for(int g=0;g<c;++g){
					pos+= pow[g]* ((q>=k)?0:q);
					q++;
				}
				cout<<pos<<' ';
			}
			cout<<'\n';
		}
	}
}