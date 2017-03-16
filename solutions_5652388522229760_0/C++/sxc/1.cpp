#include<iostream>
#include<algorithm>

using namespace std;

bool ch[105][10];

void getchar(int p,int i){
	while(i>0){
		ch[p][i%10]=true;
		i/=10;
	}
}

bool check(int p){
	bool flag=true;
	for(int i=0;i<10;i++){
		flag &= ch[p][i];
	}
	return flag;
}

int main(){
	int n;
	cin>>n;
	int c=n;
	while(c--){
		int i=n-c;
		int num;
		cin>>num;
		if(num==0){
			cout<<"Case #"<<i<<": INSOMNIA"<<endl;
		}else{
			for(int j=0;j<100;j++){
				getchar(i,j*num);
				if(check(i)){
					cout<<"Case #"<<i<<": "<<j*num<<endl;
					break;
				}
			}
		}	
	}
	return 0;
}

