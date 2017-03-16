#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;

struct event{
	int day, w, e;
	long long str;
	event(int a, int b, int c, long long d){
		day = a; w = b; e = c; str = d;
	}
	event(){}
};

bool operator<(event a, event b){
	return a.day<b.day;
}


int main(){
	int Z;
	scanf("%d",&Z);
	for(int z = 1; z <= Z; ++z){
		vector<event> atak;
		long long wall[10000];
		for(int i = 0; i<10000; ++i)wall[i]=0;
		int n;
		long long res = 0;
		scanf("%d",&n);
		for(int i = 0; i < n; ++i){
			int day1, num, w1,e1,  dd, de;
			long long s1, ds;
			scanf("%d %d %d %d %lld %d %d %lld",&day1, &num, &w1,&e1, &s1, &dd, &de,&ds);
			w1+=1000;
			e1+=999;
			for(int j = 0; j<num; ++j){
				atak.PB(event(day1,w1,e1,s1));
				day1+=dd;
				w1+=de;
				e1+=de;
				s1+=ds;
			}
		}
		sort(atak.begin(), atak.end());
		int last = -1;
		for(int i = 0; i < atak.size(); ++i){
	//		printf("atak: %d %d %d %lld\nwall: ", atak[i].day, atak[i].w, atak[i].e, atak[i].str);
	//		for(int j = atak[i].w; j<= atak[i].e; ++j)printf("%lld ",wall[j]);printf("\n");
			
			if(atak[i].day!=last){
	//			printf("updating\n");
				for(int k = i-1; k>=0 && atak[k].day==last; --k){
					for(int j = atak[k].w; j<=atak[k].e; ++j)
						wall[j]=max(wall[j],atak[k].str);
				}
			}
			for(int j = atak[i].w; j<= atak[i].e; ++j){
				if(wall[j]<atak[i].str){
					res++;
					break;
				}
			}
			last = atak[i].day;
		}
		printf("Case #%d: %lld\n",z,res);
		atak.clear();
	}
	return 0;
}
