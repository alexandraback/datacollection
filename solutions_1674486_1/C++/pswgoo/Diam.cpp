#include<fstream>
#include<string.h>
using namespace std;
const int MAX = 1010;

int mat[MAX][MAX];
bool mark[MAX];
int N;
int cnt;

bool BFS(int s);

int main()
{
    ifstream fin("A-large.in");
	ofstream fout("out.txt");
	int T;
	fin>>T;
	for(int i=0;i!=T;++i)
	{   fin>>N;
	    for(int j=0;j!=N;++j)
		{   int m;
		    fin>>m;
			for(int k=0;k!=N;++k) 
			    mat[j][k] = 0;
			for(int k=0;k!=m;++k)
			{   int to;
			    fin>>to;
				mat[j][to-1] = 1;
			}
		}
		memset(mark,0,sizeof(mark));
		bool bb=false;
		for(int j=0;j!=N;++j)
		{   if(!mark[j])
		        if(BFS(j))
				{   bb = true;
     				break;
				}
		}
		fout<<"Case #"<<i+1<<": ";
		if(bb) fout<<"Yes"<<endl;
		else fout<<"No"<<endl;
	}
	
	return 0;
}

bool BFS(int s)
{
    bool mm[MAX];
	memset(mm,0,sizeof(mm));
	int que[MAX+20];
	int front=0,rear=0;
	que[rear++] = s;
	while(front!=rear)
	{   int nod = que[front++];
	    for(int i=0;i!=N;++i)
		{   if(mat[nod][i])
		    {   if(mm[i])
			        return true;
				mm[i] = true;
				mark[i] = true;
				que[rear++] = i;
			}
		}
	}
	return false;
}
	