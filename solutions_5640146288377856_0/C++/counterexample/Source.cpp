#include <iostream>
#include <algorithm>
using namespace std;
#define re(i,j,n) for(int i=j;i<n;i++)
int main(){
	int t;
	cin >> t;
	int i = 1;
	long long ans, r, c, w;
	while (i != t + 1){
		cin >> r >> c >> w;
		ans = ((c / w)*r + w-(int)(c%w==0));
		cout << "Case #"<<i++<<": "<<ans<<endl;
	}
}