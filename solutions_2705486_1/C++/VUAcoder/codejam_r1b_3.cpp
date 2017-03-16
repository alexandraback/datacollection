/*
AUTHOR : VUAcoder
LANGUAGE : C++
PROBLEM :
*/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
#include<set>
#include<fstream>
#include<cfloat>
using namespace std;
#define PI (2.*acos(0.))
#define EPS 1e-9
#define ZERO(x)     (fabs(x) < EPS)
#define EQ(a,b)     (ZERO((a)-(b)))
#define LESSER(a,b) (!EQ(a,b) && (a)<(b))
#define GREATER(a,b)(!EQ(a,b) && (a)>(b))
#define GETBIT(x,i) (x&(1<<i))
#define SETBIT(x,i) (x|(1<<i))
#define FORab(i,a,b) for(typeof(b) i=(a);i<=(b);i++)
#define FOR(i,n) FORab(i,0,(n)-1)
#define FOR1(i,n) FORab(i,1,n)
#define FORit(it,a) for( typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define all(a) (a).begin(),(a).end()
#define ms(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define sz(a) (int)a.size()
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define px first
#define py second
#define __eXYZ__
#ifdef __eXYZ__
//USE THESE FOR DEBUG
#define RFILE(a)    freopen(a, "r", stdin)
#define WFILE(a)    freopen(a, "w", stdout)
#define _r(arg) {dbg,arg; dbg.start(); }
#define _n(arg...) {_r(#arg " ==> ");dbg,arg; }
#define _(arg...) { _n(arg); dbg.nl(); }
#else
#define RFILE(a)
#define WFILE(a)
#define _n(arg) {}
#define _n(arg...) {}
#define _(arg...) {}
#endif


typedef long long  LL;
typedef vector<int>   vi;
typedef pair<int,int>  pii;

template<class A, class B> ostream &operator<<(ostream& o, pair<A,B>& p) { //pair print
	return o << "("<<p.first<<", "<<p.second<<")";
}

template<class T> ostream& operator<<(ostream& o, const vector<T>& v) { //vector print
	o << "{";FORit(it, v) o << *it << ", "; return o << "}";
}

struct debugger
{
	ostream &out; bool first;
	void start() { first = true; }
	debugger(ostream& out):out(out) {start();}
	void nl() { out << endl; start(); }
	// Taken from rudradevbasak
	template<class T> debugger& operator,(T& v) {
		if(first) first = false; else out << ", ";
		out << v; return *this;
	}
	template<class T> debugger& operator,(pair<T*,int> arr) { //array print
		out << "{";
			FOR(i, arr.second) { out << arr.first[i] << ", "; }
		out << "}";
		return *this;
	}
} dbg(cerr);
int trie[5000000][26];
int isend[5000000],node_cnt;
void make_trie(int node,string &str,int ind){
    if(ind==sz(str)){
        isend[node]=1;
        return;
    }
    else if(trie[node][str[ind]-'a']==0){
        node_cnt++;
        trie[node][str[ind]-'a']=node_cnt;
        make_trie(trie[node][str[ind]-'a'],str,ind+1);
    }else{
        make_trie(trie[node][str[ind]-'a'],str,ind+1);
    }
}
int search_trie(int node,string &str,int ind,int lastind){
    if(ind==lastind){
        return isend[node];
    }
    else if(trie[node][str[ind]-'a']==0){
        return 0;
    }else{
        return search_trie(trie[node][str[ind]-'a'],str,ind+1,lastind);
    }
}
void dictionary_preprocess(){
    RFILE("garbled_email_dictionary.txt");
    char str[15];

    node_cnt=1;
    while(gets(str)){
        string st=str;
        //if(node_cnt%100000==0)cout<<st<<" "<<node_cnt<<endl;
        make_trie(0,st,0);
        if(st=="codejam")cout<<"PAISI"<<endl;
        //if(!search_trie(0,st,0,sz(st)))cout<<"ERROR"<<endl;
    }

}
#define INF 1000000
string S;
int mem[4010][5];
void printstr(string& S,int ind,int len){
    //FOR(i,len)cout<<S[ind+i];
    //cout<<endl;
    //if(S.substr(ind,len)=="code")cout<<"HELLO"<<endl;
    //if(S.substr(ind,len)=="jam")cout<<"HELLO1"<<endl;
}
int solve(int ind,int togo){
    //cout<<ind<<" "<<togo<<endl;
    if(ind==sz(S))return 0;
    else if(mem[ind][togo]!=-1)return mem[ind][togo];
    int &ret=mem[ind][togo];
    ret=INF;
    int newtogo;
    FOR1(len,10){
        if(ind+len>sz(S))break;
        if(search_trie(0,S,ind,ind+len)){
            //printstr(S,ind,len);
            newtogo=max(togo-len,0);
            ret=min(solve(ind+len,newtogo),ret);
        }

        FOR(i,len){
            if(i<togo)continue;
            FOR(k,26){
                char ch=S[ind+i];
                S[ind+i]='a'+k;
                if(search_trie(0,S,ind,ind+len)){
                    //printstr(S,ind,len);
                    newtogo=max(4-(len-i-1),0);
                    ret=min(solve(ind+len,newtogo)+1,ret);
                }
                S[ind+i]=ch;
            }

            FORab(j,i+5,len-1){
                if(j<togo)continue;
                FOR(k,26){
                    FOR(l,26){
                        char ch1=S[ind+i],ch2=S[ind+j];
                        S[ind+i]='a'+k;S[ind+i]='a'+l;
                        if(search_trie(0,S,ind,ind+len)){
                      //      printstr(S,ind,len);
                            newtogo=max(4-(len-j-1),0);
                            ret=min(solve(ind+len,newtogo)+2,ret);
                        }
                        S[ind+i]=ch1; S[ind+j]=ch2;
                    }
                }
            }
        }
    }
    return ret;

}

int main()
{
    dictionary_preprocess();
    //string str="codejam";
    //cout<<search_trie(0,str,0,7)<<endl;

	RFILE("input.txt");
	WFILE("output_r1b_C_large.txt");
    int t,cn=1;
    //cout<<"gee"<<endl;
	cin>>t;
	while(t--){
	    ms(mem,-1);
	    cin>>S;
        cout<<"Case #"<<cn++<<": "<<solve(0,0)<<endl;
	}

	return 0;
}
