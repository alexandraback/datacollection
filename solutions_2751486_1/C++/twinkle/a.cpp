#include <iostream>
using namespace std;

int fynow,lastfynum,ans,len,Case,T,m;
char str[1101111];

bool yy(char x){
	if(x == 'a')return 1;
	if(x == 'e')return 1;
	if(x == 'i')return 1;
	if(x == 'o')return 1;
	if(x == 'u')return 1;
	return 0;
}


int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	scanf("%d",&T);
	for(int Case = 1; Case <= T ;Case ++){
		scanf("%s %d",&str,&m);
		len = strlen(str);
		fynow = 0;
		lastfynum = 0;
		ans = 0;
		for(int i = 0; i < len ; i ++){
		//	printf("%d %d %d %d\n",fynow,lastfynum,i,ans);
			if(yy(str[i])){
				ans += lastfynum;
				fynow = 0;
			}
			else{
				fynow ++;
				if(fynow >= m){
					ans += (i - m + 2); 
					lastfynum = i - m + 2;
				}
				else{
					ans += lastfynum;
				}
			}	
		}
		printf("Case #%d: %d\n",Case,ans);
	}
	return 0;
}
