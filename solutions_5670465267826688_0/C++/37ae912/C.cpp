
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

int L, X;
char buf [1<<20];

enum D {ONE, I, J, K};

typedef pair<bool,D> Num;

void out(Num x){
	if(x.first) putchar('-');
	if(x.second == ONE) puts(" ONE");
	if(x.second == I) puts("I");
	if(x.second == J) puts("J");
	if(x.second == K) puts("K");
}

Num multi(Num a, Num b){
	//printf("a= "); out(a);
	//printf("b= "); out(b);
	bool sign = false; //not negative => 0 means positive
	D res = ONE;
	if(a.second == ONE) res = b.second;
	else if(b.second == ONE) res = a.second;
	else if(a.second == b.second){
		sign = a.second != ONE;
		res = ONE;
	}
	else if(a.second == I){
		res = b.second == J ? K : J;
		sign = b.second == K;
	}
	else if(a.second == J){
		res = b.second == I ? K : I;
		sign = b.second == I;
	}
	else if(a.second == K){
		res = b.second == I ? J : I;
		sign = b.second == J;
	}

	//Num t( sign ^ a.first ^ b.first, res );
	//printf("r= "); out(t);

	return Num( sign ^ a.first ^ b.first, res );
}

Num toNum(char c){
	if(c == 'i') return Num(false, I);
	if(c == 'j') return Num(false, J);
	if(c == 'k') return Num(false, K);
	fprintf(stderr, "illegal character: %c\n", c);
	return Num(false, ONE);
}

bool check(){
	Num res( false, ONE);
	for(int i=0; i<L; ++i){
		res = multi(res,toNum(buf[i]));
	}

	return res.first == true && res.second == ONE;
}

int first_i(){
	Num res( false, ONE);
	Num stop(false, I);
	int i = 0;
	while(i<L){
		res = multi(res,toNum(buf[i]));
		if(res == stop) break;
		++i;
	}
	return i;
}

int last_k(){
	Num res(false, ONE);
	Num stop(false, K);
	int i = L;
	while(--i >=0){
		res = multi(toNum(buf[i]), res);
		if(res == stop) break;
	}
	return i;
}

int main()
{
	int cs = 0, T=0;
	scanf("%d",&T);
	while(++cs <= T){
		scanf("%d%d%s",&L,&X,buf);
		//X %= 12;
		for(int i=0;i<L;++i){
			for(int j=1;j<X;++j){
				buf[ j*L + i ] = buf[i];
			}
		}

		L *= X;
		
		string res = "YES";
		if( check() == false){
			res = "NO";
		}
		else{
			int i = first_i();
			int k = last_k();
			//printf("first_i = %d\n", i);
			//printf("last_k= %d\n", k);
			res = i < k-1 ? "YES" : "NO";
		}

		printf("Case #%d: %s\n", cs, res.c_str());
	}

	return 0;
}
