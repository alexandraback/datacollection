//Grzegorz Prusak
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>

///////////////////////////////////////////////////////////////////////////

#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,p,k) for(int i=(p); i<=(k); ++i)
#define FORD(i,p,k) for(int i=(p); i>=(k); --i)

typedef long long LL;

template<size_t digits> struct BN
{
	BN(){ REP(i,n_max) A[i] = 0; }
	BN(int v){ REP(i,n_max) A[i] = 0; A[0] = v; }

	BN & operator+=(const BN &b)
	{
		LL c = 0;
		REP(i,n_max)
		{
			c += A[i]+b.A[i];
			A[i] = c%BASE;
			c/=BASE;
		}
		return *this;
	}

	BN & operator-=(const BN &b)
	{
		LL c = 0;
		REP(i,n_max)
		{
			c += A[i]-b.A[i];
			A[i] = (c+BASE)%BASE;
			if(c<0) c = -1; else c = 0;
		}
		return *this;
	}

	BN & operator*=(int d)
	{
		LL c = 0;
		REP(i,n_max)
		{
			c += LL(A[i])*d;
			A[i] = c%BASE;
			c /= BASE;
		}
		return *this;
	}

	BN & operator/=(int d)
	{
		LL c = 0;
		FORD(i,n_max-1,0)
		{
			c += A[i];
			A[i] = c/d;
			c = c%d*BASE;
		}
		return *this;
	}

	BN & operator<<=(int j)
	{
		FORD(i,n_max-j-1,0) A[i+j] = A[i];
		REP(i,j) A[i] = 0;
		return *this;
	}

	BN operator*(const BN &b) const
	{
		BN r;
		REP(i,n_max)
		{
			BN t = b;
			t *= A[i];
			t <<= i;
			r += t;
		}
		return r;
	}

	bool operator<(const BN &b) const
	{
		FORD(i,n_max-1,0) if(A[i]!=b.A[i]) return A[i]<b.A[i];
		return 0;
	}

	enum { DIGITS = digits, LOG_BASE = 8, BASE = 100000000, n_max = (digits+LOG_BASE-1)/LOG_BASE };
	int A[n_max];	

	void print() const
	{
		char S[n_max*8];
		print(S);
		printf("%s",S);
	}

	void print(char *S) const
	{
		BN t = *this;
		int sl = 0;
		while(BN(0)<t)
		{
			S[sl++] = t.A[0]%10+'0';
			t /= 10;
		}
		REP(i,sl/2) std::swap(S[i],S[sl-i-1]); S[sl] = 0;
	};

	void scan()
	{
		char S[n_max*LOG_BASE];
		scanf("%s",S);
		scan(S);
	}

	void scan(const char *S)
	{
		int sl = strlen(S);
		*this = 0;
		REP(i,sl)
		{
			*this *= 10;
			A[0] += S[i]-'0';
		}
	}
};
///////////////////////////////////////////////////////////////////////////

enum { n_max = 120 };

template<typename T> void checkmax(T &a, T b){ if(a<b) a = b; }

bool pal(LL v)
{
	char A[50];
	int l=0;
	while(v){ A[l++] = v%10; v/=10; } 
	REP(i,l) if(A[i]!=A[l-i-1]) return 0;
	return 1;
}

void brute(int n)
{
	REP(v,n)
	{
		if(pal(v) && pal(v*(LL)v)) printf("%d\n",v);
	}
}

struct Builder
{
	Builder() : c(0) {}

	char A[n_max],A2[n_max],A02[n_max],A92[n_max];
	BN<n_max> b;
	
	LL c;

	void fns()
	{
		b.scan(A);
		//printf("a   = %s\n",A);
		//printf("a   = "); b.print(); puts("");
		b = b*b;
		b.print(A2);
		//printf("a^2 = "); b.print(); puts("");
		int n = strlen(A2);
		REP(i,n/2) if(A2[i]!=A2[n-i-1]) return;
		printf("%s %s\n",A,A2);
		//if(!(++c%1000)) printf("c = %lld\n",c);
	}

	void run(int n, int i = 0)
	{
		A[n] = 0;
		if(i>=(n+1)/2){ fns(); return; }
		if(i)
		{
			FOR(k,i,n-i-1) A[k] = '0';
			b.scan(A);
			//b.print(); printf("\t");
			b = b*b;
			//b.print(); printf("\n");
			b.print(A02); b.print(A2);
			
			FOR(k,i,n-i-1) A[k] = '9';
			b.scan(A);
			//b.print(); printf("\t");
			b = b*b;
			//b.print(); printf("\n"); 
			b.print(A92);
			
			int l = strlen(A2);
			REP(j,l/2) std::swap(A2[j],A2[l-j-1]);
			A2[i] = A02[i] = A92[i] = 0;
			
			//printf("%s %s %s\n\n",A02,A92,A2);
			if(strcmp(A02,A92)<0)
			{
				if(strcmp(A02,A2)>0 || strcmp(A2,A92)>0) return;
			}
			else if(strcmp(A92,A2)>0 || strcmp(A2,A02)>0) return;
		}
		FOR(j,i==0,9)
		{
			A[i] = A[n-i-1] = '0'+j;
			run(n,i+1);
		}
	}

};

struct CheatBuilder
{
	typedef BN<105> B;
	
	void pal(const B &b)
	{
		char A[105];
		b.print(A);
		int n = strlen(A);
		REP(i,n/2) if(A[i]!=A[n-i-1]) return;
		#pragma omp critical
		V.push_back(A);
	}
	
	std::vector<std::string> V;

	void check(char A[], int l)
	{
		B b;
		std::copy(A,A+l,A+l);
		std::reverse(A,A+l);
		A[2*l] = 0;
		b.scan(A);
		pal(b = b*b);
		
		std::copy_backward(A+l,A+2*l,A+2*l+1);
		A[2*l+1] = 0;
		REP(i,3)
		{
			A[l] = '0'+i;
			b.scan(A);
			pal(b = b*b);
		}
	}

	void check_mask(int m)
	{
		char A[105];
		int l = 0; while(m){ A[l++] = '0'+(m&1); m>>=1; }
		check(A,l);
	}

	void run()
	{
		pal(9);
		int n = 25;
		#pragma omp parallel for
		REP(i,1<<n) check_mask(i);
		
		FOR(l,1,n)
		{
			char A[105];
			REP(i,l) A[i] = '0';
			A[l] = 0;
			A[l-1] = '2';
			check(A,l);
		}
	}

	static bool cmp(const std::string &a, const std::string &b)
	{ return a.size()!=b.size() ? a.size()<b.size() : a<b; }
	
	void dump()
	{
		std::sort(V.begin(),V.end(),cmp);
		printf("%d\n",V.size());
		REP(i,V.size()) printf("%s\n",V[i].c_str());
	}
};

#include <fstream>
#include <iostream>

int main()
{
	/*CheatBuilder builder;
	builder.run();
	builder.dump();
	return 0;*/

	std::vector<std::string> V;
	std::ifstream f("c.dump");
	int n; f >> n;
	REP(i,n)
	{
		std::string s; f >> s;
		V.push_back(s);
	}

	int t; scanf("%d",&t);
	FOR(_,1,t)
	{
		std::string a,b;
		std::cin >> a >> b;
		int res = 0;
		REP(i,V.size()) if(
			!CheatBuilder::cmp(V[i],a) &&
			!CheatBuilder::cmp(b,V[i])) res++;
		printf("Case #%d: %d\n",_,res);
	}
	return 0;
}
