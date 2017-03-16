#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> code(10);
vector<int> adj[10];
vector<int> ord;



int nex;
bool visita(int v){
	if(v != ord[nex]) return false;
	nex++;
	
	bool ok;
	do{
		ok = false;
		for(int i=0; i<(int)adj[v].size(); i++){
			if(visita(adj[v][i])) ok = true;
		}
	}while(ok);
	
	return true;
}


bool comp(int x, int y){return code[x]<code[y];}

void test(int index){
	int n,m;
	
	cin >> n >> m;
	
	ord.clear();
	for(int i=0; i<n; i++) {cin >> code[i]; adj[i].clear(); ord.push_back(i);}
	for(int i=0; i<m; i++){
		int x,y; cin >> x >> y; x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	sort(ord.begin(), ord.begin()+n, comp);
	
	do{
		nex = 0;
		//cerr << "Case #" << index << ": ";
		//for(int i=0; i<n; i++) cerr << code[ord[i]];
		//cerr << endl;
		
		if(!visita(ord[0]) || nex < n) continue;
		
		cout << "Case #" << index << ": ";
		for(int i=0; i<n; i++) cout << code[ord[i]];
		cout << endl;
		return;
	}while(next_permutation(ord.begin(), ord.begin()+n, comp));
	
	cerr << "ERRORE case " << index << endl;
}

int main(){
	int t; cin >> t;
	for(int i=1; i<=t; i++) test(i);
	return 0;
}
