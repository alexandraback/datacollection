#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;

int main() {
  ifstream fin("E:\\D-large.in");
  // ifstream fin("E:\\temp.txt");
  ofstream fout("E:\\D-large.out");
  int T;
  fin >> T;
  for (int i = 1; i <= T; i++) {
	  int X, R, C;
	  fin >> X;
	  fin >> R;
	  fin >> C;
	  if (X >= 7) {
          fout << "Case #" << i << ": " << "RICHARD" << endl;
	  }
	  else {
		  if (X == 1) {
			  fout << "Case #" << i << ": " << "GABRIEL" << endl;
		  }
		  else {
			  if (X == 2) {
				  if (R % 2 == 0 || C % 2 == 0) {
					  fout << "Case #" << i << ": " << "GABRIEL" << endl;
				  }
				  else {
					  fout << "Case #" << i << ": " << "RICHARD" << endl;
				  }
			  }
			  else {
				  if (X == 3) {
					  if (R % 3 == 0 || C % 3 == 0) {
						  if (R == 1 || C == 1) {
							  fout << "Case #" << i << ": " << "RICHARD" << endl;
						  }
						  else {
							  fout << "Case #" << i << ": " << "GABRIEL" << endl;
						  }
					  }
					  else {
						  fout << "Case #" << i << ": " << "RICHARD" << endl;
					  }
				  }
				  else {
					  if (X == 4) {
						  if (R % 4 == 0 || C % 4 == 0) {
							  if (R <= 2 || C <= 2) {
								  fout << "Case #" << i << ": " << "RICHARD" << endl;
							  }
							  else {
								  fout << "Case #" << i << ": " << "GABRIEL" << endl;
							  }
						  }
						  else {
							  if (R % 2 == 0 && C % 2 == 0) {
								  if (R == 2 || C == 2) {
									  fout << "Case #" << i << ": " << "RICHARD" << endl;
								  }
								  else {
									  fout << "Case #" << i << ": " << "GABRIEL" << endl;
								  }
							  }
							  else {
								  fout << "Case #" << i << ": " << "RICHARD" << endl;
							  }
						  }
					  }
					  else {
						  if (X == 5) {
							  if (R % 5 == 0 || C % 5 == 0) {
								  if (R <= 3 || C <= 3) {
									  if (R >= 10 || C >= 10) {
										  fout << "Case #" << i << ": " << "GABRIEL" << endl;
									  }
									  else {
										  fout << "Case #" << i << ": " << "RICHARD" << endl;
									  }
								  }
								  else {
									  fout << "Case #" << i << ": " << "GABRIEL" << endl;
								  }
							  }
							  else {
								  fout << "Case #" << i << ": " << "RICHARD" << endl;
							  }
						  }
						  else {
							  assert(X == 6);
							  if (R % 6 == 0 || C % 6 == 0) {
								  if (R <= 3 || C <= 3) {
									  fout << "Case #" << i << ": " << "RICHARD" << endl;
								  }
								  else {
									  fout << "Case #" << i << ": " << "GABRIEL" << endl;
								  }
							  }
							  else {
								  if (R % 2 == 0 && C % 3 == 0) {
									  if (R == 2) {
										  fout << "Case #" << i << ": " << "RICHARD" << endl;
									  }
									  else {
										  assert(R >= 4);
										  if (C == 3) {
											  fout << "Case #" << i << ": " << "RICHARD" << endl;
										  }
										  else {
											  fout << "Case #" << i << ": " << "GABRIEL" << endl;
										  }
									  }
								  }
								  else {
									  if (R % 3 == 0 && C % 2 == 0) {
										  if (C == 2) {
											  fout << "Case #" << i << ": " << "RICHARD" << endl;
										  }
										  else {
											  assert(C >= 4);
											  if (R == 3) {
												  fout << "Case #" << i << ": " << "RICHARD" << endl;
											  }
											  else {
												  fout << "Case #" << i << ": " << "GABRIEL" << endl;
											  }
										  }
									  }
									  else {
										  fout << "Case #" << i << ": " << "RICHARD" << endl;
									  }
								  }
							  }
						  }
					  }
				  }
			  }
		  }
	  }
  }
	return 0;
}
