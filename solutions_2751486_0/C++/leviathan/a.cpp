#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool noti(char cc){
	if( cc=='a' || cc=='u' || cc=='i' || cc=='o' || cc=='e' )
		return false;
	return true;
}

int main(){

	int t;
	cin>>t;
	for(int cou=1;cou<=t;cou++){
		string l;
		int n;
		cin>>l>>n;
		int c=0,i=0;
		for(i=0;i<n;i++){
			if(noti(l[i]))
				c++;
		}
		int last=0;
		long long r=0;
		while(i<l.size()){
			if(c==n){
				r+=(i-n+1-last)*(l.size()-i+1);
				last = i-n+1;
			}
		
			if(noti(l[i]))
				c++;
			if(noti(l[i-n]))
				c--;
			i++;
		}
		if(c==n){
			r+=(i-n+1-last)*(l.size()-i+1);
		}
		cout<<"Case #"<<cou<<": "<<r<<endl;
	}

	return 0;
}