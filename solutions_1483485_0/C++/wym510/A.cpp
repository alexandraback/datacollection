/*
 * File: A.cpp
 * Author: wym510 
 * Email: <wym6110@gmail.com>
 * Create Date: 2012-04-14 10:26:09
*/

#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define S size()
#define B begin()
#define E end()
#define P push_back
#define fu(i,a,b) for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=b-1;i>=a;--i)
typedef long long int64;
using namespace std;

char mt[500];
void pre()
{
	char s1[]="ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjvqz";
	char s2[]="ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveupzq";

	for(int i=0;s1[i]!='\0';i++) mt[s1[i]]=s2[i];
	mt[' ']=' ';mt['\n']='\0';
}

int main()
{
	int test;
	
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	
	scanf("%d\n",&test);pre();
	for(int no=1;no<=test;no++)
	{
		char str[200];
		
		cin.getline(str,150);
		for(int i=0;str[i]!='\0';i++) str[i]=mt[str[i]];
		printf("Case #%d: %s\n",no,str);
	}
	return 0;
}

/* vim: set ts=4 sw=4: */

