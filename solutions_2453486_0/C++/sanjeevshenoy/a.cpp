#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<limits>
#include<cassert>

using namespace std;

const int max_n=10;

int T,n;
char a[max_n][max_n];

bool diag(char c)
{
	int t=0;
	for(int i=0; i<4; i++)
		if(a[i][i]=='T' or a[i][i]==c)
			t++;
	if(t==4)
		return true;
	t=0;
	for(int i=0; i<4; i++)
		if(a[i][3-i]=='T' or a[i][3-i]==c)
			t++;
	if(t==4)
		return true;
	return false;
}

bool col(int i, char c)
{
	int t=0;
	for(int j=0; j<4; j++)
		if(a[j][i]==c or a[j][i]=='T')
			t++;
	if(t==4)
		return true;
	return false;
}

bool row(int i, char c)
{
	int t=0;
	for(int j=0; j<4; j++)
		if(a[i][j]==c or a[i][j]=='T')
			t++;
	if(t==4)
		return true;
	return false;
}

bool check(char c)
{
	for(int i=0; i<4; i++)
		if(row(i,c))
			return true;
	for(int i=0; i<4; i++)
		if(col(i,c))
			return true;
	if(diag(c))
		return true;
		
	return false;
}

bool is(char c)
{
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			if(a[i][j]==c)
				return true;
				
	return false;
}

int main()
{
    scanf("%d",&T);
	for(int z=1; z<=T; z++)
	{
		for(int i=0; i<4; i++)
			scanf("%s",a[i]);
		
		printf("Case #%d: ",z);
		if(check('X'))
			printf("X won\n");
		else if(check('O'))
			printf("O won\n");
		else if(is('.'))
			printf("Game has not completed\n");
		else
			printf("Draw\n");
    }
	
    return 0;
}
