#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;

struct node {
	int x,y;
	int lvl,prev;
	char ch;
	node(int a,int b,int c,int d,char p):x(a),y(b),lvl(c),prev(d),ch(p){}
	bool operator < (const node &a) const {
		if(x!=a.x) return x<a.x;
		if(y!=a.y) return y<a.y;
		return false;
	}
};

int dx[]={1,-1,0, 0};
int dy[]={0, 0,1,-1};
char mpr[]={'E','W','N','S'};

int arr[8001][8001];
int main()
{
	int tc=1;
	int no;	
	scanf(" %d",&no);
	while(no--){
	int X,Y;
	int SX,SY;
	SX=SY=4000;
	memset(arr,-1,sizeof(arr));
	scanf(" %d %d",&X,&Y);
	  node tmp(0,0,0,-1,0);
	  vector<node> v;
	  v.push_back(tmp);
	  int i=0,j,cnt=0;
	  printf("Case #%d: ",tc++);
	  set<pair<int,int> > S;
	  arr[SX][SY]=1;
	  while(cnt<v.size()){
	    node tmp=v[cnt];
	    if((tmp.x==X) and (tmp.y==Y)) { 
		vector<char> ans;
		i=cnt;
		while(i!=-1)
		{
			ans.push_back(v[i].ch);
			i=v[i].prev;
		}
		reverse(ans.begin(),ans.end());
		for(i=1;i<ans.size();i++) printf("%c",ans[i]);
		printf("\n");
		break;
	    }
	
	    int lvl=tmp.lvl+1;
	    if(lvl > 502 || (v.size()>6000000)) { cnt++; continue; }
	    for(j=0;j<4;j++)
	    {
			int newx=tmp.x + dx[j]*lvl ;
			int newy=tmp.y + dy[j]*lvl;
			if((newx>0) && X==0) continue;
			if((newy>0) && Y==0) continue;
		//	printf("%d,%d\n",newx,newy);
			if((SX+newx>8000) || (SY+newy>8000) || (SX+newx<0) || (SX+newy<0)) continue;
			if(arr[SX+newx][SY+newy]==1) continue;
			arr[SX+newx][SY+newy]=1;
			v.push_back(node(newx,newy,lvl,cnt,mpr[j]));
	    }
	
	    
	    cnt++;
	    
	  }
		
	}
	
	return 0;
}
