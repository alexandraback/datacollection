#include<iostream>
#include<vector>
#include<string>
#include<conio.h>
#include<map>
#define MAX_N 50100
#define MAX_L 5000
#define infinity 2000000000
using namespace std;
// Global Vars
char s[MAX_L];
int dp_count[MAX_L];
int N;





class CBor
{
	struct type
	{
		type *m[50];
		int index;
	};
	type *root;
	
	type* NewElem();
	
	void add(type *T,char *ptr);
	void find(type *T,int start,char *ptr,int length,int cur);
public:
	CBor() { root=NewElem(); }
	void add(char *ptr) { add(root,ptr); }
	void find(int start,char *ptr) { find(root,start,ptr,0,0); }

};
CBor::type* CBor::NewElem()
{
	type *a=(type*)malloc(sizeof(type));
	a->index=-1;
	for(int i='a';i<='z';i++) a->m[i-'a']=NULL;
	return a;
}

void CBor::add(type *T,char *ptr)
{
	if(!(*ptr)) 
	{
		T->index=1;
		return;
	}
	short v=ptr[0]-'a';
	if(!(T->m[v])) T->m[v]=NewElem();
	add(T->m[v],ptr+1);
}

void CBor::find(type *T,int start,char *ptr,int length,int cur)
{
	if(T->index!=-1)
	{
		dp_count[start+length-1]=min(dp_count[start+length-1],((start)?dp_count[start-1]:0)+cur);
	}
	if(!(*ptr)) return;
	short v=(*ptr)-'a';
	if(T->m[v]) find(T->m[v],start,ptr+1,length+1,cur);
	int i;
	for(i=0;i<=v-5;i++)
		if(T->m[i]) find(T->m[i],start,ptr+1,length+1,cur+1);
	for(i=v+5;i<='z'-'a';i++)
		if(T->m[i]) find(T->m[i],start,ptr+1,length+1,cur+1);
}


CBor bor;


bool solve(int T)
{
	scanf("%s",&s);
	int i,L=strlen(s);
	for(i=0;i<L;i++) 
	{
		dp_count[i]=infinity;
	}
	for(i=0;i<L;i++)
		if(!i||dp_count[i-1]!=infinity)
			bor.find(i,s+i);
//	for(i=0;i<L;i++) printf("%d | %d\n",i,dp_count[i]);
//	getch();
	printf("Case #%d: %d\n",T,dp_count[L-1]);
	return true;
}

void init()
{
	FILE *f=fopen("codejam.txt","r");
	for(int i=0;i<521196;i++)
	{
		fscanf(f,"%s",s);
		bor.add(s);
	}
	fclose(f);
}

int main()
{
	init();
	int i,T;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	for(i=1;i<=T;i++) solve(i);
	return 0;
}