#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
long long int gcd(long long int a,long long int b)
{ 
	long long int temp;
	while(a%b)   
	  {   
	   temp=a;   
	   a=b;   
	   b=temp%b;              
	  }   
	  return b;
}
int gcdd(int a,int b){
	while(a>=1&&b>=1){
		if(a==b)
			a=a-b;
		else if(a%2==0)
			a/=2;
		else if(b%2==0)
			b/=2;
		else if(a>=b)
			a=a%b;
		else if(b>a)
			b=b%a;
	}
	if(a>=1)
		return a;
	else 
		return b;
}
int main(){
	int T;
	cin>>T;
	long long int a,b,c,d;
	int ans;
	for(int x=0;x<T;x++){
		ans=0;
		scanf("%lld/%lld",&a,&b);
		c=gcd(a,b);
		a=a/c;
		b=b/c;
		d=b;
		while(d%2==0){
			d=d/2;
		}
		if(d>1)
			printf("Case #%d: impossible\n",x+1);
		else if(a*2>=b){
			printf("Case #%d: 1\n",x+1);
		}
		else{
			while(a<b/2){
				a*=2;
				ans++;
			}
			ans++;
			printf("Case #%d: %d\n",x+1,ans);
		} 
	}
	return 0;
}
