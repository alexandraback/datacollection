#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int war(const vector<double> &naomi, const vector<double> &ken){
    int pt = 0;
    auto na = naomi.begin(), nb = naomi.end();
    auto ka = ken.begin(), kb = ken.end();
    
    while(na != nb){
        if(*(nb-1) > *(kb-1)){
            ++pt;
            ++ka;
        }else{
            --kb;
        }
        --nb;
    }
    
    return pt;
}

int deceit(const vector<double> &naomi, const vector<double> &ken){
    int pt = 0;
    auto na = naomi.begin(), nb = naomi.end();
    auto ka = ken.begin(), kb = ken.end();
    
    while(na != nb){
        if(*na > *ka){
            ++pt;
            ++ka;
        }else{
            --kb;
        }
        
        ++na;
    }
    
    return pt;
}

void proc(ifstream &in, ofstream &out, int tc){
    int n;
    in >> n;
    vector<double> naomi(n), ken(n);
    for(int i=0; i<n; ++i){
        in >> naomi[i];
    }
    
    for(int i=0; i<n; ++i){
        in >> ken[i];
    }
    
    sort(naomi.begin(), naomi.end());
    sort(ken.begin(), ken.end());
    
    out << "Case #" << tc << ": ";
    out << deceit(naomi, ken) << " " << war(naomi, ken) << endl;
}

int main()
{
    ifstream in("D-large.in");
    ofstream out("D-large.out");
    
    int T;
    in >> T;
    for(int i=1; i<=T; ++i){
        proc(in, out, i);
    }
    
    
    return 0;
}

