// GCJ2016QRB.cpp 
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

bool IsOK(string s) {
	int i;
	for(i=0;i<s.size();i++) 
		if(s[i]!='+') return false;
	return true;
}

string Ret(string s, int n) {
	int i;
	string r;
	r="";
	for(i=0;i<n;i++) {
		if(s[n-i-1]=='+') r+="-";
		else r+="+";
	}
	if(n<s.size()) r+=s.substr(n,s.size()-n);
	return r;
}

void Run() {
	int i, j, k, m,  a,b,tc,mn,nb,kmn,aa,bb,lg,lw;
	int T;
	int res;
	int pt;
	double dres;
	string st,sres,S;
	char c;
	
	
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
		
		// Init
		*fi >> S ;
		//getline(*fi, st);  // Pour lire une ligne !
		
		// Exe
		pt=0;
		st=S;
		c=st[0];
		while(!IsOK(st)) {
			for(;pt<st.size();pt++) {
				if(st[pt]!=c) {
					c=st[pt];
					break;
				}
			}
			st=Ret(st,pt);
			res++;
		}

		// Sortie
		fprintf(fo, "Case #%d: %d\n", tc,res);
		printf("Case #%d: %d\n", tc,res);
	}
}


void Fichiers() {
	fi=new ifstream("B-large.in");
	fo=fopen("Test.out","w");
}


int main(int argc, char** argv) {
	unsigned int i;

	printf("GCJ2016QRB\n");
	Fichiers();
	Run();


	return 0;
}