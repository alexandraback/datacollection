#include <cstdlib>
#include <cstdio>

#include <algorithm>
#include <functional>
#include <vector>

#include <iostream>

using namespace std;

double solve(int aTyped, int aFull, const vector<double>& aProbs) {
    int toType = aFull - aTyped;
    
    // vector<double> pOk(aProbs);
    // for(vector<double>::iterator it = pOk.begin(); it != pOk.end(); ++it){
        // *it = 1.0 - *it;
    // }
  
    vector<double> pInitialOk(aProbs.size());
    
    vector<double>::const_iterator itOk = aProbs.begin();
    double cum = 1.0;
    
    for(vector<double>::iterator it = pInitialOk.begin(); it != pInitialOk.end(); ++it){
        cum *= *itOk;
        *it = cum;
       
        ++itOk;
    }
    double pAllOkBefore = cum;
    double pMistakeBefore = 1.0 - pAllOkBefore;
  
    // backspace all and hit
    double min = 2*aTyped+toType+1;
    // this is actually 0 backspace
    double expContinue = pMistakeBefore * (2+aFull + toType) + (1.0-pMistakeBefore)*(toType+1);
    min = expContinue < min ? expContinue : min;
    // hit enter case have sense if we have full pass typed
    double expHit = (toType==0) ? (pAllOkBefore) : (2+aFull);
    min = expHit < min ? expHit : min;
    // ev for backspace hits
    vector<double> expBack(aProbs.size());
    for(int i=0; i<aProbs.size(); ++i){
        double hits = 2*i+toType+1;
        expBack[i] = pInitialOk[aTyped-i-1]*(hits) 
            +       (1.0-pInitialOk[aTyped-i-1])*(hits+ aFull+1);
            
        min = expBack[i] < min ? expBack[i] : min;
    }
    
    return min;
}

int main(){

    int cases;
    cin >> cases;

    for(int i=0; i<cases; ++i) {
        int a, b;
        cin >> a >> b;
        vector<double> p(a);
        for(int j=0;j<a;++j){
            cin >> p[j];
        }
        double ret = solve(a,b,p);
        
        cout << "Case #"<< (i+1) <<": "<< fixed << ret << endl;
    }
    return 0;
}
