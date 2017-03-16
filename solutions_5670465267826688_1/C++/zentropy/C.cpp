#include <stdio.h>
#include <string.h>
#include <vector>

using std::vector;

struct value_t
{
public:
	char	v;
	bool	neg;
public:
	value_t(char c = '1'):v(c),neg(false) { ; }
};

// unit element and inverse element

value_t op(value_t a,value_t b)
{
	static const unsigned int maxsize = 0x100;
	static unsigned int ops[maxsize][maxsize] = { 0 };
	static bool sign[maxsize][maxsize] = { 0 };
	static bool init = false;
	if(!init)
	{
		ops['1']['1'] = '1';ops['1']['i'] = 'i';ops['1']['j'] = 'j';ops['1']['k'] = 'k';

		ops['i']['1'] = 'i';ops['i']['i'] = '1';ops['i']['j'] = 'k';ops['i']['k'] = 'j';
		sign['i']['i'] = true;sign['i']['k'] = true;

		ops['j']['1'] = 'j';ops['j']['i'] = 'k';ops['j']['j'] = '1';ops['j']['k'] = 'i';
		sign['j']['i'] = true;sign['j']['j'] = true;

		ops['k']['1'] = 'k';ops['k']['i'] = 'j';ops['k']['j'] = 'i';ops['k']['k'] = '1';
		sign['k']['j'] = true;sign['k']['k'] = true;

		init = true;
	}
	value_t ret;
	ret.v = ops[a.v][b.v];
	unsigned int count = sign[a.v][b.v] + a.neg + b.neg;
	ret.neg = (0 != (count&1));
	return ret;
}

/*

显然,运算包括单位元1,(a*e = e*a = a),且任意一个元素有逆元,因此如果x*y = z,则y = x^(-1)*z

记f(L,R)为字符串中[L,R]运算的结果,那么f(0,R) = f(0,L-1)*f(L,R),隐藏f(L,R) = f(0,L-1)^(-1)*f(0,R)

同时,若f(0,L-1) = x,则f(0,3L-1) = 1,对于任意的x都成立;即

又,如果i*x = -1 = i*j*k,那么x = i,即如果存在一个方法使得满足要求,那么任意的一个前m项结果是i的都成立

*/

bool is_product_correct(const char* buff,unsigned int len,unsigned long long x)
{
	// i*j*k = -1
	value_t product('1');
	for(unsigned int i = 0;i < len;++i) product = op(product,value_t(buff[i]));

	if('1' == product.v)
	{
		if(!product.neg) return false;
		// 2n+1
		if(0 == (x&1)) return false;
	}
	else
	{
		// 4n + 2
		if(2 != (x&3)) return false;
	}
	return true;
}

bool can_get_value(const char* buff,unsigned int len,unsigned long long x,unsigned long long& p,const value_t& dst)
{
	value_t product;
	for(unsigned int i = 0;p < x*len && i < 4*len;++p,++i)
	{
		product = op(product,value_t(buff[p%len]));
		if(dst.v == product.v && product.neg == dst.neg) return true;
	}
	return false;
}

bool slove(const char* buff,unsigned int len,unsigned long long x)
{
	if(!is_product_correct(buff,len,x)) return false;
	unsigned long long p = 0;
	if(!can_get_value(buff,len,x,p,value_t('i'))) return false;
	++ p;
	if(!can_get_value(buff,len,x,p,value_t('j'))) return false;
	return true;
}

int main()
{
	static const unsigned int maxlen = 10000;
	static const unsigned int maxsize = 16;

	char buff[maxlen+1] = { 0 };

	value_t front[maxsize][maxlen];
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int len = 0;
		unsigned long long x = 0;
		scanf("%d%I64u%s",&len,&x,buff);
		bool ans = slove(buff,len,x);
		printf("Case #%u: %s\n",iCases,ans?"YES":"NO");
	}
	return 0;
}