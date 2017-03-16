#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	freopen("0.in","r",stdin);
	freopen("0.out","w",stdout);
	int TEST;
	cin>>TEST;
	int ROW,COLUM,WIDTH;
	int COUNT=0;
	while(TEST--){
		COUNT++;
		cin>>ROW>>COLUM>>WIDTH;
		int FA;
		if(COLUM%WIDTH==0)
		{
			FA=COLUM/WIDTH;
			FA*=ROW;
			FA=FA+WIDTH-1;
		}
		else
		{
			FA=COLUM/WIDTH;
			FA*=ROW;
			FA+=WIDTH;
		}
		cout<<"Case #"<<COUNT<<": "<<FA<<"\n";
	}
}
