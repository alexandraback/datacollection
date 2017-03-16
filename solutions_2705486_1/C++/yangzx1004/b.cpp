#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

#pragma comment(linker, "/STACK:1024000000,1024000000")
#define PB push_back
#define MP make_pair

const double pi=2.0*asin(1.0),eps=1e-12;
const int maxn=1100,maxm=1400000,inf=0x3f3f3f3f;
const int maxlen=26;

class node{
    public:
    node* next[maxlen];
    int ptr;
    void init()
    {
        ptr=-1;
        int i;
        for(i=0;i<maxlen;i++)next[i]=NULL;
    }
};
class trie
{
    public:
    node* head;
    int numptr,p;
    node s[maxm];
    public:
    void init()
    {
        numptr=0;
        head=&s[numptr++];
        head->init();
        p=0;
    }
    int ins(char ch[])
    {
        node* temp=head;
        int k=0;
        while(ch[k]!=0)
        {
            if(temp->next[ch[k]-'a']==NULL)
            {
                temp->next[ch[k]-'a']=&s[numptr];
                s[numptr].init();
                numptr++;
            }
            temp=temp->next[ch[k]-'a'];
            k++;
        }
        temp->ptr=p++;
        return temp->ptr;
    }
    int question(char ch[])
    {
        node* temp=head;
        int k=0;
        while(ch[k]!=0&&temp)
        {
            temp=temp->next[ch[k]-'a'];
            k++;
        }
        if(temp==NULL)return -1;
        return temp->ptr;
    }
}h;
char ch[4400];
int dp[4400][5];
void cal(int begin,int id,int val)
{
	node *ptr=h.head;
	int i,x;
	for(i=begin;ch[i]!=0&&ptr;i++)
	{
		ptr=ptr->next[ch[i]-'a'];
		if(ptr==NULL)break;
		if(ptr->ptr!=-1&&i>=id)
		{
			x=i-id;
			if(x>4)x=4;
			dp[i][x]=min(dp[i][x],val);
		}
	}
}
int main()
{
	int i,Maxlen=0,t,ca=1,ans,j,k,l,n;
	char temp;
	FILE *fp=fopen("txt","r");
	i=0;
	h.init();
	while(fscanf(fp,"%s",ch)==1)
	{
		h.ins(ch);
		i++;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",ch+1);
		memset(dp,0x3f,sizeof(dp));
		dp[0][4]=0;
		n=strlen(ch+1);
		for(i=0;i<n;i++)
		{
			for(j=0;j<5;j++)
			{
				if(dp[i][j]==inf)continue;
				cal(i+1,i-j,dp[i][j]);
				for(k=5-j;k<11&&i+k<=n;k++)
				{
					temp=ch[i+k];
					for(l='a';l<='z';l++)
					{
						ch[i+k]=l;
						int x=dp[i][j];
						if(l!=temp)x++;
						cal(i+1,i+k,x);
						for(int c=k+5;c<11;c++)
						{
							char z=ch[i+c];
							for(int d='a';d<='z';d++)
							{
								ch[i+c]=d;
								int y=x;
								if(z!=d)y++;
								cal(i+1,i+c,y);
							}
							ch[i+c]=z;
						}
					}
					ch[i+k]=temp;
				}
			}
		}
		ans=inf;
		for(i=0;i<5;i++)ans=min(ans,dp[n][i]);
		printf("Case #%d: %d\n",ca++,ans);
	}
	return 0;
}

