#include <iostream>
#include <algorithm>
using namespace std;
long long arr[20];
long long pow[10];

int getL(long long a){
	int res=0;
	while(a){
		++res;
		a/=10;
	}
	return res;
}

int getHigh(long long a){
	int res=0;
	int l=getL(a);
	int d=(l)/2;
	for(int i=0;i<d; ++i){
		res+=a/pow[l-i-1]*pow[i];
		a-=a/pow[l-i-1]*pow[l-i-1];
	}
	if(res == 1)
		return 0;
	return res;
}


int main(){

	pow[0]=1;
	for(int i=1;i<10;++i)
		pow[i]=pow[i-1]*10;
	arr[0]=-1;
	arr[1]=9;
	for(int i=2;i<20;++i){
		arr[i]=arr[i-1]+pow[i/2];//19	109
		++arr[i];//91	901
		arr[i]+=pow[i/2]-2;//99	909
		if(i&1)
			arr[i] += pow[i/2+1]-pow[i/2];
	}
//	for(int i=1;i<20;++i)
	//	cout<<arr[i]<<' '<<endl;

	int T;
	cin>>T;
	long long a;
	for(int cs=1; cs<=T; ++cs){
		cout<<"Case #"<<cs<<": ";
		cin>>a;

		int l=getL(a);


		long long res=arr[l-1]+1;

		int la=l/2;
		int lb=l-la;

		int t1=a%pow[lb];
		int t2=getHigh(a);

		if(a%10 == 0 && getL(a) != getL(a-1)){
			goto output;
		}
		if(a%10==0){
			++res;
			--a;
		}

		la=l/2;
		lb=l-la;
		t1=a%pow[lb];
		t2=getHigh(a);


	//	cout<<t1<<' '<<t2<<endl;
		res+=t2;
		//res+=1;
		res+=t1;

output:
		cout<<res<<endl;
	}
	return 0;
}
