#include <map>
#include <vector>
using namespace std;


bool name(vector<vector<int>>& cls, vector<int>& grp, int root, int nm)
{
	for (int i=0;i<cls[root].size();i++)
		if (grp[cls[root][i]]==nm)
			return true;
		else
		{
			grp[cls[root][i]]=nm;
		}

		for (int i=0;i<cls[root].size();i++)
			if (name(cls,grp,cls[root][i],nm))
				return true;

		return false;
}

int main(int argc, char* argv[])
{

	FILE* f=fopen("codejam.in","r");
	FILE* o=fopen("codejam.out","w");
	
	int T;

	fscanf(f,"%d",&T);
	

	for(int t=1;t<=T;t++)
	{
		int N;

		fscanf(f,"%d",&N);

		vector<vector<int>> cls(N+1);
		vector<int> grp(N+1);

		for (int n=1;n<=N;n++)
		{
			int M;
			fscanf(f,"%d",&M);
			for (int m=1;m<=M;m++)
			{
				int mi;
				fscanf(f,"%d",&mi);
				cls[n].push_back(mi); //n is a parent to mi
			}
		}

		const char* fnd="No";
		for (int n=1;n<=N;n++)
		{
			if (grp[n]==0 && name(cls,grp,n,n))
			{
				fnd="Yes";
				break;
			}
		}

		fprintf(o,"Case #%d: %s\n",t,fnd);
	}

	fclose(f);
	fclose(o);
	return 0;
}

