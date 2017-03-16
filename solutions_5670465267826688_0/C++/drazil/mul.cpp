#include <iostream>
#include <algorithm>

using namespace std ;

int multable[4][4] = 
{
	{1,2,3,4},
	{2,-1,4,-3},
	{3,-4,-1,2},
	{4,3,-2,-1}
} ;

int mul(int a, int b)
{
	int neg = 1 ;
	if(a<0)
	{
		neg *= -1 ;
		a *= -1 ;
	}
	if(b<0)
	{
		neg *= -1 ;
		b *= -1 ;
	}
	return neg*multable[a-1][b-1] ;
}

int pow(int x, long long exp)
{
	long long ans = 1 ;
	long long curexp = 1 ;
	long long cur = x ;
	
	while(curexp <= exp)
	{
		if((curexp&exp)!=0)
			ans = mul(ans, cur) ;
		curexp <<= 1 ;
		cur = mul(cur, cur) ;
	}
	
	return ans ;
}

int main(void)
{
	int tc ;
	cin >> tc ;
	
	int cor = mul(mul(2,3),4) ; //ijk
	
	for(int c=1;c<=tc;c++)
	{
		long long L, X ;
		cin >> L >> X ;
		string str ;
		cin >> str ;
		
		int res = 1 ;
		for(int i=0;i<str.size();i++)
			res = mul(res, str[i]-'i'+2) ;
		res = pow(res, X) ;
		
		cout << "Case #" << c << ": " ;
		if(res != cor)
			cout << "NO" << endl ;
		else
		{
			str = str+str+str+str+str ;
			res = 1 ;
			int iLen = -1 ;
			for(int i=0;i<str.size();i++)
			{
				res = mul(res, str[i]-'i'+2) ;
				if(res==2) //i
				{
					iLen = i+1 ;
					break ;
				}
			}
			res = 1 ;
			int kLen = -1 ;
			for(int i=str.size()-1;i>=0;i--)
			{
				res = mul(str[i]-'i'+2, res) ;
				if(res==4) //k
				{
					kLen = str.size()-i ;
					break ;
				}
			}
			if(iLen<0 || kLen<0 || iLen+kLen>=X*L)
				cout << "NO" << endl ;
			else
				cout << "YES" << endl ;
		}
	}
	
	return 0 ;
}
