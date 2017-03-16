#include <stdio.h>
#include <algorithm>
using namespace std;
int mul_sim[4][4] = { 0,1,2,3,1,4,3,6,2,7,4,1,3,2,5,4};
int mul[8][8];
int atl,atx;
int x,l;
int a[10005];
int mark[10];
int co,total,t;
char s[10005];
int pow(int h1,int h2) {
	if(h2==0) return 0;
	int temp = pow(h1,h2/2);
	temp = mul[temp][temp];
	if(h2&1) temp = mul[temp][h1];
	return temp;
}
int find(int startl,int startx,int lookfor) {
	atl=-1;
	atx=-1;
	int now = 0;
	int end;
	if(startx+1==x) {
		end = l;
	}
	else {
		end = startl+l;
	}
	for(int ii=startl;ii<end;ii++) {
		int i=ii;
		if(ii>=l) {
			i=ii-l;
		}
		co++;
		now = mul[now][a[i]];
		int now_it = startx;
		int now_val = now;
		while(now_it!=x && mark[now_val]!=co) {
			if(now_val==lookfor) {
				if(atl==-1) {
					atl = i;
					atx = now_it;
				}
				else {
					if(now_it<atx || (now_it==atx && i<atl)) {
						atx = now_it;
						atl = i;
					}
				}
				break;
			}
			mark[now_val]=co;
			now_val = mul[now_val][total];
			now_it++;
		}
	}
	if(atl!=-1) return 1;
	return 0;
}
int main(int argc, char *argv[])
{
	for(int i=0;i<8;i++) {
		for(int j=0;j<8;j++) {
			int neg=0;
			int ii=i;
			int jj=j;
			if(ii>3) {
				ii-=4;
				neg^=1;
			}
			if(jj>3) {
				jj-=4;
				neg^=1;
			}
			mul[i][j] = mul_sim[ii][jj];
			if(neg) {
				if(mul[i][j]>3) {
					mul[i][j]-=4;
				}
				else {
					mul[i][j]+=4;
				}
			}
		}
	}
	scanf("%d",&t);
	for(int r=1;r<=t;r++) {
printf("Case #%d: ",r);
		scanf("%d %d",&l,&x);
		scanf("%s",s);
		for(int i=0;i<l;i++) {
			if(s[i]=='i') a[i]=1;
			else if(s[i]=='j') a[i]=2;
			else if(s[i]=='k') a[i]=3;
		}
		int now=0;
		for(int i=0;i<l;i++) {
			now = mul[now][a[i]];
		}
		total = now;
		if(pow(now,x)!=mul[mul[1][2]][3]) {
			printf("NO\n");
		}
		else {
			if(!find(0,0,1)) {
				printf("NO\n");
			}
			else {
				atl++;
				if(atl==l) {
					atl=0;
					atx++;
				}
				if(find(atl,atx,2)) {
					printf("YES\n");
				}
				else {
					printf("NO\n");
				}
			}
		}
	}
	return 0;
}
