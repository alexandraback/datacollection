#include <iostream>
#include <set>
#include <string>
using namespace std;

int isCon(char c){
	if(c=='a' || c=='e'|| c=='i' || c=='o' || c=='u'){
	return 0;
	}
	else
	return 1;
}

int main()
{
	int t;
	cin>>t;
	int j=0;
	while(t--){
		j++;
		string s;
		long long int p,len;
		long long int count;
		long long int ans=0;
		cin>>s;
		cin>>p;
		len=s.length();
			int i=0,k=0;
			count=0;
			while(k<len){
				if( isCon(s[k])){
					count++;
				}
				else
					count=0;
				if(count==p){
						//cout<<"K"<<k<<" "<<i<<endl;
						ans+=(k-p+2-i)*((len-k));
						//cout<<"T = "<<ans<<endl;
						i=k-(p-2);
						count=p-1;
				}
				k++;
			}
			cout<<"Case #"<<j<<": "<<ans<<endl;
	}
	return 0;
}
