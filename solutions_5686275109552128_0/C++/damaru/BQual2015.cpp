#include <iostream>
#include <queue>
using namespace std;

priority_queue <int > q;

int main() {
    int i, j, t, cont=1, n, aux, min, tiem;

    cin >>t;

    for (i=0; i<t; i++){
    	while (!q.empty()) q.pop();
    	cout << "Case #" << cont++ << ": ";
    	cin >> n;
    	for (j=0; j<n; j++){
    		cin >> aux;
    		q.push(aux);
    	}
    	tiem=0;
    	min = q.top();
    	aux = min;
    	q.pop();
    	while (aux > 2){
    		tiem++;
    		if (aux & 1){aux>>=1; q.push(aux); q.push(aux+1);}
    		else{aux >>= 1; q.push(aux); q.push(aux);}
    		aux = q.top();
    		q.pop();
    		if (tiem + aux < min) min = tiem +aux;
    	}
    	cout << min << endl;
    }
    return 0;
}
/*
3
1
3
4
1 2 1 2
1
4
 * */
