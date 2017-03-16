#include<string>
#include<vector>
#include<fstream>
#include<map>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>

using namespace std;


void add_index(int &i, const int len)
{
	i++;
	if(i>=len) i-=len;
}

bool match(int j, char sn [7], char sm [7])
{
	int nlen=strlen(sn);
	int mlen=strlen(sm);
	for(int i=0; i<nlen; i++)
	{
		if(sn[i]!=sm[j]) return false;
		add_index(j, mlen);
	}
	return true;
}

bool is_recycled(int n, int m)
{
	char sn [9];
	char sm [9];
	
	itoa(n, sn, 10);
	itoa(m, sm, 10);
		
	int nlen=strlen(sn);
	int mlen=strlen(sm);
	if(nlen!=mlen) return false;

	for(int j=0; j<mlen; j++)
	{
		if(match(j, sn, sm)) return true;
	}
	return false;
}

int answer(int A, int B)
{
	if(A>=B) return 0;
	if(A+1==B)
	{
		return is_recycled(A, B)? 1: 0;
	}
	else
	{
		int ans=answer(A, B-1);
		for(int n=A; n<B; n++)
		{
			if(is_recycled(n, B))
				ans++;
		}
		return ans;
	}
}



int main()
{
	freopen("C:\\Users\\theaa\\Downloads\\C-small-attempt.in","r",stdin);
	freopen("C:\\Users\\theaa\\Downloads\\C-small-attempt.out","w",stdout);
	int T;
	cin>>T;
	
	for(int caseno=1; caseno<=T; caseno++)
	{
		int A, B;
		cin>>A>>B;
		cout<<"Case #"<<caseno<<": "<<answer(A, B)<<endl;
	}


	return 0;
}