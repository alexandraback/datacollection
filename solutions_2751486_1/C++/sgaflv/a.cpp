
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <iostream>
#include <assert.h>



#include <algorithm>
#include <map>
#include <vector>
#include <set>

using namespace std;

#define PI 3.14159265358979323
#define EPS 0.000000001
#define INF 1000000000

int T;



char lc;

int l;
int n, m;

char buf[1000010];

bool is_vowel(char a) {
	if (a==0) return false;
	switch (a) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return true;
		default:
			return false;
	}
}

bool is_cons(char a) {
	if (a==0) return false;
	return !is_vowel(a);
}


int main() {
	cin>>T;
	int cs=1;
	char tc;
	
	while (T-->0) {
		
		scanf("%s %d", buf, &n);
		
//		cout<<buf<<" "<<n<<endl;
		
		l = strlen(buf);
		
		int i1 =0;
		int i2 = 0;
		int st=0;
		int cnt=0;
		long long res=0;
		
		while (i2<l) {
			
			while (is_vowel(buf[i2])) i2++;
			
			
			st=i2;
			while (is_cons(buf[i2])) {
				
				if (i2-st+1>=n) {
				
//			cout<<"i2="<<i2<<" st="<<st<<" i1="<<i1<<endl;
					while (i1<=st) {
						res+=l-i2;
						i1++;
					}
					
					st++;
				}
				
				i2++;
				
			}
			

			
		}
		
		printf("Case #%d: ", cs++);
		
		cout<<res;
		
		printf("\n");
	}
	
    return 0;
    
}


