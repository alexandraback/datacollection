/*
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>
#include <iomanip> 
#include <sstream>
using namespace std;

////////////////////////////////////////////////////
#define TRY
#define SMALL
//#define LARGE
/////////////////////////////////////////////////////
#define INF 100000000
typedef pair<int,int> PII;
#define MP make_pair
#define MAX_N 1000002
////////////////////////////////////////////////////////
void Solve();
void Initial();
//char Func(char x,char y);
map<pair<char,char>, char > mc;
map<string, char> ms;
void main() 
{
#ifdef TRY
	freopen("1.txt", "rt", stdin);
	//freopen("2.out","wt",stdout);
#endif
#ifdef SMALL
	freopen("C-small-attempt0.in","rt",stdin);
	freopen("C-small.txt","wt",stdout);
#endif
#ifdef LARGE
	freopen("C-large.in","rt",stdin);
	freopen("C-large.txt","wt",stdout);
#endif

	int Numcase;
	cin>>Numcase;
	Initial();
	for(int test=1;test<=Numcase;test++)
	{
		cout<<"Case #"<<test<<": ";
		//cout<<"Case #"<<test<<":"<<endl;
		
		Solve();
	}
}

//map<pair<char,char> , char> charmp;

//charmp[make_pair('1','1')]='1';
void Initial(){
	mc[MP('1','1')]='1';
	mc[MP('1','i')]='i';
	mc[MP('1','j')]='j';
	mc[MP('1','k')]='k';
	mc[MP('i','1')]='i';
	mc[MP('i','i')]='0';
	mc[MP('i','j')]='k';
	mc[MP('i','k')]='J';
	mc[MP('j','1')]='j';
	mc[MP('j','i')]='K';
	mc[MP('j','j')]='0';
	mc[MP('j','k')]='i';
	mc[MP('k','1')]='k';
	mc[MP('k','i')]='j';
	mc[MP('k','j')]='I';
	mc[MP('k','k')]='0';
	/////////////////////////////
	mc[MP('0','1')]='0';
	mc[MP('0','i')]='I';
	mc[MP('0','j')]='J';
	mc[MP('0','k')]='K';
	mc[MP('I','1')]='I';
	mc[MP('I','i')]='1';
	mc[MP('I','j')]='K';
	mc[MP('I','k')]='j';
	mc[MP('J','1')]='J';
	mc[MP('J','i')]='k';
	mc[MP('J','j')]='1';
	mc[MP('J','k')]='I';
	mc[MP('K','1')]='K';
	mc[MP('K','i')]='J';
	mc[MP('K','j')]='i';
	mc[MP('K','k')]='1';
}
void Solve(){
	int X,L;
	string str;
	cin>>L>>X;
	cin>>str;
	//check i j k;
	int flag=0;
	if(str.find('i')!=-1) flag++;
	if(str.find('j')!=-1) flag++;
	if(str.find('k')!=-1) flag++;
	if(flag<=1) {cout<<"NO"<<endl;return ;}
	//compute str;
	char temp='1';
	string store="";
	for(int i=0;i<L;i++){
		store += str[i];		
		if(ms.find(store)==ms.end()){
			temp = mc[MP(temp,str[i])];
			ms[store]=temp;
		}
		else  temp = ms[store];	
	}
	if(temp=='1') {cout<<"NO"<<endl;return ;}
	if(temp=='0' && X%2==0) {cout<<"NO"<<endl;return ;}
	else if(temp!='0' && temp!='1' && X%4 != 2) {cout<<"NO"<<endl;return ;}
	///// find i j k
	temp='1';
	store="";
	int p=0;//flag
	for(int i=0;i<X;i++){
		for(int j=0;j<L;j++){
			store += str[j];		
			if(ms.find(store)==ms.end()){
				temp = mc[MP(temp,str[j])];
				ms[store]=temp;
			}
			else  temp = ms[store];
			if(p==0 && temp=='i'){
				store="";
				temp='1';
				p=1;
			}
			else if(p==1 && temp=='j'){
				cout<<"YES"<<endl;return;
			}
		}
	}
	cout<<"NO"<<endl;
}
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>
#include <iomanip> 
#include <sstream>
using namespace std;

////////////////////////////////////////////////////
#define TRY
//#define SMALL
#define LARGE
/////////////////////////////////////////////////////
#define INF 100000000
typedef pair<int,int> PII;
#define MP make_pair
#define MAX_N 1000002
////////////////////////////////////////////////////////
void Solve();
void Initial();
//char Func(char x,char y);
map<pair<char,char>, char > mc;
map<string, char> ms;
void main() 
{
#ifdef TRY
	freopen("1.txt", "rt", stdin);
	//freopen("2.out","wt",stdout);
#endif
#ifdef SMALL
	freopen("C-small-attempt0.in","rt",stdin);
	freopen("C-small.txt","wt",stdout);
#endif
#ifdef LARGE
	freopen("C-large.in","rt",stdin);
	freopen("C-large.txt","wt",stdout);
#endif

	int Numcase;
	cin>>Numcase;
	Initial();
	for(int test=1;test<=Numcase;test++)
	{
		cout<<"Case #"<<test<<": ";
		//cout<<"Case #"<<test<<":"<<endl;

		Solve();
	}
}

//map<pair<char,char> , char> charmp;

//charmp[make_pair('1','1')]='1';
void Initial(){
	mc[MP('1','1')]='1';
	mc[MP('1','i')]='i';
	mc[MP('1','j')]='j';
	mc[MP('1','k')]='k';
	mc[MP('i','1')]='i';
	mc[MP('i','i')]='0';
	mc[MP('i','j')]='k';
	mc[MP('i','k')]='J';
	mc[MP('j','1')]='j';
	mc[MP('j','i')]='K';
	mc[MP('j','j')]='0';
	mc[MP('j','k')]='i';
	mc[MP('k','1')]='k';
	mc[MP('k','i')]='j';
	mc[MP('k','j')]='I';
	mc[MP('k','k')]='0';
	/////////////////////////////
	mc[MP('0','1')]='0';
	mc[MP('0','i')]='I';
	mc[MP('0','j')]='J';
	mc[MP('0','k')]='K';
	mc[MP('I','1')]='I';
	mc[MP('I','i')]='1';
	mc[MP('I','j')]='K';
	mc[MP('I','k')]='j';
	mc[MP('J','1')]='J';
	mc[MP('J','i')]='k';
	mc[MP('J','j')]='1';
	mc[MP('J','k')]='I';
	mc[MP('K','1')]='K';
	mc[MP('K','i')]='J';
	mc[MP('K','j')]='i';
	mc[MP('K','k')]='1';
}
void Solve(){
	//int X,L;
	long long X,L;
	char st[10002];
	cin>>L>>X;
	scanf("%s",st);
	//check i j k;
	string str=st;
	int flag=0;
	if(str.find('i')!=-1) flag++;
	if(str.find('j')!=-1) flag++;
	if(str.find('k')!=-1) flag++;
	if(flag<=1) {cout<<"NO"<<endl;return ;}
	//compute str;
	char temp='1';
	string store="";
	for(int i=0;i<L;i++){
		temp = mc[MP(temp,str[i])];
	}
	if(temp=='1') {cout<<"NO"<<endl;return ;}
	if(temp=='0' && X%2==0) {cout<<"NO"<<endl;return ;}
	else if(temp!='0' && temp!='1' && X%4 != 2) {cout<<"NO"<<endl;return ;}
	///// find i j k
	temp='1';
	store="";
	int p=0;//flag
	long long innerX=0;
	for(long long i=0;i<X;i++){
		if(innerX>6) {cout<<"NO"<<endl;return;}
		innerX++;
		for(int j=0;j<L;j++){
			temp = mc[MP(temp,str[j])];
			if(p==0 && temp=='i'){
				temp='1';
				p=1;
				innerX=0;
			}
			else if(p==1 && temp=='j'){
				cout<<"YES"<<endl;return;
			}
		}
	}
	cout<<"NO"<<endl;
}