
/*Paresh Verma*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <cstring>
#include <queue>		//max heap implementation
#include <limits.h>

#define pub push_back
#define pob pop_back
#define fi first
#define se second
#define debug(a) { for( typeof(a.begin()) it = a.begin() ; it != a.end() ; it++ ) cout << *it << " "; cout << endl; }

using namespace std;

//class comparators for queue and others
class classcomp{
	public:
		bool operator() (const int& l, const int& r)const{
			return l<r;
		}
};


int main(){
	char in[][100]={"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	char out[][100]={"our language is impossible to understand","there are twenty six factorial possibilities","so it is okay if you want to just give up"};
	int a[26];
	memset(a,120,sizeof(a));
	int i,j,k,l;
	for(i=0;i<3;i++){
		l=strlen(in[i]);
		for(j=0;j<l;j++){
			if(in[i][j]!=' '){
				a[in[i][j]-'a']=out[i][j]-'a';
			}
		}
	}
	a['q'-'a']='z'-'a';
	a['z'-'a']='q'-'a';

/*	for(i=0;i<26;i++){
		printf("%c",a[i]+'a');
	}
	printf("\n");
*/
	int T;
	char c;
	scanf("%d\n",&T);
	for(int p=1;p<=T;p++){
		printf("Case #%d: ",p);
		while(1){
			scanf("%c",&c);
			if(c=='\n'){
				printf("\n");
				break;
			}
			if(c==' ')
				printf(" ");
			else
				printf("%c",a[c-'a']+'a');
		}
	}
	return 0;
}
