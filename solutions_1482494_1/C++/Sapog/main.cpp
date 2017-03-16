#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <string>

class Found{};

using namespace std;

typedef pair<int,int> pii;
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define mp(a,b) (make_pair((a),(b)))

bool comp(pii p1, pii p2)
{
    return p1.first<p2.first || (p1.first==p2.first && p1.second<p2.second);
}

int main()
{
    ifstream in("C:\\Users\\Olexandr\\Desktop\\B-large.in");
    ofstream out("C:\\Users\\Olexandr\\Desktop\\output.txt");
    int T;
    in>>T;


    for(int t=0; t<T; t++)
    {
        out<<"Case #"<<(t+1)<<": ";
        //code here:
        int N;
        in>>N;
        vector<pii> levels(N);
        for(int i=0; i<N; i++)
        {
            int a,b;
            in>>a>>b;
            levels[i]=mp(a,b);
        }
        bool ok=true;
        int result=0, stars=0;
        vector<short> tested(N); //0-no, 1-one star, 2-2 star
        for(int i=0; stars!=2*N; i++)
        {
            int index=-1,stars_=0;
            for(int j=0; j<N; j++)
            {
                if(tested[j]==1 && levels[j].second<=stars)
                {
                    index=j;
                    stars_=1;
                    break;
                }
                if(tested[j]==0 && levels[j].first<=stars)
                {
                    if(levels[j].second<=stars)
                    {
                        stars_=2;
                        index=j;
                        break;
                    }
                    if(index==-1 || levels[index].second<levels[j].second)
                    {
                        index=j;
                        stars_=1;
                    }

                }
            }
            if(index==-1)
            {
                ok=false;
                break;
            }
            stars+=stars_;
            tested[index]+=stars_;
            result++;
            
        }
        if(ok)
            out<<result<<endl;
        else
            out<<"Too Bad"<<endl;
    }
    system("pause>nul");
    return 0;
}