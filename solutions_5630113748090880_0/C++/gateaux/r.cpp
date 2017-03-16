
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;

ifstream fin ("B-small-attempt1.in");
ofstream fout ("output.out");

int main(){
int testcase;
fin >> testcase;
cout << testcase << endl;
forn(i,testcase){
    int N;
    int h[2501]={0};
    fin >> N;
    vector<int> v;
    forn(j,2*N-1){
                 forn(k,N){
                int x;
                 fin >> x;
                    h[x]++;
                 }
                }
    forn(k,2501){
                    if(h[k]%2==1)v.push_back(k);
                 }
    sort(v.begin(),v.end());
    fout << "Case #" << i+1 << ":";
    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
        fout << " " <<*it;
    }
    fout << endl;
    cout << "finish test case " << i+1 << endl;
}
return 0;
}
