#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;


#define MAX(Z,Y) max((Z),(Y))
#define MIN(X,Y) min((X),(Y))
#define N 1000000

FILE* fpOut;
typedef map<pair<int, int>, bool > myMap;
myMap substring;

bool consonantMap[] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0};

void printResult(int n, char* result)
{
	fprintf(fpOut,"Case #%d: %s\n", n,result);
}

void printResult(int n, int result)
{
	fprintf(fpOut,"Case #%d: %d\n", n, result);
}

void putData(int start, int end, int len)
{
	for(int st=0;st<=start;st++)
	{
		for(int ed=end;ed<len;ed++)
			substring[make_pair(st,ed)]=true;
	}
}

void solve(int t, char* name, int n)
{
	int len = strlen(name);

	for(int i=0;i<=len-n;)
	{
		int j=i;
		for(;j<i+n;j++)
		{
			int ch = name[j]-'a';
			if(consonantMap[ch]==true)
				break;
		}

		if(j==i+n)
		{
			putData(i,i+n-1,len);
			i++;
		}
		else
			i=j+1;
	}
	printResult(t,substring.size());
}


int main()
{
	FILE * fpIn = fopen("A-small-attempt1.in","r");
	fpOut = stdout;//fopen("A-small-attempt0.out","w+");
	//fpOut = stdout;
	
    int T=0;
	fscanf(fpIn,"%d",&T);
	char temp[10];
	fgets(temp,10,fpIn);

	for(int t=1;t<=T;t++)
	{
		char str[N+1];
		memset(str,0,N+1);
		fgets(str,N+1,fpIn);
		char* name = strtok(str," ");
		char* count = strtok(NULL, "\n");
		int n = atoi(count);
		solve(t,name,n);
		substring.clear();
	}

	fclose(fpIn);
	//fclose(fpOut);

}
