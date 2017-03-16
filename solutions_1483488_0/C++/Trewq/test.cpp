#include<iostream>
#include<memory.h>
using namespace std;
bool visit[2000001];
int powoften[10],comoftwo[10];
int leftshift(int n,int d)
{
	return (10*n+n/powoften[d-1])%powoften[d];
}
int length(int n)
{
	int cnt=1;
	while(n/=10)
		cnt++;
	return cnt;
}
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);

	powoften[0]=1;
	comoftwo[0]=0;
	for(int i=1;i<10;i++)
	{
		powoften[i]=10*powoften[i-1];
		comoftwo[i]=(i*i-i)/2;
	}

	int tc,a,b,cnt,t,curlen,next,tot;
	cin>>tc;
	for(int c=1;c<=tc;c++)
	{
		cin>>a>>b;
		tot=0;
		curlen=length(a);
		next=powoften[curlen];
		memset(visit+a,0,(b-a+1)*sizeof(bool));
		for(int p=a;p<=b;p++)
		{
			if(p==next)
			{
				curlen++;
				next=powoften[curlen];
			}
			if(!visit[p])
			{
				visit[p]=1;
				cnt=1;
				t=p;
				for(int i=0;i<curlen-1;i++)
				{
					t=leftshift(t,curlen);
					if(a<=t && t<=b)
					{
						if(!visit[t])
							cnt++;
						visit[t]=1;
					}
				}
				tot+=comoftwo[cnt];
			}
		}
		cout<<"Case #"<<c<<": "<<tot<<endl;
	}
	return 0;
}