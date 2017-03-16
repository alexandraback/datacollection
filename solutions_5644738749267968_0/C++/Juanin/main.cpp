#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

FILE *in;
FILE *out;
set<float> NaomiSetO;
set<float> KenSetO;

set<float> NaomiSet;
set<float> KenSet;

set<float> NaomiSetDeceitful;
set<float> KenSetDeceitful;

int numeroBloques;

int main() {
	int numero_casos;
	in = fopen("D-small-attempt0.in", "r");
	out = fopen("D-small-attempt0.out", "w+");
	fscanf(in, "%d\n", &numero_casos);

	for ( int caseNum = 0; caseNum < numero_casos; caseNum++ ) {
		// leo los datos
		fscanf(in, "%d\n", &numeroBloques);
		NaomiSet.clear();
		KenSet.clear();
		NaomiSetO.clear();
		KenSetO.clear();
		NaomiSetDeceitful.clear();
		KenSetDeceitful.clear();
		float temp;
		for ( int i = 0; i < numeroBloques; i++ ) {
			fscanf(in, "%f", &temp);
			NaomiSet.insert( temp );
			NaomiSetO.insert( temp );
			NaomiSetDeceitful.insert( temp );
		}
		for ( int i = 0; i < numeroBloques; i++ ) {
			fscanf(in, "%f", &temp);
			KenSet.insert( temp );
			KenSetO.insert( temp );
			KenSetDeceitful.insert( temp );
		}

		int naomiPtsWar = 0;
		int naomiPtsNoWar = 0;

		// calculo
		// Deceitful War
		while( NaomiSetDeceitful.size() > 0 ) {
			// tomo el mas pequeno de naomi
			if ( *NaomiSetDeceitful.begin() < *KenSetDeceitful.begin() ) {
				// quemo el mas pequeno de naomi y el mas grande de ken -> ken gana un punto
				NaomiSetDeceitful.erase( NaomiSetDeceitful.begin() );
				KenSetDeceitful.erase( *KenSetDeceitful.rbegin() );
			}
			else {
				// si no, juego el mas pequeno de naomi (ken su mas pequeno) -> ken pierde
				NaomiSetDeceitful.erase( NaomiSetDeceitful.begin() );
				KenSetDeceitful.erase( KenSetDeceitful.begin() );
				naomiPtsNoWar++;
			}
		}
		
		// War
		while( NaomiSet.size() > 0 ) {
			// tomo el mas pequeno de naomi, ken juega con el mas pequeno mayor al de naomi
			if ( KenSet.upper_bound( *NaomiSet.begin() ) == KenSet.end() ) {
				// ken no tiene uno con tamano mayor al de naomi, por lo que juega si pieza mas pequena y pierde un punto
				KenSet.erase( KenSet.begin() );
				NaomiSet.erase( NaomiSet.begin() );

				naomiPtsWar++;
			}
			else {
				KenSet.erase( KenSet.upper_bound( *NaomiSet.begin() ) );
				NaomiSet.erase( NaomiSet.begin() );
			}
		}


		// imprimo el resultado
		fprintf(out, "Case #%d: %d %d\n", caseNum+1, naomiPtsNoWar, naomiPtsWar );
		/*
		for ( set<float>::iterator it = NaomiSetO.begin(); it != NaomiSetO.end(); ++it ) {
			fprintf(out, "%f ", *it );
		}
		fprintf(out, "\n");
		for ( set<float>::iterator it = KenSetO.begin(); it != KenSetO.end(); ++it ) {
			fprintf(out, "%f ", *it );
		}
		fprintf(out, "\n\n" );*/
	}

	fclose(in);
	fclose(out);

	return 0;
}

