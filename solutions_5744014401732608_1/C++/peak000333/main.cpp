#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    ifstream fcin;
    ofstream fout;
    fcin.open("B-large (1).in");
    fout.open("B.out");
    int testCase;
    fcin>>testCase;
    for(int t=1;t<=testCase;t++){
        int n;
        long long int m;
        fcin>>n;
        fcin>>m;
        vector<string> ans;
        vector<int> trace;
        vector<int> trace2;
        ans.clear();
        trace.clear();
        trace2.clear();
        string s;
        for(int i=0;i<n;i++){
            s.push_back('1');
        }
        for(int i=0;i<n;i++){
            string temp=s;
            for(int j=0;j<=i;j++){
                temp[j]='0';
            }
            ans.push_back(temp);
        }
        long long int bit=1;
        for(int j=0;j<n-2;j++){
            bit*=2;
        }
        if(m>bit){
           
            fout<<"Case #"<<t<<": IMPOSSIBLE\n";
        }

        else{
            long long int want=bit-m;
            for(int i=0;i<=n;i++){
                long long int bb=1;
                for(int j=0;j<i;j++){
                    bb*=2;
                }
                if(want&bb){
                    trace.push_back(i+1);
                }
            }
        
        for(int i=0;i<trace.size();i++){
            int pos=trace[i];
            ans[pos][n-1]='0';
        }
        fout<<"Case #"<<t<<": POSSIBLE\n";
        for(int i=0;i<ans.size();i++){
            fout<<ans[i];
            fout<<"\n";
        }
        }
    
    }
    
    
    return 0;
}