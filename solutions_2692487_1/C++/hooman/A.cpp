#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int A,N,m[100];

int solve(int index)
{
	int i,j,tmp=0;
cout<<"index"<<index<<endl;
	if(index >= N)
		return 0;

	if(A<2)
		return N-index;

	while(A<=m[index])
	{
		A += A-1;
		tmp++;
	}
	A += m[index];
	tmp += solve(index+1);
	if(tmp > N-index)
		return N-index;
	return tmp;
}

int main()
{
	FILE *in,*out;
//	char line[1000];
	int T, t;
	int i, j, tmp;
	in = fopen("A.in","r");
	out = fopen("A.out","w+");
//	fgets(line,999,in);
//	sscanf(line,"%d",&T);
	fscanf(in,"%d ",&T);
	for(t = 1; t <= T; t++)
	{
//		fgets(line,999,in);//empty line
		fscanf(in,"%d %d ",&A,&N);
cout<<A<<' '<<N<<endl;
		for(i=0; i<N; i++)
			fscanf(in,"%d ",&m[i]);
		for(i=0; i<N; i++)
			for(j=i+1; j<N; j++)
				if(m[i]>m[j])
				{
					tmp = m[i];
					m[i] = m[j];
					m[j] = tmp;
				}
		fprintf(out, "Case #%d: %d\n",t,solve(0));
	}
	fclose(in);
	fclose(out);
}
