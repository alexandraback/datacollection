#include <list>
#include <queue>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
    if(argc < 3)
    {
        cout << "Usage : "<<argv[0] <<" test.in test.out";
        return 0;
    }
    cout << argv[0] << " " << argv[1] << " " << argv[2] << endl;

    ifstream in(argv[1]);
    if(!in.is_open()) {
        cout << "Failed to open " << argv[1] << endl;
        return 0;
    }

    ofstream out(argv[2]);
    if(!out.is_open()) {
        cout << "Failed to open " << argv[2] << endl;
        return 0;
    }

    int T;
    in >> T;
    for(int i = 0; i < T; ++i)
    {
        int J,P,S,K;
        in >> J;
        in >> P;
        in >> S;
        in >> K;

        stringstream ss;
        unsigned long long total = 0;
        for(int j = 0; j < J; ++j)
        {
            int set = 0;
            for(int p =0; p < P; ++p)
            {
                bool sh_f = false;

                for(int s=0 +set*K ;s < S; ++s)
                {
                    if((s-set*K) >= K) {sh_f = true; break; }
                    ++total;
                    ss << 1+j << " " << 1+p << " " << 1+s << endl;
                }
                if(p >= K){ 
                    if(sh_f)
                    {
                        ++set; if(set*K >= S) break; 
                    }
                    else { set = 0; break;}
                }
            }
        }
        
        cout << "Solving case : " << i<<endl;
        out << "Case #" << i+1 << ": ";
        out << total << endl;
        out << ss.str();
    }
    return 0;
}





