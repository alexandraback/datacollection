#include <stdio.h>
using namespace std;

#define file_in "A-small-attempt0.in"
#define file_out "A.out"

int test, a, b;          /* # of test case */
FILE *fi;
FILE *fo;

int main() {
    int i, j, k;
    double mi, x, v, t1;
    
    fi = fopen(file_in, "r");
    fo = fopen(file_out, "w");

    fscanf(fi, "%d", &test);
    //scanf("%d", &test);
    
    for (i=1; i<=test; i++)
    {
        fscanf(fi, "%d %d", &a, &b);
        t1 = 1.0;
        mi = 200100.0;
        
        for (j=0; j<a; j++)
        {
			k = a-j;
			v = k + (b-a+1+k)*t1 + (b-a+1+k+b+1)*(1-t1);
			if (v<mi) mi = v;
			
			fscanf(fi, "%lf", &x);
			t1 = t1*x;
		}

		
		//keep going
		v = (b-a+1)*t1 + (b+b-a+2)*(1-t1);
		if (v<mi) mi = v;
		
		//hit enter
		v = b+2;
		if (v<mi) mi = v;
		
		/*
		for (k=1; k<=a; k++)
		{
			//delete k char
			v = k + (b-a+1+k)*t1 + (b-a+1+k+b+1)*(1-t1);
			if (v<mi) mi = v;
		}
		*/

        fprintf(fo, "Case #%d: %.6lf\n", i, mi);
    }
    fclose(fi);
    fclose(fo);
}


