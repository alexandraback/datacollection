// All includes 
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

#include <list>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>

#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include <functional>
#include <numeric>
#include <iomanip>
#include <cstdio>

// All Macros
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin(); it != (c).end() ; it++ )
#define F(i,mi,ma) for(int i=mi;i<ma;i++)

#define vi vector< int >
#define vs vector< string >
#define bn begin()
#define en end()
#define sz size()
#define pb push_back

#define mp make_pair
#define itr iterator

#define ld long double
#define ll long long

#define Fu(i,min,ma,inc) for(int i=min;i<ma;i+= inc)
#define Fd(i,ma,min,dec) for(int i=ma;i>=min;i-= dec)
#define vvi vector< vector< int > >
#define vvs vector < vs >
#define vd vector< double >
#define vvd vector< vd >
#define vb vector< bool >
#define vll vector< ll >

#define ERR 0.000001

using namespace std;

int getminL(const string &L)
{
    int a=L.sz/2, b=L.sz ;
    string t1,t2;
    F(i,0,a){
            t1 = L.substr(  b-(a-i) );
            t2 = L.substr( 0, (a-i));
            if(t1==t2) return b-(a-i);
    }
    return b;
}
    
     
long long STL(string s){
     long long a=s[0]-'0';
     for(int i=1;i<s.size();i++)
             a=a*10+(s[i]-'0');
     return a;
} 
vector<int> SPint(string s,const string delim){
            vector<int> ans(0);
            string::size_type t=0,p=0;
            int N=0;
            while(true){
                   stringstream str;
                   p= s.find_first_of(delim,t);
                   if(p== string::npos  ){str<<s.substr(t);if(str.str()=="")break;str>>N;ans.pb(N);break;}
                   if(p!=t){str<< s.substr(t,p-t);str>>N;ans.pb(N);}
                   t=p+1;
            }
            return ans;
}
double getn1(vi kls, string &K, string &L, int &tb )
{
     int minL = getminL(L);
     tb = kls[2]/minL ;
     int tk = K.sz;
     
     map<char,double> kp;
     F(i,0,K.sz) kp[ K[i] ] += 1.0/(1.0*tk);
     
     double retp=1.0;
     F(i,0,L.sz) {
                 retp *= kp[ L[i] ]; 
                 if( kp[ L[i] ] == 0.0 ) { tb=0; return 0.0;}
     }
     
     return (1-retp)*tb;
}

                  
    
int main()
{
    ifstream in("B-small-attempt1.in");
    ofstream out("B-small-attempt1.out");
    
   // ifstream in("A-large.in");
   // ofstream out("A-large.out");
    
    //while(in){
              string s,K,L;
              getline(in,s);
              int T = STL(s);
              F(i,0,T){
                       getline(in,s);
                       //cout<<s<<endl;
                       vi kls = SPint(s," ");
                       getline(in,s);
                       K=s;
                       getline(in,s);
                       L=s;
                       int tb=0;                       
                       
                       double ans1=getn1(kls,K,L,tb);
                       
                       if( ans1 == int(ans1) ){
                           int ttt = int(ans1);
                           out<<"Case #"<<i+1<<": "<<ttt<<".0"<<endl;
                       }
                       else{
                            
                           out<<"Case #"<<i+1<<": "<< ans1<<endl;
                       }
              }
    //}
    out.close();
    in.close();
    cout<<"done";
    getchar();
}
