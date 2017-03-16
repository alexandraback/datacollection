#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <set>

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define FORC(it,cont) for(__typeof(cont.begin()) it=(cont).begin(); it!=(cont).end();++(it))
#define VI vector<int>
#define VS vector<string>
#define SN 20000
#define PN 1000
using namespace std;
int N;
int powmod[PN][4][32];
const int a[] ={2,3,5,7};
int sieve[SN];
VI primes;
void generate()
	{
	sieve[0] = sieve[1] = 1;
	for( int i=2; i < SN; ++i )
		if( sieve[i] == 0)
			{
			primes.push_back(i);
			if( i > 10000) continue;
			for (int j=i*i; j<SN; j+=i)
				sieve[j] = 1;
			}
	primes.resize(PN);
	
	//for( int i =0; i < primes.size();++i ) 
	//	cout << primes[i] << endl;
	
	for (int i=0; i < PN; ++i )
		for (int j=0; j< 4; ++j )
			{
			powmod[i][j][0] = 1;
			for( int k=1; k < 32; ++k)
				powmod[i][j][k]= (powmod[i][j][k-1]*a[j])%primes[i];
			}
	}

string tostr2(int x)
	{
	string s;
	for( int i=0; i < N-2; ++i)
		{ 
		s += (char)('0'+(x&1));
		x>>=1;
		}
	//reverse(s.begin(),s.end());
	//cout << x << "  " << s << endl;
	return s;
	}

int get( int p, int a, int b)
	{
	if (a == 2)
		return powmod[p][0][b];
	if (a == 3)
		return powmod[p][1][b];
	if (a == 5)
		return powmod[p][2][b];
	if (a == 7)
		return powmod[p][3][b];
	if (a == 4)
		{
		long long tmp = powmod[p][0][b]*powmod[p][0][b];
		return tmp%primes[p];
		}
	if (a == 6)
		{
		long long tmp = powmod[p][0][b]*powmod[p][1][b];
		return tmp%primes[p];
		}
	if (a == 8)
		{
		long long tmp = powmod[p][0][b]*powmod[p][0][b]*powmod[p][0][b];
		return tmp%primes[p];
		}
	if (a == 9)
		{
		long long tmp = powmod[p][1][b]*powmod[p][1][b];
		return tmp%primes[p];
		}
	if (a == 10)
		{
		long long tmp = powmod[p][0][b]*powmod[p][2][b];
		return tmp%primes[p];
		}
	}

int main()
	{
	generate();
	int T,J;
	
	int infile = 1;
	string sin,sout;
	if(infile == 0)
		{
		sin = "in.txt";
		sout = "out.txt";
		}
	else
		{
		sin = "in2.txt";
		sout = "out2.txt";
		}
	ifstream fcin(sin.c_str(),ios::in);
	FILE* fout;
	fout = fopen(sout.c_str(),"w");
	fcin >> T;
	cout << T << endl;
	FOR(tc,0,T)
		{
		int res = 0;
		fcin >> N >> J;
		VS sol;
		int cnt = 0;
		vector< VI > proofs;
		
		for( int i=0; i < (1<<N-2); ++i )
			{
			string s = "1" + tostr2( i ) + "1";	
			//cout << s << endl;
			VI bases;
			for (int j=2;j<=10; ++j)
				{
				int myproof = -1;
				for (int k=0; k < PN; ++ k)
					{
					//cout << "p " <<  primes[k] << endl;
					int sum =0;
					for( int l = 0; l < N; ++l )
						if(s[l] == '1')
							sum += get(k,j,l);
					//cout << sum << endl;
					if( sum%primes[k] == 0 )
						{
						myproof = primes[k];
						break;
						}
					}
				if( myproof > 0 )
					bases.push_back(myproof); 
				else break;
				}
			if (bases.size() == 9)
				{
				++cnt;
				proofs.push_back(bases);
				reverse(s.begin(),s.end());
				sol.push_back(s);
				}
			//cout << bases.size() << endl;
			if( cnt == J) 
				break;
			}
		fprintf(fout,"Case #%d:\n",tc+1);
		for( int i=0; i < sol.size(); ++i )
			{
			fprintf(fout,"%s",sol[i].c_str());
			for (int j = 0; j < 9; ++j )
				fprintf(fout," %d",proofs[i][j]);
			fprintf(fout,"\n");
			}
		
		}
	fcin.close();
	return 0;
	}
