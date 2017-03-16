#include <algorithm>  
#include <iostream>  
#include <iomanip>  
#include <fstream>  
#include <sstream>  
#include <string>  
#include <list>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <iomanip>  
using namespace std;  

#define FOR(i,a,b) for(long i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  

#define VD vector<double>
#define IT iterator
#define RIT reverse_iterator

long calculateWarScore(VD naomi, VD ken)
{
    //Calculate War score
    VD::RIT it = naomi.rbegin();
    long naomiWarScore = 0;
    for(; it != naomi.rend(); ++it)
    {
        VD::IT ub = upper_bound(ken.begin(), ken.end(), *it);
        if(ub == ken.end())
        {
            ++naomiWarScore;
            ub = ken.begin();
        }

        ken.erase(ub);
    }
    return naomiWarScore;
}

int main(int argc, char** argv)
{
    ifstream in;
    in.open(argv[1],ios::in);
    ofstream out;
    out.open(argv[2],ios::out);
    int N = 0;
    in>>N;
    cout << " Total  " << N <<endl;
    REP(caseN,N)
    {
        cout<<"solving case "<<caseN+1<<endl;
        VD naomi;
        VD ken;
        int N;
        in >> N;

        double d;
        REP(c, N)
        {
            in >> d;
            naomi.push_back(d);
        }
        REP(c, N)
        {
            in >> d;
            ken.push_back(d);
        }

        sort(ken.begin(), ken.end());
        sort(naomi.begin(), naomi.end());
        
        cout << "Sorted Naomi = ";
        REP(i,naomi.size())
            cout << naomi[i] << " ";
        cout << "\nSorted  Ken  = ";
        REP(i,ken.size())
            cout << ken[i] << " ";
        cout << endl;
        long naomiWarScore = calculateWarScore(naomi,ken);
        long naomiDWScore = 0;
        VD::RIT kit = ken.rbegin();
        VD::RIT nit = naomi.rbegin();
        int iter = 0;
        for(int k = ken.size() - 1; k>=0; --k)
        {
        cout << "iter " << iter << " Naomi would throw " << naomi[k] << " So ken would throw " << ken[k] ;
            if(naomi[k] < ken[k])
            {
                cout << "  <<< Ken\n";
                cout << " ( Actuall ken throws " << ken[k] << " and naomi throws " << naomi[0] << endl;
                //ken would win this one, let us take this one out
                naomi.erase(naomi.begin());
                ken.erase(ken.begin() + k);
                //kit = ken.rbegin() + iter + 1;
            }
            else 
            {
                cout << "  <<< Naomi\n";
                ++naomiDWScore;
            }
        }
        
        out << "Case #"<<caseN+1<<": ";
        out << naomiDWScore << " " << naomiWarScore << endl;
    }
        
    in.close();
    out.close();
    return 0;
}
