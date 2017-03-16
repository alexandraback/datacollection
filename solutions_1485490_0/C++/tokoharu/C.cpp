#include <algorithm>
#include <cmath>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define MP make_pair

typedef long long LL;
typedef pair<LL,LL> PII;

LL intersect(LL x,LL y,LL z,LL w) {
	y+=x;
	w+=z;
	x = max(x,z);
	y = min(y,w);
	if(x<y) return y-x;
	return 0;
	
}

LL minL(LL a,LL b) {
	if(a<b) return a;
	return b;
}

int main() {
	int t;
	int T;
	cin>>t;
	T=t;
	for(;t;t--) {
		
		int n,m;
		cin>>n>>m;
		vector<PII>tmp,box;
		vector<LL>data[2];
		LL sum = 0;
		data[0].push_back(0);
		data[1].push_back(0);
		for(int a=0; a<n; a++) {
			LL x,y;
			cin>>x>>y;
			
			tmp.push_back(MP(x,y));
			sum += x;
			data[0].push_back(sum);
		}
		
		if(n>2 && tmp[0].second ==tmp[1].second && tmp[0].second==tmp[2].second) {
			tmp[0].first += tmp[1].first + tmp[2].first;
	//		cout<<"hoge"<<endl;
			box.push_back(tmp[0]);
		}
		else if(n>1 && tmp[0].second==tmp[1].second ) {
			tmp[0].first += tmp[1].first;
			box.push_back(tmp[0]),box.push_back(tmp[2]);
		}
		else if(n>2 && tmp[1].second==tmp[2].second)  {
			tmp[2].first += tmp[0].first;
			box.push_back(tmp[0]),box.push_back(tmp[2]);
		}
		else box.push_back(tmp[0]) , box.push_back(tmp[1]) , box.push_back(tmp[2]);
		
	//	cout<<box.size()<<endl;
		
		sum = 0;
		vector<PII>toy;
		for(int a=0; a<m; a++) {
			LL x,y;
			cin>>x>>y;
			sum += x;
			toy.push_back(MP(x,y));
			data[1].push_back(sum);
		}
		/*
		LL ret = 0;
		for(int i=0; i<n+1; i++) for(int j=0; j<m+1; j++) {
			LL init = data[0][i]-data[1][j];
			
			LL iteX = 0;
			LL iteY = 0;
			
			LL posX = 0;
			LL posY = init;
			 
			LL ans  = 0;
			
			while(iteX<n && iteY<m) {
				cout<<"   "<<posX<<" "<<posY<<"    "<<iteX<<" "<<iteY<<"   "<<ans<<endl;
				if(toy[iteY].second == box[iteX].second) {
					ans += intersect(posX,box[iteX].first,posY,toy[iteY].first);
					
				}
//				if(iteX==n-1 && iteY==m-1) break;
				
				if(posX>posY ) {
					posY += toy[iteY].first;
					iteY++;
				}
				else {
					posX += box[iteX].first;
					iteX++;
				}
			}
			cout<<ans<<endl;
			if(ret<ans) ret = ans;
		}
		
		
		*/
		
		LL ret = 0;
		for(int z=0; z<2; z++) {
		if(z==1 && box.size()==3 && box[0].second==box[2].second) {
			PII hoge = box[0];
			hoge.first += box[2].first;
			
			box.clear();
			box.push_back(hoge);
		}
		else if(z==0);
		else break; 
//		if(z==1) cout<<box.size()<<" "<<box[0].first<<" "<<box[0].second<<endl; 
		for(int i=0; i<=m; i++) for(int j=i; j<=m; j++) {
//			cout<<i<<" "<<j<<endl;
			LL ans = 0;
			LL counting = 0;
			for(int k = 0; k<i; k++) {
				if(box[0].second==toy[k].second) counting += toy[k].first;
			}
			ans += minL(counting,box[0].first);
			counting = 0;
			
			if(1<box.size())for(int k=i; k<j; k++) 
				if(box[1].second==toy[k].second) counting += toy[k].first;
			ans += minL(counting,box[1].first);
			counting = 0;
			
			
			if(2<box.size())for(int k=j; k<m; k++) 
				if(box[2].second==toy[k].second) counting += toy[k].first;
			
			ans += minL(counting,box[2].first);
			counting = 0;
			
			if(ret<ans) ret = ans;
			
		}
		
		}
		 cout<<"Case #"<<T-t+1<<": "<<ret<<endl;
		
	}
	return 0;
	
}



