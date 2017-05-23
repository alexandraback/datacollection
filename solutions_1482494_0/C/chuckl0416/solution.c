#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

void Merge(int A[][3], int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1+1][3], R[n2+1][3];
	int i, j, k;
	
	for (i=0; i<n1; i++) { L[i][0] = A[p+i][0]; L[i][1] = A[p+i][1]; L[i][2] = A[p+i][2]; }
	for (j=0; j<n2; j++) { R[j][0] = A[q+j+1][0]; R[j][1] = A[q+j+1][1]; R[j][2] = A[q+j+1][2]; }
	
	
	i=0;
	j=0;
	
	for (k=p; k<=r; k++){
		if (i<n1 && j<n2){
			if (L[i][1]>R[j][1]) { A[k][0] = L[i][0]; A[k][1] = L[i][1]; A[k][2] = L[i][2]; i++;}
			else if (L[i][1]==R[j][1]){
				if (L[i][0]>R[j][0]) { A[k][0] = L[i][0]; A[k][1] = L[i][1]; A[k][2] = L[i][2]; i++;}
				else { A[k][0] = R[j][0]; A[k][1] = R[j][1]; A[k][2] = R[j][2]; j++;}
			}
			else { A[k][0] = R[j][0]; A[k][1] = R[j][1]; A[k][2] = R[j][2]; j++;}
		}
		else if (i<n1) { A[k][0] = L[i][0]; A[k][1] = L[i][1]; A[k][2] = L[i][2]; i++;}
		else { A[k][0] = R[j][0]; A[k][1] = R[j][1]; A[k][2] = R[j][2]; j++;}
	}
	
}

int Partition(int A[][3], int p, int r){
	if (p<r){
		int q = (p+r)/2;
		Partition(A, p, q);
		Partition(A, q+1, r);
		Merge(A, p, q, r);
	}
}





int main(){
	FILE *fin, *fout;
	fin = freopen("B-small-attempt0.in", "r", stdin);
	fout = freopen("B-small-attempt0.out", "w", stdout);
	
	int Testcases, TCCount;
	scanf("%d", &Testcases);
	int i, Levels, Possible, PossibleMin, StarsGained, Limit;
	int Star[2000][3]; /*0: 1-Star, 1: 2-Star, 2: Gained*/
	int Time[2000];
	for (TCCount=1; TCCount<=Testcases; TCCount++){
		printf("Case #%d: ", TCCount);
		Possible = 1;
		scanf("%d", &Levels);
		scanf("%d%d", &Star[0][0], &Star[0][1]);
		if (Star[0][1]>(2*Levels)) Possible = 0;
		PossibleMin = Star[0][0];
		Star[0][2]=0;
		for (i=1; i<Levels; i++){
			scanf("%d%d", &Star[i][0], &Star[i][1]);
			if (Star[i][1]>(2*Levels)) Possible = 0;
			if (Star[i][0]<PossibleMin) PossibleMin = Star[i][0];
			Star[i][2]=0;
		}
		if (PossibleMin) Possible=0;
		if (Possible==0) { printf("Too Bad\n"); continue;}
		
		StarsGained = 0;
		Partition(Star, 0, Levels-1);
		Limit = Levels*2;
		
		int Ans =0;
		
		for (i=0; i<Levels; i++){
			Limit-=2;
			if (Star[i][1]<=Limit) Time[i]=1;
			else { Limit++; Time[i]=2; }
			
			
		}
		
		for (i=0; i<Levels; i++){
			Ans += Time[i];
		}
		
		printf("%d", Ans);
		
		
		
		
		
		putchar(10);
	}
	
	fclose(fin);
	fclose(fout);
	//system("Pause");
	return 0;
}
