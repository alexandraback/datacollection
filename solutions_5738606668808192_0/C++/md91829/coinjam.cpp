#include <iostream>
#include <bits/stdc++.h>

using namespace::std;

vector<string> answer;

void getStrings( string s, int digitsLeft )
{
   if( digitsLeft == 0 ) // the length of string is n
      answer.push_back( s );
   else
   {
      getStrings( s + "0", digitsLeft - 1 );
      getStrings( s + "1", digitsLeft - 1 );
   }
}

int isNotPrime(long long int n){
	for(long long int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return i;
		}
	}
	return -1;
}

int main(){
	long long int t;
	cin>>t;
	long long int k=1;
	while(t){
		t--;
		long long int n,j;
		cin>>n>>j;		
		cout<<"Case #"<<k<<": "<<endl;
		long long int arr[11];
		getStrings("",n-2);
		for(long long int i=0;i<answer.size() && j>0;i++){
			string a=answer[i];
			a="1"+a+"1";
			//cout<<a<<endl;
			long long int num=0;
			int flag=0;
			for(long long int x=2;x<=10;x++){
				num=0;
				for(long long int j=0;j<a.length();j++){
					if(a[j]=='1')
						num+=(pow(x,a.length()-j-1));
				}
				//cout<<num<<endl;
				long long int w=isNotPrime(num);
				if(w==-1){
					flag=1;
					break;
				}else{
					arr[x]=w;
				}
			}
			if(flag==0){
				j--;
				cout<<a<<" ";
				for(int j=2;j<=10;j++){
					cout<<arr[j]<<" ";
				}
				cout<<endl;
			}
		}
	}
	return 0;
}