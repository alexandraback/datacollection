#include <stdio.h>
#include <map>
#include <string>
#include <vector>

FILE* in=fopen("C-large.in","r");
FILE* out=fopen("out.txt","w");

using namespace std;

int word[1000];
int check[1000];
vector<int> A[1000];
	
int f(int k)
{
    int i,size=A[k].size();
    for(i=0;i<size;i++) if(word[A[k][i]]<0)
    {
        check[A[k][i]]=1;
        word[A[k][i]]=k;
        return 1;
    }
    for(i=0;i<size;i++) if(check[A[k][i]]==0)
    {
        check[A[k][i]]=1;
        if(f(word[A[k][i]]))
        {
            word[A[k][i]]=k;
            return 1;
        }
    }
    return 0;
}

void solve()
{
	map<string,int> front,back;
	int i,j,n,r=0,c=0;
	char F[21],B[21];
	
	fscanf(in,"%d",&n);
	
	for(i=0;i<n;i++) A[i].clear();
	
	for(i=0;i<n;i++)
	{
		fscanf(in,"%s",F);
		if(front.find(F)==front.end()) front[F]=r++;
		
		fscanf(in,"%s",B);
		if(back.find(B)==back.end()) back[B]=c++;
		
		A[front[F]].push_back(back[B]);
	}
	
    for(j=0;j<c;j++) word[j]=-1;
    int cnt=0;
     
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++) check[j]=0;
        cnt+=f(i);
    }
    fprintf(out,"%d\n",n-(r+(c-cnt)));
}

int main()
{
	int i,t;
	fscanf(in,"%d",&t);
	for(i=1;i<=t;i++)
	{
		fprintf(out,"Case #%d: ",i);
		solve();
	}
	return 0;
}
