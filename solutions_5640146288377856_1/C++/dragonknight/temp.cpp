#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int i,j,t,case_no,r,c,w,ans;
	case_no=1;
	ifstream inf("A-large.in");
	inf >> t;
	printf("t=%d\n",t);
	ofstream outf("output.txt");
	while(t--) {
		inf >> r;
		inf >> c;
		inf >> w;
		ans = (r*(c/w)) + (w-1) + ((c%w==0)?0:1);
		outf << "Case #"<<case_no<<": "<<ans<<"\n";
		case_no++;
	}
	outf.close();
	inf.close();
	return 0;
}