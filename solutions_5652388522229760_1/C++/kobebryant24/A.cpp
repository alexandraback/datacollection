#include <bits/stdc++.h>
using namespace std;

#define forall(i,a,b)               for(int i=a;i<b;++i)

int main(){
	int t,n,temp,tot;cin >> t;
	forall(test,0,t){
		cout << "Case #" << test+1 << ": ";
		cin >> n;
		tot=0;
		map<int,int> mymap;
		for(int i=1;i<1001;++i){
			temp=n*i;
			while(temp){
				if(mymap[temp%10]==0) ++tot,mymap[temp%10]=1;
				temp/=10;
			}
			if(tot==10){
				cout << n*i << endl;
				break;
			}
			else if(i==1000) cout << "INSOMNIA" << endl;
		}
	}
}