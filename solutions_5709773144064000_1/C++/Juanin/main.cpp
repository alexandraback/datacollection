#include <cstdio>
#include <iostream>

using namespace std;

	FILE *in;
	FILE *out;

double costoGranja;
double fpsGranja;
double meta;
double resultado;

double galletasActuales;
double fpsActuales;
double segundosTranscurridos;


double segundosParaMeta() {
	if ( galletasActuales >= meta )
		return 0;
	double retorno = (meta - galletasActuales)/fpsActuales;
	return retorno;
}

double segundosParaGranja() {
	if ( galletasActuales >= costoGranja )
		return 0;
	double retorno = (costoGranja - galletasActuales)/fpsActuales;
	retorno = (costoGranja)/fpsActuales;
	//fprintf(out, "division %f    %fs\n", costoGranja, fpsActuales);
	return retorno;
}

bool convieneGranja() {
	bool conviene = false;
	double segundosActuales = segundosTranscurridos;
	double backGalletasActuales = galletasActuales;
	double backFpsActuales = fpsActuales;
	double segundosSinGranja = segundosTranscurridos + segundosParaMeta();
	segundosActuales += segundosParaGranja();
	//galletasActuales -= costoGranja;
	fpsActuales += fpsGranja;
	if ( segundosSinGranja <= segundosActuales+segundosParaMeta() ) {
		conviene = false;
	}
	else {
		conviene = true;
	}
	galletasActuales = backGalletasActuales;
	fpsActuales = backFpsActuales;
	return conviene;
}

void comprarGranja() {
	//galletasActuales -= costoGranja;
	segundosTranscurridos += segundosParaGranja();
	fpsActuales += fpsGranja;
}

int main() {
	int numero_casos;
	in = fopen("B-large.in", "r");
	out = fopen("B-large.out.txt", "w+");
	fscanf(in, "%d\n", &numero_casos);

	for ( int caseNum = 0; caseNum < numero_casos; caseNum++ ) {
		costoGranja;
		fpsGranja;
		meta;
		resultado = -1;
		fpsActuales = 2.0f;
		galletasActuales = 0;
		segundosTranscurridos = 0;
		// leo los datos
		float C, F, X;
		fscanf(in, "%f %f %f\n", &C, &F, &X);
		costoGranja = C;
		fpsGranja = F;
		meta = X;
		//fscanf(in, "%f %f %f\n", &costoGranja, &fpsGranja, &meta);
		
		int numgranjas = 0;
		// calculo
		while ( resultado == -1 ) {
			if ( segundosParaMeta() < segundosParaGranja() ) {
				resultado = segundosTranscurridos + segundosParaMeta();
			}
			else if ( convieneGranja() ) {
				//segundosTranscurridos += segundosParaGranja();
				//fprintf(out, "precompra numero %d:  %fs\n", numgranjas, segundosTranscurridos);
				comprarGranja();
				numgranjas++;
				//cout << "compra numero " << numgranjas+1 << ": " << segundosTranscurridos << "s" << endl;
				//fprintf(out, "compra numero %d:  %fs\n", numgranjas, segundosTranscurridos);
			}
			else {
				resultado = segundosTranscurridos + segundosParaMeta();
			}
		}


		// imprimo el resultado
		fprintf(out, "Case #%d: ", caseNum+1 );
		fprintf(out, "%.8f", resultado);
		fprintf(out, "\n");
		/*fprintf(out, "granjas: %d\n", numgranjas);
		fprintf(out, "gps: %f\n", fpsActuales);
		fprintf(out, "C: %f\n", costoGranja);
		fprintf(out, "F: %f\n", fpsGranja);
		fprintf(out, "X: %f\n", meta);*/
	}

	fclose(in);
	fclose(out);

	return 0;
}

