#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <set>
#include <map>
#include <sstream>
#include <bitset>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
ll G(ll a,ll b){if(b==0)return a;return G(b,a%b);}
int a[1111],b[1111][1111],ans;
bool mark[1111];
vector<int> v;
void f(int r){
	v.clear();
	while(!mark[r]){
		v.pb(r);
		mark[r]=1;
		r=a[r];
	}
	if(v.size()==0)return;
	if(a[v[v.size()-1]]==v[0]){
		ans=max(ans,(int)v.size());
	}
	if(a[v[v.size()-1]]==v[v.size()-2]){
		b[v[v.size()-1]][v[v.size()-2]]=max(b[v[v.size()-1]][v[v.size()-2]],(int)v.size());
	}
	for(int i=0;i<v.size();i++)mark[v[i]]=0;
}
int main(){
	ifstream fin("C-small-attempt3.in");
	ofstream fout("b.txt");
	int T;
	fin>>T;
	for(int t=1;t<=T;t++){
		memset(b,0,sizeof(b));
		memset(mark,0,sizeof(mark));
		ans=0;
		int n;
		fin>>n;
		for(int i=0;i<n;i++)fin>>a[i];
		for(int i=0;i<n;i++)a[i]--;
		for(int i=0;i<n;i++){
			f(i);
		}
		int tmp=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				tmp+=b[i][j];
				if(b[i][j])tmp--;
				//cout<<b[i][j]<<" ";
			}
			//cout<<endl;
		}
		//cout<<"_"<<ans<<" "<<tmp<<endl;
		fout<<"Case #"<<t<<": "<<max(ans,tmp)<<endl;
	}
}
