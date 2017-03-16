#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <vector>

int main(){
	unsigned short T;
	std::cin >> T;
	for(unsigned short t=1; t<=T; ++t){
		int K, L, S;
		std::cin >> K >> L >> S;
		std::string keys, target;
		std::cin >> keys >> target;

        std::vector<int> jt(L+1, -1);
 
		for(int i=1; i<=L; ++i){
			int pos=jt[i - 1];
			while(pos!=-1 && target[pos]!=target[i-1])
				pos=jt[pos];
			jt[i]=pos + 1;
		}


		std::array<double, 26> alpha;
		alpha.fill(0.);
		for(int i=0; i<K; ++i)
			alpha[keys[i]-'A']++;
		for(int i=0; i<26; ++i)
			alpha[i]/=K;

		std::vector<double> probs(L+1, 0);
		probs[0]=1;

		double p=0;
		for(int i=0; i<S; ++i){
			std::vector<double> newprobs(L+1, 0);
			newprobs[0]=1;
			for(int j=0; j<L; ++j){
				std::array<double, 26> tmpalpha=alpha;
				int b = j;
				while(b!=-1){
					newprobs[b+1] += probs[j] * tmpalpha[target[b]-'A'];
					tmpalpha[target[b]-'A']=0;
					b = jt[b];
				}
			}
			probs = newprobs;
			p+=probs.back();
		}

		bool possible=true;
		for(int i=0; i<L; ++i)
			possible = possible && (alpha[target[i]-'A']!=0);

		int m;
		if(!possible || S<=jt.back())
			m=0;
		else
			m=(S-jt.back())/(L-jt.back());

		std::cout << "Case #" << t << ": " << std::setprecision(9) << (m-p) << "\n";
	}
}
