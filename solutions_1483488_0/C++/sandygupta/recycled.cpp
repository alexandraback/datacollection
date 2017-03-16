#include<stdio.h>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

typedef pair<int,int> Pair ; 
	
int val1, val2 ;
int final ;
map<Pair,int > mm ; 


int num(string str)
{
	int l = str.length();
	int i ; 
	int ans = 0 ; 
	for(i = 0 ; i < l; i++)
		ans = ans * 10 + (str[i] - '0');
	return ans ; 
}

void check(string str)
{
	int l = str.length();
	int keep ; 
	keep = num(str);

	int val = 0 ; 
	int ct ; 
	int i , j ; 

	for(i = 0 ; i < l ; i++)
	{
		val = 0 ; 
		ct = 0 ; 
		j = i ; 
		while(ct < l)
		{
			val = val*10  + (str[j%l] -'0');
			j++ ;
			ct ++ ; 
		}
		if(val != keep && val >= val1 && val <= val2)
		{
			mm[Pair(min(keep,val) , max(keep,val))] = 1 ;
		}
	}
	return ; 
}

string add1(string str)
{
	int l = str.length();
	int i ;
	int carry = 0 ;
	int prev = 1 ;
	int use ; 
	for(i = l - 1 ; i >= 0 ; i--)
	{
		use = (str[i] - '0') + prev + carry ; 
		carry = use / 10 ; 
		str[i] = (use % 10) + '0' ;
		prev = 0 ; 
	}
	return str ; 
}

int main()
{
	int t ;
	int total = 1 ;
	string str1 ; 
	string str2 ; 
	scanf("%d",&t);

	while(t--)
	{
		final = 0 ;
		mm.clear();
		cin >> str1 >> str2 ; 
		val1 = num(str1);
		val2 = num(str2);

		while(str1 <= str2)
		{
			check(str1);
			if(str1 == str2)
			{
				break ; 
			}
			str1 = add1(str1);
		}
		printf("Case #%d: %d\n",total++,mm.size());
	}
	return 0;
}
