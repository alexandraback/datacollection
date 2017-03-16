#include<bits/stdc++.h>
#include <sstream>
using namespace std;
long long int ans[1000005];
ofstream out("Aout.txt");
ifstream in("A-large.in");
int main(){
    //Precalculate
    ans[0] = -1;
    for(int n = 1; n <= 1000004; n ++){
        set<long long int> seen;
        long long int actual = 0;
        while(seen.size() < 10){
            actual+=n;
            long long int cop = actual;
            while(cop > 0){
                long long int d = cop%10;
                seen.insert(d);
                cop = (cop-d)/10;
            }

        }
        if(n%100000 == 0)
            cout << n << endl;
        ans[n]=actual;
    }
    cout <<"Finished precalc" << endl;
    int T;
    in >> T;
    for (int cas = 1; cas<= T; cas ++){
        int x;
        in >> x;
        if(x==0)
            out << "Case #"<<cas<<": INSOMNIA"<<endl;
        else
            out << "Case #"<<cas<<": "<<ans[x]<<endl;
    }
}
