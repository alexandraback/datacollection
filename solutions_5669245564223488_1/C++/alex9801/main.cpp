#include <stdio.h>
#include <memory.h>

const int PROB_NUM=4;

bool chk[26];
bool use[26];
bool ext[26][2];
char ori[100][101];
char arr[100][101];
char nex[26];
int len[100];
int sel[26];
long long fac[101];
const long long m=1000000007;

void pre_process()
{
	int i;
	fac[0]=1;
	for(i=1;i<=100;i++)
		fac[i]=(fac[i-1]*i)%m;
}

void process()
{
	memset(chk,0,sizeof(chk));
	memset(use,0,sizeof(use));
	memset(ext,0,sizeof(ext));
	memset(len,0,sizeof(len));
	memset(sel,0,sizeof(sel));
	char p;
	int c=0,t,n,i,j;
	long long r;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%s",ori[i]);
	for(i=0;i<n;i++)
	{
		p=0;
		for(j=0;ori[i][j];j++)
		{
			if(ori[i][j]!=p)
			{
				arr[i][len[i]++]=ori[i][j];
				p=ori[i][j];
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=1;j<len[i]-1;j++)
		{
			if(chk[arr[i][j]-'a'])
			{
				printf("0\n");
				return;
			}
			chk[arr[i][j]-'a']=1;
		}
	}
	for(i=0;i<26;i++)
		nex[i]=i;
	for(i=0;i<n;i++)
	{
		if(chk[arr[i][0]-'a']||chk[arr[i][len[i]-1]-'a'])
		{
			printf("0\n");
			return;
		}
		if(arr[i][0]==arr[i][len[i]-1])
			sel[arr[i][0]-'a']++;
		else
		{
			if(ext[arr[i][0]-'a'][0]||ext[arr[i][len[i]-1]-'a'][1])
			{
				printf("0\n");
				return;
			}
			ext[arr[i][0]-'a'][0]=1;
			ext[arr[i][len[i]-1]-'a'][1]=1;
			nex[arr[i][0]-'a']=arr[i][len[i]-1]-'a';
		}
	}
	for(i=0;i<26;i++)
	{
		if(!ext[i][1]&&(sel[i]||ext[i][0])&&!use[i])
		{
			c++;
			t=i;
			while(1)
			{
				if(use[t])
				{
					printf("0\n");
					return;
				}
				use[t]=1;
				if(t==nex[t])
					break;
				t=nex[t];
			}
		}
	}
	r=fac[c];
	for(i=0;i<26;i++)
	{
		r*=fac[sel[i]];
		r%=m;
	}
	printf("%lld\n",r);
}

int main()
{
	char in[10]="0.in";
	char out[10]="0.out";
	in[0]=PROB_NUM+'0';
	out[0]=PROB_NUM+'0';
	freopen(in,"r",stdin);
	freopen(out,"w",stdout);
	int t,i;
	scanf("%d",&t);
	pre_process();
	for(i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		process();
	}
	return 0;
}