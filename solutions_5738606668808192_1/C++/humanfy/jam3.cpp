#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 4000
using namespace std;
int v[111],ans[111],tot;  
char str[11111];
class node
{
	public:
		node(){}
		node(int a){set(a);}
    int wei,p[N];
    void op()
    {
        if (!wei)
        {
            printf("0\n");
            return;
        }
        printf("%d",p[wei]);
        for (int i=wei-1;i;i--)
        {
            if (p[i]/1000) printf("%d",p[i]/1000);else printf("0");
            if ((p[i]%1000)/100) printf("%d",(p[i]%1000)/100);else printf("0");
            if ((p[i]%100)/10) printf("%d",(p[i]%100)/10);else printf("0");
            if (p[i]%10) printf("%d",p[i]%10);else printf("0");
        }
        printf("\n");
    }
    void set(int a)
    {
        wei=0;
        memset(p,0,sizeof(p));
        while (a)
        {
            wei++;
            p[wei]=a%10000;
            a/=10000;
        }
    }
    void inp()
    {
        set(0);
        scanf("%s",str+1);
        int len=strlen(str+1);
        for (int i=len;i>0;i-=4)
        {
            wei++;
            for (int j=3;j>=0;j--)
            if (i-j>0) p[wei]=p[wei]*10+str[i-j]-'0';
        }
    }
}A,B,ret;



node operator +(node a,node b)
{
	ret.set(0);
    ret.wei=max(a.wei,b.wei);
    for (int i=1;i<=ret.wei;i++)
    ret.p[i+1]+=(ret.p[i]+a.p[i]+b.p[i])/10000,ret.p[i]=(ret.p[i]+a.p[i]+b.p[i])%10000;
    if (ret.p[ret.wei+1]) ret.wei++;
    return ret;
}
  
  
  
node operator -(node a,node b)
{
    ret.wei=a.wei;
    for (int i=1;i<=ret.wei;i++)
    {
        ret.p[i]=a.p[i]-b.p[i];
        if (ret.p[i]<0) ret.p[i]+=10000,b.p[i+1]++;
    }
    for (;ret.wei&&ret.p[ret.wei]==0;ret.wei--);
    return ret;
}
  
  
  
node operator *(node a,node b)
{
    ret.set(0);
    if (!a.wei||!b.wei) return ret;
    for (int i=1;i<=a.wei;i++)
    for (int j=1;j<=b.wei;j++)
    ret.p[i+j]=ret.p[i+j]+(ret.p[i+j-1]+a.p[i]*b.p[j])/10000,ret.p[i+j-1]=(ret.p[i+j-1]+a.p[i]*b.p[j])%10000;
    for (ret.wei=a.wei+b.wei;ret.p[ret.wei]==0;ret.wei--);
    return ret;
}
  
  
  
node operator *(node a,int b)
{
    ret.set(0);
    if (!b||!a.wei) return ret;
    for (int i=1;i<=a.wei;i++)
    ret.p[i]=a.p[i]*b;
    for (int i=1;i<=a.wei;i++)
    ret.p[i+1]+=ret.p[i]/10000,ret.p[i]%=10000;
    for (ret.wei=a.wei;ret.p[ret.wei+1];ret.wei++) ret.p[ret.wei+1]+=ret.p[ret.wei]/10000,ret.p[ret.wei]%=10000;
    return ret;
}
  
  
  
node operator /(node a,int b)
{
    int yu=0;
    for (int i=a.wei;i;i--)
    yu=yu*10000+a.p[i],ret.p[i]=yu/b,yu%=b;
    for (ret.wei=a.wei;ret.wei&&ret.p[ret.wei]==0;ret.wei--);
    return ret;
}
  
  
  
int operator %(node a,int b)
{
    int yu=0;
    for (int i=a.wei;i;i--)
    yu=yu*10000+a.p[i],yu%=b;
    return yu;
}
  
  
  
bool operator >(node a,node b)
{
    if (a.wei!=b.wei) return a.wei>b.wei;
    for (int i=a.wei;i;i--)
    {
        if (a.p[i]!=b.p[i]) return a.p[i]>b.p[i];
    }
    return 0;
}
  
  
  
bool operator <(node a,node b)
{
    if (a.wei!=b.wei) return a.wei<b.wei;
    for (int i=a.wei;i;i--)
    {
        if (a.p[i]!=b.p[i]) return a.p[i]<b.p[i];
    }
    return 0;
}
  
  
  
bool operator ==(node a,node b)
{
    if (a.wei!=b.wei) return 0;
    for (int i=a.wei;i;i--)
    {
        if (a.p[i]!=b.p[i]) return 0;
    }
    return 1;
}

int prime(node a)
{
	for (int i=2;i<111;i++)
	if (a%i==0) return i;
	return 0;
}
void hehe()
{
	
		for (int i=2;i<11;i++)
		{
			node a;
			a.set(1);
			for (int j=30;j;j--)
			a=a*i+node(v[j]);
			a=a*i+1;
			ans[i]=prime(a);
			if (!ans[i]) return;
		}
		printf("1");
		for (int i=30;i;i--)printf("%d",v[i]);
		printf("1 ");
		for (int i=2;i<11;i++) printf("%d ",ans[i]);
		printf("\n");
		tot++;
}
void dfs(int dep)
{
//	cout<<dep<<endl;
	if (tot==500) return;
	if (!dep)
	{
		hehe(); 
		return;
	}
	v[dep]=0;
	dfs(dep-1);
	v[dep]=1;
	dfs(dep-1);
}
int main()
{
	freopen("C2.out","w",stdout);
	cout<<"Case #1:"<<endl;
	dfs(30);
}
