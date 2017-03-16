//#include <iostream>
#include <fstream>
using namespace std;
ifstream cin("input.txt");
ofstream cout("output2.txt");

int value[10000], cases, energy, activities, repl, dummy;



int solve(int left, int right, int start, int finish){
    //cout<<left<<" "<<right<<" "<<start<<" "<<finish<<"\n";
    //cin>>dummy;
    if(left-1==right) return 0;
    int total = 0;
    // find maximum. crucial to calculations.
    int maxID = -1, high = 0;
    for(int i = left; i <= right; i++){
        if(value[i] > high){ // if same, results should be same no matter what choice
            high = value[i];
            maxID = i;
        }
    }
    // find left and right.
    int leftrepl = min(repl*(maxID-left) + start,energy);
    int rightrepl = min(repl*(right-maxID+1),energy);

    int needMax = max(0,finish-rightrepl);
    int allowTake = min(energy,leftrepl-needMax);
    //take that amount. Greedy.
    total += allowTake * high;
    // solve the left and right.
    int leftscore = solve(left,maxID-1,start,min(energy,allowTake+needMax));
    int rightscore = solve(maxID+1,right,min(needMax+repl,energy),finish);
    return total + leftscore + rightscore;
}

int main(){
    cin>>cases;
    for(int c = 1; c <= cases; c++){
        cin>>energy>>repl>>activities;

        for(int i = 0; i < activities; i++){
            cin>>value[i];
        }

        cout<<"Case #"<<c<<": "<<solve(0,activities-1,energy,0)<<"\n";
    }
}
