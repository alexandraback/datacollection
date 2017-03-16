#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int N;
int M;

struct Box{
	int amount;
	int remain;
	int type;
};

struct Toy{
	int amount;
	int remain;
	int type;
};

Box boxes[101];
Toy toys[101];

void reset()
{
	for( int i=0; i<N; i++ ) boxes[i].remain = boxes[i].amount;
	for( int i=0; i<M; i++ ) toys[i].remain = toys[i].amount;
}

int solver()
{
	cin >> N;
	cin >> M;
	
	for( int i=0; i<N; i++ ){
		cin >> boxes[i].amount;
		boxes[i].remain = boxes[i].amount;
		cin >> boxes[i].type;
	}

	for( int i=0; i<M; i++ ){
		cin >> toys[i].amount;
		toys[i].remain = toys[i].amount;
		cin >> toys[i].type;
	}

	int power2 = (int)pow( 2.0, N );

	int max = 0;
	for( int i=0; i<power2; i++ ){ //bit adder
		
		int count = 0;
		for( int j=0, k=0; j<N && k<M; j++ ){

			int on = 1 << j;
			if( !(i & on) ) continue; //┻斌

			for( ; k<M; k++ ){
				if( boxes[j].type == toys[k].type ){ // type单
					if( boxes[j].remain <= toys[k].remain ){
						count += boxes[j].remain;
						toys[k].remain -= boxes[j].remain;
						break; // 传Box
					} else{
						count += toys[k].remain;
						boxes[j].remain -= toys[k].remain;
					}
				}
			}
			
		}

		if( count > max ) max = count;
		reset();
	}

	if( M > 30 ) return max;

	power2 = (int)pow( 2.0, M );

	for( int i=0; i<power2; i++ ){ //bit adder
		
		int count = 0;
		for( int j=0, k=0; j<M && k<N; j++ ){

			int on = 1 << j;
			if( !(i & on) ) continue; //┻斌

			for( ; k<N; k++ ){
				if( toys[j].type == boxes[k].type ){ // type单
					if( toys[j].remain <= boxes[k].remain ){
						count += toys[j].remain;
						boxes[k].remain -= toys[j].remain;
						break; // 传Box
					} else{
						count +=  boxes[k].remain;
						toys[j].remain -= boxes[k].remain;
					}
				}
			}
			
		}

		if( count > max ) max = count;
		reset();
	}



	return max;
}

	

int main()
{
	freopen( "C-small-attempt0.in", "r", stdin );
	freopen( "C-small-attempt0.out", "w", stdout );
	//freopen( "A-large-practice.in", "r", stdin );
	//freopen( "A-large-practice.out", "w", stdout );

	int T;
	scanf("%d", &T );
	for( int i=1; i<=T; i++ ){
		printf("Case #%d: ", i);
		printf("%d", solver() );
		printf("\n");
	}

	//system("pause");
}