#include <bits/stdc++.h>
using namespace std;

map<long long,long long> g;

long long n;

long long work(long long x){
	long long ans = 0;
	while (x){
		ans=ans*10+x%10;
		x/=10;
	}
	return ans;
}

long long q[16],qq[16],b[16];
//={1,10,29,138,337,1436};

int main(){
	int T;
	scanf("%d",&T);
	q[1]=1;q[2]=10;q[3]=29;
	long long t=1;
	qq[0]=1;
	for (int i=1;i<=15;i++) qq[i]=qq[i-1]*10;
	for (int i=4;i<=15;i++){
		int di = (i-1)/2;
		q[i]=q[i-1]+qq[di]+qq[i-1-di]-1;
	//	t*=10;
	//	cout << q[i]<<endl;
	}
//	return 0;
	for (int ti=1;ti<=T;ti++){
		scanf("%lld",&n);
		printf("Case #%d: ",ti);

		long long p = n;
		long long ans;
		if (n>1000){
		ans=0;
		if (n%100==0){
			p--;
			ans++;	
		}
		int num=0;
		while (p){
			num++;
			b[num]=p%10;
			p/=10;
		}
		int bo=0;
		if (b[num]>1){
			ans+=b[num]-1;
			b[num]=1;
			bo=1;
		}
		ans+=q[num];
		//cout << ans<<"!"<<endl;
		for (int i=1;i<num;i++){
			int tp=i-1;
			if (num-i<tp && b[i]) {tp=num-i;bo=1;}
			ans+=qq[tp]*b[i];
		}
		ans+=bo;
		
	//	cout << ans<<endl;
		}
		else{
		g.clear();
		g[1]=1;
		queue<long long> q;
		q.push(1);
		while (!q.empty()){
			long long now = q.front();
						q.pop();
			if (now==n) break;
			if (g.find(now+1)==g.end()){
				g[now+1]=g[now]+1;
				q.push(now+1);
			}
			long long re = work(now);
			if (g.find(re)==g.end()){
				g[re]=g[now]+1;
				q.push(re);
			}
		//	cout << now<<" "<<re<<endl;

		}
	//	if (ans!=g[n]) cout<<n<<" "<<ans<<" "<<g[n]<<endl;
		ans=g[n];
	}
		printf("%lld\n",ans);
	}
	return 0;
}

