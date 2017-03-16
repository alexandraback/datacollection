#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
vector<int> p;
int k,n;
vector<int> s,key;
vector<vector<int> > d;

int f(int u){
	if(p[u]!=-7) return p[u];
	p[u]=-1;
	map<int,int> m;
	for(int i=0;i<k;i++)
		m[s[i]]++;
	for(int i=0;i<n;i++)
		if(u&(1<<i)){
			m[key[i]]--;
			for(int j=0;j<d[i].size();j++)
				m[d[i][j]]++;
		}

	for(int i=0;i<n;i++)
		if(u&(1<<i))
			continue;
		else{
			if(m[key[i]]>0){
				int newpoint=u+(1<<i);
				int ver=f(newpoint);
				if(ver>=0){
					p[u]=i;
					break;
				}
			}

		}
	return p[u];
}
int main(){
	//freopen("1.txt","r",stdin);
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-out.txt","w",stdout);
	//freopen("D-large.in","r",stdin);
	//freopen("D-large-out.txt","w",stdout);
	int T=0;
	cin>>T;
	for(int at=0;at<T;at++){
		printf("Case #%d: ",at+1);
		cin>>k>>n;	
		s.resize(k);
		key.resize(n);
		d.resize(n);
		for(int i=0;i<k;i++)
			cin>>s[i];
		for(int i=0;i<n;i++){
			int a;
			cin>>key[i]>>a;
			d[i].resize(a);
			for(int j=0;j<a;j++)
				cin>>d[i][j];
		}
		p.resize((1<<n));
		for(int i=0;i<(1<<n);i++)
			p[i]=-7;
		p[(1<<n)-1]=1111;

		int t=f(0);

		if(t==-1)
			printf("IMPOSSIBLE");
		else{
			int pos=0;
			while(t!=1111){
				printf("%d",t+1);
				pos=pos+(1<<t);
				t=f(pos);
				if(t!=1111)
					printf(" ");
			}
		}
		printf("\n");
	}
}