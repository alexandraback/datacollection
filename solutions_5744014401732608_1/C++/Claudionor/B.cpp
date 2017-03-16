#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	long long b;
	long long m;
	int sl[60][60];
	for(int i=0;i<60;i++){
		for(int j=i+1;j<60;j++)
			sl[i][j]=1;
	}
	int cont=1;
	cin>>t;
	while(t--){
		cout<<"Case #"<<cont<<": ";
		cont++;
		cin>>b;
		cin>>m;
		if(m>(1<<(b-2)))
			cout<<"IMPOSSIBLE\n";
		else{
			cout<<"POSSIBLE\n";
			for(int j=0;j<b-1;j++)
				cout<<sl[0][j];
			if(m==(1<<(b-2))){
				cout<<1;
				m--;
			}
			else
				cout<<0;
			cout<<"\n";
			for(int i=1;i<b-1;i++){
				for(int j=0;j<b-1;j++)
					cout<<sl[i][j];
				cout<<m%2;
				m>>=1;
				cout<<"\n";
			}
			for(int i=0;i<b;i++)
				cout<<0;
			cout<<"\n";
		}
		
	}
	return 0;
}