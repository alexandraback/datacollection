#include <iostream>

using namespace std;

int solve(int r, int c, int w){
	if (r > 1) return r*solve(1, c, w);
	if (c == w) return w;
	if (w >= (c / 2)+(c % 2)) return w + 1;
	return c/w-1+ solve(1,c-(c/w-1)*w,w);
}


int main(){
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int t,r,c,w;


	cin >> t;
	for (int cases = 0; cases < t; cases++){
		cin >> r>>c>>w;


		cout << "Case #" << cases + 1 << ": " << solve(r, c, w) << endl;
	
	

	}
	//system("pause");
	return 0;
}