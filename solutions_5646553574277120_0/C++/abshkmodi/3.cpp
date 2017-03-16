#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector< PII > VPII;
typedef map<int,int> MII;
typedef set<int> SI;
typedef map<string, int> MSI;
typedef vector<bool> VB;
typedef long double LD;

#define pb push_back
#define mp make_pair
#define for_each(s,v) for(typeof((v).begin()) s=(v).begin(); s!=(v).end(); s++)
const double eps=1e-11;

int main(){
	
	int t;
	cin>>t;
	
	for(int o=1;o<=t;o++){
		
		int ans=0,incomplete=22;
		int c,d,v,a[20];

		SI sums;

		cin>>c>>d>>v;

		MII cnt;
		MII used;

		used.clear();

		for(int i=0;i<d;i++){
			cin>>a[i];
			used[a[i]]=1;
		}

		while(incomplete){
		incomplete=0;
		sums.clear();
		cnt.clear();
		int upp=1<<d;

		for(int i=1;i<=upp;i++){

			int temp=i;
			int cursum=0;
			for(int j=1;j<=d;j++){
				int last=temp&1;

				if(last)
					cursum+=a[j-1];
				temp=temp>>1;
			}

			sums.insert(cursum);
		}

		for(int i=1;i<=v;i++){
			if(sums.find(i)==sums.end()){
				for_each(s,sums){
					if(*s<i){
						cnt[i-*s]++;
						incomplete++;
					}
				}
			}
		}

		int max=-1,maxcnt=0;
		for_each(s,cnt){
			if(s->second>maxcnt && !used[s->first]){
				max=s->first;
				maxcnt=s->second;
			}
		}

		if(max!=-1){
		//cout<<o<<" val "<<max<<endl;
		used[max]=1;
		incomplete-=cnt[max];
		ans++;
		a[d++]=max;
	}
		}

		cout<<"Case #"<<o<<": "<<ans<<endl;
		
	}
	
	return 0;
} 

