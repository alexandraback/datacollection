#include <iostream>

void func(const int cas){
	double c, f, x;
	std::cin >> c >> f >> x;
	double time = 0, speed = 2;
	while(true){
		double t = c / speed;
		double t1 = x / speed;
		double t2 = t + x / (speed + f);
		if(t1 <= t2){
			time += t1;
			break;
		}else{
			time += t;
			speed += f;
		}
	}
	std::cout << "Case #" << cas << ": " << time << std::endl;
}

int main(){
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::cout.precision(7);

	int T;
	std::cin >> T;
	for(int cas = 1; cas <= T; cas++)
		func(cas);
	return 0;
}