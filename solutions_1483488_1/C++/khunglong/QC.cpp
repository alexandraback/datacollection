#include <string>
#include <fstream>
#include <vector>

using namespace std;

#define file_in "C-large.in"
#define file_out "QC.out"

long maxi(long a, long b)
{
	return a>b?a:b;
}

long mini(long a, long b)
{
	return a<b?a:b;
}

int main()
{
	int T;
	long a, b, c, num, newnum;
    FILE *fi;
    FILE *fo;
    fi = fopen(file_in, "r");
    fscanf(fi, "%d", &T);

    fo = fopen(file_out, "w");

  	for (int i=0; i<T; i++)
  	{
		fscanf(fi, "%ld %ld", &a, &b);
		//m = 2000000;
		c = 0;  //count
		
		//2 digits
		for (num=maxi(10, a); num<=mini(b, 99); num++)
		{
			newnum = (num%10)*10 + (num/10);
			if ((newnum>num)&&(newnum<=b))
			{
				c++;
				//fprintf(fo, "%d : %d\n", num, newnum);
			}
		}
		
		//3 digits
		for (num=maxi(100, a); num<=mini(b, 999); num++)
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
		for (num=maxi(1000, a); num<=mini(b, 9999); num++)
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
			if (newnum==(num%10)*1000 + (num/10)) continue; //abab
			if ((newnum>num)&&(newnum<=b))
			{
				c++;
				//fprintf(fo, "%d : %d\n", num, newnum);
			}
		}

		//5 digits
		for (num=maxi(10000, a); num<=mini(b, 99999); num++)
		{
			//abcde -> eabcd
			newnum = (num%10)*10000 + (num/10);
			if ((newnum>num)&&(newnum<=b)) c++;
			//abcde -> deabc
			newnum = (num%100)*1000 + (num/100);
			if ((newnum>num)&&(newnum<=b)) c++;
			//abcde -> cdeab
			newnum = (num%1000)*100 + (num/1000);
			if ((newnum>num)&&(newnum<=b)) c++;
			//abcde -> bcdea
			newnum = (num%10000)*10 + (num/10000);
			if ((newnum>num)&&(newnum<=b)) c++;
		}

		//6 digits
		for (num=maxi(100000, a); num<=mini(b, 999999); num++)
		{
			if (num%1000==num/1000) //3 so dau = 3 so cuoi
			{
                //abcdef -> fabcde
				newnum = (num%10)*100000 + (num/10);
				if ((newnum>num)&&(newnum<=b)) c++;
				//abcdef -> efabcd
				newnum = (num%100)*10000 + (num/100);
				if ((newnum>num)&&(newnum<=b)) c++;
				continue;
			}
			
			if ((num%100==num/10000)&&(num%100==(num/100)%100)) //ababab
			{
                //abcdef -> fabcde
				newnum = (num%10)*100000 + (num/10);
				if ((newnum>num)&&(newnum<=b)) c++;
				continue;
			}

			//abcdef -> fabcde
			newnum = (num%10)*100000 + (num/10);
			if ((newnum>num)&&(newnum<=b)) c++;
			//abcdef -> efabcd
			newnum = (num%100)*10000 + (num/100);
			if ((newnum>num)&&(newnum<=b)) c++;
			//abcdef -> defabc
			newnum = (num%1000)*1000 + (num/1000);
			if ((newnum>num)&&(newnum<=b)) c++;
			//abcdef -> cdefab
			newnum = (num%10000)*100 + (num/10000);
			if ((newnum>num)&&(newnum<=b)) c++;
			//abcdef -> bcdefa
			newnum = (num%100000)*10 + (num/100000);
			if ((newnum>num)&&(newnum<=b)) c++;
		}

		//7 digits
		for (num=maxi(1000000, a); num<=mini(b, 2000000); num++)
		{
			//abcdefg -> gabcdef
			newnum = (num%10)*1000000 + (num/10);
			if ((newnum>num)&&(newnum<=b)) c++;
			//abcdefg -> fgabcde
			newnum = (num%100)*100000 + (num/100);
			if ((newnum>num)&&(newnum<=b)) c++;
			//abcdefg -> efgabcd
			newnum = (num%1000)*10000 + (num/1000);
			if ((newnum>num)&&(newnum<=b)) c++;
			//abcdefg -> defgabc
			newnum = (num%10000)*1000 + (num/10000);
			if ((newnum>num)&&(newnum<=b)) c++;
			//abcdefg -> cdefgab
			newnum = (num%100000)*100 + (num/100000);
			if ((newnum>num)&&(newnum<=b)) c++;
			//abcdefg -> bcdefga
			newnum = (num%1000000)*10 + (num/1000000);
			if ((newnum>num)&&(newnum<=b)) c++;
		}
		
		fprintf(fo, "Case #%d: %ld\n", i+1, c);
  	}
  	fclose(fi);
  	fclose(fo);
}
