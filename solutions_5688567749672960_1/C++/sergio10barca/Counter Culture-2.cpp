#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cstdio>
#define x first
#define y second
#define IN(x, n) (0 <= (x) && (x) < n)
#define MAX 1000010
#define MOD 1000000007
using namespace std;

typedef long long int entero;

long long int itoap(long long int n){
    char s[20];
//    printf("original %lld\n", n);
    sprintf(s, "%lld", n);
    reverse(s, s+strlen(s));
    sscanf(s, "%lld", &n);
//    printf("reversa %lld\n", n);
    return n;
}

long long int digitos(long long int n){
    int cont = 0;
    do{
        cont++;
        n/=10;
    }while(n > 0);
    return cont;
}

long long int multiplo10(long long int n){
    long long int valor = 1;
    if(n == 1)
        return 1;
    for(; valor*10 < n; valor*=10);
    return valor == n;
}

long long int solve(const long long int n){
    long long int pasos, valor, suma;
    if(n <= 20)
        return n;
    pasos = 10, valor = 10;
    for(;valor*10 <= n;){
        long long int a, cont = digitos(valor), lim;
        lim = (cont)/2;
        for(suma = 1, a = 0; a < lim; a++)
            suma*=10;
        pasos += suma;
        lim = (cont+1)/2;
        for(suma = 1, a = 0; a < lim; a++)
            suma*=10;
        pasos += suma-1;
        valor *= 10;
//        printf("valor %lld pasos %lld\n", valor, pasos);
    }
    if(valor == n)
        return pasos;
//    printf("suma %lld pasos %lld\n", suma, pasos);
    char s[100], t[100];
    long long int i, j, cont = digitos(n), mitad;
    long long N = n%10 == 0 ? n-1 : n, agregar = n%10 == 0 ? 1 : 0;
    mitad = (cont)/2;
    sprintf(t, "%lld", N);
    int ceros = 0;
    for(i = 0; i < mitad; i++){
        s[i] = t[i];
        ceros += t[i] == '0';
    }
    s[i] = '\0';
    reverse(s, s+i);
    sscanf(s, "%lld", &suma);
    pasos += suma - multiplo10(suma);
//    printf("suma %lld pasos %lld\n", suma, pasos);
    for(i = mitad, j = 0; i < cont; i++, j++)
        s[j] = t[i];
    s[j] = '\0';
    sscanf(s, "%lld", &suma);
    pasos += suma;
    return pasos+agregar;
}


int main(){
	int casos;
	long long int n;
	cin >> casos;
	for(int i = 1; i <= casos; i++){
        cin >> n;
        cout << "Case #"<<i<<": "<<solve(n) << endl;
	}
	return 0;
}
