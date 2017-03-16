#include<iostream>
#include<vector>
using namespace std;

typedef pair<int,int> pii;

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		int n;
		cin>>n;
		vector<pii> in;
		for(int i=0;i<n;i++) {
			int a,b;
			cin>>a>>b;
			in.push_back(pii(a,b));		
		}
		int curstar = 0;
		vector<int> mark(n,0);
		int ans = 0;
		while(curstar<2*n) {
			int flag = 0;
			for(int i=0;i<n;i++)
				if(mark[i]!=2 && in[i].second<=curstar) {
					curstar+=2-mark[i];
					mark[i]=2;
					ans++;
					flag=1;
				}
			if(flag)
				continue;
			int best = -1;
			for(int i=0;i<n;i++)
				if(!mark[i] && in[i].first<=curstar) {
					if(best==-1 || in[best].second<in[i].second)
						best = i;
				}
			if(best==-1)
				break;
			ans++;
			mark[best]=1;
			curstar++;
		}
		cout<<"Case #"<<tn+1<<": ";
		if(curstar<2*n)
			cout<<"Too Bad"<<endl;
		else
			cout<<ans<<endl;
	}
}
