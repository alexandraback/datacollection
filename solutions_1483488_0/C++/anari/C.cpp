#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
int A, B;
vector<pair<int,int> > ps;
int main(){
	int tnum;cin>>tnum;int tcou=0;
	while (tnum--){
		ps.clear();
		cin>>A>>B;
		int p10=1;
		while (p10*10<=A)
			p10*=10;
		for (int i=A;i<=B;++i){
			int t=i;
			for (int j=0;j<10;++j){
				t=t/10+p10*(t%10);
				if (i<t && t>=A && t<=B)
					ps.push_back(pair<int,int>(i,t));
			}
		}
		sort(ps.begin(), ps.end());
		cout<<"Case #"<<++tcou<<": "<<unique(ps.begin(), ps.end())-ps.begin()<<endl;
	}
	return 0;
}
