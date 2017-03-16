#include "stdio.h"
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#define ll long long
using namespace std;

#define isc(c) ((c)!='a' && (c)!='e' &&(c)!='i' && (c)!='o' && (c)!='u')

int getAns(char* name, int len,int n) {
	int ret=0;
	int c;
	for(int i=0; i<=len-n; ++i) {
		for(int j=i+n; j<=len; ++j) {
			c=0;
			for(int k=i; k<j; ++k) {
				if(!isc(name[k])) c=0;
				else	++c;
				if(c>=n) break;
			}
			if(c>=n) ++ret;
		}
	}
	return ret;
}
int main() {
	FILE *fp, *fp2;
	int num;
	char name_c[105];
	string name;
	int n;
	char tmp;

	fopen_s(&fp, "A-small-attempt0.in", "r");
	fopen_s(&fp2, "A-small-attempt0.out", "w");
	fscanf_s(fp, "%d", &num);

	int c=0;
	for(int i=0; i<num; ++i) {
		fscanf_s(fp, "%c", &tmp);
		fprintf(fp2,"Case #%d: ",i+1);
		c=0; tmp=0;
		do{
			fscanf_s(fp, "%c", &tmp);
			if(tmp!=' ') {
				name_c[c]=tmp;
				++c;
			}
		}while(tmp!=' ');
		fscanf_s(fp, "%d",&n);
		fprintf(fp2, "%d\n", getAns(name_c, c,n));
	}

	fclose(fp);
	fclose(fp2);
	return 0;
}
