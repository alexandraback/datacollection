#include <string>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

#define file_in "C-small-attempt0.in"
#define file_out "QC.out"

int main()
{
    int T, a, b, m, c, num, newnum;
    FILE *fi;
    FILE *fo;
    fi = fopen(file_in, "r");
    fscanf(fi, "%d", &T);

    fo = fopen(file_out, "w");

  	for (int i=0; i<T; i++)
  	{
		fscanf(fi, "%d %d", &a, &b);
		//m = 2000000;
		c = 0;  //count
		
		//2 digits
		for (num=max(10, a); num<=min(b, 99); num++)
		{
			newnum = (num%10)*10 + (num/10);
			if ((newnum>num)&&(newnum<=b))
			{
				c++;
				//fprintf(fo, "%d : %d\n", num, newnum);
			}
		}
		
		//3 digits
		for (num=max(100, a); num<=min(b, 999); num++)
		{
			//abc -> cab
			newnum = (num%10)*100 + (num/10);
			if ((newnum>num)&&(newnum<=b))
			{
				c++;
				//fprintf(fo, "%d : %d\n", num, newnum);
			}
			//abc -> bca
			newnum = (num%100)*10 + (num/100);
			if ((newnum>num)&&(newnum<=b))
			{
				c++;
				//ffprintf(fo, "%d : %d\n", num, newnum);
			}
		}
		
		//4 digits
		for (num=max(1000, a); num<=min(b, 9999); num++)
		{
			//abcd -> dabc
			newnum = (num%10)*1000 + (num/10);
			if ((newnum>num)&&(newnum<=b))
			{
				c++;
				//fprintf(fo, "%d : %d\n", num, newnum);
			}
			//abcd -> cdab
			newnum = (num%100)*100 + (num/100);
			if ((newnum>num)&&(newnum<=b))
			{
				c++;
				//fprintf(fo, "%d : %d\n", num, newnum);
			}
			//abcd -> bcda
			newnum = (num%1000)*10 + (num/1000);
			if ((newnum>num)&&(newnum<=b))
			{
				c++;
				//fprintf(fo, "%d : %d\n", num, newnum);
			}
		}
		
		fprintf(fo, "Case #%d: %d\n", i+1, c);
  	}
  	fclose(fi);
  	fclose(fo);
}
