#include <iostream>
using namespace std;

int f[2501000][3],T,n,d[30];

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	cin >> T;
	for(int Case = 1; Case <= T ; Case ++){
		cin >> n;
		memset(f,0,sizeof(f));
		for(int i = 1;i <= n; i ++)
			cin >> d[i];
		int yes = 0,k,ans;
		for(int i = 1;i <= n; i ++){
			for(int j = 2000000; j >= 1; j --){
				if(f[j][0] == 1){
					k = j + d[i];
					f[k][++f[k][0]] = j;
					if(f[k][0] == 2){
						yes = 1;
						ans = k;
						break;
					}
				}
			}
			if(yes)break;
			f[d[i]][++f[d[i]][0]] = 0;
			if(f[d[i]][0] == 2){
				yes = 1;
				ans = d[i];
				break;
			}
		}
		printf("Case #%d:\n",Case);
		int t;
		if(yes){
			t = ans;
			printf("%d",t-f[t][1]);
			t = f[t][1];
			while(t != 0){
				printf(" %d",t-f[t][1]);
				t = f[t][1];
			}
			printf("\n");
			t = ans;
			printf("%d",t-f[t][2]);
			t = f[t][2];
			while(t != 0){
				printf(" %d",t-f[t][1]);
				t = f[t][1];
			}
			printf("\n");
		}
		else
			printf("Impossible\n");
	}

	return 0;
}
