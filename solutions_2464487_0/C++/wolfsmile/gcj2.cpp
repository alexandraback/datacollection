#include<iostream>
using namespace std;

int main()
{
	FILE *in;
	FILE *out;
	in = fopen("in.txt","r");
	out = fopen("out.txt","w");
	int T;
	int Case = 1;
	fscanf(in,"%d",&T);
	while(Case<=T)
	{
		__int64 r,t;
		fscanf(in,"%I64d%I64d",&r,&t);
		__int64 start,end;
		end = sqrt(double(t));
		if(t/(2*r)+1< end)
			end = t/(2*r)+1;
		start = 1;
		while(start < end)
		{
			__int64 mid;
			mid = (start + end +1)/2;
			__int64 result;
			result = (__int64)2*mid*mid+((__int64)2*r-(__int64)1)*mid;
			if(result > t)
			{
				end = mid - 1;
			}
			if(result < t)
			{
				start = mid;
			}
			if(result == t)
			{
				start = mid;
				end = mid;
			}
		}
		fprintf(out,"Case #%d: %I64d\n",Case,start);
		Case++;
	}
	return 0;
}