#include <bits/stdc++.h>
using namespace std;

#define MAXV 105

int T, C, D, V, tmp;
bool presente[MAXV], fatte[MAXV];

int main() {
	ios::sync_with_stdio(false);
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> T;
	for(int i=1;i<=T;i++) {
	   memset(presente, false, sizeof presente);
	   memset(fatte, false, sizeof fatte);
	   in >> C >> D >> V;
	   for(int j=0;j<D;j++) in>>tmp, presente[tmp]=true;
	   int add=0;
	   vector< int >appo;
	   for(int j=1; j <= V; j++) {
		   if(presente[ j ]) {
			   appo.clear();
			   for(int k=1; k<=V; k++) if(fatte[k] && k+j<=V) appo.push_back(k+j); 
			   fatte[j]=true;
			   for(auto k : appo) fatte[k]=true;
		   }
		   else if(fatte[j]) continue;
		   else {
			   appo.clear();
			   for(int k=1; k<=V; k++) if(fatte[k] && k+j<=V) appo.push_back(k+j); 
			   fatte[j]=true;
			   for(auto k : appo) fatte[k]=true;
		       ++add;
	       }
	   }
	   out << "Case #"<<i<<": "<<add<<endl;
    }
	in.close(), out.close();
	return 0;
}
