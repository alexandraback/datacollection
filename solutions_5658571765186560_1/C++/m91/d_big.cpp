#include<vector>
#include <utility>
#include<iostream>
#include <algorithm>

using namespace std;
char s[2000];

int main(){
int T,i,j;

cin>>T;

for(i=0;i<T;i++){
	int X,R,C;
	cin>>X>>R>>C;
	int ok=1;
	if((R*C)%X!=0)ok=0;
	//X=1 and 2 simple
	if(R>C)swap(R,C);
	if(X==3 && !(R>=2 && C>=3))ok=0;
	if(X==4 && !((R>=3 && C>=4)||(R>=3 && C>=5)||(R>=2 &&C>=6)))ok=0;
	if(X>=7)ok=0;//holes
	if(X==5 && !((R>=3 && C>=10) ||(R>=4 && C>=5)))ok=0;
	if(X==6 && !((R>=4 && C>=6) ))ok=0;
	//if(X==4 && !((R==3)&&(C==4)))ok=0;
	cout<<"Case #"<<(i+1)<<": ";
	cout<<(ok?"GABRIEL":"RICHARD")<<endl;
	}






return 0;
}
