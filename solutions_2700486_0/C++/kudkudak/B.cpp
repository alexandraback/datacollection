#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <list>
#include <set>
#include <queue>
#include <iostream>
#include <map>
#include <bitset>

using namespace std;

typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PI;
typedef pair<double,double> PD;

#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); ......x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) (int)(x).size()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second

#define DEBUG 1
#define DEBUG_ON
#define INF 10000000; 


#define NEWLINE cout<<"\n"
#define REPORT(x) cout<<#x<<"="<<(x)<<endl;
#define ASSURE(x) cout<<#x<<endl<<flush
#define ASSERT(x) if(!(x)) REPORT("warunek nie spelniony!!")
template <typename T>
void write(T begin, T end)
{
	T ptr = begin;
	while(ptr!=end){
		cout<<*(ptr++)<<" ";
	}
	cout<<endl;
} 
template <>
void write(pair<int,int> * begin, pair<int,int> * end){
	pair<int,int>* ptr = begin;
	while(ptr!=end){
		cout<<"("<<(ptr->first)<<","<<(ptr->second)<<") ";
		++ptr;
	}
	cout<<endl;

}	
template <typename T>
T to(const std::string & s)
{
    std::istringstream stm(s);
    T result;
    stm >> result;
    return result;
}



template<class T, class K>
ostream& operator<<(ostream& out, const pair<T,K> & p){
	out<<"("<<p.first<<","<<p.second<<")";
	return out;
}

// A space optimized Dynamic Programming Solution
int binomialCoeff(int n, int k)
{
    int* C = (int*)calloc(k+1, sizeof(int));
    int i, j, res;
 
    C[0] = 1;
 
    for(i = 1; i <= n; i++)
    {
        for(j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j-1];
    }
 
    res = C[k];  // Store the result before freeing memory
 
    free(C);  // free dynamically allocated memory to avoid memory leak
 
    return res;
}

void processCase(){
	int N,X,Y;
	scanf("%d %d %d",&N,&X,&Y);
	
	
	//wylicz wspolrzedne piramidowe
	int T=0,K=0,W=0;
	

	
	int ommited = 0;
	while(N>ommited){
		T+=1;
		ommited += 4*T-3;
	} ommited -= (4*T-3);

	K = N - ommited;

	int T_field = (abs(X)+Y)/2 + 1;

	if(T_field>T) {printf("0.0\n"); return;}
	else if(T_field<T) {printf("1.0\n");return;}
	
	
	//jestesmy na stosie ostatecznym
	if(X>0) X=-X;
	W = Y + 1;

	if(W==2*T-1){ 
		if(K == 4*T-3) printf("1.0\n");
		else printf("0.0\n");
		return;
	}
	
	float basic_prob = 1/(float)(1<<K);

	if(K<=(2*T-2)){
	float acc = 0;
	for(int i=W; i<=K;++i){
		
		acc += binomialCoeff(K,i)*basic_prob;
	}
	
	printf("%f\n",acc);
	}else{
		
	float acc = 0;
	for(int i=1; i<=K;++i){
		int good = (i>(2*T-2))? i : (i + ((K-i)-(2*T-2)));
		if(good<W) continue;
		acc += binomialCoeff(K,i)*basic_prob;
	}
	
	printf("%f\n",acc);	
	}
}

int main(){
	int T;
	scanf("%d",&T);
	
	REP(i,T){
			printf("Case #%d: ",i+1);
			processCase();
	}
	
	return 0;
}
