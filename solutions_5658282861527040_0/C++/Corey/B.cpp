#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>

#define ASCII_SPACE 32
#define ASCII_NEWLINE 10


using namespace std;




#define PRINT_TOKEN(token)\
	do{\
		cout<<#token<<" is "<<token<<endl; \
	}while(0)


#define READ(arg)\
	do{\
		long long arg;\
		cin>>arg;\
	}while(0)

//#define PRINT_ARR()
typedef long long ll;

ll A,B,K;

ll solve()
{	
	//cout<< A << " " << B << " " << K <<endl;
	ll result = 0;
	for(ll a = 0;a < A; a++ ){
		for(ll b = 0;b < B; b++){
			ll andVal = a&b;
			if(andVal < K){
				result++;
			}
		}
	}
	return result;
}

int main()
{
	long long T;

	cin>>T;
	
	for(long long i=0;i<T;i++){

		long long result=0 ;
		cin >> A>>B>>K;
		result = solve();
		cout<<"Case "<<"#"<<i+1<<": "<<result;
		cout<<endl;

	}
	return 0;
}


