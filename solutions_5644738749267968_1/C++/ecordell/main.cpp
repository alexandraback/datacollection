#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

class AtLeast
{
public:
    AtLeast (double min) : _min( min ) {}
    bool operator() (double x) { return (x > _min); }
private:
    double _min;
};

template <typename Iter, typename Cont>
bool is_last(Iter iter, const Cont& cont)
{
    return (iter != cont.end()) && (next(iter) == cont.end());
}

int main(int argc, const char * argv[])
{
    std::ifstream infile("/Users/evan/Git/GoogleCodeJam/Qualification/Problem D/QualProblemD/QualProblemD/D-large.in");
    std::ofstream outfile;
    outfile.open("/Users/evan/Git/GoogleCodeJam/Qualification/Problem D/QualProblemD/QualProblemD/large.out");
    
    int T; //number of test cases
    infile >> T;
    
    for (int tcase = 1; tcase<=T; tcase++) {
        
        int numWeights;
        int warWins = 0;
        int decWarWins = 0;
        
        infile >> numWeights;
        
        std::vector<double> ken;
        std::vector<double> naomi;
        
        for (int i = 0; i<numWeights; i++) {
            double val;
            infile >> val;
            naomi.push_back(val);
        }
        for (int i = 0; i<numWeights; i++) {
            double val;
            infile >> val;
            ken.push_back(val);
        }
        
        std::sort(ken.begin(), ken.end());
        std::sort(naomi.begin(), naomi.end());
        std::vector<double> decKen(ken);
        std::vector<double> decNaomi(naomi);
        
        //play war
        for(std::vector<double>::iterator it = naomi.begin(); it != naomi.end();) {
            double naomiChoice = *it;
            AtLeast cmp(naomiChoice);
            
            if (ken.size() > 1) {
                std::vector<double>::iterator kenElem = std::find_if(ken.begin(), ken.begin() + ken.size() - 1, cmp);
                
                if (is_last(kenElem, ken)) {
                    //not found, check if last elem works
                    if (*kenElem > naomiChoice) {
                        //ken wins
                    } else {
                        //naomi wins
                        warWins++;
                    }
                    ken.pop_back();
                } else {
                    //ken wins
                    ken.erase(kenElem);
                }
                it = naomi.erase(it);
            } else {
                //only one option for ken, vec.begin
                if ((*ken.begin()) < naomiChoice) {
                    warWins++;
                }
                ken.erase(ken.begin());
                it = naomi.erase(it);
            }
        }
        
        
        //play decietful war
        for(std::vector<double>::iterator it = decNaomi.begin(); it != decNaomi.end();) {
            double naomiChoice = *it;
            
            bool match = false;
            for(std::vector<double>::iterator kit = decKen.begin(); kit != decKen.end(); kit++) {
            
                if (naomiChoice > *kit) {
                    decWarWins++;
                    it = decNaomi.erase(it);
                    decKen.erase(kit);
                    match = true;
                    break;
                }
            }
            if (!match) {
                it++;
            }
        }
        
        outfile << "Case #" << tcase << ": " << decWarWins << ' ' << warWins << "\n";

    }
    outfile.close();
    return 0;
}
