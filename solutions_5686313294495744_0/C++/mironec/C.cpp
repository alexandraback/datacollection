#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;

typedef struct IDK {
    string first;
    string second;
    
    int idFirst;
    int idSecond;
    int candidate;
} IDK;

void doStuff(int cas, int N, vector<string> v){
    vector<IDK> vidk;
    vector<string> firsts;
    vector<string> seconds;
    int num = 0;
    
    for(int i=0;i<N;i++){
        IDK o;
        string s = v[i];
        size_t spacePos = s.find(" ");
        o.first = s.substr(0,spacePos);
        o.second = s.substr(spacePos+1);
        
        int found = false;
        for(int j=0;j<firsts.size();j++){
            if(o.first.compare(firsts[j])==0) {
                o.idFirst = j;
                found = true;
            }
        }
        if(!found){
            firsts.push_back(o.first);
            o.idFirst = firsts.size()-1;
        }
        
        int found2 = false;
        for(int j=0;j<seconds.size();j++){
            if(o.second.compare(seconds[j])==0) {
                o.idSecond = j;
                found2 = true;
            }
        }
        if(!found2){
            seconds.push_back(o.second);
            o.idSecond = seconds.size()-1;
        }
        
        o.candidate = found + found2;
        
        vidk.push_back(o);
    }
    
    for(int i=0;i<N;i++){
        if(vidk[i].candidate) num+=vidk[i].candidate;
    }
    
    cout << "Case #" << (cas) << ": " << num/2 << endl;
}

int main(){
    int T;
    string nothing;
    
    cin >> T;
    getline(cin, nothing);
    
    for(int i=0;i<T;i++){
        int N;
        string in;
        
        cin >> N;
        getline(cin, nothing);
        
        vector<string> v;
        for(int i=0;i<N;i++){
            getline(cin, in);
            v.push_back(in);
        }
        
        doStuff(i+1, N, v);
    }
    
    return 0;
}