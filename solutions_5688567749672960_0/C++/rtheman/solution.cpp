#include<fstream>
#include<iostream>
#include <iomanip>

using namespace std;
int rev(int x){
	int temp=0;
	while(x){
		temp=temp*10+x%10;
		x/=10;
	}
	return temp;
}
int dp[1000010];
int main()
{	

	ifstream input;
 	ofstream output;
 	input.open("cj1ba.txt");
 	output.open("answer.txt");
	int n,t;
	input>>t;
	dp[1]=1;
	int ss=t;
	for(int i=2;i<=1000000;i++){
		dp[i]=dp[i-1]+1;
		//if(i<=23)
			//cout<<rev(i)<<endl;
		if(rev(i)<i&&i%10!=0){
			
			//cout<<i<<endl;
			dp[i]=min(dp[i],dp[rev(i)]+1);
		}
	}
	cout<<dp[10]<<endl;
	while(t--){
		input>>n;
		output<<"Case #"<<ss-t<<": "<<dp[n]<<endl;
	}
	return 0;
}
