#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int A,n;
int mote[100];

int process(){
	int i,j;
	int ans,addc,rmvc;
	long long mysize;
	vector<int> motes;

	sort(mote,mote+n);

	for(ans=0;;ans++){
		for(addc=0;addc<=ans;addc++){
			rmvc=ans-addc;
			motes.clear();
			for(i=n-rmvc-1;i>-1;i--) motes.push_back(mote[i]);
			mysize=A;
			for(i=0;i<=addc;i++){
				while(motes.size()>0){
					if((long long)motes[motes.size()-1]<mysize){
						mysize+=(long long)motes[motes.size()-1];
						motes.pop_back();
					}
					else break;
				}
				if(motes.size()==0) break;
				mysize+=mysize-1LL;
			}
			if(i<=addc){
				return ans;
			}
		}
	}
	return 0;
}

int main(){
	int i,t,tc;
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	for(tc=1;tc<=t;tc++){
		printf("Case #%d: ",tc);
		scanf("%d%d",&A,&n);
		for(i=0;i<n;i++) scanf("%d",&mote[i]);
		int res=process();
		printf("%d\n",res);
	}
	return 0;
}