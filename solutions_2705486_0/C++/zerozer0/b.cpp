#include <stdio.h>
#include <string.h>
struct node
{
	node *child[26];
	bool flag;
	node()
	{
		for(int i=0;i<26;i++)
			child[i]=NULL;
		flag=false;
	}
};
node *root;
char str[4010];
int n,ans;
void insert(char *a)
{
	node *p=root,*tmp;
	int j;
	for(;*a;++a)
	{
		j=*a-'a';
		if(!p->child[j])
		{
			tmp=new node();
			p->child[j]=tmp;
		}
		p=p->child[j];
	}
	p->flag=true;
}

void dfs(int deep,int pre,node *p,int count)
{
	if(count>=ans)
		return ;
	if(deep==n)
	{
		if(p->flag)
		{
			ans=count;
		}
		return ;
	}
	if(pre!=-1 && deep>=pre+5)
		pre=-1;
	if(p->child[str[deep]-'a'])
	{
		dfs(deep+1,pre,p->child[str[deep]-'a'],count);
		return ;
	}
	if(p->flag)
	{
		dfs(deep,pre,root,count);
	//	return ;
	}	

	if(pre==-1)
	{
		for(int i=0;i<26;i++)
		{
			if(p->child[i])
			{
				if(str[deep]!='a'+i)
					dfs(deep+1,deep,p->child[i],count+1);
			}
		}
	
	}



}
int main()
{	
	int t,test=0;
	freopen("garbled_email_dictionary.txt","r",stdin);
	root=new node;
	while(scanf("%s",str)!=EOF)
		insert(str);
    fclose(stdin);
	freopen("CON","r",stdin);
	freopen("C-small-attempt2.in","r",stdin);
	freopen("cs.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		n=strlen(str);
		ans=n/5+1;
		dfs(0,-1,root,0);
		printf("Case #%d: %d\n",++test,ans);
	}

	return 0;
}