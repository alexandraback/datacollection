#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

class C{
public:
	int m, ind;
	C(int a, int b):m(a),ind(b){}
	C(){}
	bool operator<(const C &c)const{
		return m > c.m;
	}
};

class CC{
public:
	int m, ind;
	CC(int a, int b):m(a),ind(b){}
	CC(){}
	bool operator<(const CC &c)const{
		return m < c.m;
	}
};

bool mk[1100];
int bs[1100];
priority_queue< C > heap1;
priority_queue< C > heap2;
priority_queue< CC > ums;
priority_queue< C > heap12;

int main(){
	int casos, n, a, b;
	scanf("%d",&casos);
	for(int u=1; u<=casos; u++){
		scanf("%d",&n);
		memset(mk,false,sizeof(mk));
		while(!heap1.empty()) heap1.pop();
		while(!heap2.empty()) heap2.pop();
		while(!heap12.empty()) heap12.pop();
		while(!ums.empty()) ums.pop();
		
		for(int i=0; i<n;i++){
			scanf("%d %d",&a,&b);
			heap1.push(C(a,i));
			heap2.push(C(b,i));
			bs[i] = b;
		}
		
		int tot = 0, ta = -1;
		int resp = 0;
		while(ta != tot){
			ta = tot;
			int respa = -1;
			while(resp != respa){
				respa = resp;
				while(!heap12.empty() && tot >= heap12.top().m){
					heap12.pop();
					tot++;
					resp++;
					//printf("12\n");
				}
				while(!heap2.empty() && tot >= heap2.top().m){
					if(!mk[heap2.top().ind]){
						tot+=2;
						resp++;
						mk[heap2.top().ind] = true;
						//printf("2\n");
					}
					heap2.pop();
				}
			}
			/*
			if(!heap1.empty() && tot >= heap1.top().m){
				if(!mk[heap1.top().ind]){
					tot++;
					mk[heap1.top().ind] = true;
					heap12.push(C(bs[heap1.top().ind],heap1.top().ind));				
					resp++;
					//printf("1\n");
				}
				heap1.pop();				
			}
			*/
			while(!heap1.empty() && tot >= heap1.top().m){
				ums.push(CC(bs[heap1.top().ind],heap1.top().ind));
				heap1.pop();
			}
			while(!ums.empty() && mk[ums.top().ind]) ums.pop();
			if(!ums.empty()){
				tot++;
				mk[ums.top().ind] = true;
				heap12.push(C(bs[ums.top().ind],ums.top().ind));				
				resp++;
				//printf("1\n");
				ums.pop();				
			}
		}
		if(tot == 2*n) printf("Case #%d: %d\n",u,resp);
		else printf("Case #%d: Too Bad\n",u);
	}
	
	return 0;
}
