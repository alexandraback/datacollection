#include <bits/stdc++.h>
using namespace std;
template<class T>inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
#define ll long long
int main()
{
	freopen("in1.txt","r",stdin);
	freopen("out1.txt","w",stdout);
	ll int test,iter;
	scanf("%lld",&test);
	for(iter=1;iter<=test;iter++){
		ll int p=0,q=0;
		string s;
		cin>>s;
		ll int j = 0;
		while(s[j]!='/'){
			p=p*10+s[j]-48;
			j++;
		}
		j++;
		while(s[j]!='\0'){
			q=q*10+s[j]-48;
			j++;
		}
		ll int i = gcd(p,q);
		p = p / i;
		q = q / i;
		printf("Case #%lld: ",iter);
		ll int temp = q,cnt=0;
		while(temp>1){
			if(temp%2==0)
			temp=temp/2;
			else
			break;
			cnt++;
		}
		if(temp==1&&p<=q){
			//cout<<"enter\n";
			if(p==1)
			printf("%lld\n",cnt);
			else{
				bool flag = true;
				ll int ans = 0;
				while(1){
					if(p<0){
						flag = false;
						break;
					}
					else if(p==1||p==0)
					break;
				//cout<<p<<" "<<q<<endl;
					q=q/2;
					if(p>=q)
					p=p-q;
					ans++;
				}
				if(flag)
				printf("%lld\n",ans);
				else
				printf("impossible\n");
			}
		}
		else printf("impossible\n");
	}
	return 0;
}
