#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
    freopen("input.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t, r, c, w, tt=1, x;
    cin>>t;

    while(t--){

        cout<<"Case #"<<tt++<<": ";
        cin>>r>>c>>w;
        x=c/w *r;
		x += w - 1;
		if (c%w != 0)
			++x;
        cout<<x<<endl;

    }
    return 0;
}
