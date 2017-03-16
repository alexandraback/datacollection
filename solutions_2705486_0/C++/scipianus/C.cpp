#include<fstream>
#include<cstring>
#include<cstdlib>
#define ch (*s - 'a')
using namespace std;
int Ts,ns;
char s[4010];
int best[4010][4010],sol;

struct Trie
{
    int nrcuv;
    Trie *fiu[26];
    Trie()
    {
        nrcuv=0;
        memset(fiu,0,sizeof(fiu));
    }
};
Trie *T=new Trie;

inline void Insert(Trie *nod,char *s)
{
    if(*s==0) 
    {
        nod->nrcuv++;
        return;
    }
    if(nod->fiu[ch]==0)
        nod->fiu[ch]=new Trie; 
    Insert(nod->fiu[ch],s+1);
}

inline void Query(Trie *nod,char *s,int poz,int cost,int last)
{
	if(cost>=sol)
		return;
	if(nod->nrcuv!=0)
	{
		best[poz][last]=min(best[poz][last],cost);
		if(poz==ns)
			sol=min(sol,best[poz][last]);
	}
	if(*s==0)
		return;
	if(nod->fiu[ch]!=0)
		Query(nod->fiu[ch],s+1,poz+1,cost,last);
	if(last==0 || abs(poz+1-last)>=5)
	{
		for(int i=0;i<26;i++)
			if(i!=ch && nod->fiu[i]!=0)
				Query(nod->fiu[i],s+1,poz+1,cost+1,poz+1);
	}
}

int main()
{
	int t,i,j;
	ifstream din("garbled_email_dictionary.txt");
	for(i=1;i<=521196;i++)
	{
		din>>s;
		Insert(T,s);
	}
	din.close();
	ifstream fin("C.in");
	ofstream fout("C.out");
	fin>>Ts;
	for(t=1;t<=Ts;t++)
	{
		fin>>(s+1);
		ns=strlen(s+1);
		best[0][0]=0;
		for(i=1;i<=ns;i++)
			for(j=0;j<=ns;j++)
				best[i][j]=1000000000;
		sol=1000000000;
		for(i=0;i<ns;i++)
		{
			for(j=0;j<=i;j++)
			{
				if(best[i][j]!=1000000000)
					Query(T,s+i+1,i,best[i][j],j);
			}
		}
		fout<<"Case #"<<t<<": "<<sol<<"\n";
	}
	fin.close();
	fout.close();
	return 0;
}
