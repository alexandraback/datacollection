#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

unsigned long long r,t;

int cal(unsigned long long n)
{
	//return t-(2*n*n+(2*r+3)*n+(2*r+1));
	unsigned long long temp=2*n*n+2*r*n-n;
	if (t==temp) return 0;
	return (t>temp)?1:-1;
}

int main()
{
	fstream in;
	fstream out;
	in.open("A-large.in", ios::in);
	out.open("output.out", ios::trunc|ios::out);

	int test;

	in>>test;
	for (int repeat = 0; repeat < test; ++repeat)
	{
		out<<"Case #"<<repeat+1<<": ";
		//cout<<"Case #"<<repeat+1<<endl;

		in>>r>>t;
		unsigned long long black=0;
		unsigned long long low=1,high=MIN(sqrt(t/2),t/2/r)+1,mid=0;
		while (high-low>1)
		{
			//cout<<"low<<mid<<high<<temp";
			mid=(low+high)/2;
			// signed & unsigned
			int temp=cal(mid);
			//cout<<"\t\t"<<low<<"\t"<<mid<<"\t"<<high<<"\t\t\n "<<temp<<endl;
			if (temp==0) {low = mid; break;}
			if (temp==1) {low = mid; } else {high = mid; }
		}
		//cout<<"fin:low<<mid<<high";
		//cout<<"\t"<<low<<"\t"<<mid<<"\t"<<high<<endl;
		// while (true) {
		// 	t-=2*r+4*black+1;
		// 	if (t>=0)
		// 	black++;
		// 	else break;
		// }

		out<<low;

		out<<endl;
	}
}