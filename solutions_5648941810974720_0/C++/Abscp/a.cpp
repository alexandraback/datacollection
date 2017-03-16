#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main() {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; ++i){
		char s[3000];
		scanf("%s", s);
		int l = strlen(s);
		int co[200];
		int ans[200];
		for(int j='A'; j<='Z'; ++j) co[j]=0;
		for(int j=0; j<l; ++j) co[s[j]]++;
		printf("Case #%d: ", i+1);
		
		ans[0] = co['Z'];
		co['E'] -= co['Z'];
		co['R'] -= co['Z'];
		co['O'] -= co['Z'];
		
		ans[6]= co['X'];
		co['S'] -= co['X'];
		co['I'] -= co['X'];
		
		ans[7]= co['S'];
		co['E'] -= 2*co['S'];
		co['V'] -= co['S'];
		co['N'] -= co['S'];
		
		ans[5]= co['V'];
		co['F'] -= co['V'];
		co['I'] -= co['V'];
		co['E'] -= co['V'];
		
		ans[4]= co['F'];
		co['O'] -= co['F'];
		co['U'] -= co['F'];
		co['R'] -= co['F'];
		
		ans[2]= co['W'];
		co['T'] -= co['W'];
		co['O'] -= co['W'];
		
		ans[3]= co['R'];
		co['E'] -= 2*co['R'];
		co['T'] -= co['R'];
		co['H'] -= co['R'];
		
		ans[1]= co['O'];
		co['E'] -= co['O'];
		co['N'] -= co['O'];
		
		ans[8]=co['G'];
		co['E'] -= co['G'];
		co['I'] -= co['G'];
		
		ans[9] = co['E'];
		for(int j=0; j<10; ++j)
			for(int k=0; k<ans[j]; ++k)
				printf("%d",j);
		printf("\n");
		
	}
	
	return 0;
}
