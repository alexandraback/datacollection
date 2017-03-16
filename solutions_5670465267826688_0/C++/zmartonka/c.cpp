#include <stdio.h>
#include <vector>

using std::vector;

class Q
{
public:
	enum Direction {ONE = 0, I = 1, J= 2, K = 3};
	int dir;
	int neg;
protected:
	Q() { dir = 0; neg = 0; }
public:
	Q(const Q& o)
	{
		dir = o.dir;
		neg = o.neg;
	}
	Q(char c, int neg = 0)
	{
		switch(c)
		{
			case '1':
			{
				dir = ONE;
				break;
			}
			case 'i':
			{
				dir = I;
				break;
			}
			case 'j':
			{
				dir = J;
				break;
			}
			case 'k':
			{
				dir = K;
				break;
			}
			default:
			{
				printf("WTF C = %d",(int)c);
			}
		}
		this->neg = neg;
	}
	Q operator*(const Q& o) const
	{
		Q q;
		q.neg = (neg + o.neg) %2;
		bool n = false;
		switch(dir)
		{
			case ONE:
			{
				switch(o.dir)
				{
					case ONE: { n = false; q.dir = ONE;	break; }
					case I: { n = false; q.dir = I;	break; }
					case J: { n = false; q.dir = J;	break; }
					case K: { n = false; q.dir = K;	break; }
				}
				break;
			}
			case I:
			{
				switch(o.dir)
				{
					case ONE: { n = false; q.dir = I;	break; }
					case I: { n = true; q.dir = ONE;	break; }
					case J: { n = false; q.dir = K;	break; }
					case K: { n = true; q.dir = J;	break; }
				}
				break;
			}
			case J:
			{
				switch(o.dir)
				{
					case ONE: { n = false; q.dir = J;	break; }
					case I: { n = true; q.dir = K;	break; }
					case J: { n = true; q.dir = ONE;	break; }
					case K: { n = false; q.dir = I;	break; }
				}
				break;
			}
			case K:
			{
				switch(o.dir)
				{
					case ONE: { n = false; q.dir = K;	break; }
					case I: { n = false; q.dir = J;	break; }
					case J: { n = true; q.dir = I;	break; }
					case K: { n = true; q.dir = ONE;	break; }
				}
				break;
			}
		}
		if (n)
		{
			q.neg = ! q.neg;
		}
		return q;
	}
	bool operator==(const Q& o) const
	{
		return dir == o.dir && neg == o.neg;
	}
	bool operator!=(const Q& o) const
	{
		return !(*this == o);
	}
	const Q& operator=(const Q& o)
	{
		dir = o.dir;
		neg = o.neg;
	}
};

int main()
{
	int T;
	scanf("%d",&T);
	for(int tn = 0; tn<T; ++tn)
	{
		bool found = false;
		int L;
		unsigned long long XB;
		scanf("%d%llu",&L, &XB);
		int X = (XB -1) % 4 + 1;
		if (XB > 4) X+=4;
		if (XB > 8) X+=8;	
		char text[10001];
		scanf("%s",text);
		Q anyad('1');
		for(int i = 0; i<L;++i)
		{
			Q q2(text[i%L]);
			anyad = anyad * q2;
		}
		Q b('1');
		for (int i = 0; i< X; ++ i)
		{
			b = b * anyad;
		}
		if (b != Q('1',1))
		{
			printf("Case #%d: NO\n",tn + 1);
			continue;
		}
		Q q('1');
		bool iFound = false;
		for(int i = 0; i<L*X - 1;++i)
		{
			Q q2(text[i%L]);
			q = q * q2;
			if (!iFound && q == Q('i'))
			{
				iFound = true;
				q = Q('1'); 
			}
			if (iFound && q == Q('j'))
			{
				printf("Case #%d: YES\n",tn + 1);
				found = true;
				break;
			}
		}
		if (!found)	printf("Case #%d: NO\n",tn + 1);
	}
	return 0;
}