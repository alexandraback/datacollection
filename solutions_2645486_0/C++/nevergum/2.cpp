#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<sstream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

long long E,R,N;
long long a[10001];

long long find(int s, int e, long long sEn, long long eEn)
{
    if (s>e) return 0;

    long long max = 0;
    int maxPos = s;
    for (int i=s; i<=e; i++) {
        if (a[i]>max) {
            max = a[i];
            maxPos = i;
        }
    }

    long long total = std::min(sEn + (maxPos-s)*R, E);
    long long should = std::max(eEn-R*(e-maxPos+1), 0ll);
    long long spend = total-should;

//std::cout<<s<<' '<<e<<' '<<sEn<<' '<<eEn<<endl;
//std::cout<<spend<<' '<<spend*max<<endl;
    return max * spend + find(s, maxPos-1, sEn, total)+ find(maxPos+1, e, should+R, eEn);
}
 

int main()
{
    ifstream infile("file.in");
    ofstream outfile("file.out");

    int TestCase;
    infile>>TestCase;

    for (int testcase = 0; testcase < TestCase; testcase++) {
        infile>>E>>R>>N;

        for (int i=0; i<N; i++)
            infile>>a[i];

        long long ret = find(0, N-1, E, 0);


        outfile<<"Case #"<<testcase+1<<": "<<ret<<endl;
//system("PAUSE");
    }
}
