#include <iostream>

using namespace std;

//ijk=234
int m[4][4] ={1, 2, 3, 4, 2, -1, 4, -3, 3, -4, -1, 2, 4, 3, -2, -1 };

int mul (int a, int b){
	int sig;
	if ((a < 0 && b >0) || (a>0 && b<0) ) sig=-1;
	else sig=1;
	if (a<0) a= -a;
	if (b<0) b=-b;
	a-=1;
	b-=1;
	return sig*m[a][b];
}


int main() {
    int i, j, t, k, cont=1, aux, vl, com;
    long long int x, l, max;
    char a;
    int la[10002];


    cin >>t;

    for (i=0; i<t; i++){
    	cout << "Case #" << cont++ << ": ";
    	cin >> l >> x;
    	if (x <10) max = l*x;
    	else max = l*10;
    	for (j=0; j<l; j++){
    		cin >> a;
    		aux = (int)(a-'g');
    		la[j]= aux;
    	}
    	vl =1;
    	for (j=0; j<l; j++){
    		vl = mul(vl, la[j]);
    	}
    	aux = (x & 3);//x%4;
    	com=1;
    	for (j=0; j<aux; j++){
    		com = mul(com, vl);
    	}
    	if (com != -1){
    		cout << "NO" << endl;
    	}
    	else{
    		com = la[0]; j=1;
    		while (com != 2 && j < max && (j< (l<<2))){
    			com = mul (com, la[j%l]);
    			j++;
    		}
    		if (com != 2) cout << "NO" << endl;
    		else{
    			com = 1; k =0;
    			while (com != 3 && (j+k) < max && (k< (l<<2))){
					com = mul (com, la[(j+k)%l]);
					k++;
				}
    			if (com != 3) cout << "NO" << endl;
    			else cout << "YES" << endl;
    		}
    	}
    }
    return 0;
}
/*
5
2 1
ik
3 1
ijk
3 1
kji
2 6
ji
1 10000
i
 * */

