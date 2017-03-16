#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<set>
#include<vector>

using namespace std;

int X,Y;
char ans[1000];

void solve(){
	int i,j,k=0,p,jump;
	p = 0;
	jump = 1;
	for(i=0; p != X; i++,jump++) {
		if(!(i%2)) {
			p += jump;
			ans[k++] = 'E';
		} else {
			p -= jump;
			ans[k++] = 'W';
		}
	}

	p = 0;
	for(i=0; p != Y; i++,jump++) {
		//printf("%d %d\n",p,jump);
		if (Y < 0) {
			if(!(i%2)) {
				p += jump;
				ans[k++] = 'N';
			} else {
				p -= jump;
				ans[k++] = 'S';
			}
		} else {
		if(!(i%2)) {
			p -= jump;
			ans[k++] = 'S';
		} else {
			p += jump;
			ans[k++] = 'N';
		}
		}
	}

	ans[k] = '\0';

	printf("%s", ans);

}



int main(){
	int i,j,k,t;
    scanf("%d\n",&t);
    for(i=1;i<=t;i++){
    	scanf("%d%d",&X,&Y);
        printf("Case #%d: ",i);
        solve();
        printf("\n");
    }
}