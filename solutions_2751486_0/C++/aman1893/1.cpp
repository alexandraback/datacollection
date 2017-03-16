#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define s(n) scanf("%d",&n)
#define p(n) printf("%d",n)
#define ll long long
#define ld long double
#define D (double)
#define LD (long double)
int fun(char a)
{
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')return 0;
    return 1;
}

int main()
{
	freopen("ip.in","r",stdin);
	freopen("op.in","w",stdout);
	int t,c=0;cin>>t;
	while(t--)
	{
		c++;
		int n;
		string str;
		cin>>str;
		cin>>n;
		int ans=0;
		for(int l=1;l<=str.size();l++)
		{
		    //int count=0;
		    for(int i=0;i<=str.size()-l;i++)
		    {
		        int count=0;int m=0;
		        for(int j=i;j<=l+i-1;j++)
		        {
		            //cout<<str[j];
		            if(fun(str[j])){count++;m=max(m,count);}
		            else count=0;

		            //else cout<<"no";
		            //cout<<endl;

                }
                if(m>=n){ans++;}
		    }

		}

		printf("Case #%d: ",c);
		cout<<ans<<endl;
	}
}
