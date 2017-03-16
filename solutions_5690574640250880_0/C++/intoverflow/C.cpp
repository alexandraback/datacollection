#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;


bool verify(char **field,int r,int c,int mines)
{

bool visited[50][50]={false};
queue<pair<int,int> > f;
int count=1;
f.push(pair<int,int>(0,0));
visited[0][0]=true;
	while (!f.empty())
	{
	pair <int,int> current;
	queue<pair<int,int> > temp;
	bool free=true;
	current=f.front();
	f.pop();
		if (current.first-1>=0)
			{
				if (!visited[current.first-1][current.second])
				{
				//visited[current.first-1][current.second]=true;
				if (field[current.first-1][current.second]=='*') free=false;
				else {temp.push(pair<int,int>(current.first-1,current.second));}	
				}
				if (current.second-1>=0)
				{
				if (!visited[current.first-1][current.second-1])
				{
				//visited[current.first-1][current.second-1]=true;
				if (field[current.first-1][current.second-1]=='*') free=false;
				else {temp.push(pair<int,int>(current.first-1,current.second-1));}	
				}
				}
				if (current.second+1<c)
				{
				if (!visited[current.first-1][current.second+1])
				{
				//visited[current.first-1][current.second+1]=true;
				if (field[current.first-1][current.second+1]=='*') free=false;
				else {temp.push(pair<int,int>(current.first-1,current.second+1));}	
				}
				}
			}
				if (current.second-1>=0)
				{
				if (!visited[current.first][current.second-1])
				{
				//visited[current.first][current.second-1]=true;
				if (field[current.first][current.second-1]=='*') free=false;
				else {temp.push(pair<int,int>(current.first,current.second-1));}	
				}
				}
				if (current.second+1<c)
				{
				if (!visited[current.first][current.second+1])
				{
				//visited[current.first][current.second+1]=true;
				if (field[current.first][current.second+1]=='*') free=false;
				else {temp.push(pair<int,int>(current.first,current.second+1));}	
				}
				}
			if(current.first+1<r)
			{	
				if (!visited[current.first+1][current.second])
				{
				//visited[current.first+1][current.second]=true;
				if (field[current.first+1][current.second]=='*') free=false;
				else {temp.push(pair<int,int>(current.first+1,current.second));}	
				}
				if (current.second-1>=0)
				{
				if (!visited[current.first+1][current.second-1])
				{
				//visited[current.first+1][current.second-1]=true;
				if (field[current.first+1][current.second-1]=='*') free=false;
				else {temp.push(pair<int,int>(current.first+1,current.second-1));}	
				}
				}
				if (current.second+1<c)
				{
				if (!visited[current.first+1][current.second+1])
				{
				//visited[current.first+1][current.second+1]=true;
				if (field[current.first+1][current.second+1]=='*') free=false;
				else {temp.push(pair<int,int>(current.first+1,current.second+1));}	
				}
				}
			}
			if (free)
			{
			 while (!temp.empty())
			 {
			  pair<int,int> a;
			  a=temp.front();
			  temp.pop();
			  visited[a.first][a.second]=true;
			  f.push(a);
			  count++;
			 }
			}
			

			
	}
	

	
	
	
	if (count==r*c-mines) {return true;}
	else return false;
}


bool bruteForce(char**field,int r,int c,int mines,int i,int mc)
{
	
	if (mc<mines && i<r*c)
	{
	//cout<<i<<endl;
			

			
			
			
			int ri=i/c;
			int rc=i%c;
			field[ri][rc]='*';
			if(bruteForce(field,r,c,mines,i+1,mc+1)) return true;
			field[ri][rc]='.';
			if (bruteForce(field,r,c,mines,i+1,mc)) return true;
			
		
			
			
	}
	
	
	
	else
	{
	if (mc==mines)
	{	

	if (verify(field,r,c,mines))return true;
	}
	}
	return false;

}

int main()
{
std::ios_base::sync_with_stdio(0);
int T;
cin>>T;
	for (int ct=1;ct<=T;ct++)
	{
	int c,r,m;
	cin>>r>>c>>m;
		
		char **field=new char*[r];
		for (int ct2=0;ct2<r;ct2++)
		{
		field[ct2]=new char[c];
		}
		
		
		for (int ct2=0;ct2<r;ct2++)
		{
		for(int ct3=0;ct3<c;ct3++)
			{
			field[ct2][ct3]='.';
			}
		}
		field[0][0]='c';
		
	printf("Case #%d:\n",ct);
	if (bruteForce(field,r,c,m,1,0))
		{
				for (int rr=0;rr<r;rr++)
			{
				for (int rc=0;rc<c;rc++)
				{
				printf("%c",field[rr][rc]);
				}
				printf("\n");
			}
		printf("\n");
		}
	else
	{
	printf("Impossible\n");
	}

	}
}
