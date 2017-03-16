// prob_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#define out stdout

#define MAXTRIBES	10
#define MAXWALL		500
#define	MIDWALL		250

int N,d[MAXTRIBES],n[MAXTRIBES],w[MAXTRIBES],e[MAXTRIBES],s[MAXTRIBES],delta_d[MAXTRIBES],delta_p[MAXTRIBES],delta_s[MAXTRIBES];
int wall[MAXWALL];

int solv() {
	int table[MAXTRIBES] , result =0; 
	for(int i=0;i<N;i++) {
		table[i]=d[i]; 
	}
	for(int i=0;i<MAXWALL;i++) {
		wall[i] = 0 ; 
	}

	while(true) {
		int mind = -1;
		for(int i=0;i<N;i++) if (n[i]>0 && (mind ==-1 || mind>table[i])) mind=table[i];
		if(mind==-1) break; 
		for(int i=0;i<N;i++) {
			if (n[i]>0 && table[i]==mind) {
				bool attack_succeed = false ; 
				for(int j=w[i];j<e[i];j++) {
					//if (wall[j]>=s[i]) {attack_succeed=false ; break; }
					if (wall[j+MIDWALL]<s[i]) { attack_succeed=true; break;}
				}
				if (attack_succeed) result++;
				//fprintf(out,"(%d,%d,%d,%d,%d,%s)\n",n[i],table[i],w[i],e[i],s[i],(attack_succeed)?"YES":"NO");
			}
		}

		for(int i=0;i<N;i++) {
			if (n[i]>0 && table[i]==mind) {
				for(int j=w[i];j<e[i];j++) {
					if (wall[j+MIDWALL]<s[i]) { wall[j+MIDWALL]=s[i];}
				}
				n[i]--; table[i]+=delta_d[i]; 
				s[i]+=delta_s[i];
				e[i]+=delta_p[i]; w[i]+=delta_p[i];
			}
		}
	}
	return result ; 
}

int _tmain(int argc, _TCHAR* argv[])
{
	int numCases;

	FILE *in = fopen("C-small-attempt0.in","r");
	FILE *out = fopen("output.txt","w");

	fscanf(in,"%d\n",&numCases);

	for(int cnt=1;cnt<=numCases;cnt++){
		fscanf(in,"%d",&N);
		for(int i=0;i<N;i++) {
			fscanf(in,"%d ",&d[i]);
			fscanf(in,"%d ",&n[i]);
			fscanf(in,"%d ",&w[i]);
			fscanf(in,"%d ",&e[i]);
			fscanf(in,"%d ",&s[i]);
			fscanf(in,"%d ",&delta_d[i]);
			fscanf(in,"%d ",&delta_p[i]);
			fscanf(in,"%d\n",&delta_s[i]);
		}

		fprintf(out,"Case #%d: %d\n",cnt,solv());
	}

	fclose(in);
	fclose(out);

	//char temp = getchar();

	return 0;
}

