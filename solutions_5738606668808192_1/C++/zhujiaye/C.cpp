#include<iostream>
#include<vector>
using namespace std;

#define LEN (32)
#define CNT (500)
typedef long long LL;
int MOD[15][40][2005];

int getDiv(int mask,int base){
	LL u=2000;
	for (LL m=2;m<=u;m++){
		int x=0;
		for (int i=0;i<LEN;i++){
			if (i==0 || i==LEN-1 || (mask>>(i-1))&1){
				x+=MOD[base][i][m];
				x%=m;
			}
		}
		if (x==0)
			return m;
	}
	return -1;
}
void prepare(){
	for (int m=2;m<=2000;m++){
		for (int i=2;i<=10;i++){
			int x=1;
			MOD[i][0][m]=x;
			for (int j=1;j<=31;j++){
				x=x*i%m;
				MOD[i][j][m]=x;
			}
		}
	}
}
int main(){
	prepare();
	int cnt=0;
	for (int i=0;i<1<<(LEN-2);i++){
		vector<int>divs;
		bool ok=true;
		for (int j=2;j<=10;j++){
			int tmp=getDiv(i,j);
			if (tmp==-1){
				ok=false;
				break;
			}
			else{
				divs.push_back(tmp);
			}
		}
		if (ok){
			cnt++;
			for (int j=LEN-1;j>=0;j--){
				if (j==0 || j==LEN-1 || ((i>>(j-1))&1))
					cout<<"1";
				else
					cout<<"0";
			}
			for (int j=0;j<divs.size();j++)
				cout<<" "<<divs[j];
			cout<<endl;
			if (cnt==CNT)
				break;
		}
	}
	return 0;
}
