#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cctype>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<fstream>
#include<numeric>
#include<map>
#include<sstream>
#include<iterator>
#define M 1000
using namespace std;
typedef long   ll;

int main()
{
	freopen("D:\\in.txt","r",stdin);
//	freopen("D:\\out.txt","w",stdout);
	ll i,j,k,c=1,l,p,A,n,a[M],b[M];
	cin >> k;
	while(k--)
    {
        p=l=0;
		for(i=0;i<M;i++) b[i] =0;
        cin >> A >>n;
        for(i=0;i<n;i++) cin >> a[i];
        sort(a,a+i);
        for(i=0;i<n;i++)
        {
            if(A>a[i])
            {
                A+=a[i];
                continue;
            }
            else
            {
                A+=A-1;
                b[p]=l+n-i;
                l++;

				p++;
				if(l==n) break;
				i--;
            }
        }
		sort(b,b+p);
		if(b[0]<l)l=b[0];
		printf("Case #%ld: %ld\n",c++,l);
    }
	return 0;
}
