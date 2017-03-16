
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;




int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	
	int T;cin>>T;
	for (int qq=1;qq<=T;qq++)
	{
		int r,t;
		cin>>r>>t;
		int total=0;
		int num=1;
		int k=0;
		while (total<=t)
		{
			total+=2*r+2*num-1;
			num+=2;
			k++;
		}
		cout << "Case #"<<qq<<": "<<k-1<<endl;



	}



	
	return 0;
}