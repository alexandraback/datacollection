#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1002
struct Node{
	int a,b,l;
}node[N],nod[N];
int n,ans;
bool taga[N],tagb[N];
int cmpa(Node &x,Node &y)
{
	return x.a < y.a;
}
int cmpb(Node &x,Node &y)
{
	return x.b < y.b;
}
void search(){
	int j;
	int value = 0;
	int x = 0;
	ans = 0;
	while(x < n)
	{
		bool ck = false;
		for(j=0;j<n;j++)
		{
			if(nod[j].b > value)break;
			if(tagb[nod[j].l] == false){
				ck = true;
				x ++;
				ans ++;
				if(taga[nod[j].l] == false){
					value += 2;
					taga[nod[j].l] = true;
				}
				else value += 1;
				tagb[nod[j].l] = true;
			}
		}
		if(ck)continue;
		ck = false;
		for(j=0;j<n;j++)
		{
			if(node[j].a > value)break;
			if(taga[node[j].l] == false && tagb[node[j].l] == false){
				ck = true;
				ans ++;
				value += 1;
				taga[node[j].l] = true;
				break;
			}
		}
		if(ck == false)break;
	}
	if(x < n) ans = -1;
}
int main()
{
		freopen("B-small-attempt2.in","r",stdin);
	//freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&n);
		for(j=0;j<n;j++){
			node[j].l = j;
			scanf("%d%d",&node[j].a,&node[j].b);
			nod[j] = node[j];
		}
		memset(taga,false,sizeof(taga));
		memset(tagb,false,sizeof(tagb));
		sort(node,node+n,cmpa);
		sort(nod,nod+n,cmpb);
		search();
		if(ans < 0)
			printf("Case #%d: Too Bad\n",i);
		else
			printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}