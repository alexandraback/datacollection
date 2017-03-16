#include<iostream>

using namespace std;

int a[10];

int all_done(){
    int res = 1;
    for( int i = 0; i < 10; i++ )
	res = res & ( a[i] > 0 );
    return res;
}

void update_digits( long long n ){
    while( n != 0 ){
	int x = n % 10;
	n = n/10;
	a[x] = 1;
    }
    return;
}

int main(){
    int t;
    cin >> t;
    
    for( int i = 1; i <= t; i++ ){
	int x; cin >> x;
	if( x == 0 ){
	    cout << "Case #" << i << ": INSOMNIA" << endl;
	    continue;
	}
	int elem = x;
	update_digits( x );
	while( !all_done() ){
	    x += elem;
	    update_digits( x );
	}
	for(int j = 0; j < 10; j++) a[j] = 0;
	cout << "Case #" << i << ": " << x << endl;  
    }
    return 0;
}
	    

	
