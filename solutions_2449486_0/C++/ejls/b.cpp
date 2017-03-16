#include <iostream>
#include <algorithm>
#include <vector>

struct lawn{
	std::size_t h, w;
	std::vector<std::vector<unsigned char> > d;

	bool ans() const;
};

std::istream &operator>>(std::istream &in, lawn &rhs){
	in >> rhs.h >> rhs.w;
	rhs.d.resize(rhs.h, std::vector<unsigned char>(rhs.w));
	for(std::size_t y=0; y<rhs.h; ++y)
		for(std::size_t x=0; x<rhs.w; ++x){
			unsigned short tmp;
			in >> tmp;
			rhs.d[y][x]=tmp;
		}
	return in;
}

int main(){
	std::size_t T;
	std::cin >> T;
	for(std::size_t t=1; t<=T; ++t){
		lawn l;
		std::cin >> l;
		std::cout << "Case #" << t << ": " << (l.ans()?"YES":"NO") << "\n";
	}
}

bool lawn::ans() const {
	std::vector<unsigned char> max_on_each_row(h, 0), max_on_each_col(w, 0);
	for(std::size_t y=0; y<h; ++y)
		for(std::size_t x=0; x<w; ++x){
			max_on_each_row[y]=std::max(max_on_each_row[y], d[y][x]);
			max_on_each_col[x]=std::max(max_on_each_col[x], d[y][x]);
		}

	for(std::size_t y=0; y<h; ++y)
		for(std::size_t x=0; x<w; ++x)
			if(d[y][x]!=max_on_each_row[y] && d[y][x]!=max_on_each_col[x])
				return false;
	return true;
}
