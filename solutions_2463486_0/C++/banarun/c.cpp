#include <iostream>
#include <cmath>
using namespace std;

inline long long int oneDigit(long long int num){    
    return (num >= 0 && num < 10);
}
 
inline bool isPalUtil(long long int num,long long int* dupNum){
	
    if (oneDigit(num))
        return (num == (*dupNum) % 10);
 
    if (!isPalUtil(num/10, dupNum))
        return false;   
    *dupNum /= 10;
    return (num % 10 == (*dupNum) % 10);
}
inline int isPal(long long int num)
{
    long long int *dupNum = new long long int(num); 
    return isPalUtil(num, dupNum);
}

int main()
{
	int t;
	int q=0;
	cin>>t;
	while(t--){
		q++;
		long long int a,b;
		cin>>a>>b;
		int count=0;
		long long int p=sqrt(a);
		if(p*p==a){
			if(isPal(a) && isPal(p))
				count++;
		}
		long long int i=(p+1)*(p+1);
		long long int j=2;
		
		while(i<=b){
			if(isPal(i) && isPal(p+j-1)){
				count++;
			}
			i=(p+j)*(p+j);
			j++;
		}	
		cout<<"Case #"<<q<<": "<<count<<endl;
	}
	
	
	return 0;
}
