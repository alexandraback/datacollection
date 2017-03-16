#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		double s[2][1000];
		for(int j=0;j<n;j++)
			cin>>s[0][j];
		for(int j=0;j<n;j++)
			cin>>s[1][j];
		sort(s[0],s[0]+n);
		sort(s[1],s[1]+n);
		cout<<"Case #"<<i<<":";
		for(int j=0;j<2;j++){
			int r=0;
			for(int k=0,l=0;k<n;k++){
				while(l<n && s[j][l] < s[!j][k])
					l++;
				if(l==n)
					break;
				r++;
				l++;
			}
			cout<<" "<<(j==0 ? r : n-r);
		}
		cout<<endl;
	}
	return 0;
}

