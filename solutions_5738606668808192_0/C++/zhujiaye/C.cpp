#include<iostream>
#include<vector>
using namespace std;

typedef long long LL;
int getDiv(int mask,int base){
	LL x=1;
	LL y=0;
	for (int i=0;i<16;i++){
		if (i==0 || i==15 || (mask>>(i-1))&1){
			y+=x;
		}
		x*=base;
	}
	for (int i=2;i<(int)min(2000LL,y-1);i++)
		if (y%i==0)
			return i;
	return -1;
}
int main(){
	int cnt=0;
	for (int i=0;i<1<<14;i++){
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
			for (int j=15;j>=0;j--){
				if (j==0 || j==15 || ((i>>(j-1))&1))
					cout<<"1";
				else
					cout<<"0";
			}
			for (int j=0;j<divs.size();j++)
				cout<<" "<<divs[j];
			cout<<endl;
			if (cnt==50)
				break;
		}
	}
	return 0;
}
