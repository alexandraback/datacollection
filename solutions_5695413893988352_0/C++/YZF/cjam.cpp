#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int technobabble()
{
    ifstream testcase("example.txt");
    ofstream result("result.out");

    int ncases;
    testcase >> ncases;

    for(int c = 0; c < ncases; ++c) {
        map<string, int> firstmap;
        map<string, int> secondmap;
        vector<string> fv;
        vector<string> sv;
        int ntitles;
        testcase >> ntitles;
        for(int i = 0; i<ntitles; ++i) {
            std::string first, second;
            testcase >> first;
            testcase >> second;
            firstmap[first]++;
            secondmap[second]++;
            fv.push_back(first);
            sv.push_back(second);
        }
        int fakers = 0;;
        for(int i=0; i<ntitles; ++i) {
            if(firstmap[fv[i]]>1 && secondmap[sv[i]]>1) {
                fakers++;
                firstmap[fv[i]]--;
                secondmap[sv[i]]--;
            }
        }
        result << "Case #" << c+1 << ": " << fakers << endl;
    }
}

#define ABS(X) (((X)>0) ? (X) : (-(X)))

int main()
{
    ifstream testcase("example.txt");
    ofstream result("result.out");

    int ncases;
    testcase >> ncases;

    for(int c = 0; c < ncases; ++c) {
        std::string first, second;
        testcase >> first;
        testcase >> second;

        long long bestf = 0;
        long long bests = 0;
        unsigned long long mindist = ULLONG_MAX;

        int qc = 0;
        unsigned long long ec = 1;
        for(int i = 0; i<first.size(); ++i) {
        /*    if(first[i]=='?' && second[i]=='?' && (i==0 || first[i-1]==second[i-1])) {
                first[i] = '0';
                second[i] = '0';
            } else { */
                if(first[i]=='?') {
                    qc++;
                    ec *= 10;
                }
                if(second[i]=='?') {
                    qc++;
                    ec *= 10;
                }
         /*   }*/
        }
        for(unsigned long long ttt = 0; ttt<ec; ttt++)
        {
            unsigned long att = ttt;
            long long f = 0, s = 0;
            for(int i=0; i<first.size(); ++i)
            {
                f *= 10;
                if(first[i]!='?') {
                    f += first[i]-'0';
                } else {
                    f += att%10;
                    att /= 10;
                }
            }
            for(int i=0; i<first.size(); ++i)
            {
                s *= 10;
                if(second[i]!='?') {
                    s += second[i]-'0';
                } else {
                    s += att%10;
                    att /= 10;
                }
            }

            unsigned long long diff = ABS(f-s);
            if(diff<mindist) {
                mindist = diff;
                bestf = f;
                bests = s;
            } else if(diff==mindist) {
                if(f<bestf) {
                    bestf = f;
                    bests = s;
                } else if(f==bestf && s<bests) {
                    bests = s;
                }
            }
        }
        ios init(NULL);
        init.copyfmt(cout);
        result << "Case #" << c+1 << ": " << setfill('0') << setw(first.size()) << bestf << " " << setfill('0') << setw(first.size()) << bests << endl;
        cout.copyfmt(init);
    }
}
