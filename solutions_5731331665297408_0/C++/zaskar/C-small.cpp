#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct city {
	string zc; int al; bool visitada;
	vector<int> f2;
	void init() { f2.clear(); al=0; visitada=false; }
	void hayv(int v) { f2.push_back(v); al++; }
};

string penalize(city *c2, vector<int> &donde, int dest) {
	int ii=donde.size()-1;
	string max_pena=c2[dest].zc;
	while (true) {
		city &c=c2[donde[ii]];
		for(int j=0;j<c.f2.size();j++) {
			int d=c.f2[j];
			if (d==dest) return max_pena;
			if (!c2[d].visitada && max_pena<c2[d].zc) {
				bool alc=false;
				for(int k=0;k<c2[d].f2.size();k++) { 
					if (!c2[c2[d].f2[k]].visitada) { alc=true; break; }
				}
				if (!alc) max_pena=c2[d].zc;
			}
		}
		ii--;
	}
}

int main(int argc, char *argv[]) {
	ifstream fin("C-small-attempt0.in");
	ofstream fout("C-small-attempt0.out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		int m,n;
		fin>>n>>m;
		city c0[50];
		for(int i=0;i<n;i++) {
			c0[i].init();
			fin>>c0[i].zc;
		}
		int a,b;
		for(int i=0;i<m;i++) { 
			fin>>a>>b;a--; b--;
			c0[a].hayv(b);
			c0[b].hayv(a);
		}
		
		int i=0;
		for(int ii=1;ii<n;ii++) if (c0[ii].zc<c0[i].zc) i=ii;
		
			vector<int> pos; vector<int> donde;
			int cual=i;
			string num;
			do {
				city &cur=c0[cual];
				cur.visitada=true;
				do {
					vector<int>::iterator it=find(pos.begin(),pos.end(),cual);
					if (it==pos.end()) break;
					pos.erase(it);
				} while (true); 
				num+=cur.zc;
				donde.push_back(cual);
				for(int j=0;j<cur.f2.size();j++) { 
					int d=cur.f2[j];
//					if (find(pos.begin(),pos.end(),d)==pos.end())
					if (!c0[d].visitada)
						pos.push_back(d);
				}
				if (pos.empty()) break;
				string smin=penalize(c0,donde,pos[0]); int imin=pos[0];
				for(int j=1;j<pos.size();j++) {
					string aux=penalize(c0,donde,pos[j]);
					if (aux<smin) { 
						smin=c0[pos[j]].zc; imin=pos[j];
					}
				}
				
				while (find(c0[cual].f2.begin(),c0[cual].f2.end(),imin)==c0[cual].f2.end()) {
					
					for(int j=0;j<c0[cual].f2.size();j++) {
						int d=c0[cual].f2[j];
						if (!c0[d].visitada) {
							bool alc=false;
							for(int k=0;k<c0[d].f2.size();k++) { 
								if (!c0[c0[d].f2[k]].visitada) { alc=true; break; }
							}
							if (!alc) num+=c0[d].zc;
							pos.erase(find(pos.begin(),pos.end(),d));
						}
					}
					
					donde.pop_back(); cual=donde.back();
				}
				
				cual=imin; pos.erase(find(pos.begin(),pos.end(),cual));
				
			} while (true);
			
		
		fout<<"Case #"<<I+1<<": "<<num<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

