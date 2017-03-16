#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    int T,A,B,case_id;
    double case1,case3,case2t,casemin;
    freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small-attempt1.out","w",stdout);
    cin >> T;
    cout << fixed;
    cout << setprecision (6);
    for (case_id=1;case_id<=T;++case_id) {
        cin >> A >> B;
        double p[A],ProbAllCorrect[A+1];
        ProbAllCorrect[0]=1;
        for (int i=0;i<A;++i) {
            cin >> p[i];
            ProbAllCorrect[i+1]=p[i]*ProbAllCorrect[i];
        }
        case1=ProbAllCorrect[A]*(double)(B-A+1)+(1-ProbAllCorrect[A])*(double)(B-A+1+B+1);
        case3=B+2;
        casemin=min(case1,case3);
        //casemax=min(casemax,(float)(A+B+1));
        for (int i=0;i<=A;++i) {
            case2t=ProbAllCorrect[i]*(double)(A-i+B-i+1)+(1-ProbAllCorrect[i])*(double)(A-i+B-i+1+B+1);
            casemin=min(casemin,case2t);
        }
        cout << "Case #" << case_id << ": " << casemin << endl;
    }
    return 0;
}
