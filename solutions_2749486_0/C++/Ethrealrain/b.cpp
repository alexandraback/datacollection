#include <cstdio>
#include <algorithm>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <memory.h>
#include <iostream>
#include<list>
#include <iomanip>
#include<stack>
#include<unistd.h>
using namespace std;

#define pb push_back
#define sz size()
#define mp make_pair
#define mset(ar,val) memset(ar,val,sizeof ar)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))


void scan(int* i) {int t = 0;char c;bool negative = false;c = getchar_unlocked();while (c < '0' || c > '9') {if (c == '-')negative = true;c = getchar_unlocked();}while (c >= '0' && c <= '9') {t = (t << 3) + (t << 1) + c - '0';c = getchar_unlocked();}if (negative)t = ~(t - 1);*i = t;}
void scan(long long int* i) {long long int t = 0;char c;bool negative = false;c = getchar_unlocked();while (c < '0' || c > '9') {if (c == '-')negative = true;c = getchar_unlocked();}while (c >= '0' && c <= '9') {t = (t << 3) + (t << 1) + c - '0';c = getchar_unlocked();}if (negative)t = ~(t - 1);*i = t;}

int tarx,tary;
bool found;
struct pos{
	int cx,cy;
};
vector<pos>path;
pos temp;

int main() {
	string result="";
	int T,t,x,y;
	scan(&T);
	for(t=1;t<=T;++t){
		x=y=0;
		found=0;
		scan(&tarx);
		scan(&tary);
		cout<<"Case #"<<t<<": ";
		if(x<tarx)
			while(x!=tarx)
				cout<<"WE",++x;
		if(x>tarx)
			while(x!=tarx)
				cout<<"EW",--x;
		if(y<tary)
			while(y!=tary)
				cout<<"SN",++y;
		if(y>tary)
			while(y!=tary)
				cout<<"NS",--y;
		cout<<endl;
	}
	return 0;
}

