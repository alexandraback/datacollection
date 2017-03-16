#include <stdio.h>
#include <stdlib.h>

// example of qsort: http://www.vivaolinux.com.br/artigo/Utilizando-a-funcao-QSort-em-C?pagina=4

int compare(const void *x, const void *y)
{
	if ( *(double*)x > *(double*)y )
       return 1;
    else if ( *(double*)x == *(double*)y )
            return 0;
    else if ( *(double*)x < *(double*)y )
            return -1;

    return 3;
}

int main(){
	int n, test=1, qnt, i,j, myFairScore, 
	    myDeceitfulScore, myBig, mySmall, theirBig, theirSmall;
	double mine[1000], theirs[1000]; 
	scanf("%d", &n);
	while(n--){
		myFairScore=0;
		myDeceitfulScore=0;
		scanf("%d", &qnt);
		for(i=0; i<qnt; i++){
			scanf("%lf", &mine[i]);
		}
		for(i=0; i<qnt; i++){
			scanf("%lf", &theirs[i]);
		}

		qsort( mine, (size_t) qnt, sizeof(double), compare );
		qsort( theirs, (size_t) qnt, sizeof(double), compare );

		//debug
		// printf("mine ");
		// for(i=0; i<qnt; i++) printf("%lf ",mine[i]);
		// printf("\n");
		// printf("theirs ");
		// for(i=0; i<qnt; i++) printf("%lf ",theirs[i]);
		// printf("\n");

		myBig = qnt-1;
		mySmall = 0;
		theirBig = qnt -1;
		theirSmall = 0;

		//playing deceitful
		while(myBig >= mySmall){//didn't read the whole list
			if (mine[myBig]>theirs[theirBig]){//myBig vs theirBig	
				myBig--;
				theirBig--;
				myDeceitfulScore++;
			}else {//mySmall vs theirBig (deceitfully)
				mySmall++;
				theirBig--;
			}
		}

		myBig = qnt-1;
		mySmall = 0;
		theirBig = qnt -1;
		theirSmall = 0;

		//playing fair War
		while(myBig >= mySmall){//didn't read the whole list
			if (mine[myBig]>theirs[theirBig]){//myBig vs theirBig	
				myBig--;
				theirSmall++;
				myFairScore++;
			}else { //myBig<theirBig
				myBig--;
				theirBig--;
			}
		}
		printf("Case #%d: %d %d\n", test++, myDeceitfulScore, myFairScore);
	}
}