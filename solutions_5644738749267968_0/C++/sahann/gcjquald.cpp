
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iterator>


using namespace std;

int DW(vector <double> ken,vector <double> naomi){
    sort(ken.begin(),ken.end());
    sort(naomi.begin(),naomi.end());
    int cnt = 0;
    int n = naomi.size();
    for(int i=0;i<n;i++){
        int j = min_element(ken.begin(),ken.end())-ken.begin();
        int m = -1;
        for(int k=0;k<ken.size();k++){
            if(naomi[k]>ken[j]) {
                m=k;
                break;
            }
        }
        if(m==-1){
            return cnt;        }
        else{
            ken.erase(ken.begin()+j);
            naomi.erase(naomi.begin()+m);
            cnt++;
        }
    }
    return 0;
    
}
int W(vector <double> ken, vector <double> naomi){
    sort(ken.begin(),ken.end());
    sort(naomi.begin(),naomi.end());
    int n = naomi.size();
    for(int i=0;i<n;i++){
        int j = min_element(naomi.begin(),naomi.end())-naomi.begin();
        int m = -1;
        for(int k=0;k<ken.size();k++){
            if(ken[k]>naomi[j]) {
                m=k;
                break;
            }
        }
        if(m==-1){
            return naomi.size();
        }
        else{
            ken.erase(ken.begin()+m);
            naomi.erase(naomi.begin()+j);
        }
    }
    return 0;
}

int main(){
    int T;
    cin >> T;
    //OK so what's Naomi strategy ?
    //force Ken to burn all of its strong ones with her weakest ones.
    //problem: how many will she force him to burn ?
    //until
    for(int t=0;t<T;t++){
        int N;
        cin >> N;
        vector <double> ken,naomi;
        for(int i=0;i<N;i++){
            double x;
            cin >> x;
            naomi.push_back(x);
            
        }
        for(int i=0;i<N;i++){
            double x;
            cin >> x;
            ken.push_back(x);
            
        }
        int a = W(ken,naomi);
        int b = DW(ken,naomi);
        cout << "Case #" << t+1 << ": " << b << " " << a << endl;
        
    }
    return 0;
}