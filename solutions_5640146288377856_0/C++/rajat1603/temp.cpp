#include<bits/stdc++.h>
#define author rajat1603
#define pb push_back
#define mp make_pair
using namespace std;
const int mod = 1e9 + 7;
int main(){
	int t;
	cin>>t;
	int tc = 0;
	while(t--){
		printf("Case #%d: ",++tc);
		int r,c,w;
		cin>>r>>c>>w;
		printf("%d\n",(   (r*(c/w) + (c%w!=0)   + w - 1 )    ));
	}
}
