#include<iostream>
using namespace std;

#define out(cond) for(int j=0;j<r;j++){\
	for(int k=0;k<c;k++)\
		if(j==0 && k==0)\
			cout<<"c";\
		else if(cond)\
			cout<<".";\
		else\
			cout<<"*";\
	cout<<endl;\
}

#define imp cout<<"Impossible"<<endl

int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int r,c,m,a;
		cin>>r>>c>>m;
		a=r*c-m;
		cout<<"Case #"<<i<<":"<<endl;
		if(a==1)
			out(false)
		else if(r==1)
			out(k<a)
		else if(a>=c*2 && a%c!=1)
			out(j*c+k < a)
		else if(r==2)
			if(a%2==0 && a>2)
				out(k < a/2)
			else
				imp;
		else if(c==2)
			imp;
		else if(a>c*3)
			out((j+2)*c<a || (j*c+c+1==a && k<c-1) || (j*c+1==a && k<2))
		else if(a==2 || a==3 || a==5 || a==7)
			imp;
		else if(a==c*2+1)
			out((j<2 && k<c-1) || (j==2 && k+2*c-2<a))
		else if(a%2==0)
			out(j<2 && k<a/2)
		else
			out((j<2 && k<a/2-1) || (j==2 && k<3))
	}
	return 0;
}
		
		
		
