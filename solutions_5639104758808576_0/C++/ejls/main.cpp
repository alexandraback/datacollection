#include <iostream>
#include <string>

int main(){
	unsigned short T;
	std::cin >> T;
	for(unsigned short t=1; t<=T; ++t){
		std::cin.ignore(5, ' ');
		int sum=0, r=0, c;
		while((c=std::cin.get())!='\n')
			if((sum=sum-1+c-'0')+r<0)
				++r;
		std::cout << "Case #" << t << ": " << r << "\n";
	}
}
