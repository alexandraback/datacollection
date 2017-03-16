#include <iostream>
#include <string>
using namespace std;


int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		string n, out = "";
		cin >> n;
		out += n[0];
		for(int j=1;j<n.size();j++)
			if(n[j]>=out[0])
				out=n[j]+out;
			else
				out=out+n[j];
		cout << "Case #" << i+1 << ": ";
		cout << out << endl;
	}

	return 0;
}