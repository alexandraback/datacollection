#include<bits/stdc++.h>
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
using namespace std;

typedef long long ll;
const ll N = 1001000 , INF = 1e9;

int t,k,l,s;
string keys,word,slowo;
int liczbaslow,liczba,maks;

void czek(){
	liczbaslow++;
	int ile=0;
	for(int i=0;i<=s-l;i++){
		for(int j=0;j<l;j++){
			if(slowo[i+j]!=word[j]){
				ile--;
				break;
			}
		}
		ile++;
	}
	maks=max(maks,ile);
	liczba+=ile;
}

void f(int dl,int lit){
	slowo[dl]=keys[lit];
	if(dl==s-1){
		//cout<<dl<<"..."<<lit<<"\n";
		czek();
		return;
	}
	for(int i=0;i<k;i++) f(dl+1,i);
}

int main(){
	cin>>t;
	for(int test=1;test<=t;test++){
		cin>>k>>l>>s>>keys>>word;
		slowo="          ";
		maks=0;
		liczba=0;
		liczbaslow=0;
		for(int i=0;i<k;i++) f(0,i);
		//cout<<maks<<" "<<liczba<<" "<<liczbaslow<<"\n";
		cout<<fixed << setprecision(10) <<"Case #"<<test<<": "<<maks-(double)liczba/liczbaslow<<"\n";
	}
}
