#include <iostream>
#include <algorithm>
#include <string>
#include <array>

std::array<char, 128> conv;

std::array<std::array<char, 4>, 8> mult={{
	{ 0, 1, 2, 3 },
	{ 1, 4, 3, 6 },
	{ 2, 7, 4, 1 },
	{ 3, 2, 5, 4 },
	{ 4, 5, 6, 7 },
	{ 5, 0, 7, 2 },
	{ 6, 3, 0, 5 },
	{ 7, 6, 1, 0 }
}};

int main(){
	conv['1']=0; conv['i']=1; conv['j']=2; conv['k']=3;
	unsigned short T;
	std::cin >> T;
	for(unsigned short t=1; t<=T; ++t){
		unsigned long long l, x;
		std::string c, tmp;
		std::cin >> l >> x >> tmp;

		for(int i=0; i<std::min(x, 16ull+x%4); ++i)
			c+=tmp;
		std::string::const_iterator it=c.cbegin();

		char cur=conv['1'];
		while(cur!=conv['i'] && it!=c.cend())
			cur=mult[cur][conv[*it++]];
		cur=conv['1'];
		while(cur!=conv['j'] && it!=c.cend())
			cur=mult[cur][conv[*it++]];
		cur=conv['1'];
		while(it!=c.cend())
			cur=mult[cur][conv[*it++]];

		std::cout << "Case #" << t << ": " << (cur==conv['k']?"YES":"NO") << "\n";
	}
}
