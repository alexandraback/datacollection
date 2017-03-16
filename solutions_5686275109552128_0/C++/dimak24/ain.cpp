#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std; 
int minutes(int* m, int max, int n) {
    int ans=0;
    for(int i=0; i<n; i++) {
            ans+=((m[i]-1)/max);
            }
    return ans;
}
int main() {
    ofstream fout("qqq.txt");
    ifstream fin("B-small-attempt0.in");
    int t;
    fin >> t;
    for(int j=0; j<t; j++) {
            int n;
            fin >> n;
            int* m=new int [n];
            for(int i=0; i<n; i++) fin >> m[i];
            sort(&m[0], &m[n]);
            int ans=9999999;
            for(int i=m[n-1]; i>=1; i--) {
                    int t=i+minutes(m, i, n);
                    ans=min(t, ans);
                    }
    fout << "Case #" << j+1 << ": " << ans << "\n";
    }
    return 0;
}
                    
