//#include <iostream>
#include <fstream>
using namespace std;
ifstream cin("input.txt");
ofstream cout("output2.txt");

long long value[10000], cases, energy, activities, repl, dummy;



long long solve(long long left, long long right, long long start, long long finish){
    //cout<<left<<" "<<right<<" "<<start<<" "<<finish<<"\n";
    //cin>>dummy;
    if(left-1==right) return 0;
    long long total = 0;
    // find maximum. crucial to calculations.
    long long maxID = -1, high = 0;
    for(long long i = left; i <= right; i++){
        if(value[i] > high){ // if same, results should be same no matter what choice
            high = value[i];
            maxID = i;
        }
    }
    // find left and right.
    long long leftrepl = min(repl*(maxID-left) + start,energy);
    long long rightrepl = min(repl*(right-maxID+1ll),energy);

    long long needMax = max(0ll,finish-rightrepl);
    long long allowTake = min(energy,leftrepl-needMax);
    //take that amount. Greedy.
    total += allowTake * high;
    // solve the left and right.
    long long leftscore = solve(left,maxID-1,start,min(energy,allowTake+needMax));
    long long rightscore = solve(maxID+1,right,min(needMax+repl,energy),finish);
    return total + leftscore + rightscore;
}

int main(){
    cin>>cases;
    for(long long c = 1; c <= cases; c++){
        cin>>energy>>repl>>activities;

        for(long long i = 0; i < activities; i++){
            cin>>value[i];
        }

        cout<<"Case #"<<c<<": "<<solve(0,activities-1,energy,0)<<"\n";
    }
}
