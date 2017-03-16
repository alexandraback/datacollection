#include <iostream>
using namespace std;

int rev(int number){
 int reverse;	
 for( ; number!= 0 ; )
   {
      reverse = reverse * 10;
      reverse = reverse + number%10;
      number = number/10;
   }
   
   return reverse;

}

int main() {
	int t; cin>>t;
	for (int pink=1; pink<=t; pink++){
		int n; cin>>n;
		int ans[n+1];
		ans[1]= 1;
		for (int i=2; i<=n; i++){
			if (rev(i)<i and i%10!=0){
				ans[i]= min(ans[i-1], ans[rev(i)])+1;
			}
			else{
				ans[i]= ans[i-1]+1;
			}
		}
		cout<<"Case #:"<<pink<<": "<<ans[n]<<endl;
	}
	return 0;
}