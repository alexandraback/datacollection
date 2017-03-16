#include <bits/stdc++.h>
using namespace std;
int L, X;
 
typedef long long ll;
map<pair<int,int>,int> mp;
int cal(int i,int j, int k){
	int res = mp[{i,j}];
	bool neg;
	if (res<0) neg = 1,res = -res;
	else neg = 0;
	int res2 = mp[{res,k}];
	if (neg) res2 = -res2;
	return res2;
}
int main() {
	 //freopen("input1.txt","r",stdin);
    freopen("C-small-attempt4.in","r",stdin);
   //freopen("A-large.in","r",stdin);
    freopen("output1.txt","w",stdout);
	int t;
	cin>>t;
	
	mp[{2,2}] = -1;
	mp[{3,3}] = -1;
	mp[{5,5}] = -1;
	mp[{1,2}] = 2;
	mp[{1,3}] = 3;
	mp[{1,5}] = 5;
	mp[{2,1}] = 2;
	mp[{3,1}] = 3;
	mp[{5,1}] = 5;
	mp[{1,1}] = 1;
	mp[{2,3}] = 5;
	mp[{3,5}] = 2;
	mp[{5,2}] = 3;
	mp[{3,2}] = -mp[{2,3}];
	mp[{5,3}] = -mp[{3,5}];
	mp[{2,5}] = -mp[{5,2}];
	for(int ti=1;ti<=t;ti++){
		cout << "Case #" << ti << ": ";
		cin>>L>>X;
		string s;
		cin>>s;
		if (L*X<3){
			cout << "NO\n";
			continue;
		}
		vector<int> v;
		for(int j=0;j<X;j++){
			for(int i=0;i<L;i++){
				if (s[i]=='i') v.push_back(2);
				else if (s[i]=='j') v.push_back(3);
				else if (s[i]=='k') v.push_back(5);
			}
		}
		int fi[10001],fk[10001];
		fi[0] = v[0];
		fi[1] = mp[{v[0],v[1]}];
		for(int i=2;i<v.size();i++){
			if (fi[i-1]>0 && v[i]>0) fi[i] = mp[{fi[i-1],v[i]}];
			else if (fi[i-1]<0 && v[i]<0) fi[i] = mp[{-fi[i-1],-v[i]}];
			else if (fi[i-1]<0) fi[i] = -mp[{-fi[i-1],v[i]}];
			else fi[i] = -mp[{fi[i-1],-v[i]}];
		}
		fk[L*X-1] = v[L*X-1];
		fk[L*X-2] = mp[{v[L*X-2],v[L*X-1]}];
		for(int i=L*X-3;i>=0;i--){
			if (v[i]>0 && fk[i+1]>0) fk[i] = mp[{v[i],fk[i+1]}];
			else if (v[i]<0 && fk[i+1]<0) fk[i] = mp[{-v[i],-fk[i+1]}];
			else if (v[i]<0) fk[i] = -mp[{-v[i],fk[i+1]}];
			else fk[i] = -mp[{v[i],-fk[i+1]}];
		}
		/*for(int i=0;i<L*X;i++) cout << fi[i] << " ";
		cout << endl;
		for(int i=0;i<L*X;i++) cout << fk[i] << " ";
		cout << endl;*/
		bool ok = false;
		int ii = 0, kk = L*X-1;
		while (kk>=0 && fk[kk]!=5)
				kk--;
		if (kk<=1){
			cout << "NO\n";
			continue;
		}
		while (ii<L*X){
			if (fi[ii]!=2){
				ii++;
				continue;
			}
			/*if (fk[kk]!=5){
				kk--;
				continue;
			}*/
			//cout << ii << ", " << kk << endl;
			if (ii>=L*X-2) break;
			int tmp = v[ii+1];
			if (tmp==3 && ii+2<L*X && fk[ii+2]==5){
				ok = true;
				break;
			}
			for(int i=ii+2;i<kk;i++){
				if (tmp>0) tmp = mp[{tmp,v[i]}];
				else tmp = -mp[{-tmp,v[i]}];
				if (tmp==3 && i+1<L*X && fk[i+1]==5){
					ok = true;
					break;
				}
			}
			if (ok) break;
			/*if (tmp==3){
				ok = true;
				break;
			}*/
			
			ii++;
			
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
}