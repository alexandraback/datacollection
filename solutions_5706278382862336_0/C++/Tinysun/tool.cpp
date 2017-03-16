#include "tool.h"

#include <math.h>

double Sqrt(double v)
{
    if (v > -0.000001 && v < 0.0)
		v = 0.0;
    return sqrt(v);
}

int Str2Uint64(char *s, uint64_t *res)
{
	if (*s == '\0')
	{
		*res = 0;
		return -1;
	}

	uint64_t v = 0;
	while (true)
	{
		if (*s == '1')
			v++;
		s++;
		if (*s == '\0')
			break;
		
		v *= 2;
	}
	
	*res = v;
	
	return 0;
}

int CountBit1(uint64_t a)
{
	int count = 0;
	
	for(int i=0; i<64; i++)
	{
		if (a & 0x1)
			count++;
		a = a >> 1;
	}

	return count;
}
