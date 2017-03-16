#pragma comment(linker,"/STACK:250000000")
#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
#define x first
#define ind second

const double PI=acos(-1.0);

vector<string> split(string str,string sep)
{
	char *S=new char[str.size()+2];
	char *Sep=new char[sep.size()+2];
	strcpy(S,str.c_str());
	strcpy(Sep,sep.c_str());
	vector<string> res;
	for (char *curr=strtok(S,Sep);curr;curr=strtok(0,Sep))
		res.push_back(curr);
	delete []S;
	delete []Sep;
	return res;
}
template<class T> T SQR(const T &a){return a*a;}

map<char,char> mp;

void test(int Test)
{
	char str[1000];
	gets(str);
	printf("Case #%d: ",Test);
	rep(i,0,strlen(str))
		if (str[i]>='a' && str[i]<='z')
			putchar(mp[str[i]]);
		else
			putchar(str[i]);
	puts("");
}

int main()
{
	freopen("A-small-attempt2.in","r",stdin);
	freopen("A-small.out","w",stdout);
	char A[]="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd	de kr kd eoya kw aej tysr re ujdr lkgc jv";
	char B[]="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	rep(i,0,strlen(A))
		mp[A[i]]=B[i];
	//cout<<mp.size()<<endl;
	mp['q']='z';
	mp['z']='q';
	int t;
	cin>>t;
	cin.get();
	rep(i,0,t)
		test(i+1);
	return 0;
}

/*
*/