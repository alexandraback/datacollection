#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;

int NoOfCakes[1010];

int main()
{
	int t, x, r, c, cases = 0;
	ifstream ifile ("D-large.in");
	//ifstream ifile ("test.in");
	ofstream ofile;
	ofile.open ("Output.out");
	ifile>>t;
	while(t--)
	{
		ifile>>x>>r>>c;
		bool ans = true;

		if(x >= 7)
			ans = false;
		else if(x > r && x > c)
			ans = false;
		else if(r * c % x != 0)
			ans = false;
		else if ((x + 1) / 2 > min(r, c))
			ans = false;
		else if(x <= 1 && x <= 3)
			ans = true;
		else if(x == 4)
			ans = min(r, c) > 2;
		else if(x == 5)
			ans = !(min(r, c) == 3 && max(r, c) == 5);
		else if(x == 6)
			ans = min(r, c) > 3;
		if(ans)
			ofile<<"Case #"<<++cases<<": "<<"GABRIEL"<<endl;
		else
			ofile<<"Case #"<<++cases<<": "<<"RICHARD"<<endl;
	}
	ifile.close();
	ofile.close();
	return 0;
}