#include<vector>
#include<cstdio>
using namespace std;
int main(){
	//freopen("C.in","r",stdin);
	int T;scanf("%d",&T);
	for(int tc=1;tc<=T;tc++){
		int C,D,V; scanf("%d%d%d",&C,&D,&V);
		vector<int> have(D);
		for(int i=0;i<D;i++)scanf("%d",&have[i]);
		for(int v=1;v<=V;v++){
			bool ok=false;
			for(int msk=0;msk<(1<<((int)have.size()));msk++){
				int s=0;for(int i=0;i<(int)have.size();i++)if(msk&(1<<i))s+=have[i];
				if(s==v)ok=true;
			}
			if(!ok)have.push_back(v);
		}
		printf("Case #%d: %d\n",tc,(int)have.size()-D);
	}
}
