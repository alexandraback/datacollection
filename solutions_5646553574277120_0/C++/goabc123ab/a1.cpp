#include <bits/stdc++.h>
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define ll long long
#define ull unsigned ll 
using namespace std;
int  Set(int *set, int set_size,int s)
{
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
    for(counter = 0; counter < pow_set_size; counter++)
    {
        int sum=0;
        for(j = 0; j < set_size; j++)
        {
            if(counter & (1<<j))
                sum+=set[j];
        }
        if(sum==s)
            return 1;
    }
    return 0;
}

int main()
{
	freopen("input.txt","r",stdin);//redirects standard input
    freopen("output.txt","w",stdout);//redirects standard output
    int t,j,i;
    cin>>t;
    for(j=1;j<=t;j++)
    {
    	int ans=0,s=0,k;
    	int c,d,v;
    	cin>>c>>d>>v;
    	int a[d],b[50];
    	rep(i,d)
    	{
    		cin>>a[i];
    		b[i]=a[i];
            s+=a[i];
    	}	
    	int newsiz=d;
        for(i=1;i<=v;i++)
        {
            if(!Set(b,newsiz,i))
            {
                int sumi=i;
                int cur=i;
                while(!Set(b,newsiz,sumi))
                {
                    b[newsiz++]=cur++;
                    ++ans;
                }
            }
        }
    	cout<<"Case #"<<j<<": "<<ans<<endl;
    }
	return 0;
}