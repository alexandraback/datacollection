#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<ctime>
#include<map>
#include<set>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
#define ULL unsigned long long
#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 1
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < n; ++i)
#define Rep(i,n) for(int i = 1; i <= n; ++i)

char s[40400];

char mul[130][130];

int main()
{
	mul[1]['i']='i';mul[1]['j']='j';mul[1]['k']='k';
	mul['i']['i']=0;mul['i']['j']='k';mul['i']['k']='J';
	mul['j']['i']='K';mul['j']['j']=0;mul['j']['k']='i';
	mul['k']['i']='j';mul['k']['j']='I';mul['k']['k']=0;
	mul[0]['i']='I';mul[0]['j']='J';mul[0]['k']='K';
	mul['I']['i']=1;mul['I']['j']='K';mul['I']['k']='j';
	mul['J']['i']='k';mul['J']['j']=1;mul['J']['k']='I';
	mul['K']['i']='J';mul['K']['j']='i';mul['K']['k']=1;
	
	mul['i'][1]='i';mul['j'][1]='j';mul['k'][1]='k';
	mul['i']['i']=0;mul['j']['i']='K';mul['k']['i']='j';
	mul['i']['j']='k';mul['j']['j']=0;mul['k']['j']='I';
	mul['i']['k']='J';mul['j']['k']='i';mul['k']['k']=0;
	mul['i'][0]='I';mul['j'][0]='J';mul['k'][0]='K';
	mul['i']['I']=1;mul['j']['I']='k';mul['k']['I']='J';
	mul['i']['J']='K';mul['j']['J']=1;mul['k']['J']='i';
	mul['i']['K']='j';mul['j']['K']='I';mul['k']['K']=1;
	int t,cas=0;
	cin>>t;
	while(cas++ < t){
		int l;
		LL x;
		cin>>l>>x;
		scanf("%s",s);
		printf("Case #%d: ",cas);
		char temp=1;
		for(int i=0;i<l;++i) temp = mul[temp][s[i]];
		if(temp == 1 || temp == 0 && x % 2 != 1 || temp && x % 4 != 2) {
			puts("NO");
			continue;
		}
		for(int i=l;i<4*l;++i)s[i] = s[i-l];
		l=4*l;
		temp=1;
		int ilen = 0, klen = 0;
		for(int i=0;i<l;++i) {
			temp = mul[temp][s[i]];
			if(temp == 'i') {
				ilen = i + 1;
				break;
			}
		}
		temp=1;
		for(int i=0;i<l;++i) {
			temp = mul[s[l-i-1]][temp];
			if(temp == 'k') {
				klen = i + 1;
				break;
			}
		}
		if(ilen && klen && ilen + klen < l/4*x) puts("YES");
		else puts("NO");
	}
	return 0;
}

