#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//做出來的話 Value改成long long

class Coin{
public:
	int Cmax, Cnow;
	long long Value;
	Coin():Cmax(1),Cnow(1){}
	Coin(int C):Cmax(C),Cnow(C){}
	Coin(int C, long long V):Cmax(C),Cnow(C),Value(V){}
};

int Values[300], C, D, ans;
long long V;
vector<Coin> Darr;

bool comp(Coin a, Coin b){
	return a.Value<b.Value;
}
void vectorReset(){
	for(int i=0; i<Darr.size(); i++){
		Darr[i].Cnow=C;
	}
	sort(Darr.begin(),Darr.end(),comp);
}

bool spell(long long v, vector<Coin> tmp){
	if(v<0) return false;
	if(v==0) return true;
	//vector<Coin> tmp = Darr;
	for(int i=0; i<tmp.size(); i++){
		if(tmp[i].Cnow==0) continue;
		tmp[i].Cnow--;
		if(spell(v-tmp[i].Value,tmp)) return true;
		tmp[i].Cnow++;
	}
	return false;
}

int main(){
	int cases;
	cin>>cases;
	for(int c=1; c<=cases; c++){
		ans=0;
		cin>>C>>D>>V;
		Darr.clear();
		//memset(Values,0,sizeof(Values));
		for(int d=0; d<D; d++){
			Darr.push_back(Coin());
			cin>>Darr.back().Value;
		}
		for(int v=1; v<=V; v++){
			if(!spell(v,Darr)){
				ans++; Darr.push_back(Coin(C,v));
				vectorReset();
			}
		}
		cout<<"Case #"<<c<<": "<<ans<<endl;
	}


	return 0;
}