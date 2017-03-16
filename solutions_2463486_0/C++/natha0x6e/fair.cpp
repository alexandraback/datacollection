#include <iostream>

//using http://www.shoup.net/ntl/ for handling large numbers
#include <NTL/ZZ.h>
NTL_CLIENT

//mid = true if the 
ZZ makePal(ZZ x, bool mid)
{
	ZZ result = x;
	
	if(mid)
	{
		x /= 10;
	}
	
	while(x > 0)
	{
		result *= 10;
		result += x % 10;
		x /= 10;
	}
	
	return result;
}

bool isFair(ZZ x)
{
	ZZ logt = to_ZZ(1);
	ZZ div = to_ZZ(1);
	while(x / div >= 10)
	{
		div *= 10;
		logt++;
	}
	
	ZZ tmp = x;
	for(ZZ i = to_ZZ(0);i < logt / 2;i++)
	{
		if(tmp % 10 != (x / div) % 10)
		{
			return false;
		}
		tmp /= 10;
		div /= 10;
	}
	
	return true;
}

ZZ test(ZZ a, ZZ b)
{
	ZZ result = to_ZZ(0);
	ZZ sq = to_ZZ(0);
	ZZ pal;
	ZZ start = to_ZZ(1);
	ZZ j;
	while(sq < b)
	{
		for(j = start;j < start * 10;j++)
		{
			pal = makePal(j, true);
			sq = pal * pal;
			if(sq >= a && sq <= b && isFair(sq))
			{
				result++;
			}
			if(sq >= b){break;}
		}
		if(sq >= b){break;}
		for(j = start;j < start * 10;j++)
		{
			pal = makePal(j, false);
			sq = pal * pal;
			if(sq >= a && sq <= b && isFair(sq))
			{
				result++;
			}
			if(sq >= b){break;}
		}
		start *= 10;
	}
	
	return result;
}

int main(int argc,char *argv[])
{
	(void) argc;
	(void) argv;
	
	
	int numTests;
	
	cin >> numTests;
	
	for(int i = 0;i < numTests;i++)
	{
		ZZ a;
		ZZ b;
		cin >> a >> b;
		
		ZZ result = test(a, b);
		
		cout << "Case #" << i+1 << ": " << result << endl;
	}
	
	return 0;
}


