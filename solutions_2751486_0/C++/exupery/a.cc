#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int a[26]={1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0};
	int T, s, nv, len;
	scanf("%d",&T);
	for (int i=1; i<=T; i++) {
		char name[111] = "";
		s=0;
		scanf("%s%d", name, &nv);
		len = strlen(name);
		for(int j=0; j<=len-nv; j++){
			for(int kk=0; kk<len-j-nv+1; kk++) {
				int cnt=0,m=0;
				for(int k=j;k<len-kk;k++){
					if(!a[name[k]-'a']){
						cnt++;
					}
					else {
						cnt=0;
					}
					m=max(cnt,m);
				}
				if(m>=nv){
					s++;
				}
			}
		}
		printf("Case #%d: %d\n", i, s);
	}

	return 0;
}
