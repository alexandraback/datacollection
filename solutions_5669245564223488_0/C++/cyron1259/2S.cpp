#include <stdio.h>
#include <string.h>
int t;
int n;
char s[110][110];
int a[110][30][6]; // 0 : only left 1: only right 2: both 3:none 4:connect
int p1[110][110];
int p2[30];
long long int tot;
int cnt;
int v[110];
void cl(){
	int i,j,k;
	for(i=0;i<=100;i++){
		for(j=0;j<=26;j++){
			for(k=0;k<6;k++){
				a[i][j][k]=0;
			}
		}
	}
	for(i=0;i<=100;i++){
		v[i]=0;
		for(j=0;j<=100;j++){
			s[i][j]=0;
			p1[i][j]=0;
		}
	}
	for(i=0;i<26;i++){
		p2[i]=0;
	}
	tot=1;
	cnt=0;
}
void f(int st, int en){

	if(v[en]){
		tot=0;
		return;
	}
	v[st]=1;
	v[en]=1;
	int i;
	for(i=p2[s[en][s[0][en]-1]-'a'];i>1;i--){
		tot*=i;
		tot%=1000000007;
	}
	p2[s[en][s[0][en]-1]-'a']=0;
	for(i=1;i<=n;i++){
		if(p1[en][i]) break;
	}
	if(i<=n) f(en,i);
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	int k;
	for(k=1;k<=t;k++){
		if(k==65){
			k=65;
		}
		cl();
		scanf("%d",&n);
		printf("Case #%d: ",k);
		int i,j;
		for(i=1;i<=n;i++){
			scanf("%s",s[i]);
			s[0][i]=strlen(s[i]);
			int l;
			for(l=1;l<s[0][i];l++){
				if(s[i][l]!=s[i][0]) break;
			}
			int r;
			for(r=s[0][i]-2;r>0;r--){
				if(s[i][r]!=s[i][s[0][i]-1]) break;
			}
			if(l==s[0][i]){
				a[i][s[i][0]-'a'][4]++;
				a[0][s[i][0]-'a'][4]++;
			}
			else{
				if(s[i][0]==s[i][s[0][i]-1]){
					a[i][s[i][0]-'a'][2]++;	//die
					a[0][s[i][0]-'a'][2]++;	//die
				}
				else{
					a[i][s[i][0]-'a'][0]++;
					a[i][s[i][s[0][i]-1]-'a'][1]++;
					a[0][s[i][0]-'a'][0]++;
					a[0][s[i][s[0][i]-1]-'a'][1]++;
				}
				for(j=l;j<=r;j++){
					a[i][s[i][j]-'a'][3]++;	//die
					a[0][s[i][j]-'a'][3]++;	//die
				}
			}
		}
		for(i=0;i<26;i++){
			for(j=0;j<5;j++){
				a[0][i][5]+=a[0][i][j];
			}
			if(a[0][i][3] && a[0][i][3]!=a[0][i][5]){
				printf("0\n");
				break;
			}
			if(a[0][i][2]){
				printf("0\n");
				break;
			}
			if(a[0][i][0]>1 || a[0][i][1]>1){
				printf("0\n");
				break;
			}
		}
		if(i<26) continue;


		for(i=0;i<26;i++){
			int st,en;
			st=en=0;
			for(j=1;j<=n;j++){
				if(a[j][i][0]) en=j;
				if(a[j][i][1]) st=j;
			}
			p1[st][en]=1;
			p2[i]+=a[0][i][4];
		}
		for(i=1;i<=n;i++){
			if(p1[0][i]){
				f(0,i);
				cnt++;
			}
		}
		for(i=0;i<26;i++){
			if(p2[i]){
				int ii;
				for(ii=p2[i];ii>1;ii--){
					tot*=ii;
					tot%=1000000007;
				}
				p2[i]=0;
				cnt++;
			}
		}
		while(cnt>0){
			tot*=cnt;
			tot%=1000000007;
			cnt--;
		}
		printf("%d\n",tot);
	}
	return 0;
}