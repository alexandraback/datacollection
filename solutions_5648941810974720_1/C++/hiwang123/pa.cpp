//hi
#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define LL long long int
int cnt[30];
int out[11];
int main(void){
    int t,hh;
    scanf("%d",&t);
    for(hh=1;hh<=t;hh++){
		char s[2005];
		scanf("%s",&s);
		int i,j;
		int n=strlen(s);
		for(i=0;i<26;i++) cnt[i]=0;
		for(i=0;i<10;i++) out[i]=0;
		for(i=0;i<n;i++)
			cnt[(int)(s[i]-'A')]++;
		out[0]=cnt[(int)('Z'-'A')];
		cnt[(int)('Z'-'A')]-=out[0];
		cnt[(int)('E'-'A')]-=out[0];
		cnt[(int)('R'-'A')]-=out[0];
		cnt[(int)('O'-'A')]-=out[0];
		
		out[6]=cnt[(int)('X'-'A')];
		cnt[(int)('S'-'A')]-=out[6];
		cnt[(int)('I'-'A')]-=out[6];
		cnt[(int)('X'-'A')]-=out[6];
		
		out[2]=cnt[(int)('W'-'A')];
		cnt[(int)('T'-'A')]-=out[2];
		cnt[(int)('W'-'A')]-=out[2];
		cnt[(int)('O'-'A')]-=out[2];
		
		out[4]=cnt[(int)('U'-'A')];
		cnt[(int)('F'-'A')]-=out[4];
		cnt[(int)('O'-'A')]-=out[4];
		cnt[(int)('U'-'A')]-=out[4];
		cnt[(int)('R'-'A')]-=out[4];
		
		out[8]=cnt[(int)('G'-'A')];
		cnt[(int)('E'-'A')]-=out[8];
		cnt[(int)('I'-'A')]-=out[8];
		cnt[(int)('G'-'A')]-=out[8];
		cnt[(int)('H'-'A')]-=out[8];
		cnt[(int)('T'-'A')]-=out[8];
		
		out[5]=cnt[(int)('F'-'A')];
		cnt[(int)('F'-'A')]-=out[5];
		cnt[(int)('I'-'A')]-=out[5];
		cnt[(int)('V'-'A')]-=out[5];
		cnt[(int)('e'-'A')]-=out[5];
		
		out[1]=cnt[(int)('O'-'A')];
		cnt[(int)('O'-'A')]-=out[1];
		cnt[(int)('N'-'A')]-=out[1];
		cnt[(int)('E'-'A')]-=out[1];
		
		out[7]=cnt[(int)('S'-'A')];
		cnt[(int)('S'-'A')]-=out[7];
		cnt[(int)('E'-'A')]-=out[7];
		cnt[(int)('V'-'A')]-=out[7];
		cnt[(int)('E'-'A')]-=out[7];
		cnt[(int)('N'-'A')]-=out[7];
		
		out[9]=cnt[(int)('I'-'A')];
		cnt[(int)('N'-'A')]-=out[9];
		cnt[(int)('I'-'A')]-=out[9];
		cnt[(int)('N'-'A')]-=out[9];
		cnt[(int)('E'-'A')]-=out[9];
		
		out[3]=cnt[(int)('R'-'A')];
		cnt[(int)('T'-'A')]-=out[3];
		cnt[(int)('H'-'A')]-=out[3];
		cnt[(int)('R'-'A')]-=out[3];
		cnt[(int)('E'-'A')]-=out[3];
		cnt[(int)('E'-'A')]-=out[3];
		
		printf("Case #%d: ",hh);
		for(i=0;i<10;i++)
			for(j=0;j<out[i];j++)
				printf("%d",i);
		printf("\n");
	}
    return 0;
}
