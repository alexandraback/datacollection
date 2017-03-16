#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>

using namespace std;

int look(int r,int c,int w)
{
	if(w==c)
		return c;
	else
		return (ceil((c*1.0)/w) -1 + w);
}

int main(){
    freopen("input.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t, r, c, w, tt=1, x;
    cin>>t;

    while(t--){

        cout<<"Case #"<<tt++<<": ";
        cin>>r>>c>>w;
        x=look(r,c,w);
        cout<<x<<endl;

    }
    return 0;
}
