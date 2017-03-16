#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

//typedef __int64 int64_t;

int64_t A, B, K;

int64_t cuenta(int64_t M, int64_t MA, int64_t MB, int64_t bit) {
    if (bit==0) {
        return 1;
    }
    //A y B pueden ser cualquier numero
    return (bit<<1)*(bit<<1);
}

int64_t cuentaB(int64_t M, int64_t MA, int64_t MB, int64_t bit) {
    //K y A no esta limitado
	if (bit==0) {
		return 0;
	}
    int64_t res = 0;
    if ((B&bit)==0) {
        res += 2*cuentaB(M, MA, MB, bit>>1);
		//res += cuentaB(M, MA|bit, MB, bit>>1);
    } else {
		res += cuenta(M, MA|bit, MB, bit>>1);
		res += cuentaB(M, MA, MB|bit, bit>>1);
		res += cuentaB(M|bit, MA|bit, MB|bit, bit>>1);
		res += cuenta(M, MA, MB, bit>>1);
	}
    return res;
}

int64_t cuentaA(int64_t M, int64_t MA, int64_t MB, int64_t bit) {
    //K y B no esta limitado
	if (bit==0) {
		return 0;
	}
    int64_t res = 0;
    if ((A&bit)==0) {
        res += 2*cuentaA(M, MA, MB, bit>>1);
		//res += cuentaA(M, MA, MB|bit, bit>>1);
    } else {
		res += cuentaA(M, MA|bit, MB, bit>>1);
		res += cuenta(M, MA, MB|bit, bit>>1);
		res += cuentaA(M|bit, MA|bit, MB|bit, bit>>1);
		res += cuenta(M, MA, MB, bit>>1);
	}
    return res;
}

int64_t cuentaAB(int64_t M, int64_t MA, int64_t MB, int64_t bit) {
    //K no esta limitando
	if (bit==0) {
		return 0;
	}
	int64_t res =0;
	if ((A&bit)==0) {
		if ((B&bit)==0) {
			res += cuentaAB(M, MA, MB, bit>>1);
		} else {
			res += cuentaAB(M, MA, MB|bit, bit>>1);
			res += cuentaA(M, MA, MB, bit>>1);
		}
	} else {
		if ((B&bit)==0) {
			res += cuentaB(M, MA, MB, bit>>1);
			res += cuentaAB(M, MA|bit, MB, bit>>1);
		} else {
			res += cuentaA(M, MA|bit, MB, bit>>1);
			res += cuentaB(M, MA, MB|bit, bit>>1);
			res += cuentaAB(M|bit, MA|bit, MB|bit, bit>>1);
			res += cuenta(M, MA, MB, bit>>1);
		}
	}
    return res;
}

int64_t cuentaK(int64_t M, int64_t MA, int64_t MB, int64_t bit) {
    if (bit==0) {
        return 0;
    }
    int64_t res = 0;
    if ((K&bit)==0) {
        //activar en A
        res += cuentaK(M, MA|bit, MB, bit>>1);
        //activar en B
        res += cuentaK(M, MA, MB|bit, bit>>1);
        //no activar
        res += cuentaK(M, MA, MB, bit>>1);
    } else {
        // activar A
        res += cuenta(M, MA|bit, MB, bit>>1);
        // activar B
        res += cuenta(M, MA, MB|bit, bit>>1);
        // activar AMBOS
        res += cuentaK(M|bit, MA|bit, MB|bit, bit>>1);
        // no activar nada
        res += cuenta(M, MA, MB, bit>>1);
    }
    return res;
}

int64_t cuentaKA(int64_t M, int64_t MA, int64_t MB, int64_t bit) {
    //B no esta limitado
    if (bit==0) {
        // no hay boletos entre M y K
        return 0;
    }
    int64_t res = 0;
    if ((K&bit)==0) {
        // no se puede activar el bit
        if ((A&bit)==0) {
            //tampoco en A (contar uno activando en B y otro no
            res += cuentaKA(M, MA, MB, bit>>1);
            res += cuentaKA(M, MA, MB|bit, bit>>1);
        } else {
            //activar en A
            res += cuentaKA(M, MA|bit, MB, bit>>1);
            //activar en B
            res += cuentaK(M, MA, MB|bit, bit>>1);
            //no activar
            res += cuentaK(M, MA, MB, bit>>1);
        }
    } else {
        //se puede activar en K
        if ((A&bit)==0) {
            // no se puede en A
            res += cuentaA(M, MA, MB, bit>>1);
            res += cuentaA(M, MA, MB|bit, bit>>1);
        } else {
            // se puede en A
            // activar en A
            res += cuentaA(M, MA|bit, MB, bit>>1);
            //activar en B
            res += cuenta(M, MA, MB|bit, bit>>1);
            //activar en ambos
            res += cuentaKA(M|bit, MA|bit, MB|bit, bit>>1);
            // no activar
            res += cuenta(M, MA, MB, bit>>1);
        }
    }
    return res;
}

int64_t cuentaKB(int64_t M, int64_t MA, int64_t MB, int64_t bit) {
    //B no esta limitado
    if (bit==0) {
        // no hay boletos entre M y K
        return 0;
    }
    int64_t res = 0;
    if ((K&bit)==0) {
        // no se puede activar el bit
        if ((B&bit)==0) {
            //tampoco en B (contar uno activando en B y otro no
            res += cuentaKB(M, MA, MB, bit>>1);
            res += cuentaKB(M, MA|bit, MB, bit>>1);
        } else {
            //activar en A
            res += cuentaK(M, MA|bit, MB, bit>>1);
            //activar en B
            res += cuentaKB(M, MA, MB|bit, bit>>1);
            //no activar
            res += cuentaK(M, MA, MB, bit>>1);
        }
    } else {
        //se puede activar en K
        if ((B&bit)==0) {
            // no se puede en A
            res += cuentaB(M, MA, MB, bit>>1);
            res += cuentaB(M, MA|bit, MB, bit>>1);
        } else {
            // se puede en A
            // activar en A
            res += cuenta(M, MA|bit, MB, bit>>1);
            //activar en B
            res += cuentaB(M, MA, MB|bit, bit>>1);
            //activar en ambos
            res += cuentaKB(M|bit, MA|bit, MB|bit, bit>>1);
            // no activar
            res += cuenta(M, MA, MB, bit>>1);
        }
    }
    return res;
}

int64_t cuentaKAB(int64_t M, int64_t MA, int64_t MB, int64_t bit) {
    if (bit==0) {
        // no hay boletos entre MA y A
        return 0;
    }
    if ((bit&K)==0) {
        //No se puede activar el bit
        int64_t res=0;
        if ((A&bit)==0) {
            //no se puede activar en A
            if ((B&bit)==0) {
                // tampoco en B
                res += cuentaKAB(M,MA,MB,bit>>1);
            } else {
                //se puede activar en B, pero no se hace
                //(contar todos los numeros mayores o iguales a MB
                // y menores a B)
                res += cuentaKA(M, MA, MB, bit>>1);
                //agregarle el contador cuando se activa el bit
                res += cuentaKAB(M, MA, MB|bit, bit>>1);
            }
        } else {
            //se puede activar el bit en A
            if ((B&bit)==0) {
                // no se puede activar en B
                //no activar en A
                res += cuentaKB(M, MA, MB, bit>>1);
                //activar en A
                res += cuentaKAB(M, MA|bit, MB, bit>>1);
            } else {
                //se puede activar en ambos
                //activar solo en B
                res += cuentaKB(M, MA, MB|bit, bit>>1);
                //activar solo en A
                res += cuentaKA(M, MA|bit, MB, bit>>1);
                // no activar ni en A ni en B
                res += cuentaK(M, MA, MB, bit>>1);
            }
        }
        return res;
    } else {
        // se puede activar en K
        int64_t res=0;
        if ((A&bit)==0) {
            //no se puede activar en A
            if ((B&bit)==0) {
                // tampoco en B
                res += cuentaAB(M, MA, MB, bit>>1);
            } else {
                //se puede activar en B, pero no se hace
                res += cuentaA(M, MA, MB, bit>>1);
                // se activa en B
                res += cuentaAB(M, MA, MB|bit, bit>>1);
            }
        } else {
            //se puede activar el bit en A
            if ((B&bit)==0) {
                // no se puede activar en B
                res += cuentaB(M, MA, MB, bit>>1);
                // se activa en A
                res += cuentaAB(M, MA|bit, MB, bit>>1);
            } else {
                //se puede activar en ambos
                // activar en B
                res += cuentaB(M, MA, MB|bit, bit>>1);
                // activar en A
                res += cuentaA(M, MA|bit, MB, bit>>1);
                //activar en AMBOS
                res += cuentaKAB(M|bit, MA|bit, MB|bit, bit>>1);
                // no actiar en ninguno (aqui va a ser el producto de las posibilidades de A y B)
                res += cuenta(M, MA, MB, bit>>1);
            }
        }
        return res;
    }
}

int64_t cuentachafa(void) {
    int64_t res=0;
    for (int64_t a=0;a<A;a++) {
        for (int64_t b=0;b<B;b++) {
            if ((a&b)<K) {
                res++;
            }
        }
    }
    return res;
}

int main(int argc, char* argv[])
{
	int T;
	#define NOMBRE_ARCHIVO "B-large"
	string nombre = NOMBRE_ARCHIVO;
	nombre = nombre + ".in";
	FILE *entrada = fopen(nombre.c_str(), "rt");
	nombre = NOMBRE_ARCHIVO;
	nombre = nombre + ".out";
	FILE *salida = fopen(nombre.c_str(), "wt");
	fscanf(entrada,"%d", &T);
	for (int t=1;t<=T;t++) {
        fscanf(entrada, "%ld %ld %ld", &A, &B, &K);
        int64_t r = cuentaKAB(0,0,0,1<<30);
		/*
        int64_t r2 = cuentachafa();
        if (r!=r2) {
            fprintf(salida,"CHAFA %ld:\n", r2);
        }
		*/
        fprintf(salida, "Case #%d: %lld\n",t, r);
        printf("Case #%d: %lld\n",t, r);
        fflush(salida);
		fflush(stdout);
	}
	fclose(salida);
	fclose(entrada);
	return 0;
}

