#include <cstdio>
#include <cstring>

main(){
	int testcases;
	scanf("%d",&testcases);
	for(int casenum=1;casenum<=testcases;casenum++){
		printf("Case #%d: ",casenum);
		
		char buf[2020];
		scanf("%s",buf);
		int freq[256]={};
		int l=strlen(buf);
		for(int i=0;i<l;i++)freq[buf[i]]++;
		
		
		int ans[10]={};
		ans[0]=freq['Z'];
		freq['Z']-=ans[0];
		freq['E']-=ans[0];
		freq['R']-=ans[0];
		freq['O']-=ans[0];
		ans[2]=freq['W'];
		freq['T']-=ans[2];
		freq['W']-=ans[2];
		freq['O']-=ans[2];
		ans[4]=freq['U'];
		freq['F']-=ans[4];
		freq['O']-=ans[4];
		freq['U']-=ans[4];
		freq['R']-=ans[4];
		ans[6]=freq['X'];
		freq['S']-=ans[6];
		freq['I']-=ans[6];
		freq['X']-=ans[6];
		ans[8]=freq['G'];
		freq['E']-=ans[8];
		freq['I']-=ans[8];
		freq['G']-=ans[8];
		freq['H']-=ans[8];
		freq['T']-=ans[8];
		ans[1]=freq['O'];
		freq['O']-=ans[1];
		freq['N']-=ans[1];
		freq['E']-=ans[1];
		ans[3]=freq['H'];
		freq['T']-=ans[3];
		freq['H']-=ans[3];
		freq['R']-=ans[3];
		freq['E']-=ans[3];
		freq['E']-=ans[3];
		ans[5]=freq['F'];
		freq['F']-=ans[5];
		freq['I']-=ans[5];
		freq['V']-=ans[5];
		freq['E']-=ans[5];
		ans[7]=freq['S'];
		freq['S']-=ans[7];
		freq['E']-=ans[7];
		freq['V']-=ans[7];
		freq['E']-=ans[7];
		freq['N']-=ans[7];
		ans[9]=freq['I'];
		freq['N']-=ans[9];
		freq['I']-=ans[9];
		freq['N']-=ans[9];
		freq['E']-=ans[9];
		for(int i=0;i<=9;i++)for(int j=0;j<ans[i];j++)printf("%d",i);
		puts("");
	}
}