#include <cstdio>
#include <map>
#include <string>
using std::map;
using std::pair;
using std::string;

string a[1086],b[1086];

int main(){
	int T;
	scanf("%d",&T);
	for(int Case = 1;Case<=T;Case++){
		int n;
		scanf("%d",&n);
		map<string,int> ma,mb;
		map<string,bool> ta,tb;
		bool done[1086];
		for(int i=0;i<n;i++){
			char sa[28],sb[28];
			scanf("%s%s",sa,sb);
			a[i].assign(sa);
			b[i].assign(sb);
			ma[a[i]]++;
			mb[b[i]]++;
			done[i] = false;
		}
		int ans = 0;
		for(int i=0;i<2*n;i++){
			for(int i=0;i<n;i++){
				if(done[i]) continue;
				if(ma[a[i]]==1||mb[b[i]]==1){
					ta[a[i]]=true;
					tb[b[i]]=true;
					done[i] = true;
				}
				if(ma[a[i]]>=2&&ta[a[i]]==true&&mb[b[i]]>=2&&tb[b[i]]==true){
					ma[a[i]]--;
					mb[b[i]]--;
					ans++;
					done[i] = true;
				}
			}
		}
		printf("Case #%d: %d\n",Case ,ans);
	}
}