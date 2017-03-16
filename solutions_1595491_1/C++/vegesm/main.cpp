#include <iostream>
#include <fstream>
using namespace std;

int bestNonSurprise(int t)
{
    int alap=t/3;
    int r=t-3*alap;
    if(r==0) return alap;
    else return alap+1;
}

int bestSurprise(int t)
{
    if(t==0) return 0;
    int alap=t/3;
    int r=t-3*alap;
    if(r==0) return alap+1;
    if(r==1) return alap+1;
    else return alap+2;
}

void solve(istream& in, ostream& out)
{
    int n, sleft, p;
    int ret=0;
    in>>n>>sleft>>p;
    //cout<<p<<endl;
    for(int i=0; i<n; i++)
    {
        int t;
        in>>t;
        if(bestNonSurprise(t)>=p){
            ret++;
        }
        else if(sleft>0 && bestSurprise(t)>=p) {
            ret++;
            sleft--;
        }
    }
    out<<ret;
}

int main()
{
    /*cout<<bestSurprise(0)<<endl;
    cout<<bestSurprise(1)<<endl;
    cout<<bestSurprise(2)<<endl;
    cout<<bestSurprise(3)<<endl;
    cout<<bestSurprise(4)<<endl;
    cout<<bestSurprise(5)<<endl;
    cout<<bestSurprise(8)<<endl;
    cout<<bestSurprise(18)<<endl;
    cout<<bestSurprise(21)<<endl;*/
    ifstream in("B-large.in");
    ofstream out("dancing.out");
    int cases;
    in>>cases;
    for(int i=0;i<cases;i++)
    {
        out<<"Case #"<<(i+1)<<": ";
        solve(in, out);
        out<<endl;
    }
    in.close();
    out.close();
    return 0;
}
