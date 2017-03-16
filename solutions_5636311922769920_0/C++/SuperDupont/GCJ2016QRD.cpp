// GCJ2016QRD.cpp 
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



void Run() {
	int i, j, k, m,  a,b,tc,mn,nb,kmn,aa,bb,lg,lw;
	int T, K,C,S;
	int res;
	int pt;
	double dres;
	string st,sres;
	ll lk, inc, lres;
	
	// Init Tout début
	
	
	// Lecture début
	*fi >> T;

	// getline(*fi, st); // Pour terminer la ligne
	// getline(*fi, st); // Pour lire une chaîne de caractères
	
	// Parcours des N test cases :
	
	getline(*fi, st);  // Pour passer à la ligne suivante :
	for (tc = 1; tc <= T; tc++) {
		
		// Reset du tour précédent (dont vectors) !
		
		// Init
		*fi >> K >> C >> S	;
		//getline(*fi, st);  // Pour lire une ligne !
		
		lk=K;
		
		// Exe
		fprintf(fo, "Case #%d: ", tc);
		printf("Case #%d: ", tc);
		
		inc=1;
		if(C>1) {
			for(i=0;i<C-1;i++) inc*=lk;
			inc++;
		}
		lres=1;
		for(i=0;i<S;i++) {		
			fprintf(fo, "%lld ",lres);
			printf( "%lld ",lres);
			lres+=inc;
		}
		fprintf(fo, "\n");
		printf( "\n");
			
		// Sortie
		// fprintf(fo, "Case #%d: %d\n", tc,res);
		// printf("Case #%d: %d\n", tc,res);
	}
}


void Fichiers() {
	fi=new ifstream("D-small-attempt1.in");
	fo=fopen("Test.out","w");
}


int main(int argc, char** argv) {
	unsigned int i;

	printf("GCJ2016QRD\n");
	Fichiers();
	Run();


	return 0;
}