#include <iostream>
#include <string>
using namespace std;

int main()
{
	//                a ,  b ,  c ,  d ,  e ,  f ,  g ,  h ,  i ,  j ,  k ,  l ,  m ,  n ,  o ,  p ,  q ,  r ,  s ,  t ,  u ,  v ,  w ,  x ,  y ,  z
	char dict[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q' };
	//
	int T;
	cin >> T;
	while(cin.get() != '\n');	// clear input buffer
	string in;
	char out[101];
	for(int t = 1; t <= T; ++t)
	{
		getline(cin, in);
		for(int i = 0, im = in.length(); i < im; ++i)
		{
			if(in[i] >= 'a' && in[i] <= 'z')
				out[i] = dict[in[i]-'a'];
			else
				out[i] = in[i];
		}
		out[in.length()] = 0;
		//
		cout << "Case #" << t << ": " << out << '\n';
	}
	return 0;
}
