#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
char s[2002];
int cnt[30];
int ans[20];
int T;
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	
	scanf("%d",&T);
	for (int k=1;k<=T;k++)
	{
		for (int i=1;i<=26;i++)
			cnt[i]=0;
		for (int i=0;i<=10;i++)
			ans[i]=0;
		
		scanf("%s",&s);
		for (int i=0;i<strlen(s);i++)
			cnt[s[i]-'A'+1]++;
		
		
		ans[0]=cnt['z'-'a'+1]; //Z
		ans[2]=cnt['w'-'a'+1]; //W
		ans[4]=cnt['u'-'a'+1]; //U
		ans[6]=cnt['x'-'a'+1]; //X
		ans[8]=cnt['g'-'a'+1]; //G
	
		ans[1]=cnt['o'-'a'+1]-ans[0]-ans[2]-ans[4];
		ans[3]=cnt['r'-'a'+1]-ans[0]-ans[4];
		ans[5]=cnt['f'-'a'+1]-ans[4];
		ans[7]=cnt['s'-'a'+1]-ans[6];
		ans[9]=cnt['i'-'a'+1]-ans[5]-ans[6]-ans[8];
			
		printf("Case #%d: ",k);
		for (int i=0;i<=9;i++)
			for (int j=1;j<=ans[i];j++)
				printf("%d",i);
		printf("\n");
	}	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}







