#include <bits/stdc++.h>
using namespace std;

int main() 
{
	freopen("A-large.in","r",stdin);
	freopen("output1.txt","w",stdout);
    int t,r,c,w,res;
    cin>>t;
    int tc = 1;
    while(t--) {
        cin>>r>>c>>w;
        printf("Case #%d: ",tc++);
        res = c / w *r;
		res += w - 1;
		if (c%w != 0)
			res++;
        cout<<res<<endl;
    }
	return 0;
}

