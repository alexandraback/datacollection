#include<iostream>
using namespace std;
int maximo(int a,int b){
	return a>b?a:b;
}
int main(){
	int t,x,r,c;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>x>>r>>c;
		int max = maximo(r,c);
		int min=c+r-max;
		r=max;c=min;
		bool pode;
		if(x==1){pode=true;}//muito fácil
		if(x==2){pode = (r*c)%2==0;}
		if(x==3){pode = (r*c)%3==0 && c>=2;}
		if(x==4){pode = (r*c)%4==0 && c>=3;}
		if(x==5){pode = c>=3 &&(r*c)%5==0;}
		if(x==6){pode = (c>=4 || (c==3 && r>=4)) &&(r*c)%6==0;}
		if(x>=7){pode=false;}//pode fazer loop
		if(r*c<x){pode=false;}//não cabe
		if((r*c)%x!=0){pode=false;}//não múltiplo
		cout<<"Case #"<<i+1<<": "<<(pode?"GABRIEL":"RICHARD")<<endl;
	}
	return 0;
}
