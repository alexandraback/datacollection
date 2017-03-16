#include<iostream>
#include<vector>
using namespace std;
struct tribe{
	int first_day;
	int number_of_attacks;
	int pocz;
	int kon;
	int strength;
	int delta_days;
	int delta_travel;
	int delta_strength;
};
struct attack{
	int strength;
	int pocz;
	int kon;
};
int T,N;
tribe t[10001];
vector<attack> V[676065];
attack pom;
int s,beg,en,ktory_dzien,max_dzien;
int mur[100000]; //mur[0] - wysokosc muru dla x=-1000
long long res;

void dobuduj(const attack &a){
	for(int i=a.pocz;i<a.kon;i++){
		//cout<<i<<endl;
		if(mur[i]<a.strength)mur[i]=a.strength;
	}
}

bool udany_atak(const attack &a){
	for(int i=a.pocz;i<a.kon;i++){
		//cout<<i<<endl;
		if(a.strength>mur[i])return 1;
	}
	return 0;
}

int main(){
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>N;
		max_dzien=0;
		for(int j=0;j<N;j++){
			cin>>t[j].first_day>>t[j].number_of_attacks>>t[j].pocz>>t[j].kon>>t[j].strength>>t[j].delta_days>>t[j].delta_travel>>t[j].delta_strength;
			t[j].pocz+=1000;
			t[j].kon+=1000;
			
			s=t[j].strength;
			beg=t[j].pocz;
			en=t[j].kon;
			ktory_dzien=t[j].first_day;
			
			for(int k=0;k<t[j].number_of_attacks;k++){
				pom.strength=s;
				pom.pocz=beg;
				pom.kon=en;
				V[ktory_dzien].push_back(pom);
				s+=t[j].delta_strength;
				beg+=t[j].delta_travel;
				en+=t[j].delta_travel;
				if(ktory_dzien>max_dzien)max_dzien=ktory_dzien;	
				ktory_dzien+=t[j].delta_days;
				
			}
			
		}
	
		for(int j=0;j<=max_dzien;j++){
			
			for(int k=0;k<V[j].size();k++){
				if(udany_atak(V[j][k]))res++;
			}
			for(int k=0;k<V[j].size();k++){
				dobuduj(V[j][k]);
			}
			V[j].clear();
		}
	cout<<"Case #"<<(i+1)<<": "<<res<<"\n";
	res=0;
	for(int i=0;i<2000;i++)mur[i]=0;
	}
cout<<endl;
return 0;
}
