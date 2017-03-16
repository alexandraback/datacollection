#include<iostream>
#include<algorithm>
#include<iomanip>

struct rec
{
	int val;
	int id;
	double sol;
}s[200];

bool comp_1(rec a, rec b)
{
	return(a.val<b.val);
}

bool comp_2(rec a, rec b)
{
	return(a.id<b.id);
}

int main()
{
	short T; std::cin >> T;
	for(short ii = 0; ii < T; ii++)
	{
		int sum = 0, N;
		std::cin >> N;
		for(int i = 0; i < N; i++)
		{
			std::cin >> s[i].val;
			sum += s[i].val;
			s[i].id = i;
		}
		std::sort(s,s+N,comp_1);
		int j = 0, part_sum = 0;
		for(; j<N; j++)
		{
			part_sum += s[j].val;
			double val = (part_sum+sum)/double(j+1);
			if(val<s[j].val) {part_sum -= s[j].val; break;}
		}
		double val = (part_sum+sum)/double(j);
		for(int i = N-1; i >= j; i--)
			s[i].sol = 0.;
		for(int i = j-1; i >= 0; i--)
			s[i].sol = val-s[i].val;
		std::sort(s,s+N,comp_2);
		std::cout << "Case #" << ii+1 << ":";
		for(int i = 0; i < N; i++)
			std::cout << ' ' << std::setprecision(9) << 100*(s[i].sol)/sum;
		std::cout << '\n';
	}
	return 0;
}
