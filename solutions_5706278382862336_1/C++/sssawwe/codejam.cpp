#include <iostream>
#include <math.h>
using namespace std;
long int GCD(long int  u, long int v) {
    while ( v != 0) {
        long int r = u % v;
        u = v;
        v = r;
    }
    return u;
}
bool test(long int &p,long int &q){
	long int y=GCD(p,q);
	p=p/y;
	q=q/y;
	long int i=0;
	if(p/q>=1){return false;}
	while(i<=40){
		double a=pow(2,i)/q;
		if((a-(long int)a)==0)
		return true;
		i++;
	}
	return false;
}
long int result(long int p,long int q){
	if(!test(p,q)){cout<<" impossible "<<endl;return 0;}
	long int a;
	double i;
	for(i=0;i<=40;i++){
	a=(p*pow(2,i))/q;
	if(a==1){cout<<" "<<i<<endl;return 1;} 
	}
}
int main(){
	long int k;
	cin>>k;
	for(long int i=0;i<k;i++){
	cout<<"Case #"<<i+1<<":";
	long int p,q;
	char a;
	cin>>p>>a>>q;
	result(p,q);
	//cout<<p<<" "<<q<<endl;
	}
	return 0;
	}
//Case #4: impossible
