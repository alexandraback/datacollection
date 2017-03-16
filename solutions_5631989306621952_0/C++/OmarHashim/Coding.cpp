#include<bits/stdc++.h>
using namespace std;

#define scl(x) scanf("%lld",&x)
#define sc(x)  scanf("%d",&x)
#define ll long long
#define lop(i,n) for(int i=0;i<n;++i)
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

int t;
string x,out;
int main(){
#ifndef ONLINE_JUDGE
	freopen("i.txt","r",stdin);
	freopen("o.txt","w",stdout);
#endif
	sc(t);
	lop(C,t){
		cin>>x;
		out="";
		lop(i,x.size()){
			if(!i)out.push_back(x[i]);
			else {
				if(x[i]>=out[0]){
					out=string(1,x[i])+out;
				}
				else {
					out.push_back(x[i]);
				}
			}
		}
		cout<<"Case #"<<C+1<<": ";
		cout<<out<<endl;
	}
}
