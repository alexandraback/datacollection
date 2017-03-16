#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

#define maxm 16

int in[maxm],st,end,ar[maxm],a[maxm],flag[maxm];
map<int,int>mn;
//bool fl1[2000100];
int cal(int n);
int main(){

	int i,j,k,l,test,t=1;

	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&st,&end);
		int ans=0;
		for(i=st;i<end;i++){
			ans+=cal(i);
		}
		printf("Case #%d: %d\n",t++,ans);

	}


	return 0;
}

int cal(int n){

	int i,j,k,l;
	if(n<10) return 0;

	for(i=0;i<=8;i++){
		a[i]=0;
	}
	l=n;
	k=0;
	while(n){
		a[k++]=n%10;
		n/=10;
	}
	memset(flag,0,sizeof(flag));
	int ret=0,num,fl;
	mn.clear();
	//memset(fl1,0,sizeof(fl1));

	for(i=k-1;i>=0;i--){
		num=0;
		fl=0;
		for(j=i;j>=0;j--){
			if(num==0&&a[j]==0){
				fl=1;
				break;
			}
			num*=10; num+=a[j];
		}
		if(fl) continue;
		for(j=k-1;j>i;j--){
			if(num==0&&a[j]==0){
				fl=1;
				break;
			}
			num*=10; num+=a[j];
		}
		if(fl) continue;
		if(num>l&&num<=end){
	//		if(fl1[num]) continue;
		//	fl1[num]=1;

		if(mn[num]) continue;
		mn[num]=1;
		//	printf("%d %d\n",l,num);
			ret++;
		}

	}
	return ret;

}

