#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>

#include <boost/lexical_cast.hpp>
#include <boost/assign.hpp>

using namespace std;
using namespace boost;
using namespace boost::assign;


struct Plan
{
    int day;
    int tribe;
    int count;
};

int main(int argc, char** argv)
{
    // ifstream in("in");
    //ofstream out("A-large-1.out");
    auto& in = cin;
    auto& out = cout;

    out << setprecision(7);

    string line;
    getline(in, line);
    int nLines = boost::lexical_cast<int>(line); 

    int wall[2000000];
    int middle = 1000000;

    for (int caseNo=0; caseNo < nLines; ++caseNo)
    {
    
        memset(wall, 0, sizeof(wall));

        int nTribes;
        in >> nTribes;
        int day0[1000], attacks[1000], west0[1000], east0[1000], strength0[1000], deltaDay[1000], deltaTravel[1000], deltaStrength[1000];
        for (int i=0; i< nTribes; ++i)
        {
            in >> day0[i] >> attacks[i] >> west0[i] >> east0[i] >> strength0[i] >> deltaDay[i] >> deltaTravel[i] >> deltaStrength[i];
        }

        std::list<Plan> attackOrder;
        for (int i=0; i<nTribes; ++i)
        {
            for (int j=0; j<attacks[i]; ++j)
            {
                Plan myPlan;
                myPlan.day = day0[i] + deltaDay[i]*j;
                myPlan.tribe = i;
                myPlan.count = j;
                attackOrder.push_back(myPlan);
            }
        }

        attackOrder.sort([](Plan& first, Plan& second) -> bool{
            return first.day < second.day; });

        int totalBreakthrough = 0;

        list<Plan> breakThroughs;
        int lastAttackDay = -1;

        for (auto iter = attackOrder.begin(); iter != attackOrder.end(); ++iter)
        {
            //cout << "Attack tribe=" << iter->tribe << " day=" << iter->day<< " count=" << iter->count << endl;
            // first check if walls are to made higher
            if (iter->day > lastAttackDay)
            {
                for (auto br = breakThroughs.begin(); br != breakThroughs.end(); ++br)
                {
                    int start = west0[br->tribe] + deltaTravel[br->tribe] * br->count + middle;
                    int count = east0[br->tribe] - west0[br->tribe];
                    int strength = strength0[br->tribe] + deltaStrength[br->tribe] * br->count;
                    //cout << "building wall start=" << start << " count=" << count << " str=" << strength << endl;
                    for (int i=0; i< count; ++i)
                    {
                        if (wall[start + i] < strength)
                        {
                            wall[start + i] = strength;
                        }
                    }
                }
                breakThroughs.clear();
            }
            
            int start = west0[iter->tribe] + deltaTravel[iter->tribe] * iter->count + middle;
            int count = east0[iter->tribe] - west0[iter->tribe];
            int strength = strength0[iter->tribe] + deltaStrength[iter->tribe] * iter->count;

            //cout << "attacking from start=" << start << " count=" << count << " str=" << strength << endl;
            for (int i=0; i< count; ++i)
            {
                if (wall[start + i] < strength)
                {
                    //cout << "found weakness location=" << start +i << " wall=" << wall[start+i] << " str=" << strength << endl;
                    totalBreakthrough++; 
                    breakThroughs.push_back(*iter);
                    lastAttackDay = iter->day;
                    break;
                }
            }
        }


        out << "Case #" << caseNo+1 << ": ";
        out << totalBreakthrough;
        out << endl;
    }


    return 0;
}

