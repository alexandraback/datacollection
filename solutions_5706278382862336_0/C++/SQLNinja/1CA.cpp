#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    freopen("in.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    int tc,a,b;
	cin>>tc;
	for (int c=1;c<=tc;c++){
		cin>>a; getchar();
		cin>>b; getchar();
		int ans=0;
		if(b%2)
        {
            printf("Case #%d: impossible\n",c);
        continue;
        }
		while ((a/b)<1){
			a*=2;
			ans++;
		}
		printf("Case #%d: %d\n",c,ans);
	}
}
