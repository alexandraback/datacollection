#include <cstdio>

#define TESTCASE "B-small-attempt0"

/*
4
3 1 5 15 13 11
3 0 8 23 22 21
2 1 1 8 0
6 2 8 29 20 8 18 18 21

Case #1: 3
Case #2: 2
Case #3: 1
Case #4: 3
*/

int main()
{
	FILE* fin=fopen(TESTCASE ".in","r");
	FILE* fout=fopen(TESTCASE ".out","w");
	int testcases;
	fscanf(fin,"%d",&testcases);
	for(int t=0;t<testcases;++t)
	{
		int n,s,l,f=0;
		fscanf(fin,"%d %d %d",&n,&s,&l);
		for(int i=0;i<n;++i)
		{
			int b,sum;
			fscanf(fin,"%d",&sum);
			b=sum/3;
			switch(sum%3)
			{
			case 0: // 3b
				if(b>=l) ++f; // b b b
				else if(b-1>=0 && b+1>=l && b+1<=10 && s>0) { --s; ++f; } // b-1 b b+1
				break;
			case 1: // 3b+1
				if(b>=0 && b+1>=l && b+1<=10) ++f; // b b b+1
				break;
			case 2: // 3b+2
				if(b>=0 && b+1>=l && b+1<=10) ++f; // b b+1 b+1
				else if(b>=0 && b+2>=l && b+2<=10 && s>0) { --s; ++f; } // b b b+2
				break;
			}
		}
		fprintf(fout,"Case #%d: %d\n",t+1,f);
	}
	fclose(fin);
	fclose(fout);
}