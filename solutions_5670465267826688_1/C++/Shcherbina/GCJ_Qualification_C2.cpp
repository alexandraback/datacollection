//#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <ctime>
 
#define MAXN 100000
#define INF 1000000000
#define pi 3.1415926535
#define LL long long
#define U unsigned
#define mp make_pair
#define pb push_back
#define eps 0.000000001
#define pii pair <int,int>
#define X first
#define Y second
#define MOD 1000000007
#define MOD2 1000000009
 
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

map <pair <string,string>, string> get;
string GET(string a, string b)
{
	LL sign=0;
	if (a[0]=='-')
	{
		sign++;
		a=a[1];
	}
	if (b[0]=='-')
	{
		sign++;
		b=b[1];
	}
	string answer = get[mp(a,b)];
	if (sign%2==0)
	{
		return answer;
	}
	else
	{
		if (answer[0]=='-')
		{
			answer=answer[1];
		}
		else
		{
			answer="-"+answer;
		}
		return answer;
	}
}
void PreProc()
{
	get[mp("1","1")]="1";
	get[mp("1","i")]="i";
	get[mp("1","j")]="j";
	get[mp("1","k")]="k";
	
	get[mp("i","1")]="i";
	get[mp("i","i")]="-1";
	get[mp("i","j")]="k";
	get[mp("i","k")]="-j";
	
	get[mp("j","1")]="j";
	get[mp("j","i")]="-k";
	get[mp("j","j")]="-1";
	get[mp("j","k")]="i";
	
	get[mp("k","1")]="k";
	get[mp("k","i")]="j";
	get[mp("k","j")]="-i";
	get[mp("k","k")]="-1";
}
string binary(LL left, string a)
{
	string r="1";
	while (left!=0)
	{
		if (left%2==0)
		{
			left/=2;
			a=GET(a,a);
		}
		else
		{
			left--;
			r=GET(r,a);
		}
	}
	return r;
}
string Solve()
{
	LL L,X,i;
	string s,temp;
	cin >> L >> X;
	cin >> s;
	temp=s;
	if (X<=30) 
	{
		for (i=0; i<X-1; i++)
			s=s+temp;
		LL n=L*X;
		string ch;
		ch=s[0];
		i=1;
		while (ch!="i" && i<n)
		{	
				temp=s[i];
			ch=GET(ch,temp);
			i++;
		}
		if (ch!="i") return "NO\n";
		
		ch="1";
		while (ch!="j" && i<n)
		{	
			temp=s[i];
			ch=GET(ch,temp);
			i++;
		}
		if (ch!="j") return "NO\n";
		 
		ch="1";
		while (i<n)
		{	
			temp=s[i];
			ch=GET(ch,temp);
			i++;
		}
		if (ch!="k") return "NO\n";
		
		return "YES\n";
	}
	else
	{
		for (i=0; i<30-1; i++)
			s=s+temp;
		LL n=L*30;
		string ch;
		ch=s[0];
		i=1;
		while (ch!="i" && i<10*L)
		{	
			temp=s[i];
			ch=GET(ch,temp);
			i++;
		}
		if (ch!="i") return "NO\n";
		
		ch="1";
		while (ch!="j" && i<20*L)
		{	
			temp=s[i];
			ch=GET(ch,temp);
			i++;
		}
		if (ch!="j") return "NO\n";
		 
		ch="1";
		while (i<30*L)
		{	
			temp=s[i];
			ch=GET(ch,temp);
			i++;
		}
		
		LL left=X-30;
		string temp_ch="1";
		for (i=0; i<L; i++)
		{
			temp=s[i];
			temp_ch=GET(temp_ch,temp);
		}
		
		temp_ch=binary(left,temp_ch);
		
		ch=GET(ch,temp_ch);
		
		if (ch!="k") return "NO\n";
		
		return "YES\n";
	}
}
int main()
{
	PreProc();
	LL q,t;
	cin >> t;
	for (q=0; q<t; q++)
	{
		cout << "Case #" << q+1 << ": ";
		cout << Solve();
	}
	return 0;
}
