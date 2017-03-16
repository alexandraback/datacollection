#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

const int MAX=1100000;
int m[MAX],m2[MAX];
void solve(){
	int A,N,t[100];
	cin>>A>>N;
//	cout<<"N="<<N<<endl;
	FOR(i,N)cin>>t[i];
	sort(t,t+N);
	for(int i=0;i<MAX;i++)m[i]=0;
	for(int i=N-1;i>=0;i--){
		FOR(j,MAX){
			m2[j]=m[j]+1;
			if(j>t[i]){
				m2[j]=min(m2[j],m[min(MAX-1,j+t[i])]);
			}else if(j>1){
				int cnt=0,cur=j;
				while(cur<=t[i]){
					cur+=cur-1;
					++cnt;
				}
//				cout<<"cnt="<<cnt<<endl;
				m2[j]=min(m2[j],m[min(MAX-1,cur+t[i])]+cnt);
			}
		}
//	  cout<<t[i]<<","<<m2[1]<<" "<<m2[2]<<" "<<m2[3]<<endl;
		FOR(j,MAX)m[j]=m2[j];
	}
	cout<<m[A]<<endl;
}

main(){
  int C;cin>>C;
  for(int c=1;c<=C;c++){ 
    cout<<"Case #"<<c<<": ";
		solve();
  }
}
