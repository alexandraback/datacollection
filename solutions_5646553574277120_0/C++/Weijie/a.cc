#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

int a[110];
bool f[100];

bool check(vector<int> a,int v){
//	printf("checking\n");
//	for(int i = 0;i < a.size();++i)
//		printf("%d ",a[i]);
//	printf("\n");
	memset(f,false,sizeof(f));
	f[0] = true;
	for(int i = 0;i < a.size();++i)
		for(int j = 30;j >= 0;--j){
			f[j + a[i]] |= f[j];
		}
	for(int i = 1;i <= v;++i)
		if(f[i] == false)
			return false;
//	for(int i = 0;i < 20;++i)
//		printf("%d: %d\n",i,f[i]);
	return true;
}

int solve(int c,int d,int v){
	vector<int> m;
	set<int> exist;
	for(int i = 1;i <= d;++i){
		m.push_back(a[i]);
		exist.insert(a[i]);
	}
	int now = 0;
	int ret = 0;
	while(now < v){
		if(check(m,v))
			break;
	//	printf("%d\n",now);
		int sum = 0;
		for(int i = 0;i < m.size();++i)
			if(m[i] <= now)
				sum += m[i];
	//	printf("sum %d\n",sum);
		if(exist.find(sum + 1) == exist.end()){
//			printf("add %d\n",sum + 1);
			m.push_back(sum + 1);
			now = sum + sum + 1;
			exist.insert(sum + 1);
			++ret;
		}else{
			now = sum + sum + 1; 
		}
	//	printf("after %d\n",now);
	}
	return ret;
}

int main(){
	int T;
    scanf("%d",&T);
    for(int cas = 1;cas <= T;++cas){
		int c,d,v;
		scanf("%d%d%d",&c,&d,&v);
		for(int i = 1;i <= d;++i)
			scanf("%d",&a[i]);
        printf("Case #%d: %d\n",cas,solve(c,d,v));
    }
    
    return 0;
}
