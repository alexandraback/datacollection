#include <iostream>
#include <cstring>
using namespace std;


int TTT,n,m;
int sco[1000010],co,st[1000010],lastloc;
char s[1000010];
long long ans;

int cono(char x){
	if (x=='a') return 0;
	if (x=='e') return 0;
	if (x=='i') return 0;
	if (x=='o') return 0;
	if (x=='u') return 0;
	return 1;
}


int main(){
	//freopen("A.in","r",stdin);
	freopen("A-large.in","r",stdin);
	
	freopen("A.out","w",stdout);
	
	scanf("%d",&TTT);
	for (int TT=1; TT<=TTT; TT++){
		printf("Case #%d: ",TT);
		scanf("%s%d",&s,&n);
		
		m = strlen(s);
		for (int i=0; i<m; i++){
			int co = cono(s[i]);
			if (i>0)
				sco[i]= sco[i-1]+co;
			else sco[i]=co;
		}
		
		st[0]=(sco[n-1]>=n);
		for (int i=1; i<m-n+1; i++){
			st[i]=(sco[i+n-1]-sco[i-1]>=n);
		}
		
		//for (int i=0; i<m; i++) printf("%d ",st[i]);
		//printf("\n");
		
		ans = 0;
		int lastloc = -1;
		for (int i=n-1; i<m; i++){
			if (st[i-n+1]) lastloc=i-n+1;
			ans = ans + lastloc+1;
		}
		
		cout << ans<<endl;
		if (ans<0) while(true);
	}
	
	fclose(stdout);
	fclose(stdin);
}
