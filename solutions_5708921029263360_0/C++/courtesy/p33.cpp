#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
#define PB push_back
#define pii pair<int,int>
#define MP make_pair
#define sz size()
#define fi first
#define se second
using namespace std;
typedef long long ll;
int A,B,C,K;
int mx,l;
int prr[10000][3];
map<int,int> m1,m2,m3;
int ch[10000],chh[10000];
void fn()
{
	int i,j,k=0;
	for(i=0;i<l;i++)k+=ch[i];
	if(k>mx)
	{
		for(i=0;i<l;i++)chh[i]=ch[i];
		mx=k;
	}
}
void fun(int c)
{
	if(c==l)
	{
		fn();
		return;
	}
	int i,j,k;
	i=prr[c][0];j=prr[c][1];k=prr[c][2];
	ch[c]=0;
	fun(c+1);
	if((m1[i*100+j]<K)&&(m2[i*100+k]<K)&&(m1[j*100+k]<K))
	{
		ch[c]=1;
		m1[i*100+j]++;
		m2[i*100+k]++;
		m3[j*100+k]++;
		fun(c+1);
		ch[c]=0;
		m1[i*100+j]--;
		m2[i*100+k]--;
		m3[j*100+k]--;		
	}
}
int main()
{
	int t,i,j,k,cs,css;
	cin>>css;
	for(cs=1;cs<=css;cs++)
	{
		cin>>A>>B>>C>>K;
		cout<<"Case #"<<cs<<": ";
		if(A==3 && B==3 && C==3 && K>=3)
		{
			cout<<"27\n";
			for(i=1;i<=3;i++)
			{
				for(j=1;j<=3;j++)
				{
					for(k=1;k<=3;k++)cout<<i<<" "<<j<<" "<<k<<endl;
				}
			}
			continue;
		}
		l=0;
		for(i=1;i<=A;i++)
		{
			for(j=1;j<=B;j++)
			{
				for(k=1;k<=C;k++)
				{
					prr[l][0]=i;
					prr[l][1]=j;
					prr[l][2]=k;
					ch[l]=0;
					l++;
				}
			}
		}
		m1.clear();m2.clear();m3.clear();
		mx=0;
		fun(0);
		cout<<mx<<endl;
		for(i=0;i<l;i++)
		{
			if(chh[i])
			{
				cout<<prr[i][0]<<" "<<prr[i][1]<<" "<<prr[i][2]<<endl;
			}
		}
	}
	return 0;
}
