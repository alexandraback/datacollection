#include<bits/stdc++.h>
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
using namespace std;

typedef long long ll;
const ll N = 1001000 , INF = 1e9;

int t,c,d,v,tab[70],tab1[70],a;

bool czek(){
	tab1[0]=1;
	for(int i=1;i<=v;i++) tab1[i]=0;
	for(int i=1;i<=v;i++){
		if(tab[i]==1){
			for(int j=v;j>=0;j--)
			if(tab1[j]==1) tab1[j+i]=1;
		}
	}
	//for(int i=1;i<=v;i++) cout<<tab[i]<<" "<<tab1[i]<<"\n";
	//cout<<"\n\n\n";
	for(int i=1;i<=v;i++) if(tab1[i]==0) return 0;
	return 1;
}

bool f(int liczba,int gdzie){
	//cout<<liczba<<" "<<gdzie<<"\n";
	//for(int i=0;i<=v;i++) cout<<tab[i]<<" ";
	//cout<<"\n";
	if(liczba==0 || gdzie==v+1){
		return czek();
	}
	if(f(liczba,gdzie+1)) return 1;
	if(tab[gdzie]==0){
		tab[gdzie]=1;
		if(f(liczba-1,gdzie+1)) return 1;
		tab[gdzie]=0;
	}
	return 0;
}

int main(){
	cin>>t;
	for(int test=1;test<=t;test++){
		cin>>c>>d>>v;
		for(int i=0;i<=v;i++) tab[i]=0;
		for(int i=0;i<d;i++){
			cin>>a;
			tab[a]=1;
		}
		for(int i=0;i<v;i++){
			if(f(i,1)){
				cout<<"Case #"<<test<<": "<<i<<"\n";
				break;
			}
		}
	}
}
