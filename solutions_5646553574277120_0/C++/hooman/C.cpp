#include <iostream>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

int C, D, V;
set<int> Ds;

bool possible(set<int>::iterator it, int v)
{
	if(it == Ds.end())
		return false;
	if((*it) > v)
		return false;
	if((*it) == v)
		return true;
//cout<<'H'<<(*it)<<' '<<v<<endl;
	int v2 = v;
	v-=(*it);
	it++;
	if(possible(it, v))
		return true;
	return possible(it,v2);
}

int solve()
{
	long long v=1;
	Ds.insert(1);
	while(v<=V)
	{
		while(possible(Ds.begin(), v))
		{
			v++;
			if(v>V)
				goto finish;
		}
cout<<v<<endl;
		Ds.insert(v);
	}
	finish:
	return Ds.size()-D;
}

int main()
{
	FILE *in,*out;
//	char line[1000];
	int T, t;
	in = fopen("C.in","r");
	out = fopen("C.out","w+");
//	fgets(line,999,in);
//	sscanf(line,"%d",&T);
	fscanf(in,"%d ",&T);
	for(t = 1; t <= T; t++)
	{
//		fgets(line,999,in);//empty line
		int i,j;
		fscanf(in,"%d %d %d ",&C, &D, &V);
cout<<t<<' '<<C<<' '<<D<<' '<<V<<endl;
		Ds.clear();
		for(i=0; i<D; i++)
		{
			int d;
			fscanf(in,"%d ",&d);
			Ds.insert(d);
		}
		fprintf(out, "Case #%d: %d\n",t, solve());
	}
	fclose(in);
	fclose(out);
}
