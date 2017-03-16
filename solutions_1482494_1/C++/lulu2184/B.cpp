#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

struct TT{int w,v,v1;} t1,tmp;
int a[1010][2],n,cnt,now,cc,T,ans,p;
priority_queue <TT> H1,H2,H3;
bool del[1010];

bool operator <(TT a,TT b){ return a.v>b.v || (a.v==b.v && a.v1<b.v1); } 

int main()
{
	freopen("b.in","r",stdin);freopen("b.out","w",stdout);
	
	cc=1;
	for (scanf("%d",&T);T;T--,cc++)
	{	
		while (!H1.empty()) H1.pop();
		while (!H2.empty()) H2.pop();
		while (!H3.empty()) H3.pop();
		memset(a,0,sizeof(a));
		memset(del,false,sizeof(del));
		scanf("%d",&n);	
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i][0],&a[i][1]);
			tmp.w=i;tmp.v=a[i][0];tmp.v1=a[i][1];
			H1.push(tmp);
			tmp.w=i;tmp.v=a[i][1];
			H2.push(tmp);
		}
		cnt=0;now=0;ans=0;
		while (cnt<n)
		{
			if (!H2.empty())
			{
				while (!H2.empty() && del[H2.top().w]) H2.pop();
				if (!H2.empty())
				{ 
					t1=H2.top();
					if (t1.v<=now)
					{
						del[t1.w]=true;
						now+=2;cnt++;ans++;
	///					cout<<t1.w<<" "<<2<<endl;
						H2.pop();continue;
					}
				}
			}
			if (!H3.empty())
			{
				t1=H3.top();
				if (t1.v<=now)
				{
					now++;cnt++;ans++;
		//			cout<<t1.w<<" "<<3<<endl;
					H3.pop();continue;	
				}	
			}
		/*	while ((!H1.empty()) && del[H1.top().w]) H1.pop();
			if (H1.empty()) break;
			t1=H1.top();
			if (t1.v<=now)
			{
				cout<<t1.w<<" "<<1<<endl;
				now++;ans++;
				H1.pop();
				t1.v=a[t1.w][1];t1.v1=0;
				H3.push(t1);
				del[t1.w]=true;
			}else break;*/
			p=0;
			for (int i=1;i<=n;i++)
			{
				if ((!del[i]) && a[i][0]<=now && a[i][1]>a[p][1]) p=i;
			}
			if (!p) break;
			now++;ans++;
			t1.v=a[p][1];t1.v1=0;
			H3.push(t1);
			del[p]=true;
		}
		if (cnt==n) printf("Case #%d: %d\n",cc,ans);
		else printf("Case #%d: Too Bad\n",cc);
	
	}
	
	return 0;	
}
