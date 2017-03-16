#include<iostream>
#include<string>
#define MAXLEN 10000
using namespace std;
int main()
{
	int T,i,j,k,N,L,a[MAXLEN],mark[MAXLEN],ans;
	string st;
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	cin>>T;
	for (k=0;k<T;k++)
	{
		cin>>st;
		L=st.length();
		for (j=0;j<L;j++)
			if (st[j]=='a'||st[j]=='e'||st[j]=='i'||st[j]=='o'||st[j]=='u') a[j]=0;
			else a[j]=1;
		cin>>N;
		mark[0]=0;
		for (i=0;i<=L-N;i++)
		{
			for (j=i;j<i+N;j++)
				if (a[j]==0) break;
			if (j==i+N) mark[++mark[0]]=i;
		}
		j=1;
		ans=0;
		for (i=0;i<L;i++)
		{
			while (mark[j]<i&&j<=mark[0]) j++;
			if (j>mark[0]) break;
			ans=ans+L-(mark[j]+N-1);
		}
		cout<<"Case #"<<k+1<<": "<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}