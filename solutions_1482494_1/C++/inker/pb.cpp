#include<iostream>
#include<map>
#include<math.h>
#include<vector>
#include<string>
#include<string.h>
#include<queue>
#include<algorithm>
#include<sstream>
#define all(X) (X).begin(),(X).end()
#define mem(X) memset(X,0,sizeof(X))
#define debug_v(v) for(int db=0;db<(v).size();db++)cout<<v[db]<<','<<;cout<<endl;
#define pqpush(pq,x,cmp) (pq).push_back(x);push_heap((pq).begin(),(pq).end(),cmp);
#define pqpop(pq,cmp) pop_heap((pq).begin(),(pq).end(),cmp);(pq).pop_back();
using namespace std;
typedef long long ll;
typedef vector<int>::iterator iv;
typedef map<string,int>::iterator msii;
typedef map<int,int>::iterator miii;
typedef map<int,bool>::iterator mibi;
typedef map<string,bool>::iterator msbi;
typedef map<string,int> msi;
typedef map<int,int> mii;
typedef map<int,bool> mib;
typedef map<string,bool> msb;
typedef vector<int> vi;
typedef vector<string> vs;


int comp[1000],ss,ans,t,h1,m1[1000],m2[1000],n,slt,rest,cc;

int cal(int fh1)
{
	if(fh1==-1)return 0;
	if(m2[fh1]<=ss)return 2-comp[fh1];
	else if(m1[fh1]<=ss)return 1-comp[fh1];
	else return -99999;
}

bool cmp(int fh1,int fh2)
{
	if(fh1==-1)
	{
		if(cal(fh2)>0)return 1;
		else return 0;
	}
	if(cal(fh2)!=cal(fh1))return cal(fh2)>cal(fh1);
	if(comp[fh2]==1)return 1;
	if(comp[fh1]==1)return 0;
	return m2[fh1]<m2[fh2];
}

int cal2(int fh1)
{
	if(fh1==-1)return -1;
	int ret;
	if(m2[fh1]<=ss)
	{
		ret=2-comp[fh1];
		comp[fh1]=2;
	}
	else if(m1[fh1]<=ss)
	{
		ret=1-comp[fh1];
		comp[fh1]=1;
	}
	else return -99999;
	return ret;
}

int main(){
	freopen("B-large (2).in","r",stdin);
	freopen("outb.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		
		
		for(h1=0;h1<n;h1++)
		{
			scanf("%d%d",&m1[h1],&m2[h1]);
			comp[h1]=0;
		}
		
		ss=0;
		rest=n;
		ans=0;
		
		while(rest)
		{
			slt=-1;
			for(h1=0;h1<n;h1++)
				if(comp[h1]!=2)
				{
					if(cmp(slt,h1))
						slt=h1;
				}
			//cout<<slt<<endl;
			if(slt==-1)
			{
				ans=-1;
				break;
			}
			
			ss+=cal2(slt);
			ans++;
			if(comp[slt]==2)rest--;
			
		}
		
		
		if(ans<=-1)printf("Case #%d: Too Bad\n",++cc);
		else printf("Case #%d: %d\n",++cc,ans);
		
	}
}
