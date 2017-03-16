#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string wl, wk;
int profmax;
int tamlet;

int cont (char* word, unsigned int size){
	unsigned int res=0, i, j;
	bool bien;
	for (i=0; i< size -wl.size()+1; i++){
		bien=true;
		for (j=0; j<wl.size(); j++){
			if (word[j+i] != wl[j]) bien=false;
		}
		if (bien) ++res;
	}
	return res;
}


void backtrack (char* word ,int* pos, int prof){
	if (prof == profmax) {
		++pos[cont(word, prof)];
		return;
	}
	else{
		int i;
		for (i=0; i<tamlet; i++){
			word[prof] = wk[i];
			backtrack (word, pos, prof+1);
		}
	}
}


int main() {
    int t, k, l, s, cont=0, max;
    unsigned i, j, m;
    cin >>t;
    double prob;
    int pos[8];
    bool esta[26], imp;
    char  word[7];
    int acum;
    long long int esp;


    for (i=0; i<t; i++){
    	cout << "Case #" << ++cont << ": ";
    	cin >> k >> l >> s;
    	cin >> wk >> wl;
    	prob=0;
    	imp=false;
    	for (j=0; j<26; j++){
    		esta[j]=false;
    	}
    	for (j=0; j<8; j++){
    		pos[j]=0;
    	}
    	for (j=0; j<wk.size(); j++){
    		esta[wk[j]-'A']=true;
    	}
    	for (j=0; j<wl.size(); j++){
    	    if (!esta[wl[j]-'A']){imp=true; break;}
    	}
    	if (imp){
    		cout << setprecision(7) << 0 << endl;
    	}
    	else{
    		for (j=1; j<wl.size(); j++){
    			imp = false;
    			for (m=0; m<wl.size()-j; m++ ){
    				if (wl[m+j] != wl[m]){imp=true; break;}
    			}
    			if (!imp) break;
    		}
    		max = 1+ ((s-wl.size())/j);
    		profmax= s;
    		tamlet=wk.size();

    		backtrack (word , pos, 0);
    		acum=0;
    		esp=0;
    		for (j=0; j<7; j++){
    			esp+=j*pos[j];
    			acum+= pos[j];
    		}
    		//prob = max;
    		//prob-= ((esp+0.0)/acum);
    		cout << setprecision(7) << max -((esp+0.0)/acum) << endl;
    	}
    }
    return 0;
}
/*

*/
