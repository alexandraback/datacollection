// GCJ2016QRC.cpp 
//


#include <istream>
#include <iostream>
#include <cstdio>
#include <vector>
#include <ctime>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>

#define pb(x) push_back(x)
#define ll long long

using namespace std;

ifstream *fi;
FILE *fo;

bool NoIsZero(vector <ll> na) {
	int i;
	for(i=0;i<3;i++) if(na[i]!=0) return false;
	return true;
}

bool NoIsEqual(vector <ll> na,vector <ll> nb) {
	int i;
	for(i=2;i>=0;i--) if(na[i]!=nb[i]) return false;
	return true;
}

bool NoIsGtEq(vector <ll> na,vector <ll> nb) {
	int i;
	for(i=2;i>=0;i--) {
		if(na[i]>nb[i]) return true;
		if(na[i]<nb[i]) return false;
	}
	return true;
}


vector <ll> NoMul10(vector <ll> na) {
	int i;
	ll cy=0;
	vector <ll> r;
	for (i=0;i<3;i++) r.pb(0);
	for(i=0;i<3;i++) {
		r[i]=na[i]*10+cy;
		cy=r[i]/100000000000000000;
		if(i<2) r[i]-=cy*100000000000000000;
	}
	return r;
}

vector <ll> NoMulN(vector <ll> na,int n) {
	int i;
	ll cy=0;
	vector <ll> r;
	for (i=0;i<3;i++) r.pb(0);
	for(i=0;i<3;i++) {
		r[i]=na[i]*n+cy;
		cy=r[i]/100000000000000000;
		if(i<2) r[i]-=cy*100000000000000000;
	}
	return r;
}

vector <ll> NoAdd(vector <ll> na,vector <ll> nb) {
	int i;
	ll cy=0;
	vector <ll> r;
	for (i=0;i<3;i++) r.pb(0);
	for(i=0;i<3;i++) {
		nb[i]+=cy;
		cy=0;
		r[i]=na[i]+nb[i];
		if((r[i]>=100000000000000000)&&(i<2)) r[i]-=100000000000000000, cy=1;
	}
	return r;
}

vector <ll> NoSub(vector <ll> na,vector <ll> nb) {
	int i;
	ll cy=0;
	vector <ll> r;
	for (i=0;i<3;i++) r.pb(0);
	for(i=0;i<3;i++) {
		nb[i]+=cy;
		cy=0;
		if((na[i]<nb[i])&&(i<2)) na[i]+=100000000000000000, cy=1;
		r[i]=na[i]-nb[i];
	}
	return r;
}

string NoNo2St(vector <ll> n) {
	int i;
	string s;
	char stchar[100];
	i=2;
	while((n[i]==0)&&(i>0))i--;
	sprintf(stchar,"%lld",n[i--]);
	s=string(stchar);
	for(;i>=0;i--) {
		sprintf(stchar,"%017lld",n[i]);
		s+=string(stchar);
	}
	return s;
}

void NoSt2No(string si, vector <ll> *n) {
	int i,lg,a,b;
	string si2,s;
	string scomp="0000000000000000000000000000000000000000000000000000000000000000000000";
	stringstream fxs;
	
	lg=si.length();
	si2=scomp.substr(0,3*17-lg)+si;
	for(i=0;i<3;i++) {
		(*n)[2-i]=0;
		// Flux fxs : clear() pour effacer l'erreur EOF
		fxs.clear();
		fxs << si2.substr(i*17,17);
		fxs >> (*n)[2-i];
	}
}

vector <ll> NoMod(vector <ll> na,vector <ll> nb) {
	int i;
	vector <ll> nx,ny,nn,n10;
	nx=na,ny=nb;
	
	while (NoIsGtEq(nx,ny)) {
		n10=ny;
		while(NoIsGtEq(nx,NoMul10(n10))) n10=NoMul10(n10);
		nn=n10;
		while(NoIsGtEq(nx,NoAdd(nn,n10))) nn=NoAdd(nn,n10);
		nx=NoSub(nx,nn);
	} 
	return nx;
}

vector <ll> NoGcd(vector <ll> na,vector <ll> nb) {
	int i;
	vector <ll> nx,ny,nn,noz;
	
	for(i=0;i<3;i++) noz.pb(0);
	
	if(NoIsGtEq(na,nb)) nx=na,ny=nb;
	else nx=nb,ny=na;
	
	if(NoIsZero(ny)) return nx;
	
	while (!NoIsEqual(ny,noz)) {
		nn=NoMod(nx,ny);
		nx=ny;
		ny=nn;
	} 
	return nx;
}


void Run() {
	int i, j, k, m,  a,b,tc,mn,nb,kmn,aa,bb,lg,lw;
	int T, N,J;
	int res;
	int pt;
	double dres;
	string st,sres;
	ll so, som,ch;
	vector <ll> no,no2,noa,nodiv[11],nodivp[10],nobase[11];
	ll ldiv[10]={3,5,7,11,13,17,19,23,29,31};
	ll lnob[11]={-1,-1,2,3,4,5,6,7,8,9,10};
	int diviseurs[11];
	bool fgOK,fg,fg2;
	
	// Init Tout début
	
	
	// Lecture début
	*fi >> T;

	// getline(*fi, st); // Pour terminer la ligne
	// getline(*fi, st); // Pour lire une chaîne de caractères
	
	// Parcours des N test cases :
	
	getline(*fi, st);  // Pour passer à la ligne suivante :
	for (tc = 1; tc <= T; tc++) {
		
		// Reset du tour précédent (dont vectors) !
		res=0;
		no.clear();
		no2.clear();
		noa.clear();
		// Diviseurs résultat :
		for(i=0;i<11;i++) nodiv[i].clear();
		// Diviseurs premiers à tester :
		for(i=0;i<10;i++) nodivp[i].clear();
		
		// Init
		*fi >> N >> J	;
		//getline(*fi, st);  // Pour lire une ligne !
		
		for(i=0;i<10;i++) {
			nodivp[i].pb(ldiv[i]);
			for(j=1;j<3;j++) nodivp[i].pb(0);
		}
		
		for(i=0;i<11;i++) {
			nobase[i].pb(lnob[i]);
			for(j=1;j<3;j++) nobase[i].pb(0);
		}
		
		ch=((ll)1<<(N-1))+1;
		
		// Exe
		fprintf(fo, "Case #%d:\n", tc);
		printf("Case #%d:\n", tc);
		for(i=0;i<J;i++) {
			fgOK=false;
			while(!fgOK) {
				for(j=2;j<=10;j++) {
					// Fabrication du 100...001 et de l'incrément :
					no.clear();
					for(k=0;k<3;k++) no.pb(0);
					noa.clear();
					noa.pb(1);
					for(k=1;k<3;k++) noa.pb(0);
					for(k=0;k<N;k++) {
						if((ch&(1<<k))!=0) no=NoAdd(no,noa);
						noa=NoMulN(noa,lnob[j]);
					}
					// On cherche à diviser :
					fg=false;
					for(k=0;k<10;k++) {
						if(NoIsZero(NoMod(no,nodivp[k]))) {
							fg=true;
							diviseurs[j]=ldiv[k];
							break;
						}
					}
					if(!fg) break;
				}
				if(j==11) {
					fgOK=true;
					st="";
					for(k=N-1;k>=0;k--) {
						if((ch&(1<<k))!=0) st+="1";
						else st+="0";
					}
					fprintf(fo, "%s ", st.c_str());
					printf("%s ", st.c_str());
					for(j=2;j<=10;j++) {
						fprintf(fo, "%d ", diviseurs[j]);
						printf("%d ", diviseurs[j]);
					}
					fprintf(fo, "\n");
					printf("\n");
				}
				ch+=2;
			}
			
		}

		// Sortie
		// fprintf(fo, "Case #%d: %d\n", tc,res);
		// printf("Case #%d: %d\n", tc,res);
	}
}


void Fichiers() {
	fi=new ifstream("C-large.in");
	fo=fopen("Test.out","w");
}


int main(int argc, char** argv) {
	unsigned int i;

	printf("GCJ2016QRC\n");
	Fichiers();
	Run();


	return 0;
}