
#include <iostream>
#include <cstdlib>

using namespace std;
long long P,Q;
int test,res;
int check(long long P, long long Q) {
    int count = 0;
    int count1;
    while (P < Q)    {
        P = P*2;
        count++;
    }
    if (P==Q) return count;
    P = P-Q;
    count1 = 0;
    while (count1 <= 100){
        while (P < Q) P = P*2;
        if (P==Q) return count;
        P = P-Q;
        count1 ++;
    }
    return -1;

}
int main(){
    char c;
	cin >> test;
	for (int t=1; t<=test; t++){
        cin >> P;
        cin >> c;
        cin >> Q;

        res = check(P,Q);
        if (res > 0)
        cout << "Case #" <<t << ": "<< res << endl;
        else cout << "Case #" <<t << ": "<< "impossible" << endl;

	}
}
