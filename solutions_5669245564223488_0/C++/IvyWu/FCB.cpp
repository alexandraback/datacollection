#include<iostream>
#define modnum 1000000007
using namespace std;

int main()
{
	freopen("b.in","r",stdin);
	freopen("b2.out","w",stdout);
	int T,N,i,j,p,q,cnt,head[26],tail[26],mid[26],len;
	char st[100][100],tempst[100];
	long long ans;
	bool flag,visit[26];
	cin>>T;
	for (int k=0;k<T;k++)
	{
		cout<<"Case #"<<k+1<<": ";
		cin>>N;
		flag=true;
		for (i=0;i<N;i++)
		{
			cin>>tempst;
			len=strlen(tempst);
			p=0;
			q=0;
			while (p<len)
			{
				st[i][q++]=tempst[p++];
				while (p<len&&tempst[p]==tempst[p-1]) p++;
			}
			st[i][q]='\0';
		}
		for (i=0;i<26;i++)
		{
			head[i]=-1;
			tail[i]=-1;
			mid[i]=0;
		}
		for (i=0;i<N;i++)
		{
			len=strlen(st[i]);
			if (len>1)
			{
				if (head[st[i][0]-'a']!=-1||tail[st[i][len-1]-'a']!=-1)
				{
					flag=false;
					break;
				}
				head[st[i][0]-'a']=i;
				tail[st[i][len-1]-'a']=i;
				for (p=1;p<len-2;p++)
				{
					if (head[st[i][p]-'a']!=-1||tail[st[i][p]-'a']!=-1||mid[st[i][p]-'a']>0)
					{
						flag=false;
						break;
					}
					head[st[i][p]-'a']=-2;
					tail[st[i][p]-'a']=-2;
					mid[st[i][p]-'a']=-2;
				}
				if (flag==false) break;
			}
			else
			{
				if (mid[st[i][0]-'a']!=-2) mid[st[i][0]-'a']++;
				else
				{
					flag=false;
					break;
				}
			}
		}
		if (flag==true)
		{
			for (i=0;i<26;i++)
				if (mid[i]>0||head[i]>=0||tail[i]>=0) visit[i]=false;
				else visit[i]=true;
			cnt=0;
			ans=1;
			for (i=0;i<26;i++)
				if (visit[i]==false)
				{
					cnt++;
					j=i;
					while (tail[j]>=0)
					{
						if (visit[j]==true)
						{
							flag=false;
							break;
						}
						visit[j]=true;
						for (p=mid[j];p>1;p--) ans=(ans*p)%modnum;
						j=st[tail[j]][0]-'a';
					}
					if (visit[j]==true||flag==false)
					{
						flag=false;
						break;
					}
					visit[j]=true;
					for (p=mid[j];p>1;p--) ans=(ans*p)%modnum;
					j=i;
					while (head[j]>=0)
					{
						j=st[head[j]][strlen(st[head[j]])-1]-'a';
						if (visit[j]==true)
						{
							flag=false;
							break;
						}
						visit[j]=true;
						for (p=mid[j];p>1;p--) ans=(ans*p)%modnum;
					}
					if (flag==false) break;
				}
			for (i=2;i<=cnt;i++) ans=(ans*i)%modnum;
			if (flag==false) ans=0;
			cout<<ans<<endl;
		}
		else cout<<"0"<<endl;
	}
	return 0;
}