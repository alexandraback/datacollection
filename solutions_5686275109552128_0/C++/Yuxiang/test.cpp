#include <fstream>
#include <iostream>
using namespace std;

int time(int a, char b){
	return (a + b - 1) / b - 1;
}

int main(){
	ifstream in("B-small-attempt1.in");
	ofstream out("out");
	int t;
	in >> t;
	for (int x = 1 ; x <= t ; x++)
	{
		int d;
		in >> d;
		int p[d];
		int m = 0;
		for (int i = 0 ; i < d ; i++)
		{
			p[i] = 0;
			in >> p[i];
			m = max(m, p[i]);
		}
		int ans = m;
		for (int b = 1 ; b <= m ; b++)
		{
			int tmp = b;
			for (int i = 0 ; i < d ; i++)
				tmp += time(p[i], b);
			ans = min(ans, tmp);
		}
		out << "Case #" << x << ": " << ans << endl;
	}
	in.close();
	out.close();
	return 0;
}
