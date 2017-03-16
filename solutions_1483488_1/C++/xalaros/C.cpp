#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(void)
{
	char lfeed[1024];
	ifstream in("C.in");
	ofstream out("C.out");
	in.getline(lfeed,1024);
	int cases = atoi(lfeed);
	int A, res, B, digs, m, count;
	char nbuf[16], recbuf[16];
	
	
	for (int caseid = 1 ; caseid <= cases ; caseid ++)
	{
		count = 0;
		digs = 1;
		int n;
		in.getline(lfeed, 1024);
		A = atoi(strtok(lfeed, " "));
		B = atoi(strtok(NULL, " "));
		res = A;
		while (res >= 10)
		{
			digs ++;
			res /= 10;
		}
		for (n = A; n <= B ; n ++)
		{
			sprintf(nbuf, "%d", n);
			int *saved = new int[digs-1];
			int sp = 0;
		for (int i = 1 ; i <= digs-1 ; i ++)
		{
			for (int k = 1 ; k <= i ; k ++)
			{
				recbuf[0+k-1] = nbuf[digs-i+k-1];
			}
			for (int p = i ; p <= digs-1 ; p ++)
			{
				recbuf[p] = nbuf[p-i];
			}
			recbuf[digs] = '\0';
			m = atoi(recbuf);
			
			bool f = false;
			for (int r = 0 ; r < sp ; r ++)
			{
				if (saved[r] == m)
				{
					f = true;
					break;
				}
			}
			saved[sp++] = m;
			
			if ((m > n) && (m <= B)) if (!f) count ++;
		}
		
		delete[] saved;
		
		}
		out << "Case #" << caseid << ": " << count << endl;
	}
	
	in.close();
	out.close();
	return 0;
}
