#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int cases;
	int a[1200];
	cin>>cases;
	for(int t =0;t<cases;t++){
		int n;
		cin>>n;
		int max1=0,min1,sum;
		for(int j =0;j< n;j++){
			cin >> a[j];
			max1 = max(max1,a[j]);
		}
		min1 = max1;
		for(int i = 1 ; i <= max1 ; i++) {  
            sum = i ;  
            for(int j = 0 ; j < n ; j++) {  
                if( a[j] > i ) {  
                    if( a[j]%i == 0 )  
                        sum += (a[j]/i-1) ;  
                    else  
                        sum += (a[j]/i) ;  
                }  
            }  
            min1 = min(min1,sum) ;  
        } 
		cout<<"Case #"<<t+1<<": "<<min1<<endl;
	}
	return 0;
}

