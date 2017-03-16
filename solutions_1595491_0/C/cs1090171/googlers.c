#include<iostream>
using namespace std;

int t,N,S,p,points,result;

int main(){
	cin>>t;
	for(int i=0;i<t;i++){
		result=0;
		cin>>N>>S>>p;
		for(int j=0;j<N;j++){
			cin>>points;
			int temp1=points/3;
			int temp2=points%3;
			if (temp1>=p) {
				result++;
				continue;
			}
			else if(temp2==0 && (temp1+1)>=p && S>0 && points>=1){
					result++;
					S--;
					continue;
			}
			else if((temp1+1)>=p && temp2!=0){
				result++;
				continue;
			}
			else if(temp2==2 && (temp1+2)>=p && S>0){
				S--;
				result++;
			}
		}
		cout<<"Case #"<<i+1<<": "<<result<<endl;
	}
	return 0;
}
