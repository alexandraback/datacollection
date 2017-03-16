#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
//#define DEBUG 1
using namespace std;
void print(vector<vector<int> >A)
{
	printf("TABLE:\n");
	for(int i =0;i<A.size();i++)
	{
		for(int j=0;j<A[i].size();j++)
		{
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
}

bool is_consonant(char c)
{
	switch (c)
	{
		case 'a':
		case 'e':
		case 'o':
		case 'i':
		case 'u':
			return false;
		break;
	}
	return true;
}
bool is_vovel(char c)
{
	if(is_consonant(c))
	{
		return false;
	}
	else
		return true;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int itr=1;itr<=T;itr++)
	{
		string A;
		int n;
		cin>>A;
		scanf("%d",&n);	
		//cout<<A<<" "<<n<<endl;
		int len=0,b=-1;
		vector<vector<int> > table;
		for(int i=0;i<A.size();i++)
		{	
	//		printf("INDEX\t%d\n",i);
			if(is_consonant(A[i]))
			{
				len++;
				if(b==-1)b=i;
			}
			
			if(is_vovel(A[i]) || i==(A.size()-1))
			{
				//printf ("%d %d %d\n",i,len,b);
				if(len>=n)
				{
			//		printf("HERE");
					vector<int> temp(2);
					temp[0]=b;
					temp[1]=len;
					table.push_back(temp);
				}
				len=0;
				b=-1;
			}
		}
#ifdef DEBUG
print(table);
#endif
		long int ans=0,j=0;
		for(int i=0;i<A.size();i++)
		{
			int pos=0;
			if(j<table.size()){
				if(i<=table[j][0])
					pos= A.size() - (table[j][0] + n -1);
				else if(i+n<=table[j][0]+table[j][1])
					pos= A.size() - (i + n -1);
				else {
					j++;
					if(j<table.size())pos= A.size() - (table[j][0] + n -1);
				}
			}

			//printf("P %d\n",pos);
			ans=ans+pos;		
		}
		printf("Case #%d: %ld\n",itr,ans);
	}
	return 0;
}
