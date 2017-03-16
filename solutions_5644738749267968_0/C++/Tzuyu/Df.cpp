#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

bool comp(const double &a,const double &b){
	if (a>b) return true;
	else return false;
}

int main(){
	int ti,T,i,j,n;
	int sn,sk,tn,tk,wn,wk;
	double tmp;
	vector<double> nao,ken;
	FILE * inf, * outf;
	inf=fopen("D-small-attempt0.in.txt","r");
	outf=fopen("D-small.out","w");
	fscanf(inf,"%d",&T);
	for (ti=0;ti<T;ti++){
		fscanf(inf,"%d",&n);
		tn=tk=n-1;
		sn=sk=n-1;
		wk=n;
		wn=0;
		nao.clear();
		ken.clear();
		for (i=0;i<n;i++){
			fscanf(inf,"%lf",&tmp);
			nao.push_back(tmp);
		}
		for (i=0;i<n;i++){
			fscanf(inf,"%lf",&tmp);
			ken.push_back(tmp);
		}
		sort(nao.begin(),nao.end(),comp);
		sort(ken.begin(),ken.end(),comp);
		//for (i=0;i<n;i++) cout << nao[i] << ken[i];
		while (tn>=0){
			while(tn>=0&&nao[tn]<ken[sn]) tn--;
			if (tn>=0&&nao[tn]>ken[sn]) wn++;
			tn--;
			sn--;
		}
		while (sk>=0){
			while(sk>=0&&nao[tk]>ken[sk]) sk--;
			if (sk>=0&&nao[tk]<ken[sk]) wk--;
			tk--;
			sk--;
		}
		fprintf(outf,"Case #%d: %d %d\n",ti+1,wn,wk);
	}
	return 0;
}
