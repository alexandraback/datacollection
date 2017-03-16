//#include <iostream>
//#include <cstdio>
//using namespace std;
//const int N=200010;
//int father[N],num[N];
//int n,m,sum;
//void init(){
//	for(int i=0;i<=n;++i){
//	  father[i]=i;
//	  num[i]=0;
//	}
//}
//int find(int x){
//	int fx=father[x];
//	if(x!=father[x]){
//	  father[x]=find(father[x]);
//	  num[x]=num[fx]+sum;
//	}
//	return father[x];
//}
//bool Union_Set(int x,int y){
//	int rootx=find(x);
//	int rooty=find(y);
//	if(rootx!=rooty){
//	  father[rooty]=rootx;
//	  num[rooty]=num[x]+sum-num[y];
//	  return true;
//	}
//	else{
//	  if(num[y]-num[x]==sum)
//		  return true;
//	  else
//		  return false;
//	}
//}
//int main(){
//	while(~scanf("%d%d",&n,&m)){
//	  init();
//	  int x,y,sum,total;
//	  while(m--){
//	    scanf("%d%d%d",&x,&y,&sum);
//		x--;
//		bool flag=Union_Set(x,y);
//	  }
//	}
//	return 0;
//}

#include <iostream>
#include <string>
#include <string.h>
#include <map>
using namespace std;
map<char,char> mp;
void init(){
	mp['a']='y';mp['b']='h';mp['c']='e';mp['d']='s';mp['e']='o';mp['f']='c';
	mp['g']='v';mp['h']='x';mp['i']='d';mp['j']='u';mp['k']='i';mp['l']='g';
	mp['m']='l';mp['n']='b';mp['o']='k';mp['p']='r';mp['q']='z';mp['r']='t';
	mp['s']='n';mp['t']='w';mp['u']='j';mp['v']='p';mp['w']='f';mp['x']='m';
	mp['y']='a';mp['z']='q';
}
int main(){
	//freopen("1.in","r",stdin);
//	freopen("2.txt","w",stdout);
	init();
	int kk=1;
	int T;
	char ss[105];
	cin>>T;
	getchar();
	while(T--){
	  gets(ss);
	  printf("Case #%d: ",kk++);
	  int len=strlen(ss);
	  for(int i=0;i<len;++i){
	    if(ss[i]>='a'&&ss[i]<='z')
			printf("%c",mp[ss[i]]);
		else
			printf("%c",ss[i]);
	  }
	  puts("");
	}
	return 0;
}