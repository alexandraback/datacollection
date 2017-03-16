#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	fstream in;
	fstream out;
	in.open("A-small-attempt0.in", ios::in);
	out.open("output.out", ios::trunc|ios::out);

	int test;
	long long r,t;

	in>>test;
	for (int repeat = 0; repeat < test; ++repeat)
	{
		out<<"Case #"<<repeat+1<<": ";

		in>>r>>t;
		long long black=0;
		while (true) {
			t-=2*r+4*black+1;
			if (t>=0)
			black++;
			else break;
		}

		out<<black;

		out<<endl;
	}
}