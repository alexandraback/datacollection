#include<fstream>
#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
typedef long long ll;
bool rc[2000001];
int A,B;
int pow10[8]={1,10,100,1000,10000,100000,1000000,10000000};
int prc(int num,int dn){
	int cn=1;
	rc[num]=true;
	for(int i=2;i <= dn;i++){
		int res=0;
		if(num/pow10[dn-i]%10 != 0){
			for(int j=i;j <= dn;j++){
				res += num/pow10[dn-j]%10*pow10[dn-j+i-1];
			}
			for(int j=1;j < i;j++){
				res += num/pow10[dn-j]%10*pow10[i-j-1];
			}
		}
		if(res != 0 && res >= A && res <= B && !rc[res]){
			cn++;
			rc[res]=true;
		}
	}
	return cn;
}
int main(){
	ifstream input("C-small-attempt0.in");
	ofstream output("C-small-attempt0.out");
	//cout << prc(110221,6);
	int T;
	input >> T;
	for(int tt=1;tt <= T;tt++){
		memset(rc,0,sizeof(rc));
		input >> A >> B;
		ll sum=0;
		if(B >= 10 && A <= 100){
			for(int i=10;i < 100 && i <= B;i++){
				if(!rc[i] && i >= A && i <= B){
					int cn=prc(i,2);
					//cout << cn << endl;
					sum += (cn-1)*cn/2;
				}
			}
		}
		if(B >= 100 && A <= 1000){
			for(int i=100;i < 1000 && i <= B;i++){
				if(!rc[i] && i >= A && i <= B){
					int cn=prc(i,3);
					//cout << cn << endl;
					sum += (cn-1)*cn/2;
				}
			}
		}
		if(B >= 1000 && A <= 10000){
			for(int i=1000;i < 10000 && i <= B;i++){
				if(!rc[i] && i >= A && i <= B){
					int cn=prc(i,4);
					//cout << cn << endl;
					sum += (cn-1)*cn/2;
				}
			}
		}
		if(B >= 10000 && A <= 100000){
			for(int i=10000;i < 100000 && i <= B;i++){
				if(!rc[i] && i >= A && i <= B){
					int cn=prc(i,5);
					//cout << cn << endl;
					sum += (cn-1)*cn/2;
				}
			}
		}
		if(B >= 100000 && A <= 1000000){
			for(int i=100000;i < 1000000 && i <= B;i++){
				if(!rc[i] && i >= A && i <= B){
					int cn=prc(i,6);
					//cout << cn << endl;
					sum += (cn-1)*cn/2;
				}
			}
		}
		if(B >= 1000000 && A <= 2000000){
			for(int i=1000000;i <= 2000000 && i <= B;i++){
				if(!rc[i] && i >= A && i <= B){
					int cn=prc(i,7);
					sum += (cn-1)*cn/2;
				}
			}
		}
		output << "Case #" << tt << ": " << sum << endl;
	}
	return 0;
	
}