#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <boost/lexical_cast.hpp>
using namespace std;

int A, B;

int recycle(int a) {
    set<int> S;

    string number = boost::lexical_cast<string>(a);
    for(int i=0; i<number.size(); i++) {
        rotate(number.begin(), number.begin()+1, number.end());
        int x = boost::lexical_cast<int>(number);
        if (number[0] != '0' && x >= A && x <= B) S.insert(x);
    }
    S.erase(S.find(a));
    return S.size();
}

int main()
{
    int numberOfCases;
    scanf("%d",&numberOfCases);
    for(int testNo=1; testNo<=numberOfCases; testNo++) {
       scanf("%d %d",&A, &B);
       int res = 0;
       for(int i=A; i<=B; i++) {
          res += recycle(i);
       }

        printf("Case #%d: %d\n", testNo, res / 2);
    }
}
