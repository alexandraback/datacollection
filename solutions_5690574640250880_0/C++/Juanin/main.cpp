#include <cstdio>
#include <iostream>

using namespace std;

FILE *in;
FILE *out;

char matrix[50][50];
bool impossible;
int rows;
int cols;
int mines;
int freev;

void convertMatrix() {
	char matrixtemp[50][50];
	for ( int y = 0; y < rows; y++ ) for ( int x = 0; x < cols; x++ ) matrixtemp[y][x] = matrix[y][x];
	// ---
	for ( int y = 0; y < rows; y++ ) {
		for ( int x = 0; x < cols; x++ ) {
			if ( matrixtemp[y][x] == 'c' ) {
				matrix[y][x] = '.';
				if ( y-1 >= 0 ) {
					matrix[y-1][x] = '.';
				}
				if ( y+1 < rows ) {
					matrix[y+1][x] = '.';
				}
				if ( x-1 >= 0 ) {
					matrix[y][x-1] = '.';
				}
				if ( x+1 < cols ) {
					matrix[y][x+1] = '.';
				}
				if ( x+1 < cols && y+1 < rows ) {
					matrix[y+1][x+1] = '.';
				}
				if ( x+1 < cols && y-1 >= 0 ) {
					matrix[y-1][x+1] = '.';
				}
				if ( x-1 >= 0 && y+1 < rows ) {
					matrix[y+1][x-1] = '.';
				}
				if ( x-1 >= 0 && y-1 >= 0 ) {
					matrix[y-1][x-1] = '.';
				}
			}

		}
	}

}

int countMatrix( char _matrix[50][50] ) {
	char matrixtemp[50][50];
	for ( int y = 0; y < rows; y++ ) for ( int x = 0; x < cols; x++ ) matrixtemp[y][x] = _matrix[y][x];
	// ---
	for ( int y = 0; y < rows; y++ ) {
		for ( int x = 0; x < cols; x++ ) {
			if ( matrixtemp[y][x] == 'c' ) {
				if ( y-1 >= 0 ) {
					if ( matrixtemp[y-1][x] != 'c' ) {
						matrixtemp[y-1][x] = '.';
					}
				}
				if ( y+1 < rows ) {
					if ( matrixtemp[y+1][x] != 'c' ) {
						matrixtemp[y+1][x] = '.';
					}
				}
				if ( x-1 >= 0 ) {
					if ( matrixtemp[y][x-1] != 'c' ) {
						matrixtemp[y][x-1] = '.';
					}
				}
				if ( x+1 < cols ) {
					if ( matrixtemp[y][x+1] != 'c' ) {
						matrixtemp[y][x+1] = '.';
					}
				}
				if ( y+1 < rows && x+1 < cols ) {
					if ( matrixtemp[y+1][x+1] != 'c' ) {
						matrixtemp[y+1][x+1] = '.';
					}
				}
				if ( y+1 < rows && x-1 >= 0 ) {
					if ( matrixtemp[y+1][x-1] != 'c' ) {
						matrixtemp[y+1][x-1] = '.';
					}
				}
				if ( y-1 >= 0 && x+1 < cols ) {
					if ( matrixtemp[y-1][x+1] != 'c' ) {
						matrixtemp[y-1][x+1] = '.';
					}
				}
				if ( y-1 >= 0 && x-1 >= 0 ) {
					if ( matrixtemp[y-1][x-1] != 'c' ) {
						matrixtemp[y-1][x-1] = '.';
					}
				}
			}
		}
	}
	int num = 0;
	for ( int y = 0; y < rows; y++ ) {
		for ( int x = 0; x < cols; x++ ) {
			if ( matrixtemp[y][x] == 'c' || matrixtemp[y][x] == '.' ) {
				num++;
			}
		}
	}
	return num;
}

bool calcMatrix( char _matrix[50][50], int x, int y ) {
	char matrixtemp[50][50];
	for ( int y = 0; y < rows; y++ ) for ( int x = 0; x < cols; x++ ) matrixtemp[y][x] = _matrix[y][x];
	// ------
	int nummfree = countMatrix( matrixtemp );
	if ( nummfree == freev ) {
		for ( int y = 0; y < rows; y++ ) for ( int x = 0; x < cols; x++ ) matrix[y][x] = matrixtemp[y][x];
		return true;
	}
	else if ( nummfree > freev ) {
		return false;
	}

	if ( x+1 < cols ) {
		if ( matrixtemp[y][x+1] != 'c' ) {
			matrixtemp[y][x+1] = 'c';
			if ( calcMatrix( matrixtemp, x+1, y ) ) {
				return true;
			}
			matrixtemp[y][x+1] = '*';
		}
	}
	if ( y+1 < rows ) {
		if ( matrixtemp[y+1][x] != 'c' ) {
			matrixtemp[y+1][x] = 'c';
			if ( calcMatrix( matrixtemp, x, y+1 ) ) {
				return true;
			}
			matrixtemp[y+1][x] = '*';
		}
	}
	if ( x-1 >= 0 ) {
		if ( matrixtemp[y][x-1] != 'c' ) {
			matrixtemp[y][x-1] = 'c';
			if ( calcMatrix( matrixtemp, x-1, y ) ) {
				return true;
			}
			matrixtemp[y][x-1] = '*';
		}
	}
	if ( y-1 >= 0 ) {
		if ( matrixtemp[y-1][x] != 'c' ) {
			matrixtemp[y-1][x] = 'c';
			if ( calcMatrix( matrixtemp, x, y-1 ) ) {
				return true;
			}
			matrixtemp[y-1][x] = '*';
		}
	}

	return false;
}


int main() {
	int numero_casos;
	in = fopen("C-small-attempt2.in", "r");
	out = fopen("C-small-attempt2.out.txt", "w+");
	fscanf(in, "%d\n", &numero_casos);

	for ( int caseNum = 0; caseNum < numero_casos; caseNum++ ) {
		// leo los datos
		rows = 1;
		cols = 1;
		mines = 0;
		fscanf(in, "%d %d %d\n", &rows, &cols, &mines);
		freev = rows*cols - mines;

		impossible = false;
		// calculo
		//fprintf( out, "division %d (%d/%d/%d)\n", (rows*cols-mines)/cols, rows*cols, cols, mines );
		// 1D
		for ( int y = 0; y < rows; y++ ) {
			for ( int x = 0; x < cols; x++ ) {
				matrix[y][x] = '*';
			}
		}
		if ( freev == 1 ) {
			matrix[0][0] = 'c';
		}
		else if ( rows == 1 || cols == 1 ) {
			if ( freev >= 2 ) {
				for ( int y = 0; y < rows; y++ ) {
					for ( int x = 0; x < cols; x++ ) {
						if ( rows == 1 && x < freev ) {
							matrix[y][x] = '.';
						}
						else if ( cols == 1 && y < freev ) {
							matrix[y][x] = '.';
						}
						else {
							matrix[y][x] = '*';
						}
					}
					matrix[0][0] = 'c';
				}
			}
			else {
				impossible = true;
			}
		}
		// 2D
		else if ( rows == 2 || cols == 2 ) {
			if ( freev >= 4 && freev%2 == 0 ) {
				for ( int y = 0; y < rows; y++ ) {
					for ( int x = 0; x < cols; x++ ) {
						if ( rows == 2 && x < freev/2 ) {
							matrix[y][x] = '.';
						}
						else if ( cols == 2 && y < freev/2 ) {
							matrix[y][x] = '.';
						}
						else {
							matrix[y][x] = '*';
						}
					}
					matrix[0][0] = 'c';
				}
			}
			else {
				impossible = true;
			}
		}
		// 3D y superior
		else {
			if ( freev <= 3 || freev == 5 || freev == 7 ) {
				impossible = true;
			}
			else {
				// busco una organizacion correcta
				if ( freev == 4 ) {
					matrix[0][0] = 'c';
					matrix[0][1] = '.';
					matrix[1][0] = '.';
					matrix[1][1] = '.';
				}
				else {
					matrix[0][0] = 'c';
					calcMatrix( matrix, 0, 0 );
					convertMatrix();
					matrix[0][0] = 'c';
				}
			}
		}

		// imprimo el resultado
		fprintf(out, "Case #%d:\n", caseNum+1 );
		if ( impossible ) {
			fprintf(out, "Impossible\n");
		}
		else {
			for ( int y = 0; y < rows; y++ ) {
				for ( int x = 0; x < cols; x++ ) {
					fprintf(out, "%c", matrix[y][x]);
				}
				fprintf(out, "\n");
			}
			convertMatrix();
			/*fprintf(out, "######convertida#####\n");
			for ( int y = 0; y < rows; y++ ) {
				for ( int x = 0; x < cols; x++ ) {
					fprintf(out, "%c", matrix[y][x]);
				}
				fprintf(out, "\n");
			}*/
		}
	}

	fclose(in);
	fclose(out);

	return 0;
}

