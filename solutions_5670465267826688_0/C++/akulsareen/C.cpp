#include <bits/stdc++.h>
using namespace std;
typedef pair<char,int> pci;
string inp,A;
string A_mult[4] = {"hijk","ihkj","jkhi","kjih"};
int B_mult[4][4] = {{1,1,1,1},{1,-1,1,-1},{1,-1,-1,1},{1,1,-1,-1}};
pci quaternion_multiply(pci x, pci y)
{
	pci ans;
	ans.first=A_mult[x.first-'h'][y.first-'h'];
	ans.second=x.second*y.second*B_mult[x.first-'h'][y.first-'h'];
	return ans;
}
bool is_splittable()
{
	pci curr=make_pair('h',1);
	bool found_i=false;
	bool found_ij=false;
	for (int i = 0; i < A.size(); ++i)
	{
		curr=quaternion_multiply(curr,make_pair(A[i],1));
		if(!found_i)
		{
			if(curr.first == 'i' && curr.second == 1)
				found_i=true;
		}
		else
		{
			if(!found_ij)
			{
				if(curr.first == 'k' && curr.second == 1)
					found_ij=true;
			}
		}
	}
	if(found_ij && curr.first == 'h' && curr.second == -1)
		return true;
	return false;
}
int main()
{
	freopen("c_small.in", "r", stdin);
	freopen("c_small.out", "w", stdout);
	// freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	for (int case_num = 1; case_num <= t; ++case_num)
	{
		long long int l,x;
		cin>>l>>x;
		cin>>inp;
		bool ans_found=false;
		if(x > 11)
		{
			for (long long int i = 1; i <= 11 && !ans_found; ++i)
			{
				if((x-i)%4ll == 0)
				{
					A="";
					for (int j = 0; j < i; ++j)
					{
						A+=inp;
					}
					if(is_splittable())
						ans_found=true;
				}
			}
		}
		else
		{
			A="";
			for (int i = 0; i < x; ++i)
			{
				A+=inp;
			}
			if(is_splittable())
				ans_found=true;
		}
		if(ans_found)
			cout<<"Case #"<<case_num<<": YES\n";
		else
			cout<<"Case #"<<case_num<<": NO\n";
	}
	return 0;
}