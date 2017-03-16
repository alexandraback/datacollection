#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int main(int argc, char *argv[])
{
    // xxxxx
    std::cout << "Starting solution of problem A..." << std::endl;

    //file names for input and output
    //std::string filenameIn = "A-large.in";
    //std::string filenameOut = "A-large.out";
    //std::string filenameIn = "A-small-practice.in";
    //std::string filenameOut = "A-small-practice.out";
    std::string filenameIn = "A-small-attempt0.in";
    std::string filenameOut = "A-small-attempt0.out";

    std::ofstream os(filenameOut.c_str());

    std::ifstream is(filenameIn.c_str());
    if (is.is_open()){
        int numTestCases = 0;
        is >> numTestCases;

        for (int nCase = 1; nCase <= numTestCases; nCase++){
            std::cout << "Processing case #" << nCase << std::endl;


            std::string word;
            int n = 0;
            is >> word >> n;

            int num = 0;
            for (int startIdx = 0; startIdx < word.length(); startIdx++){
                int endIdx = word.length()-1;
                for (int endIdx = word.length()-1; endIdx >= startIdx; endIdx--){
                    int numCons = 0;
                    for (int i = startIdx; i <= endIdx; i++){
                        if (word.at(i) != 'a' && word.at(i) != 'e' && word.at(i) != 'o' && word.at(i) != 'i' && word.at(i) != 'u'){
                            //consonant
                            numCons++;
                            if (numCons >= n){
                                break;
                            }
                        } else {
                            //vowel
                            numCons = 0;
                        }
                    }
                    if (numCons >= n){
                        num++;
                    }
                }
            }

            //result is minimum number of operations
            int result = num;

            //write result for test case into file
            os << "Case #" << nCase << ": " << result << std::endl;
            std::cout << "Case #" << nCase << ": " << result << std::endl;
        }

    }
    is.close();

    os.close();

    return 0;
}
