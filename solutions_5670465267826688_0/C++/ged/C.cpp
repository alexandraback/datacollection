#include <vector>
#include <list>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
#define FN(i,n) for (int i=0; i<(int)(n); i++)
#define SZ(c) ((int)(c).size())

#define FBE(i,v,T) for (vector<T >::iterator i=(v).begin(); i!=(v).end(); i++)
#define FEB(i,v,T) for (vector<T >::reverse_iterator i=(v).rbegin(); i!=(v).rend(); i++)
#define ABS(a) ((a)<0?-(a):(a))
#define PI     3.14159265358979323846
#define MIN (a,b)  ((a)<(b) ? (a) : (b))
#define MAX (a,b)  ((a)<(b) ? (b) : (a))
#define MAXINT (1<<30)
#define MININT (-MAXINT)
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
template<class X,class Y> ostream &operator<<(ostream &s, pair<X,Y> p){s<<p.first<<'@'<<p.second;return s;}
template<class V> ostream &operator<<(ostream &s, list<V> v){char c='{';for (typename list<V >::iterator i=v.begin(); i!=v.end();i++){s<<c<<*i; c=','; }s<<'}';return s;}
template<class A> string printString(A o ) { ostringstream s; (s << o); return s.str(); }
template<class C> void kill(C&c){for(typename C::iterator i=c.begin(); i!=c.end(); i++)kill:for(typename C::iterator j=i+1;j!=c.end();j++)if(*i==*j){*j=c.back();c.pop_back();goto kill;}}
template<class TA, class TV> void feed(vector<TV> &v, TA a[], int n) {  v.clear(); FN(i,n) v.push_back(TV(a[i])); }
#define FEED(vec,arr) feed((vec),(arr),sizeof((arr))/sizeof((arr)[0]))
#define all(a) (a).begin(), (a).end()
vector<string> tokens(const string &str, const string &delims){
	char *buf = strdup(str.c_str()), *token;
	const char *dels = delims.c_str();
	vector<string> v;
	token = strtok( buf, dels );
	while (token) {	v.push_back(token);	token = strtok(NULL, dels);	}
	free(buf);
	return v;
}
#define erase_unique(v)     (v).erase(unique(all(v)),v.end())  
#define erase_remove(v,val) (v).erase(remove(all(v),(val)),v.end()) 

template<class T> ostream &operator<<(ostream &s, vector<T> v){char c='[';for(typename vector<T >::iterator i=v.begin();i!=v.end();i++){s<<c<<*i;c=',';}s<<']';return s;}
PII operator+(PII a, PII b) { return make_pair(a.first+b.first, a.second+b.second); }
// END CUT HERE 


char val(char c) {
	if (c== 1 ) return 1;
	if (c=='i') return 2;
	if (c=='j') return 3;
	if (c=='k') return 4;
}

char MUL[5][5] = {
	{ 0, 0, 0, 0, 0 },
	{ 0, 0x1, 0x2, 0x3, 0x4 },
	{ 0, 0x2,0x11, 0x4,0x13 },
	{ 0, 0x3,0x14,0x11, 0x2 },
	{ 0, 0x4, 0x3,0x12,0x11 }
};

char mul(char a, char b) {
	char sign = (a&0x10) ^ (b&0x10);
	a = a&0xF;
	b = b&0xF;
	if (a==0) printf("!!!!!! a=0\n");
	if (b==0) printf("!!!!!! b=0\n");
	if (a>4) printf("!!!!!! a>4\n");
	if (b>4) printf("!!!!!! b>4\n");
	return sign ^ MUL[a][b];
}	
std::string show(char a) {
	char sign = (a&0x10);
	a = a&0xF;
	std::string s = a==1 ? "1" : a==2 ? "i" : a==3 ? "j" : a==4 ? "k" : "WTF";
	if (sign) s = "-"+s;
	return s;
}

char arr[10001];

char mulrange(int from, int to) {
	char x = 1;
	for (int i=from; i<to; i++) {
		x = mul(x, arr[i]);
	}
	return x;
}

/*char INV(char x) {
	if (x==1) return 1;
	if (x==-1) return -1;
	return 0x10 ^ x;
}*/


#include "stdio.h"
int main(int argc, char* argv[])
{
	char s[10010];
	cin.getline(s,10010);
	int T;
	sscanf(s, "%d", &T);

	/*for(int i=1; i<=4; i++) {
		for(int j=1; j<=5; j++) {
			printf("%s*%s=%s\t", show(i).c_str(), show(j).c_str(), show(mul(i,j)).c_str());
		}
		printf("\n");
	}*/
		
	FN(ca,T) {
//		if (ca>3) break; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		cin.getline(s,10010);
		int L,X;
		sscanf(s, "%d %d", &L, &X);
		cin.getline(s,10010);
		
		int N = L*X;
		
		FN(i,N) arr[i] = val(s[i%L]);
//		printf("case %d: L=%d X=%d N=%d\n", ca, L, X, N);
		//printf(s);printf("\n");
		
		char start[10001], end[10001];
		start[0] = 1;
		for (int i=1; i<=N; i++) {
			start[i] = mul(start[i-1], arr[i-1]);
		}
		
		
		end[N] = 1;
		for (int i=N-1; i>=0; i--) {
			end[i] = mul(arr[i], end[i+1]);
		}

		/*cout<<"Input="; FN(i,N) cout<<show(arr[i%L]); cout<<endl;
		cout<<"start="; for (int i=0; i<=N; i++) cout<<show(start[i])<<" "; cout<<endl;
		cout<<"end  ="; for (int i=0; i<=N; i++) cout<<show(end[i])<<" "; cout<<endl;*/

/*CHECK
		for (int i=0; i<N; i++) {
			for(int j=i+1; j<=N; j++) {
				char A = start[i], C=start[j];
				char B = mulrange(i, j);
				char Bx = mul(INV(A), C);
				//if (B!=Bx) cout<<"WRONG: i="<<i<<" j="<<j<<" A="<<show(A)<<" B="<<show(B)<<" C="<<show(C)<<" but Bx="<<show(Bx)<<endl;
			}
		}*/


		int found = 0;
		if (start[N]==0x11) { // ijk=-1, skip otherwise
			for (int i=0; i<N && !found; i++) {
				if (start[i]!=2) continue; // 'i'				
	//			cout<<"* from 0 to "<<i<<" yields 'i'"<<endl;
				for(int j=i+1; j<=N && !found; j++) {
					if (end[j]!=4) continue; // 'k'
					found=1;
				}			
			}
		}		
		/*
		int prev[510],cur[510];
		int N=strlen(text);
		FN(i,N)prev[i]=1;

		for (int j=M-1; j>=0; j--) {
			char c = pattern[j];
			cur[N]=0;
			for (int i=N-1; i>=0; i--) {
				cur[i]=cur[i+1];
				if (c==text[i]) {
	//				cout<<"text["<<i<<"]==pattern["<<j<<"]=="<<c<<endl;
					cur[i]=(cur[i]+prev[i])%1000; //MODULO
				}
			}

	//		FN(j,M+1)cout<<cur[j]<<" ";cout<<endl;
			memcpy(prev,cur,sizeof(cur));
		}
		* */
		char s[100];
		sprintf(s, "Case #%d: %s\n", ca+1, found?"YES":"NO");
		cout<<s;
	}

	return 0;
}
// END CUT HERE 
