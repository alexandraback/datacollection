#include <fstream>
#include <cstring>
using namespace std;

int v[1001][1001],vz[1001],nrfl,isdy;

int fill(int node) {
	int i;
	int fubar=0;
	for (i=1; i<=v[node][0]; i++)
		if (vz[v[node][i]]&&vz[v[node][i]]==nrfl) {
			fubar=1;
			break;
		}
		else if (vz[v[node][i]]!=nrfl&&!fubar) {
			vz[v[node][i]]=nrfl;
			fubar=fill(v[node][i]);
		}
	return fubar;
}
		
	
int main() {
	int l,i,j,n,t;
	ifstream f("input.in");
	ofstream g("output.out");
	f>>t;
	for (l=1; l<=t; l++) {
		f>>n;
		nrfl=0;
		isdy=0;
		memset(vz,0,sizeof(vz));
		memset(v,0,sizeof(v));
		for (i=1; i<=n; i++) {
			f>>v[i][0];
			for (j=1; j<=v[i][0]; j++)
				f>>v[i][j];
		}
		for (i=1; i<=n; i++)
			if (!vz[i]) {
				nrfl++;
				vz[i]=nrfl;
				isdy=fill(i);
				if (isdy)
					break;
				
			}
		g<<"Case #"<<l<<": ";
		if (isdy)
			g<<"Yes"<<'\n';
		else
			g<<"No"<<'\n';
	}
	g.close();
	return 0;
}
