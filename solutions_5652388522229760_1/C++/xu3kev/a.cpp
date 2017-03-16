#include<iostream>
#include<string>
using namespace std;
/*
1 1*9 = 9
2
3 7*9  = 63
4
5 *2^8*( max (1,2,3,4,6,7,8,9) )
6 
7 3*9 = 27
8
9 9*9 = 81

*/

const int SIZE = 1000001;
long long int table[SIZE];
int main(){
	for(int i=1;i<=1000000;++i){
		//if(i%1000!=0)
			//cout<<i<<" "<<endl;
		int a[10]={0};
		long long int num = i;
		int count = 0;
		long long int j = 1;
		while(count < 10){
			long long int tmp = num*j;
			table[i] = tmp;
			if(tmp > 1<<30){
				cerr<<"WARNING"<<endl;
				exit(-1);
			}
			while(tmp>0){
				if(a[tmp%10]==0){
					a[tmp%10] = 1;
					++count;
				}
				tmp/=10;
			}
			++j;
		}
	}
	int T;
	cin>>T;
	int ans=0;
	int n;
	for(int cs=1;cs<=T;++cs){

		cin>>n;
		if(n==0){
			cout<<"Case #"<<cs<<": "<<"INSOMNIA"<<endl;;
		}
		else{
			cout<<"Case #"<<cs<<": "<<table[n]<<endl;;
		}
	}
	return 0;
}
