#include <iostream>
#include <string>

#define ll long long int

using namespace std;


int main()
{
	int TN;
	cin >> TN;
	for (int tc = 0; tc < TN; tc++)
	{
		ll ans = 0;
		string name;
		int L;

		cin >> name >> L;

		for( int s=0; s<name.size(); s++ ) {
			for( int f=s+1; f<=name.size(); f++ ) {
				string sub = name.substr(s, f-s);
				int maxcons = 0, sec = 0;
				for( int i=0; i<sub.size(); i++ ) {
					if( sub[i] == 'a' || sub[i] == 'i' || sub[i] == 'u' || sub[i] == 'e' || sub[i] == 'o' ) {
						sec = 0;
					} else {
						sec ++;
					}
					maxcons = max( maxcons, sec );
				}

				if( maxcons >= L ) ans ++;
			}
		}

		cout << "Case #" << tc+1 << ": " << ans << endl;
	}
	return 0;
}