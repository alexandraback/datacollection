
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<set>
#include<vector>
using namespace std;

typedef long double LD;
double array[11];
vector<double> ken;
int N;
int go(int nIndex, int used) {
    // try eliminating each index
    int m = 0;
    for(int i = 0; i < N; i++){
        if(!(used& (1<<i))){
            if(array[nIndex] > ken[i]){
                m = max(m,1 + go(nIndex+1, used|(1<<i)));
            }else{
                m = max(m,go(nIndex+1, used|(1<<i)));
            }
        }
    }
    return m;
}

int main(){

    int TC,c,d,a,b;

    scanf("%d",&TC);
    int casenum =1 ;
    
    while(TC--){

        cin >> N;
        vector<double> naomi;
        ken.clear();
        double tmp;
        for(int i = 0; i < N; i++){
            cin >> tmp;
            
            naomi.push_back(tmp);
        }
     
        for(int i = 0; i < N; i++){
            cin >> tmp;
            
            ken.push_back(tmp);
        }

        sort(ken.begin(), ken.end());
        sort(naomi.begin(), naomi.end());
        /*for(int i = 0; i < N; i++){
            cout << naomi[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < N; i++){
            cout << ken[i] << " ";
        }
        cout << endl;*/
        int nindex=0, kindex = 0;
        int count = 0;
        while(nindex < N && kindex < N){
            
            while(ken[kindex] < naomi[nindex] && kindex < N){
                kindex++;
            }
            kindex++;
            nindex++;
            
        }

        
        for(int i = 0; i < N; i++){
            array[i] = naomi[i];
        }
        /*cout << "arrayjhgas: ";
        for(int i = 0; i < N; i++){ cout << array[i] << " ";}
        cout << endl;
        for(int i = 0; i < N; i++) cout << naomi[i] << " ";
        cout << endl;*/
        
        
        cout << "Case #" << casenum++ << ": " << go(0,0) << " " << kindex-nindex  << endl;
    }
    
}
