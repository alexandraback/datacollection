#include <stdio.h>
#include <map>
#include <set>
using namespace std;

int T;


void doFall(int fall){
	printf("Case #%d: ", fall);
	int A, B;
	scanf("%d %d",&A,  &B);
	set<pair<int, int> > recycles;
	char s[16];
	char recycl[16];
	for(int start = A; start <= B; start++){
		sprintf(s, "%d", start);
		sprintf(recycl, "%d", start);
		int len = strlen(s);
		for(int mod=1;mod<len;mod++){
			for(int i=0;i<len;i++){
				recycl[i] = s[(i+mod)%len];
			}
			int r;
			sscanf(recycl, "%d", &r);
			if(r<A || r>B){
				continue;
			}
			int m,n;
			if(start<r){
				n = start;
				m = r;
			} else if(start>r){
				n = r;
				m = start;
			} else {
				continue;
			}			
			recycles.insert(make_pair(n, m));
		}
	}
	printf("%d\n", recycles.size());
	/*for(set<pair<int, int> >::iterator it = recycles.begin(); it != recycles.end(); ++it){
		printf("%d -> %d\n", it->first, it->second);
	}*/
}

int main(){
	scanf("%d", &T);
	for(int fall=1;fall<=T;fall++){
		doFall(fall);
	}	
}