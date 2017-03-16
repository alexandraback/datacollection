#include <iostream>
#include <cstdio>

using namespace std;

int arr[100003];
int prime[1000003];

int mod[10003][11][32];

int T,N,J;
void display(int a){
	cout<<1;
	int mask = 1<<N-3;
	while(mask){
		if(mask&a){
			cout<<1;
		}else
			cout<<0;
		mask >>=1;
	}
	cout<<1;
}

int main(){
	cin>>T>>N>>J;

	for(int i=2; i<100000; ++i){
		if(!arr[i])
			for(int j = 2; i*j<100000; ++j){
				arr[i*j]= 1;
			}
	}
	int cnt=0;
	arr[0]=arr[1]=-1;

	for(int i =2; i<100000; ++i){
		if(!arr[i]){
			arr[i] = cnt;
			prime[cnt++] = i;
		}else
			arr[i]= -1;
	}

	// cout<<cnt<<endl;
	for(int i=0; i<cnt; ++i){
		for(int k =2; k<11; ++k){
			mod[i][k][0] = 1;
			for(int j = 1; j<32; ++j){
				mod[i][k][j]= (mod[i][k][j-1]*k)%prime[i];
			}
		}
	}

	// cout<<mod[arr[7]][10][2]<<endl;
	int mm = 16000;

	int tmp2[11];

	int res[30000][11];
	int rcnt=0;
	int c;

	for(int i=0; i<mm; ++i ){
		c = 0;
		for(int k=2; k<=10; ++k){
			for(int j = 0; j< 1000; ++j){
				int tmp  = mod[j][k][0]+mod[j][k][N-1];
				int mask = 1;
				for(int kk = 0; kk< N-2; ++kk){
					if( (1<<kk)&i){
						tmp += mod[j][k][kk +1];
					}
				}
				// if(!i){
				// 	cout<<tmp<<" ";
				// 	cout<<prime[j]<<endl;
				// }
				if(tmp % prime[j] == 0){
					++c;
					tmp2[k] = prime[j];
					break;
				}
			}
		}
		if( c == 9){
			for(int i2=2; i2<11; ++i2){
				res[rcnt][i2-1] = tmp2[i2];
			}
			res[rcnt++][0]=i;
		}

	}

	// cout<<res[0][0]<<endl;
	cout<<"Case #1:"<<endl;
	for(int i= 0; i<J; ++i ){
		display(res[i][0]);
		for(int k=0; k<9; ++k){
			cout<<' '<<res[i][k+1];
		}
		cout<<endl;
	}

	
	return 0;
}
