#include<iostream>
#include<map>
#include<math.h>
#include<vector>
#include<string>
#include<string.h>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<sstream>
#define all(X) (X).begin(),(X).end()
#define mem(X) memset(X,0,sizeof(X))
#define debug_v(v) for(int db=0;db<(v).size();db++)cout<<v[db]<<','<<;cout<<endl;
#define pqpush(pq,x,cmp) (pq).push_back(x);push_heap((pq).begin(),(pq).end(),cmp);
#define pqpop(pq,cmp) pop_heap((pq).begin(),(pq).end(),cmp);(pq).pop_back();
#define PB(x) push_back(x)
using namespace std;
typedef long long ll;
typedef vector<int>::iterator iv;
typedef map<string,int>::iterator msii;
typedef map<int,int>::iterator miii;
typedef map<int,bool>::iterator mibi;
typedef map<string,bool>::iterator msbi;
typedef map<string,int> msi;
typedef map<int,int> mii;
typedef map<int,bool> mib;
typedef map<string,bool> msb;
typedef vector<int> vi;
typedef vector<string> vs;

int t,cc;

unsigned long long r,tt;

unsigned long long cal(unsigned long long k){
	if(k==0)return 0;
	return 2*k*(r-1)+2*(k)*(k+1)-k;
}

int main(){
	
	freopen("A-large (1).in","r",stdin);
	freopen("a_ans_large.txt","w",stdout);
	
	scanf("%d",&t);
	while(t--){
		cin>>r>>tt;
		unsigned long long upper = min(sqrt(tt), (r==1?1e30:(tt/(2*r-2)))), lower = 0;
		
		while(upper>lower){
			//cout<<upper<<' '<<lower<<endl;
			unsigned long long mid = (upper+lower)/2;
			//cout<<mid<<' '<<cal(mid)<<" tt"<<tt<<endl;
			if(cal(mid)<=tt)
			{
				//cout<<"go\n";
				lower = mid+1;
			}
			else
				upper = mid;
		}
		
		while(cal(lower)>tt)lower --;
		
		printf("Case #%d: ",++cc);
		cout<<lower<<endl;
	}
}
