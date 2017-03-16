#include<iostream>
using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int ncase;
	cin >> ncase;
	int x, y;
	string ans;
	for(int icase = 1; icase <= ncase; icase++){
		cout << "Case #" <<icase <<": ";
		ans = "";
		cin>>x>>y;
		for(int i = 0; i < abs(x); i++)
			ans += x>0? "WE":"EW";
		for(int i = 0; i < abs(y); i++)
			ans += y>0? "SN":"NS";
		cout<<ans.c_str()<<endl;
	}
	return 0;
}