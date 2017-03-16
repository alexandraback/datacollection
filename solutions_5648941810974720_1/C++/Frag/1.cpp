#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
string number[11]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int f[129];
int ans[11];
string lt;
void Decl(int num,int cnt)
{
	for(int i=0;i<number[num].length();i++)
		f[number[num][i]]-=cnt;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		cin>>lt;
		memset(f,0,sizeof(f));
		memset(ans,0,sizeof(ans));
		for(int j=0;j<lt.length();j++)
			f[lt[j]]++;
		ans[0]=f['Z'];
		Decl(0,f['Z']);
		ans[6]=f['X'];
		Decl(6,f['X']);
		ans[7]=f['S'];
		Decl(7,f['S']);
		ans[4]=f['U'];
		Decl(4,f['U']);
		ans[5]=f['F'];
		Decl(5,f['F']);
		ans[3]=f['R'];
		Decl(3,f['R']);
		ans[8]=f['G'];
		Decl(8,f['G']);
		ans[9]=f['I'];
		Decl(9,f['I']);
		ans[2]=f['T'];
		Decl(2,f['T']);
		ans[1]=f['O'];
		Decl(1,f['O']);
		printf("Case #%d: ",i);
		for(int j=0;j<=9;j++)
			for(int k=0;k<ans[j];k++)
				printf("%d",j);
		printf("\n");
	}
	return 0;
}
