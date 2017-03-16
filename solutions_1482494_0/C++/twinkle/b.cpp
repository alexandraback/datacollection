#include <iostream>
using namespace std;

double mymin(double a,double b){
	if(a<b)return a;
	return b;
}

struct rec{
	int i,a,b;
}da[1100],db[1100];

int cmp1(const void *a,const void *b){
	rec t1,t2;
	t1 = *(rec *)a;
	t2 = *(rec *)b;
	if(t1.a < t2.a)return -1;
	if(t1.a > t2.a)return 1;
	if(t1.b < t2.b)return 1;
	if(t1.b > t2.b)return -1;
	return 0;
}
int cmp2(const void *a,const void *b){
	rec t1,t2;
	t1 = *(rec *)a;
	t2 = *(rec *)b;	
	if(t1.b < t2.b)return -1;
	if(t1.b > t2.b)return 1;
	if(t1.a < t2.a)return 1;
	if(t1.a > t2.a)return -1;
	return 0;
}

int used[5555];

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int T,n;
	cin >> T;
	for(int Case = 1; Case <= T ;Case ++){
		cin >> n;
		for(int i = 1;i <= n; i ++){
			cin >> da[i].a >> da[i].b;
			da[i].i = i;
			db[i] = da[i];
		}
		qsort(&da[1],n,sizeof(rec),cmp1);
		qsort(&db[1],n,sizeof(rec),cmp2);
		int pb = 1,pa = 1;
		int star = 0,ans = 0;
		memset(used,0,sizeof(used));
		while(pb <= n){
			ans ++;
			if(star >= db[pb].b){
				star = star + 2 - used[db[pb].i];
				pb ++;
				continue;
			}
			if(star >= da[pa].a){
				star ++;
				used[da[pa].i] = 1;
				pa ++;
				continue;
			}
			break;
		}
		if(pb <= n)
			printf("Case #%d: Too Bad\n",Case);
		else
			printf("Case #%d: %d\n",Case,ans);
	}
	
	
	return 0;
}
