#include<iostream>
#include<string>
using namespace std;

void solve(int q){
	string S;
	cin>>S;
	int a[10];
	fill(a,a+10,0);
	int n=S.size();
	for(string::iterator i=S.begin();i!=S.end();++i){
		if(*i=='Z'){
			++a[0];
		}else if(*i=='X'){
			++a[6];
		}else if(*i=='W'){
			++a[2];
		}else if(*i=='G'){
			++a[8];
		}else if(*i=='U'){
			++a[4];//ここまでは確定
		}else if(*i=='O'){
			++a[1];
		}else if(*i=='F'){
			++a[5];
		}else if(*i=='T'){
			++a[3];
		}else if(*i=='S'){
			++a[7];
		}else if(*i=='N'){
			++a[9];
		}
	}
	a[1]-=(a[2]+a[4]+a[0]);
	a[5]-=a[4];
	a[3]-=(a[2]+a[8]);
	a[7]-=a[6];
	a[9]-=(a[1]+a[7]);
	a[9]/=2;
	cout<<"Case #"<<q<<": ";
	for(int i=0;i<10;++i){
		for(int j=0;j<a[i];++j){
			cout<<i;
		}
	}
	cout<<endl;
}

int main(){
	int Q;
	cin>>Q;
	for(int q=1;q<=Q;++q){
		solve(q);
	}
}
