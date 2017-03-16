// GCJ2012QRB.cpp 
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

int Chif(ll n) {
	int i,r;
	ll i10,c;
	r=0;
	i10=1;
	for(i=0;i10<=n;i++) {
		c=(n%(i10*10))/i10;
		r|=1<<c;
		i10*=10;
	}
	return r;
}

void Run() {
	int i, j, k, m,  a,b,tc,mn,nb,kmn,aa,bb,lg,lw;
	int T;
	int res;
	int pt;
	double dres;
	string st,sres;
	ll so, cpt,som,lres,N;
	int cible,ch;
	bool fgposs;
	
	// Init Tout début
	cible=0;
	for (i=0;i<10;i++) cible|=1<<i;
	
	// Lecture début
	*fi >> T;

	// getline(*fi, st); // Pour terminer la ligne
	// getline(*fi, st); // Pour lire une chaîne de caractères
	
	// Parcours des N test cases :
	
	getline(*fi, st);  // Pour passer à la ligne suivante :
	for (tc = 1; tc <= T; tc++) {
		
		// Reset du tour précédent (dont vectors) !
		lres=0;
		
		// Init
		*fi >> N 	;
		//getline(*fi, st);  // Pour lire une ligne !
		
		
		// Exe
		if(N==0) fgposs= false;
		else {
			fgposs=true;
			ch=0;
			lres=0;
			do {
				lres+=N;
				ch|=Chif(lres);
			} while(ch!=cible);
		}
		

		// Sortie
		if(fgposs) {
			fprintf(fo, "Case #%d: %lld\n", tc,lres);
			printf("Case #%d: %lld\n", tc,lres);
		} else {
			fprintf(fo, "Case #%d: INSOMNIA\n", tc);
			printf("Case #%d: INSOMNIA\n", tc);
		}
	}
}


void Fichiers() {
	fi=new ifstream("A-small-attempt0.in");
	fo=fopen("Test.out","w");
}


int main(int argc, char** argv) {
	unsigned int i;

	printf("GCJ2016QRA\n");
	Fichiers();
	Run();


	return 0;
}