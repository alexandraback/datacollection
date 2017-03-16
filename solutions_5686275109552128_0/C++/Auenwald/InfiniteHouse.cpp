#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
	int T;
	cin>>T;
	for(int i=1; i<=T; i++){
		multiset<int, greater<int> > p;
		int D;
		cin>>D;
		for(int j=0; j<D; j++){
			int h;
			cin>>h;
			p.insert(h);
		}
		int now = *p.begin();
		int count=0;
		while(count<now){
			int m = *p.begin();
			if(m<=1)
				break;
			p.erase(p.begin());
			p.insert(m/2);
			p.insert(m-m/2);
			count++;
			int a = *p.begin();
			if(now > count + a)
				now = count + a;
		}
		cout<<"Case #"<<i<<": "<<now;
		if(i!=T)
			cout<<"\n";
	}
}