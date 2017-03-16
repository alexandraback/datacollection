#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>
#include<set>
#include<functional>
#include<algorithm>
#include<climits>


#define mod %
#define NUM 1000000007

typedef long long int ll;

using namespace std;

ll gcd(ll a,ll b){
	if(b == 0 or a == 0)
		return a+b;
	return gcd(b,a mod b);
}

ll balance(ll ans){
	if(ans >= NUM)
		return ans mod NUM;
	while(ans<0){
		ans+=NUM;
	}
	return ans;
}



void solve(){
	int c,d,v;
	cin>>c>>d>>v;
	int ar[d];
	int sum = 0;
	set<int> ss;
	for(int i=0;i<d;i++){
		cin>>ar[i];
		sum+=ar[i];
		if(ar[i]<=v)
		ss.insert(ar[i]);
	}
//	sort(ar,ar+d);
//	int k=0;
//	int cnt = 0;
//	for(int i=1;i<v;i++){
//		if(k<d && ar[k] == i){
//			k++;
//		}
//		else{
//			cnt++;
//		}
//	}
	if(sum<=v)
	ss.insert(sum);
//	for(int i = d-1;i>=0;i--){
//		cout<<"here";
//		for(int j=0;j+i<d;j++){
////			cout<<"#\n";
//			int sum = 0;
//			for(int k=j;k<=i+j;k++){
////				cout<<ar[k]<<"$ ";
//				sum+=ar[k];
//			}
//			cout<<sum;
//			ss.insert(sum);
//		}
//	}
//
	if(d==5){
		for(int i=0;i<d;i++){

			if(sum-ar[i]<=v)
			ss.insert(sum-ar[i]);
		}
	}
	for(int i=0;i<d;i++){
		for(int j=0;j<d;j++)
		{
			for(int k=0;k<d;k++){
				if(i==j || i==k || k==j)
					continue;
				if(ar[i]+ar[j]+ar[k]<=v)
				ss.insert(ar[i]+ar[j]+ar[k]);
			}
		}
	}
	for(int i=0;i<d;i++){
		for(int j=0;j<d;j++){
			if(i==j)
				continue;
			if(ar[i]+ar[j]<=v)
			ss.insert(ar[i]+ar[j]);
		}
	}


//	for(auto iq =ss.begin();iq!=ss.end();iq++)
//					cout<<(*iq)<<endl;

//				cout<<"------\n";


	set<int> qq;
	int cnt = 0;
	for(int i=1;i<=v;i++){
		if(ss.find(i) == ss.end())
		{
//			cout<<"%%%%"<<i<<"\n";
//			qq.insert(i);

			for(auto i1 =ss.rbegin();i1!=ss.rend();i1++){
				int x =(*i1);
				if(x+i<=v)
					ss.insert(x+i);
			}

			if(i<=v)
				ss.insert(i);
//			for(auto iq =ss.begin();iq!=ss.end();iq++)
//				cout<<(*iq)<<endl;

//			cout<<"------\n";
			cnt++;
		}
	}



	cout<<cnt;
}

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int TC;
	cin>>TC;
	for(int ZZ=1;ZZ<=TC;ZZ++){
		cout<<"Case #"<<ZZ<<": ";
		solve();
		cout<<endl;
	}
	return 0;
}
