#include <iostream>
#include <algorithm>
using namespace std;
#define N 101
#define MID 500
struct Attack{
	int start_day,delta_day;
	int num;
	int west,east;
	int strength,delta_s;
	int delta_p;
}attack[N];
struct Node{
	int west,east;
	int day;
	int strength;
}node[N*N];
int cmp(Node &a,Node &b)
{
	return a.day < b.day;
}
int height[1000];
bool attackSuc(Node a)
{
	int i;
	for(i=a.west;i<a.east;i++)
		if(height[i+MID] < a.strength)
			return true;
	return false;
}
void rebuild(Node a)
{
	int i;
	for(i=a.west;i<a.east;i++)
		if(height[i+MID] < a.strength)
			height[i+MID] = a.strength;
}
int main(){
	//freopen("A-small-practice.in","r",stdin);
	//freopen("A-small-practice.out","w",stdout);
	int t,i,j,count,ans,x,n;
	scanf("%d",&t);
	for(x=0;x<t;x++)
	{
		memset(height,0,sizeof(height));
		scanf("%d",&n);
		count = 0;
		for(i=0;i<n;i++){
			scanf("%d%d%d%d%d%d%d%d",&attack[i].start_day,&attack[i].num,&attack[i].west,&attack[i].east,&attack[i].strength,&attack[i].delta_day,&attack[i].delta_p,&attack[i].delta_s);
			for(j=0;j<attack[i].num;j++){
				node[count].day = attack[i].start_day + attack[i].delta_day * j;
				node[count].east = attack[i].east + attack[i].delta_p * j;
				node[count].west = attack[i].west + attack[i].delta_p * j;
				node[count].strength = attack[i].strength + attack[i].delta_s * j;
				count ++;
			}
		}
		sort(node,node+count,cmp);
		ans = 0;
		for(i=0;i<count;i++)
		{
			if(i>0&&node[i].day>node[i-1].day){
				rebuild(node[i-1]);
				for(j=i-2;j>=0&&node[j].day==node[i-1].day;j--)
					rebuild(node[j]);
			}
			if(attackSuc(node[i]))ans++;
		}
		printf("Case #%d: %d\n",x+1,ans);

	}
	return 0;
}