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

vector<int> motes,d;
void processCase(){
	// load variables//
	int a,n;
	scanf("%d %d",&a,&n);
	
	motes.resize(n); d.resize(n);
	
	int x;
	REP(i,n){
		scanf("%d",&x);
		motes[i]=x;
	}
	sort(motes.begin(), motes.begin()+n);

	//construct D -array//

	int mote_size_eaten=a;
	REP(i,n){
		d[i] = mote_size_eaten;
		mote_size_eaten += motes[i];
	}
	

	int add=0, op=0, op_alternative=100*n;
	int mote_size = a;
	
	while(1){
		
		
		int i_problem=0;
		while(i_problem!=n && d[i_problem]+add > motes[i_problem]) ++i_problem;
		
		//mozemy policzyc alternatywe
		op_alternative = min(op_alternative,op + n-i_problem); //usuwam te
		//REPORT(op);
		//REPORT(op_alternative);		
		if(op >= op_alternative) break; //tylko rosnie
		

		//REPORT(i_problem);
		if(i_problem == n) break; //all clear
		
		//problem
		
		mote_size = d[i_problem]+add;
		
		op += 1;
		add += mote_size - 1; //dodajemy pylek o prawie najwiekszej wartosci
		
		//REPORT(add);
	}
	printf("%d\n",min(op_alternative,op));

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
