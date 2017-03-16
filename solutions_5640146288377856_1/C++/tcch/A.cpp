#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
	int R,C,W;
	cin>>R>>C>>W;
	int res = C/W;
	res+=W-1;
	if(C%W!=0) res++;
	res*=R;
	cout<<res<<endl;
	return;
}

int main(){
	int T;
	freopen("A-large.in","r",stdin);
	freopen("outl","w",stdout);
	cin>>T;
	for(int t=0; t<T; t++){
		printf("Case #%d: ",t+1);
		solve();
	}
	return 0;
}