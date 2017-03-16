#include <iostream>

using namespace std;

void rep(char c,int n) { for (int i=0; i<n; i++) cout << c; }
void free(int n) { rep('.',n); }
void mines(int n) { rep('*',n); }

main() {
  int T;
  cin >> T;
  for (int t=1; t<=T; t++) {
    int R, C, M, F;
    cin >> R >> C >> M;
    cout << "Case #" << t << ":" << endl;
    //cout << "Case #" << t << ": " << R << " " << C << " " << M << endl;
    F = R*C-M;
    if (F==1) {
      cout << "c"; mines(C-1); cout << endl;
      for (int i=1; i<R; i++) {	mines(C); cout << endl; }
    } else if (R==1) {
      cout << "c";
      free(F-1); mines(M);
      cout << endl;
    } else if (C==1) {
      cout << "c" << endl;
      for (int i=1; i<F; i++) cout << "." << endl;
      for (int i=0; i<M; i++) cout << "*" << endl;
    } else if (F==2 || F==3) {
      cout << "Impossible" << endl;
    } else if (R==2) {
      if (M % 2==1) cout << "Impossible" << endl;
      else {
	cout << "c";
	free(F/2-1); mines(C-F/2); cout << endl;
	free(F/2);   mines(C-F/2); cout << endl;
      }
    } else if (C==2) {
      if (M % 2==1) cout << "Impossible" << endl;
      else {
	cout << "c." << endl;
	for (int i=1; i<F/2; i++) { free(2); cout << endl; }
	for (int i=0; i<M/2; i++) { mines(2); cout << endl; }
      }
    } else if (F==5 || F==7) {
      cout << "Impossible" << endl;
    } else if (F<=2*C) {
      if (F % 2 == 0) {
	cout << "c"; free(F/2-1); mines(C-F/2); cout << endl;
	free(F/2); mines(C-F/2); cout << endl;
	for (int i=2; i<R; i++) { mines(C); cout << endl; }
      } else {
	cout << "c"; free((F-1)/2-2); mines(C-(F-1)/2+1); cout << endl;
	free((F-1)/2-1); mines(C-(F-1)/2+1); cout << endl;
	free(3); mines(C-3); cout << endl;
	for (int i=3; i<R; i++) { mines(C); cout << endl; }
      }
    } else if (F % C != 1) {
      cout << "c"; free(C-1); cout << endl;
      for (int i=1; i<F/C; i++) { free(C); cout << endl; }
      if (M>0) {
	free(F % C); mines(C-(F%C)); cout << endl;
	for (int i=F/C+1; i<R; i++) { mines(C); cout << endl; }
      };
    } else if (F != 2*C+1) { // F=3C+1,4C+1,5C+1,...
      cout << "c"; free(C-1); cout << endl;
      for (int i=1; i<F/C-1; i++) { free(C); cout << endl; }
      free(C-1); mines(1); cout << endl;
      free(2); mines(C-2); cout << endl;
      for (int i=F/C+1; i<R; i++) { mines(C); cout << endl; }
    } else { // F==2C+1
      cout << "c"; free(C-2); mines(1); cout << endl;
      free(C-1); mines(1); cout << endl; 
      free(3); mines(C-3); cout << endl;
      for (int i=3; i<R; i++) { mines(C); cout << endl; }
    }
  };
};
