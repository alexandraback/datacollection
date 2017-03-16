#include<iostream>
#include<cstring>
using namespace std;

int c[2000001];
int a[100];
int T,N;

int sum(int x){
	int s=0;
	for(int i=0; i<20 && x>0; i++, x/=2){
		if(x%2)
			s += a[i];
	}
	return s;
}

int pr(int x){
	bool fir=true;
	for(int i=0; i<20 && x>0; i++, x/=2){
		if(x%2){
			if(fir)
				fir = false;
			else
				cout<<" ";
			cout<<a[i];
		}
	}
	cout<<endl;
	return 0;
}
int main(){
	cin>>T;
	for(int ca=1; ca<=T; ca++){
		cout<<"Case #"<<ca<<": "<<endl;
		cin>>N;
		for(int i=0; i<N; i++)
			cin>>a[i];
		memset(c, 0, sizeof(c));
		bool suc = false;
		for(int i=1; !suc && i<1024*1024; i++){
			int s = sum(i);
			if(c[s] > 0){
				pr(c[s]);
				pr(i);
				suc = true;
			}
			else
				c[s] = i;
		}	
		if(!suc)
			cout<<"Impossible"<<endl;
	}	
	return 0;
}
