#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

long long E,R,N,v[10000];

void RMQ_precompute()
{
	
}

int find_max(int l, int r)
{
	int id = l;
	for(int i=l;i<r;i++)
		if (v[id]<v[i])
			id = i;
	return id;
}

long long solve(int l, int r, long long eng_beg, long long eng_end)
{
	long long total_eng = (r-l-1)*R+eng_beg-(eng_end-R);

	int max_id = find_max(l,r);

	long long max_eng_have = min(E, eng_beg+(max_id-l)*R);

	long long max_eng_can_use = max_eng_have;

	if ( (r-max_id)*R - eng_end < 0 )
		max_eng_can_use -= eng_end - (r-max_id)*R;

	long long ret = max_eng_can_use*v[max_id];

	if (max_id!=l)
		ret += solve(l, max_id, eng_beg, min(E,max_eng_can_use+eng_end-R));
	if (max_id!=r-1)
		ret += solve(max_id+1, r, (max_eng_have-max_eng_can_use+R), eng_end);

	return ret;
}

int main()
{
	freopen("B-small-attempt0.in", "r",stdin);
	freopen("B-small-attempt0.out", "w",stdout);
	int T;
	cin>>T;
	for(int tt=1;tt<=T;tt++)
	{
		cin>>E>>R>>N;
		for(int i=0;i<N;i++)
			cin>>v[i];
		R=min(R,E);
		RMQ_precompute();

		long long ans = solve(0,N,E,R);

		cout<< "Case #" << tt << ": " << ans << endl;
	}

	return 0;
}
