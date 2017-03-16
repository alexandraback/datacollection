#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;;
int solve(int s, int p, vector<int> v);
int main()
{
	std::ifstream f("B-large.in");
	std::ofstream o("result2-2.txt");

	int size;
	f >> size;
	for(int i = 0; i < size; i++)
	{
		int n, s, p;
		f >> n >> s >> p;
		vector<int> v(n);
		for(int j = 0; j < n; j++)
		{
			f >> v[j];
		}
		int result = solve(s,p,v);
		std::cout << "Case #" << i+1 << ": " << result << std::endl;
		o << "Case #" << i+1 << ": " << result << std::endl;
	}
	return 0;
}

int solve(int s, int p, vector<int> v)
{
	int cnt = 0;
	int pcnt = 0;
	for(int i = 0; i < (int)v.size(); i++)
	{
		if(v[i] >= p &&  p * 3 - 2 <= v[i])		
			cnt++;
		else if(v[i] >= p && p * 3 - 4 <= v[i] && 28 >= v[i])		
			pcnt++;
	}
	return s < pcnt ? cnt+s : cnt+pcnt;

}