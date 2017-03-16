#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int t;
	cin>>t;
	for(int h=0;h<t;h++){
		double c,f,x;
		cin>>c>>f>>x;
		double min=x/2;
		double sum=0;
		for(int i=0;;i++){
			sum=sum+1/(2+i*f);
			double sum2 = sum*c + x/(2+(i+1)*f);
			//cout<<sum2<<endl;
			if(sum2>min){
				cout<<"Case #"<<h+1<<": ";
		        printf("%f",min);
		        cout<<"\n";
		        break;
			}
			min=sum2;
		}
	}
}
