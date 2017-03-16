#include<iostream>
#include<algorithm>
#include<cstring>
#include <string>
#include<vector>
#include <queue>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int r,c,w;
int main(){
   // freopen("input1.txt","r",stdin);
   freopen("A-small-attempt0.in","r",stdin);
  // freopen("A-large-practice.in","r",stdin);
    freopen("output1.txt","w",stdout);
    
    int t;
    cin >> t;
	
    for(int ti=1;ti<=t;ti++){
		cout << "Case #"<<ti<<": ";
        cin>>r>>c>>w;
		if (w==1 || r*c==w) {
			cout << r*c << "\n";
			continue;
		}
		if (w==c){
			cout << r-1+c << "\n";
			continue;
		}
		int ans = ((c+w-1)/w)-1+(c/w)*(r-1)+w;
		cout << ans << "\n";
    }
    return 0;
}
