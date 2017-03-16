/*******************************************************************
*                          CODE JAM 2012
*                    ROUND:                 1A 
*                       CONTESTER:  yi
*                           Problem: A
*******************************************************************/
 
// headers
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#include <omp.h>
//#include <gmp>


//DEBUGING

#ifdef DEBUG
#define ASSEART(X)     if (!(X)) {printf("\n %s: assertion failed at line %d\n",__FILE__,__LINE__);exit(0);} 
#define PRINT(fmt, args...) printf("%s:%s:%d: "fmt, __FILE__, __FUNCTION__, __LINE__, args); 
#define PVAR(var) cout<<__FILE__<<":"<<__FUNCTION__<<":"<<__LINE__<<":    "<<#var<<" = "<<var<<endl;
#define PLINE(array,n) \
printf("\n%s:%s:line %d : "#array"[0:%d]=\n",__FILE__, __FUNCTION__, __LINE__,n);\
for(register size_t __i__=0;__i__<n;__i__++) \
    cout<<__i__<<" ";\
cout<<endl;\
for(register size_t __i__=0;__i__<n;__i__++) \
        cout<<array[__i__]<<" ";\
        cout<<endl;
#define PMAP(array,n,m,fmt) {\
printf("%s:%s:line %d : "#array"[0:%d][0:%d]=\n",__FILE__, __FUNCTION__, __LINE__,n,m);\
cout<<"  ";\
for(register size_t __j__=0;__j__<m;__j__++) \
cout<<__j__;\
cout<<endl;\
for(register size_t __i__=0;__i__<n;__i__++) {\
    cout<<__i__;\
    for(register size_t __j__=0;__j__<m;__j__++) \
        printf(fmt,array[__i__][__j__]);\
    cout<<endl;\
}\
}
#define PBIN(n) {\
        int i,bit[256];\
        for(i=0;i<sizeof(n)*8;i++) {bit[i]=n%2;n>>=1;}\
        for(;i>0;i--) {cout<<bit[i-1];}\
    }
#define EVAL(cmd) cmd
#else
#define PMAP(array,n,m,fmt) 
#define ASSEART(X)
#define PVAR(var)
#define PRINT(fmt, args...) 
#define PLINE(array,n)
#define PBIN(n)
#define EVAL(cmd)
#endif
//Helpers
#define repeat(n,__i__) for(register size_t __i__=0;__i__<n;__i__++) 
#define all(cnt) cnt.begin(),cnt.end()
#define forall(cnt,it) for(typeof(cnt.begin()) it=cnt.begin();it!=cnt.end();it++)
#define RCMAP(array,n,m) \
    for(register size_t __i__=0;__i__<n;__i__++) {\
        string __l__;\
        getline(cin,__l__);\
        for(register size_t __j__=0;__j__<m;__j__++) {\
            array[__i__][__j__]= __l__[__j__];\
        }\
    }
#define RMAP(array,n,m) \
    for(register size_t __i__=0;__i__<n;__i__++) {\
        string __l__;\
        getline(cin,__l__);\
        for(register size_t __j__=0;__j__<m;__j__++) {\
            istringstream(__l__)>>array[__i__][__j__];\
        }\
    }
typedef long long ll;

//Possible Template classes (Graph, Geometric...).         

//Test Case 
class TestCase {
    //Helpers
    template <typename t_input>
    void inline readSeq(t_input A,size_t N,istream& input=cin) {
        for(size_t i=0;i<N;i++) input>>A[i];
    };
//    inline readMap(int N,M) {};
    //static const int Limit=1;
    
    //variables list
    int A,B;
    double r1;
    vector<double> p;
    //Implement details
    
public:
    //Input
    TestCase(istream& input) {
        init(input);
    }
    //TestCase(i,j,k) : N(i),J(j),K(k) {};
    template<class _stream>
    void init(_stream& input=cin) {
        string line;
        getline(input,line);
        istringstream(line)>>A>>B;
        p.resize(A);
        repeat(A,i) input>>p[i];
        getline(input,line);
    };
    //solve the problem
    void solve() {
        //TEST input first?
//        cout<<A<<","<<B<<endl;
//        repeat(A,i) cout<<p[i]<<" ";
        //case1
        double p1=1.0;
        p1=1.0;
        repeat(A,i) p1*=p[i];
        r1=p1*(B-A+1)+(1-p1)*(2*B-A+2);
        //case 2
        double r2=1e100;
        double p2=p1;
        double p3=1.0;
        for(int i=A-1;i>=0;i--) {
            p3*=p[i];
            p2=p1*(1-p3)/p3;
            r2=min(r2,(p1+p2)*(B-A+2*(A-i)+1)+(1-p2-p1)*(2*B-A+2*(A-i)+2));
//            cout<<p2<<","<<r2<<endl;
        }
        r1=min(r1,r2);
        return ;
    };
    //format output
    double result() {
        double r=min(r1,B+2.0);
        return r;
    };
};
    
// ------------------------ Start @ Fri Apr 27 21:08:11 EDT 2012 ---------------------------------------

int main() {
    int nCase;
    string line;
    getline(cin,line);
    istringstream(line)>>nCase;
    vector<TestCase> testcases;
    for(int i=0;i<nCase;i++) testcases.push_back(TestCase(cin));
#pragma omp parallel for num_threads(4)
    for(int i=0;i<nCase;i++) testcases[i].solve();
    cout.precision(6);
    for(int i=0;i<nCase;i++) {
        cout<<"Case #"<<i+1<<": ";
        printf("%.6f\n",testcases[i].result());
    }

}

//Statistics
//------- finished small at Fri Apr 27 21:55:39 EDT 2012--------------
