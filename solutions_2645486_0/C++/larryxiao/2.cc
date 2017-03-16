#include <fstream>
#include <iostream>

using namespace std;

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int e,r,n;
int v[20];

int dfs(int gain,int energy,int task)
{
	//cout<<gain<<'\t'<<energy<<'\t'<<task<<endl;
	if (task==n-1) {
		gain+=energy*v[task];
		return gain;
	}
	int max=gain;
	for (int i = 0; i < energy+1; ++i)
	{
		int temp_gain=gain+i*v[task];
		int temp=dfs(temp_gain,MIN(energy-i+r,e),task+1);
		if (max<temp) max=temp;
	}
	return max;
}

int main()
{
	fstream in;
	fstream out;
	in.open("B-small-attempt0.in", ios::in);
	out.open("output.out", ios::trunc|ios::out);

	int test;

	in>>test;
	for (int repeat = 0; repeat < test; ++repeat)
	{
		out<<"Case #"<<repeat+1<<": ";
		//cout<<"Case #"<<repeat+1<<endl;

		in>>e>>r>>n;
		// //cout<<"in>>e>>r>>n\t";
		// //cout<<e<<'\t'<<r<<'\t'<<n<<endl;
		int gain=0,max_gain=0;

		for (int i = 0; i < n; ++i)
		{
			in>>v[i];
		}

		if (r>=e) 
		{
			// //cout<<"if (r>=e)"<<endl;
			for (int i = 0; i < n; ++i)
			{
				max_gain+=v[i];
			}
			out<<max_gain*e<<endl;
			continue;
		}

		max_gain=dfs(0,e,0);

		out<<max_gain;

		out<<endl;
	}
}