#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
using namespace std;

void shift_k(char* kk, int lk)
{
	int i;
	char t=kk[lk-1];
	for(i=lk-1;i>0;i--) kk[i]=kk[i-1];
	kk[0]=t;
}

int main()
{
	int t,T,A,B,k,tk,i,lk,c;
	char kk[10];
	scanf("%d", &T);
	for(t=0;t<T;t++) {
		scanf("%d %d", &A,&B);
		c=0;
		for(k=A;k<B+1;k++) {
			set<int> tset;
			sprintf(kk,"%d", k);
			lk=strlen(kk);
			for(i=1;i<lk;i++) {
				shift_k(kk, lk);
				tk=atoi(kk);
				if(tk<k && tk>=A) { 
					pair<set<int>::iterator,bool> r=tset.insert(tk);
					if(r.second) c++;
				}
			}
		}
		printf("Case #%d: %d\n", t+1, c);
	}
}
