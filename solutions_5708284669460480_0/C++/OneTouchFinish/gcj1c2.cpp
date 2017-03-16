#include<bits/stdc++.h>
#define rep(i,s,n) for((i)=(s);(i)<=(n);(i)++)
#define getint(x) scanf("%d",&x)
#define getlong(x) scanf("%lld",&x)
#define putint(x) printf("%d",x)
#define putintln(x) printf("%d\n",x)
#define putlong(x) printf("%lld",x)
#define putlongln(x) printf("%lld\n",x)
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
vector<string> vr;
int findoc(string a,string b,int al,int bl)
{
	int ans=0,i,j;
	rep(i,0,bl-al)
	{
		rep(j,0,al-1)
		{
			if(a[j]!=b[i+j])
				break;
		}
		if(j==al)
			ans++;
	}
	return ans;
}

int main()
{
	int t,k,l,i,s,ind;
	getint(t);
	rep(ind,1,t)
	{
		getint(k);
		getint(l);
		getint(s);
		char key[k+1],tar[l+1];
		scanf("%s%s",key,tar);
		int x=(int)pow(k,s);
		rep(i,1,x)
		{
			int temp=i,pos=0;
			string ts="";
			while(pos!=s)
			{
				int poss=temp%k;
				ts.pb(key[poss]);
				temp/=k;
				pos++;
			}
			vr.pb(ts);
		}
		double num=0,maxnum=-1;
		rep(i,0,x-1)
		{
			int rec=findoc(tar,vr[i],l,s);
			num=num+rec;
			if(rec>maxnum)
				maxnum=rec;
		}
		num=num/x;
		num=maxnum-num;
		printf("Case #%d: %.6lf\n",ind,num );
		vr.clear();
	}
}