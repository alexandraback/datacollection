#include <iostream>
#include <math.h>
using namespace std;
int GCD(int  u, int v) {
    while ( v != 0) {
        int r = u % v;
        u = v;
        v = r;
    }
    return u;
}
bool test(int &p,int &q){
	int y=GCD(p,q);
	p=p/y;
	q=q/y;
	int i=0;
	if(p/q>=1){return false;}
	while(i<=40){
		double a=pow(2,i)/q;
		if((a-(int)a)==0)
		return true;
		i++;
	}
	return false;
}
int result(int p,int q){
	if(!test(p,q)){cout<<" impossible "<<endl;return 0;}
	int a;
	double i;
	for(i=0;i<=40;i++){
	a=(p*pow(2,i))/q;
	if(a==1){cout<<" "<<i<<endl;return 1;} 
	}
}
int main(){
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
	cout<<"Case #"<<i+1<<":";
	int p,q;
	char a;
	cin>>p>>a>>q;
	result(p,q);
	//cout<<p<<" "<<q<<endl;
	}
	return 0;
	}
//Case #4: impossible
