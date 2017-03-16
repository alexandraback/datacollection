#include <deque>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <eigen3/Eigen/Core>

int main(int argc, char**argv){


    if(argc != 2){
        std::cout << "Pass the filename" << std::endl;
        return 0;
    }

    std::string line;
    std::ifstream infile(argv[1]);

    std::getline(infile,line); // discard number of cases
    int case_ = 0;

    int J =0;
    int P =0;
    int S =0;
    int K =0;

    while (std::getline(infile, line))  // this does the checking!
    {
        std::istringstream iss(line);
        iss >> J;
        iss >> P;
        iss >> S;
        iss >> K;

        //find smallest value of J*P*K etc.
        
        int maxDays = J*P*S;
        // 0 means K irrelevant, 1 S, 2 P , 3 J
        int limiter = 0;
        if( J*P*K < maxDays){
            limiter = 1; 
            maxDays = J*P*K;
        }
        if( J*S*K < maxDays){
            limiter = 2;
            maxDays = J*S*K;
        }
        if(P*S*K < maxDays){
            limiter = 3;
            maxDays = S*P*K;
        }

        std::cout << "Case #" << ++case_ << ": "<< maxDays << std::endl;
        if(limiter == 0 ){
            for(int j = 1; j <= J; ++j)
                for(int p = 1; p <= P; ++p)
                    for(int s = 1; s <=S; ++s)
                        std::cout << j << " " << p << " " << s << std::endl;
        }

        //Here K is relevant
        int loop = 1;
        int biggerVal = 0;
        if(limiter == 1 ){
            biggerVal = ( J < P ? P : J);
            for(int k = 1; k <= K; ++k){
                loop = k;
                for(int j = 1; j <= J; ++j){
                    for(int p = 1; p <=P; ++p){
                            std::cout << j << " " << p << " " << loop << std::endl;
                            ++loop;
                            if(loop > biggerVal) loop = 1;
                    }
                }
            }
        }
        if(limiter == 2 ){
            biggerVal = ( J < S ? S : J);
            for(int k = 1; k <= K; ++k){
                loop = k;
                for(int j = 1; j <= J; ++j){
                    for(int s = 1; s <=S; ++s){
                        std::cout << j << " " << loop << " " << s << std::endl;
                        ++loop;
                        if(loop > biggerVal) loop =1;
                    }
                }
            }
        }

        if(limiter == 3 ){
            biggerVal = ( P > S ? P : S);
            for(int k = 1; k <= K; ++k){
                loop = k;
                for(int p = 1; p <= P; ++p){
                    for(int s = 1; s <=S; ++s){
                        std::cout << loop << " " << p << " " << s << std::endl;
                        ++loop;
                        if(loop > biggerVal) loop =1;
                    }
                }
            }
        }
   }

    return 0;
}
