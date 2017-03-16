#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
    void solute(){
        ifstream fin("A-small-attempt0.in");
        ofstream fout("out.txt");
        int T;
        fin>>T;
        string s;
        map<char, int> chm;
        vector<int> v;
        for(int i=0;i<T;i++){
            fin>>s;

            chm.clear();
            v.clear();
            for(char ch : s){
                chm[ch]++;
            }
            while(findchar('Z', chm)){
                v.push_back(0);
                chm['Z']--;
                chm['E']--;
                chm['R']--;
                chm['O']--;
            }
            while(findchar('W', chm)){
                v.push_back(2);
                chm['T']--;
                chm['W']--;
                chm['O']--;
            }
            while(findchar('X', chm)){
                v.push_back(6);
                chm['X']--;
                chm['S']--;
                chm['I']--;
            }
            while(findchar('U', chm)){
                v.push_back(4);
                chm['F']--;
                chm['O']--;
                chm['U']--;
                chm['R']--;
            }
            while(findchar('G', chm)){
                v.push_back(8);
                chm['E']--;
                chm['I']--;
                chm['G']--;
                chm['H']--;
                chm['T']--;
            }
            while(findchar('O', chm)){
                v.push_back(1);
                chm['O']--;
                chm['N']--;
                chm['E']--;
            }
            while(findchar('R', chm)){
                v.push_back(3);
                chm['T']--;
                chm['H']--;
                chm['R']--;
                chm['E']--;
                chm['E']--;
            }
            while(findchar('S', chm)){
                v.push_back(7);
                chm['S']--;
                chm['E']--;
                chm['V']--;
                chm['E']--;
                chm['N']--;
            }
            while(findchar('V', chm)){
                v.push_back(5);
                chm['F']--;
                chm['I']--;
                chm['V']--;
                chm['E']--;
            }
            while(findchar('I', chm)){
                v.push_back(9);
                chm['N']--;
                chm['I']--;
                chm['N']--;
                chm['E']--;
            }
            sort(v.begin(), v.end());
            fout<<"Case #"<<i+1<<": ";
            for(auto item:v){
                fout<<item;
            }
            fout<<endl;
        }

        fin.close();
        fout.close();
    }

    bool findchar(char ch, map<char, int>& m){
        if(m.find(ch)!=m.end()){
            if(m[ch]!=0) return true;
            else return false;
        }
        return false;
    }

};


int main() {
    Solution solution;
    solution.solute();
    return 0;
}