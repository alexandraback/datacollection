#include <stdio.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <stack>

using namespace std;

FILE *in=fopen("C-small-attempt0.in","rt");
FILE *out=fopen("C-small-attempt0.out","wt");

string sum;

int n;
bool mat[10][10];
char zip[10][10];

int a[11]={0,1,2,3,4,5,6,7,8,9};

void input()
{
	int m;
	memset(mat,0,sizeof(mat));
	fscanf(in,"%d %d",&n,&m);
	for(int i=1; i<=n; i++) fscanf(in," %s",&zip[i][1]);
	for(int i=1; i<=m; i++) {
		int x,y;
		fscanf(in,"%d %d",&x,&y);
		mat[x][y]=mat[y][x]=1;
	}
}

bool go_check()
{
	int x=a[1];
	stack<int> st;
	for(int i=2; i<=n; i++) {
		int y=a[i];
		if(mat[x][y]){
			st.push(x);
			x=y;
		}
		else {
			if(!st.empty()){
				x=st.top();
				st.pop();
				i--;
			}
			else return false;
		}
	}
	return true;
}

void process()
{
	sort(a,a+10);
	sum="999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
	do
	{
		string tmp;
		for(int i=1; i<=n; i++) tmp+=&zip[a[i]][1];
		if(go_check() && sum>tmp) sum=tmp;
	}while(next_permutation(a+1,a+n+1));
}

int main()
{
	int t;
	fscanf(in,"%d",&t);
	for(int i=1; i<=t; i++) {
		fprintf(out,"Case #%d: ",i);
		input();
		process();
		fprintf(out,"%s\n",sum.c_str());
	}
	fclose(in);
	fclose(out);
	return 0;
}