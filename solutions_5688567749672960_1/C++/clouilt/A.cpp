#include <iostream>
#include <algorithm>
using namespace std;
long long arr[20];
long long pow[20];

long long getL(long long a){
	long long res=0;
	while(a){
		++res;
		a/=10;
	}
	return res;
}

long long getHigh(long long a){
	long long res=0;
	long long l=getL(a);
	long long d=(l)/2;
	for(long long i=0;i<d; ++i){
		res+=a/pow[l-i-1]*pow[i];
		a-=a/pow[l-i-1]*pow[l-i-1];
	}
	if(res == 1)
		return 0;
	return res;
}


int main(){

	pow[0]=1;
	for(long long i=1;i<20;++i)
		pow[i]=pow[i-1]*10;
	arr[0]=-1;
	arr[1]=9;
	for(long long i=2;i<20;++i){
		arr[i]=arr[i-1]+pow[i/2];//19	109
		++arr[i];//91	901
		arr[i]+=pow[i/2]-2;//99	909
		if(i&1)
			arr[i] += pow[i/2+1]-pow[i/2];
	}
//	for(long long i=1;i<20;++i)xx
	//	cout<<arr[i]<<' '<<endl;

	long long T;
	cin>>T;
	long long a;
	for(long long cs=1; cs<=T; ++cs){
		cout<<"Case #"<<cs<<": ";
		cin>>a;

		long long l=getL(a);


		long long res=arr[l-1]+1;

		long long la=l/2;
		long long lb=l-la;

		long long t1=a%pow[lb];
		long long t2=getHigh(a);

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
