#include <iostream>
#include <algorithm>
using namespace std;
int T,R,C,W;
int main(){
	cin>>T;
	for(int cs=1; cs<=T; ++cs){
		cin>>R>>C>>W;
		int res=0;
		res+=((C+W-1)/W)*R;
		res+=W-1;
		cout<<"Case #"<<cs<<": "<<res<<endl;
	}
	return 0;
}
