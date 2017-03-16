#include <iostream>
#include <cstring>

using namespace std;

int E, R, N, * activities;

int get_max(int index, int energy_left)
{
	if (index >= N) return 0;

	int x,y,z;
	int max_val = 0, cur_val = 0;
	for(x = energy_left; x >= 0; x--)
	{
		z = energy_left - x + R;
		if (z > E) z = E;
		y = x * activities[index];
		cur_val = y + get_max(index + 1, z);
		if (cur_val > max_val)
			max_val = cur_val;
		else if (cur_val < max_val)
			break;
	}

	return max_val;
}

int main()
{
	int cases,t,x,y;

	cin>>cases;
	for (t = 0; t < cases; t++){
		cin>>E>>R>>N;
		activities = new int[N];
		for(x = 0; x < N; x++) cin>>activities[x];

		x = get_max(0, E);
		cout<<"Case #"<<t+1<<": "<<x<<endl;
	}

	return 0;
}
