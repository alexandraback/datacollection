#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef deque<char> str;

ostream& operator<<(ostream& os, str charlist){
	str::iterator it;
	for(it=charlist.begin();it!=charlist.end();it++)
		os << *it;
	return os;
}

ll strToInt(str s){
	ll result=0;
	for(ll i=0;i<s.size();i++){
		result*=10;
		result+=s[i]-'0';
	}
	return result;
}

template <typename T>
bool next_selection(T* begin, T* end, T** selectBegin, T** selectEnd){
	if(*(selectEnd-1)<end-1){
		(*(selectEnd-1))++;
		return true;
	}
	else if(selectBegin+1==selectEnd){
		*selectBegin=begin;
		return false;
	}
	else{
		bool result=next_selection(begin,end-1,selectBegin,selectEnd-1);
		*(selectEnd-1)=1+*(selectEnd-2);
		return result;
	}
}

ll facll(ll n){
	if(n)
		return n*facll(n-1);
	return 1;
}

ld facld(ll n){
	if(n)
		return (ld)n * facld(n-1);
	return 1.;
}

#define mp make_pair
#define x first
#define y second
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define hash unordered_map

#define v(type) deque<type >
#define it(container) typeof((container).begin())
#define all(x) (x).begin(), (x).end()
#define select(x,i) (x).begin()+(i), (x).begin()+(i)+1
#define foreach(cit,container) for(typeof((container).begin()) cit = (container).begin(); cit != (container).end(); cit++)
#define foreachc(c,cit,container) {ll c=0;for(typeof((container).begin()) cit = (container).begin(); cit != (container).end(); c++, cit++)
#define forn(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define fornn(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define fore(i, a, b) for (ll i = (ll)(a); i <= (ll)(b); ++i)

#define inf 9000000000000000000L
#define eps 1e-15

void init(){
}

typedef ll otype;
otype calcFunction(ll r, ll c, ll w) {
	if(w==1)
		return r*c;
	otype result=0;
	v(ll) values;
	bool ** array=new bool*[r];
	forn(i,r){
		array[i]=new bool[c];
		forn(j,c){
			if((i+j)%w==w-1){
				array[i][j]=true;
				ll counter=0;
				if(0<i && i<r-1 && r>=2 && c>=2)
					counter=2;
				else if(0<j && j<c-1 && r>=2 && c>=2)
					counter=2;
				else if((i==0 || i==r-1) && (j==0 || j==c-1) && c>=2 && r>=2)
					counter=1;
				else if(c==1 || r==1){
					if( (0<i && i<r-1) || (0<j && j<c-1))
						counter=1;
					else
						counter=0;
				}
				values.pub(counter);
			} else {
				array[i][j]=false;
			}
		}
	}
	sort(all(values));
	/*
	foreach(val,values){
		cout << *val << endl;
	}
	cout << endl;
	*/
	ll max=0;
	foreachc(c,val,values){
		ll current=values.size()-c-1+*val+w;
		if(max<current)
			max=current;
	}}
	return max;
}

int main() {
	init();
	ofstream outfile("output.txt");
	ll tests = 0;
	cin >> tests;
	fore(test, 1, tests){
		//read input
		ll r, c, w;
		cin >> r >> c >> w;
		//write output
		otype result=calcFunction(r,c,w);
		outfile << "Case #" << test << ": ";
		outfile << result << endl;continue;
		if(result>=0)
				outfile << result << endl;
		else if(result<0)
			outfile << "FALSE" << endl;
	}
	outfile.close();
	return 0;
}