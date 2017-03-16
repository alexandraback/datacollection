#include <stdio.h>

#ifndef min
#define min(a,b) (a<=b?a:b)
#endif

char M[][4] = {
	{'h','i','j','k'},
	{'i','h','k','j'},
	{'j','k','h','i'},
	{'k','j','i','h'}
};

char F[][4] = {
	{0,0,0,0},
	{0,1,0,1},
	{0,1,1,0},
	{0,0,1,1}
};

class Char
{
public:
	char c;
	char flag;
	
	Char(char c_='h', char flag_=0):c(c_),flag(flag_){
		if(c_ == 0){
			++*(int*)NULL;
		}
	};
	Char(const Char& other): c(other.c), flag(other.flag){
		if(c == 0){
			++*(int*)NULL;
		}
	};
	
	//Char(const Char& other) = default;
	//Char& operator=(const Char& other) = default;
	Char& operator=(const Char& other){
		c = other.c;
		flag = other.flag;
		
		if(c == 0){
			++*(int*)NULL;
		}
		return *this;
	}
	
	bool operator==(const Char& other){
		return c==other.c && flag==other.flag;
	}
	bool operator!=(const Char& other){
		return !(*this == other);
	}
	
	Char& operator*=(const Char& other){
		int f = F[c-'h'][other.c-'h'];
		//printf("operator* (%c %d) (%c %d) %d\n"
		//	, c, flag, other.c, other.flag, f);
		flag ^= f;
		flag ^= other.flag;
		c = M[c-'h'][other.c-'h'];
		return *this;
	}
};

Char operator*(const Char& left, const Char& right)
{
	Char result(left);
	result *= right;
	return result;
}

Char I[10001];
Char K[10001];
Char J[10001][10001];
Char A;


int setup(const char* S, int L)
{
	Char ci;
	for(int i=0; i<L; ++i){
		Char t(S[i],0);
		ci *= t;
		I[i+1] = ci;
	}
	
	//printf("I=");
	//for(int i=0; i<L+1; ++i)
	//	printf("(%c %d)", I[i].c, I[i].flag);
	//printf("\n");
	
	Char ck;
	for(int i=L-1; i>=0; --i){
		Char t(S[i],0);
		ck = t*ck;
		K[i] = ck;
		
	}
	//printf("K=");
	//for(int i=0; i<L+1; ++i)
	//	printf("(%c %d)", K[i].c, K[i].flag);
	//printf("\n");
	
	for(int i=0; i<L; ++i){
		Char cj;
		for(int j=i+1; j<L+1; ++j){
			Char t(S[j-1],0);
			cj *= t;
			J[i][j] = cj;
		}
	}
	
	A = Char();
	for(int i=0; i<L; ++i){
		Char t(S[i],0);
		A *= t;
	}
	return 0;
}
extern "C"{
	
int solve(char* S, int L, int X);
int hello(const char* S, int L, int X);
}

int solve(char* S, int L, int X)
{
	setup(S,L);
	printf("S=%s L=%ld X=%d A=(%c %d)\n", S,L,X,A.c,A.flag);
	
	
	for(int e1=0; e1<L; ++e1){
		for(int e2=e1; e2<L+1; ++e2){
			Char cj(J[e1][e2]);
			
			if(cj != Char('j',0)) continue;
			
			int x = X-1;
			for(int xi=0; xi<min(x+1,4); ++xi)
			{
				int xk = (x-xi)%4;
				Char ci,ck;
				for(int i=0; i<xi; ++i) ci *= A;
				//for(int i=0; i<xj; ++i) cj *= A;
				for(int i=0; i<xk; ++i) ck *= A;
				//printf("xi=%d (%c %d) xk=%d (%c %d)\n", xi, ci.c, ci.flag, xk, ck.c, ck.flag);
				//printf("e1,e2=%d,%d (%c %d)(%c %d)\n", e1,e2, I[e1].c, I[e1].flag, K[e2].c,K[e2].flag);
				
				ci *= I[e1];
				ck = K[e2] * ck;
				
				//for(int i=0; i<xi; ++i)
				//	printf(S);
				//char b;
				//b = S[e1]; S[e1] = 0;
				//printf("%s|", S);
				//S[e1] = b;
				//b = S[e2];S[e2] = 0;
				//printf("%s|", S+e1);
				//S[e2] = b;
				//printf("%s", S+e2);
				//	
				//for(int i=0; i<xk; ++i)
				//	printf(S);
				//printf("\n");
				//printf("(%c %d)(%c %d)(%c %d)\n", ci.c, ci.flag, cj.c, cj.flag, ck.c, ck.flag);
				//fflush(stdout);
				//if(cj == Char('j',0))
				if(ci == Char('i',0) && ck == Char('k',0)) return 1;
			}
		}
	}
	
	int x = X-2;
	for(int xj=0; xj<min(x+1,4); ++xj)
	{		
		for(int e1=0; e1<L+1; ++e1){
			for(int e2=0; e2<L+1; ++e2){
				Char cj;
				for(int i=0; i<xj; ++i) cj *= A;
				
				Char cj1 = K[e1];
				Char cj2 = I[e2];
				cj = cj1 * cj * cj2;
				
				if(cj != Char('j',0)) continue;
				
				for(int xi=0; xi<min(x-xj+1,4); ++xi)
				{
					int xk = (x-xj-xi)%4;
					Char ci,ck;
					for(int i=0; i<xi; ++i) ci *= A;
					//for(int i=0; i<xj; ++i) cj *= A;
					for(int i=0; i<xk; ++i) ck *= A;
					
					//printf("xi=%d (%c %d) xk=%d (%c %d)\n", xi, ci.c, ci.flag, xk, ck.c, ck.flag);
					//printf("e1,e2=%d,%d (%c %d)(%c %d)\n", e1,e2, I[e1].c, I[e1].flag, K[e2].c,K[e2].flag);
					
					ci*= I[e1];
					ck = K[e2]*ck;
					
					//for(int i=0; i<xi; ++i)
					//	printf(S);
					//char b;
					//b = S[e1]; S[e1] = 0;
					//printf("%s|", S);
					//S[e1] = b;
					//
					//printf("%s", S+e1);
					//for(int i=0; i<xj; ++i)
					//	printf(S);
					//b = S[e2]; S[e2] = 0;
					//printf("%s|", S);
					//S[e2] = b;
					//
					//printf("%s", S+e2);
					//	
					//for(int i=0; i<xk; ++i)
					//	printf(S);
					//printf("\n");
					//printf("(%c %d)(%c %d)(%c %d)\n", ci.c, ci.flag, cj.c, cj.flag, ck.c, ck.flag);
					//if(cj == Char('j',0))
					if(ci == Char('i',0) && ck == Char('k',0)) return 1;
				}
			}
		}
	}
	
	return 0;
}

int hello(const char* S, int L, int X)
{
	printf("%s %d\n", S, X);
	Char c;
	for(int i=0; i<L; ++i){
		//printf("%c %d\n", c.c, c.flag);
		c*=Char(S[i],0);
	}
	printf("%c %d\n", c.c, c.flag);
	return 0;
}
