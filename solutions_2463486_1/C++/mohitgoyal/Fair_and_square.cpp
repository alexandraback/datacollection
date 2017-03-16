#include<cstdio>
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
int b[10000001];
bool check_pal(long long int);
int main()
{
    freopen("C-large-1.in","r",stdin);
    freopen("Cbig.out","w",stdout);
	int i=1,j;
	b[0]=0;
	while(i<=10000000)
	{
	    j=0;
	    int m=0;
	    long long int w=(long long int)i;
	    bool x,y;
	    x=check_pal(w);
		if(x)
        {
            w=(long long int)((long long int)i*(long long int)i);
            y=check_pal(w);
            if(y)
                m=0;
            else
                m=1;
        }
        else
            m=1;

        if(m==0)
        {
            b[i]=b[i-1]+1;
            //cout<<i<<" "<<(long long int)i*(long long int)i<<endl;
        }
        else
            b[i]=b[i-1];

		i++;
	}
	//cout<<b[10000000];
	int t=0,ans;
	i=0;
	long long int aa,bb;
	scanf("%d",&t);
	while(i<t)
    {
        int d,e;
        cin>>aa;
        cin>>bb;
        d=sqrt(aa);
        e=sqrt(bb);
        if(aa==(long long int)((long long int)d*(long long int)d)&&(b[d]-b[d-1]==1))
            ans=b[e]-b[d]+1;
        else
            ans=b[e]-b[d];
        cout<<"Case #"<<i+1<<": "<<ans<<endl;
        i++;
    }
	return 0;
}
bool check_pal(long long int i)
{
    int a[16];
    int m=0,j=0,w;
    //long long int x=(long long int)((long long int)i*(long long int)i);
		long long int y=(long long int)i;
		while(y!=0)
        {
            j++;
            w=(long long int)y%10;
            a[j]=w;
            y=(long long int)y/10;
        }
        int l=j+1;
        j=j/2;
        int k=1;
        //int z=10;
        while(k<=j)
        {
            if(a[k]!=a[l-k])
            {
                m=1;
                break;
            }
            k++;
        }
        if(m==1)
            return false;
        else
            return true;
}
