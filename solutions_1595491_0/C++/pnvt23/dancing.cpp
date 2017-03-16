#include<iostream>

int num_pass(){
	/* Return the number of people who have the best result at least p */
	int n, s, p, res=0;
	std::cin >> n >> s >> p;
	for (int i=0; i<n ; i++){
		int totscore, avg, mod;
		std::cin >> totscore;
		avg = totscore/3;
		mod = totscore%3;
		if (avg+2<p) continue;
		if (avg >= p){
			res += 1;
			continue;
		}
		if (mod==0){
			if (avg+1==p and s>0 and avg>0){
				res += 1;
				s -= 1;
			}
			continue;
		}
		if (mod==1){
			if (avg+1==p) res += 1;
			continue;
		}
		
		if (avg+1==p) res+=1;
		else if (s>0){
			s -= 1;
			res += 1;
		}
	}
	return res;
}
int main(){
	int t = 10;
	std::cin >> t;
	for (int i=0; i<t; i++){
		std::cout << "Case #"<<i+1<<": " << num_pass() << std::endl;
	}
}