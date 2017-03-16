#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <sstream>
#include <string>
using namespace std;

#define file_in "C-large-1.in"
//#define file_in "Q3.in"
#define file_out "Q3.out"

int test;          /* # of test case */
FILE *fi;
FILE *fo;

long long a, b;
long long p[40];

int checkpalin(long long x)
{
	string s_num;          // string which will contain the result
	ostringstream convert;   // stream used for the conversion
	convert << x;      // insert the textual representation of 'Number' in the characters in the stream
	s_num = convert.str(); // set 'Result' to the contents of the stream
	
	//cout<<s_num<<"\n";
	int i, j;
	i = 0;
	j = s_num.length() - 1;
	
	while (i<j)
	{
		if (s_num[i] != s_num[j]) return 0;
		i++; j--;
	}
	return 1;
}

int main() {
    int i, j, k;
	long long n;
	
    fi = fopen(file_in, "r");
    fo = fopen(file_out, "w");

    fscanf(fi, "%d", &test);

	p[0] = 1;  //1
	p[1] = 4;  //2
	p[2] = 9;  //3
	p[3] = 121;  //11
	p[4] = 484;  //22
	p[5] = 10201;  //101
	p[6] = 12321;  //111
	p[7] = 14641;  //121
	p[8] = 40804;  //202
	p[9] = 44944;  //212
	p[10] = 1002001;  //1001
	p[11] = 1234321;  //1111
	p[12] = 4008004;  //2002
	p[13] = 100020001;  //10001
	p[14] = 102030201;  //10101
	p[15] = 104060401;  //10201
	p[16] = 121242121;  //11011
	p[17] = 123454321;  //11111
	p[18] = 125686521;  //11211
	p[19] = 400080004;  //20002
	p[20] = 404090404;  //20102
	p[21] = 10000200001;  //100001
	p[22] = 10221412201;  //101101
	p[23] = 12102420121;  //110011
	p[24] = 12345654321;  //111111
	p[25] = 40000800004;  //200002
	p[26] = 1000002000001;  //1000001
	p[27] = 1002003002001;  //1001001
	p[28] = 1004006004001;  //1002001
	p[29] = 1020304030201;  //1010101
	p[30] = 1022325232201;  //1011101
	p[31] = 1024348434201;  //1012101
	p[32] = 1210024200121;  //1100011
	p[33] = 1212225222121;  //1101011
	p[34] = 1214428244121;  //1102011
	p[35] = 1232346432321;  //1110111
	p[36] = 1234567654321;  //1111111
	p[37] = 4000008000004;  //2000002
	p[38] = 4004009004004;  //2001002

/*
	k = 0;
	for (n=1; n<=10000000; n++)
	{
		if (checkpalin(n))
		    if (checkpalin(n*n))
		    {
                cout<<"p["<<k<<"] = "<<n*n<<";  //"<<n<<endl;
                k++;
		    }
	}
	cout<<"done";
	getch();
*/

    for (i=1; i<=test; i++)
    {
		fscanf(fi, "%lld %lld", &a, &b);
		j = 0;	while ((p[j]<a) && (j<=38)) j++;
		k = 38;	while ((p[k]>b) && (k>=0)) k--;

		fprintf(fo, "Case #%d: %d\n", i, k-j+1);
	}

    fclose(fi);
    fclose(fo);
}

