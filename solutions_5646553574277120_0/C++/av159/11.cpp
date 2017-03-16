#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

ll a[100002];

int main(){
	ll z,t,c,d,v,count,sum,i;
	
	cin>>t;
	for(z=1;z<=t;z++){
		cin>>c>>d>>v;
		for(i=0;i<d;i++)
			cin>>a[i];
		sort(a,a+d);
		
		count=0,sum=0;
		for(i=0;i<d;){
			if(sum+1>=a[i]){
				sum+=c*a[i];
				i++;
			}
			else{
				count++;
				sum+=c*(sum+1);
			}
			if(sum>=v)
				break;
		}
		if(sum<v){
			while(sum<v){
				count++;
				sum+=c*(sum+1);
			}
		}
		cout<<"Case #"<<z<<": "<<count<<endl;
	}
	return 0;
}
