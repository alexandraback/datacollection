#include<iostream>
#include<fstream>
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include <sstream>
#include <vector>
#include <map>

int getMinNumToSay(int aNumToReach)
{
    //std::cout<<"Iter: "<<aNumToReach;
    assert(aNumToReach >=1);
    static std::map<int, int> result_cache;
    int result = -1;
    std::map<int, int>::iterator iter = result_cache.find(aNumToReach);
    if (iter != result_cache.end())
    {
        result = iter->second;
    }
    else
    {
        if (aNumToReach == 1)
        {
            result = 1;
        }
        else
        {
            int one_lower = getMinNumToSay(aNumToReach - 1);
            std::string str_val(std::to_string(aNumToReach));
            std::string orig_str = str_val;
            std::reverse(str_val.begin(), str_val.end());
            int flipped = -1;
            if (orig_str == str_val)
            {
                result = one_lower + 1;
            }
            else
            {
                std::istringstream str_str(str_val);
                int int_val = -1;
                str_str >> int_val;
                assert(int_val >= 1);
                std::string rev_str(std::to_string(int_val));
                if ((int_val < aNumToReach) && (rev_str.size() == orig_str.size()))
                {
                    flipped = getMinNumToSay(int_val);
                    result = (flipped > one_lower) ? one_lower : flipped;
                    result = result + 1;
                }
                else
                {
                    assert(rev_str.size() <= orig_str.size());
                    result = one_lower + 1;
                }
            }
        }
        //std::cout<<"Res: "<<aNumToReach << " : "<<result<<std::endl;
        result_cache[aNumToReach] = result;
    }
    assert(result != -1);
    return result;
}

int main(int argc, char* argv[])
{
    using namespace std;

    if (argc > 1)
    {
        std::ifstream input_data(argv[1]);
        std::ofstream output_file(std::string("out_")+argv[1]);
        int num_probs = -1;
        std::string line;

        if (input_data.is_open())
        {
            int prob_id = 1;
            getline(input_data, line);
            num_probs = atoi(line.c_str());
            int num_to_be_reached = -1;
            while(getline(input_data, line))
            {
                std::stringstream prob_vars(line);
                prob_vars >> num_to_be_reached;
                //std::cout<<"Prob: "<<num_to_be_reached<<std::endl;
                for (int index = 2; index< num_to_be_reached; index++)
                {
                    getMinNumToSay(index);
                } 
                int min_nums_to_say = getMinNumToSay(num_to_be_reached);
                output_file<<"Case #"<<prob_id<<": "<<min_nums_to_say<<std::endl;

                prob_id++;
            }
            assert(num_probs == prob_id -1);
        }
        else
        {
            std::cerr<<"Cannot open input file: "<<argv[1]<<std::endl;
        }
    }
    else
    {
        std::cerr<<"File path to input data is mandatory input!"<<std::endl;
    }

}
