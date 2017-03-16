#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n,m;
char str[105];
char d[3][2][105];
int mp[26];
int main(){
	int i,j,k;
	for (i = 0; i < 26; i++)
		mp[i] = -1;
	strcpy(d[0][0], "ejp mysljylc kd kxveddknmc re jsicpdrysi");
	strcpy(d[0][1], "our language is impossible to understand");
	strcpy(d[1][0], "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
	strcpy(d[1][1], "there are twenty six factorial possibilities");
	strcpy(d[2][0], "de kr kd eoya kw aej tysr re ujdr lkgc jv");
	strcpy(d[2][1], "so it is okay if you want to just give up");
	mp['z'-'a'] = 'q'-'a';
	mp['q'-'a'] = 'z'-'a';
	for(i = 0; i < 3; i++){
		m = strlen(d[i][0]);
		for(j = 0; j < m;j++){
			if (d[i][0][j]==' ') continue;
			if (mp[d[i][0][j]-'a'] != -1 && mp[d[i][0][j]-'a']!=d[i][1][j]-'a') printf("no!!!! %c %c\n", d[i][0][j], d[i][1][j]);
			mp[d[i][0][j]-'a'] = d[i][1][j]-'a';
		}
	}
	freopen("input.txt", "r", stdin);
	scanf("%d ",&n);
	FILE *out = fopen("output.txt","w");
	for(i=0;i<n;i++){
		gets(str);
		m = strlen(str);
		fprintf(out, "Case #%d: ", i+1);
		for(j=0;j<m;j++){
			if (str[j] != ' ') 
				str[j] = 'a' + mp[str[j]-'a'];
			fprintf(out, "%c", str[j]);
		}
		fprintf(out, "\n");
	}
	return 0;
}