#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

typedef pair<ull, pair<string, string> > score;

set<string> cs, js;

void generate1(string soFar, string c, ull i){
	//cerr<<i<<endl;
	if(i==c.length()){
		cs.insert(soFar);
		return;
	}
	if(c[i] !='?'){
		generate1(soFar+c[i], c, i+1);
		return;
	}
	for(char cc = '0'; cc<='9'; cc++){
		generate1(soFar+cc, c, i+1);
	}
}

void generate2(string soFar, string c, ull i){
	if(i==c.length()){
		js.insert(soFar);
		return;
	}
	if(c[i] !='?'){
		generate2(soFar+c[i], c, i+1);
		return;
	}
	for(char cc = '0'; cc<='9'; cc++){
		generate2(soFar+cc, c, i+1);
	}
}



int main(){
	ull T;
	cin>>T;
	for(ull k=1; k<=T; k++){
		string c, j;
		cin>>c>>j;
		
		cs.clear();
		js.clear();
		
		generate1("", c, 0);
		//cerr<<"Done"<<endl;
		generate2("", j, 0);
		
		c=*cs.begin();
		j=*js.begin();
		
		score m;
		m={abs(stoi(c)-stoi(j)), {c, j}};
		
		for(string c:cs){
			for(string j:js){
				int C = stoi(c);
				int J = stoi(j);
				m = min(m, {abs(C-J), {c, j}});
			}
		}
		cout<<"Case #"<<k<<": "<<m.second.first<<" "<<m.second.second<<endl;
	}
	return 0;
}
