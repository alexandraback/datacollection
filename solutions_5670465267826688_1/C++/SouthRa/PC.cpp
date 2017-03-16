#include<cstdio>
#include<cstring>

using namespace std;

int conv[8][8]={{0,1,2,3,4,5,6,7},{1,4,3,6,5,0,7,2},{2,7,4,1,6,3,0,5},{3,2,5,4,7,6,1,0},{4,5,6,7,0,1,2,3},{5,0,7,2,1,4,3,6},{6,3,0,5,2,7,4,1},{7,6,1,0,3,2,5,4}};
char str[10000000000000005];

int main()
{
	int t, i, j, st, nex, fnl, len;
	long long x, l, usei, usek;
	bool ans, oki, okk;
	freopen("C:\\C-large.in", "r", stdin);
	freopen("C:\\C-large.txt", "w", stdout);
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		st=0;
		scanf("%lld %lld",&l, &x);
		scanf("%s",str);
		len=strlen(str);
		for(j=0;j<len;j++){
			nex=str[j]-'h';
			st=conv[st][nex];
			//printf("st=%d\n",st);
		}
		//printf("st=%d\n",st);
		ans=0;
		fnl=st;
		if(st&&st!=4){
			if((x%4!=0)&&(x%2==0)) ans=1;
		}
		else if((st==4)&&(x%2)!=0) ans=1;
		oki=0;
		okk=0;
		if(ans){
			st=0;
			usei=0;
			for(j=0;st!=1&&usei<=len*4;j++){
				if(j==len) j=0;
				nex=str[j]-'h';
				usei++;
				st=conv[st][nex];
				//printf("%d ",st);
			}
			if(st==1&&usei<len*x) oki=1;
			st=0;
			usek=0;
			for(j=len-1;st!=3&&usek<=len*4;j--){
				if(j<0) j=len-1;
				nex=str[j]-'h';
				usek++;
				st=conv[nex][st];
				//printf("%d ",st);
			}
			if(st==3&&usei+usek<len*x) okk=1;
		}
		printf("Case #%d: ",i);
		if(oki&&okk) puts("YES");
		else puts("NO");
	}
	return 0;
}
