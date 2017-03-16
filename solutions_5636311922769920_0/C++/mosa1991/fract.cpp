#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;

int main() {
	int t,s,k,c;
	cin >> t;
	for(int i=0;i<t;i++)
	{
	    cin >> s >> k >> c;
	    cout << "Case #" <<i+1<<": ";
	    for(int i=1;i<=s;i++)
		cout << i << " ";
	    cout << endl;
	}
	return 0;
}
