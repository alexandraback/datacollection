#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<string.h>
#include<string>
#include<map>
using namespace std;
map<string,int> dhh;
string str,Min;
char c[110];int c1;
int pl,a,b;
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;++i){
		scanf("%d%d",&a,&b);
		dhh.clear();
		for (int i=a;i<=b;++i){
			c1=0;
			int tmp=i;
			while (tmp){
				c[++c1]=tmp%10;tmp/=10;
			}
			if (c1==0)c[++c1]=0;
			Min="zzzzzzzzzzzzzzzz";
			for (int i1=1;i1<=c1;++i1){
				str="";
				for (int j=1;j<=c1;++j){
					pl=(i1+j)%c1;
					if (!pl)pl=c1;
					str+=c[pl];
				}
				if (str<Min)Min=str;
			}
			++dhh[Min];
		}
		int ans=0;
		for (map<string,int>::iterator zzy=dhh.begin();zzy!=dhh.end();++zzy)
			ans+=(zzy->second)*(zzy->second-1)/2;
		printf("Case #%d: ",i);
		printf("%d\n",ans);
	}
	//system("pause");
	return 0;
}




