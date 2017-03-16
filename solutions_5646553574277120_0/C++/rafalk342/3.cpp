#include <iostream>
#include <vector>
using namespace std;

main(){
    ios_base::sync_with_stdio(false);
    int licznik=1;
    int t;
    cin >> t;
    while(t--){
        int res=0;
        int c,d,v;
        cin >> c >> d >> v;
        vector<int> DP(v+1,0);
        DP[0]=1;
        for(int i=0;i<d;i++){

            int den;
            cin >> den;
            for(int j=v;j>=den;j--){
                DP[j]=max(DP[j],DP[j-den]);
            }
        }
        for(int i=1;i<=v;i++){
            if(DP[i]==0){
                res++;
                for(int j=v;j>=i;j--){
                    DP[j]=max(DP[j],DP[j-i]);
                }
            }
        }
        cout <<"Case #" << licznik++ << ": " <<res << endl;
    }
    return 0;
}
