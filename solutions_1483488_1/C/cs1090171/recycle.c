#include<iostream>
#include<math.h>
#include<utility>
#include<set>
using namespace std;

set<pair<int,int> > hash;
int t,a,b,res,temp;
int arr[10];
int num[]={36};

int digits(int a){
	int k=1,i=1;
	while(a/k) {k*=10;i++;}
	return i-1;
}

void brea(int n){
	int p=temp;
	while(n!=0){
		arr[--p]=n%10;
		n=n/10;
	}
}


int main(){
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a>>b;
		res=0;
		temp=digits(a);
		for(int j=a;j<=b;j++){
			brea(j);
			for(int k=0;k<temp-1;k++){
				if(arr[k+1]==0) continue;
				int num=0;
				for(int m=k+1;m<temp;m++) num=num*10+arr[m];
				for(int m=0;m<=k;m++) num=num*10+arr[m];
				//cout<<num<<endl;
				if(num<=b && num>j){
					hash.insert(make_pair(j,num));
					 res++;
				 }
			}
		}
		cout<<"Case #"<<(i+1)<<": "<<hash.size()<<endl;
		hash.clear();
	}
	return 0;
}
		
				
			
				
