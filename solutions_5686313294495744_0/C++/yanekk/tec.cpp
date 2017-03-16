#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 3000+20;

map <string,int> M1;
map <string,int> M2;
vector <int> Graf[N];
pair <string,string> Kraw[N];
int Skojarzony[N];
int Odw[N];

bool DFSPowieksz(int v){
	int i;
	Odw[v] = 1;
	for(i=0; i<Graf[v].size(); i++){
		if(!Odw[Graf[v][i]] && ( !Skojarzony[ Graf[v][i] ] || (Odw[Graf[v][i]] = 1, DFSPowieksz(Skojarzony[Graf[v][i]])) ) ){
			Skojarzony[v] = Graf[v][i];
			Skojarzony[ Graf[v][i] ] = v;
			return true;
		}
	}
	return false;
}

int LiczMaksSkojarzenie(int n){
	int i,res;
	bool kon;
	kon = true;
	while(kon){
		kon = false;
		for(i=1; i<=n; i++) Odw[i] = 0;
		for(i=1; i<=n; i++){
			if(!Odw[i] && !Skojarzony[i]) kon |= DFSPowieksz(i);
		}
	}
	res = 0;
	for(i=1; i<=n; i++) if(Skojarzony[i]) res++;
	return res/2;
}

void Czysc(int m,int n){
	int i;
	for(i=0; i<m; i++){
		M1[Kraw[i].first] = 0;
		M2[Kraw[i].second] = 0;
	}
	for(i=0; i<=n; i++) {
		Graf[i].clear();
		Odw[i] = 0;
		Skojarzony[i] = 0;
	}
}

int main(){
	int i,j,l1,l2,m,nk,pk,n,t;
	string s1,s2;
	cin >> n;
	for(i=0; i<n; i++){
		cin >> m;
		l1 = l2 = 0;
		t = 1;
		for(j=0; j<m; j++){
			cin >> s1 >> s2;
			Kraw[j] = make_pair(s1,s2);
			if(M1[s1] == 0) {
				M1[s1] = t++;
				l1++;
			}
			if(M2[s2] == 0) {
				M2[s2] = t++;
				l2++;
			}
			Graf[M1[s1]].push_back(M2[s2]);
			Graf[M2[s2]].push_back(M1[s1]);
		}
		nk = LiczMaksSkojarzenie(l1+l2);
		pk = l1+l2-nk;
		cout << "Case #" << i+1 << ": " << m-pk << "\n";
		Czysc(m,l1+l2);
	}
	return 0;
}
