#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <climits>
#include <map>


#define MAXA 72500000
#define MOD 1000000007
#define SIZ  101

using namespace std;


char arr[MAXA],*ptr;
long long t,ret;
int grid[SIZ][SIZ];
int nGrid[SIZ][SIZ];
inline long long get_int()
{
	ret =0;
	while ( !(*ptr >= '0' && *ptr <= '9'))
		ptr++;
	while (*ptr >= '0' && *ptr<= '9') {
		ret = ret*10 + (*ptr - '0');
		ptr++;
	}
	return ret;
}

void getGrid(int n,int m){
	for(int xx = 0;xx<n;xx++)
		for(int yy = 0;yy<m;yy++)
		{grid[xx][yy] = get_int();nGrid[xx][yy] = -1;}
}

int getLargestBelow(int n,int m, int bel){
	int larRet=0;
	for(int xx = 0;xx<n;xx++)
		for(int yy = 0;yy<m;yy++)
			if(grid[xx][yy] < bel && grid[xx][yy] > larRet)
				larRet = grid[xx][yy];
	return larRet;
}

bool done(int n, int m)
{
	for(int xx = 0;xx<n;xx++)
		for(int yy = 0;yy<m;yy++)
			if(grid[xx][yy] != nGrid[xx][yy])
				return false;
	return true;
}

int locHor[SIZ],locVer[SIZ];
int locVCount,locHCount;
void fillnGrid(int n, int m, int largest){
	for(int xx = 0;xx<n;xx++)
		for(int yy = 0;yy<m;yy++)
		{
		if(grid[xx][yy] == largest && (locHor[xx] == largest || locHor[xx] == SIZ || locVer[yy] == SIZ || locVer[yy] == largest))
			{
				nGrid[xx][yy] = largest;
				if(locHor[xx] ==  SIZ)
				{
					locHCount++;
					locHor[xx] = largest;
				}
				if(locVer[yy] == SIZ)
				{
					locVCount++;
					locVer[yy] = largest;
				}
			}
		}
}

void printGridLock(int n, int m){
	cout << endl;
	cout << ".\t";
	for(int xx =0; xx<m;xx++)
		cout << locVer[xx] << "\t";
	cout << endl;
	for(int xx =0; xx<n;xx++)
	{
		cout << locHor[xx] << "\t";
		for(int yy =0;yy<m;yy++)
			cout << nGrid[xx][yy] << "\t";
		cout << endl;
	}
	cout << endl;
}

bool solve(int n, int m){
	
	for(int xx =0;xx<n;xx++)
		locHor[xx] = 101;
	for(int yy =0;yy<m;yy++)
		locVer[yy] = 101;
	locHCount = 0;
	locVCount = 0;
	
	int largest = 101;
	while((locHCount != n || locVCount != m) && !done(n,m)){
//	printGridLock(n,m);
		largest = getLargestBelow(n,m,largest);
		fillnGrid(n,m,largest);
	}
//	printGridLock(n,m);
	if(!done(n,m))
		return false;
	else
		return true;
}

int main()
{
	fread(arr,sizeof(char),MAXA,stdin);
	ptr = arr;
	t = get_int();
	int n,m;
	bool ans;
	for(int tt = 1;tt<=t;tt++)
	{
		n = get_int();
		m = get_int();
		getGrid(n,m);
		ans = solve(n,m);
		if(!ans)
			cout << "Case #" << tt << ": NO" << endl;
		else
			cout << "Case #" << tt << ": YES" << endl;
	}
	
	return 0;
}