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

int N;
int findMinRtnJb(int a, int* s)
{
	
	int min = 999999;
	for(int i=0;i<N;i++){
		if( i == a) continue;
		if(min > s[i]){
			min = s[i];
		}
	}

	return min;

}

int main()
{
	long long T;

	cin>>T;

	for(long long i=0;i<T;i++){

	//	long long result=0 ;
		int s[200];
		int X=0;
		cin>>N;
		//cout<<"N="<<N<<endl;
		for(int a=0;a<N;a++){
			cin>>s[a];
			X += s[a];
		//	cout<<"s["<<a<<"]="<<s[a]<<endl;
		}
		//cout<<"X="<<X<<endl;
		
		double result[200];
		int fcz[200]={-1};
		int cz=0;
		cout<<"Case "<<"#"<<i+1<<": ";
		for(int e=0;e<N;e++){
			int jb = findMinRtnJb(e,s);
			int ja = s[e];
			

			if(fcz[e] != 1)
				result[e] =  ( ((double)(2*X)/ (N-cz)) -ja )  /X;
			
			
			if(result[e] <0 && fcz[e] != 1){
				cz++;
				fcz[e] = 1;
				e = -1;
				X -= s[e];
			}

			//cout<<result<<" ";
		}
		for(int ee=0;ee<N;ee++){
			if( result[ee] <= 0  ) result[ee] = 0;
			printf("%.6f ",result[ee]*100);
			
		}
		cout<<endl;

	}
	return 0;
}


