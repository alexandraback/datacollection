//
// Created by Yuxiang LI on 09/04/16.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int T,N;
string s1,s2;
map<string,int> dic;
vector<string> sss;
vector<set<int>> fir(2000),sec(2000);
vector<pair<int,int>> l;

int main(){
    ifstream in("C-small.in");
    ofstream out("output.out");
    in >> T;
    for(int cases = 1; cases <= T; cases++){
        in >> N;
        int count = 0;
        int fake = 0;
        for(int i = 0; i < N*2; i++){
            fir[i].clear();
            sec[i].clear();
        }
        l.clear();
        dic.clear();
        sss.clear();
        for(int i = 0; i < N; i++) {
            in >> s1 >> s2;
            //cout << dic.count(s1) <<' ' << dic.count(s2) << endl;
            if (dic.count(s1) != 0 && dic.count(s2) != 0 && fir[dic[s1]].size() != 0 && sec[dic[s2]].size() != 0) {
                fake++;
                //cout << s1 << ' ' << s2 << endl;
                continue;
            }
            if (dic.count(s1) == 0){
                dic[s1] = count;
                sss.push_back(s1);
                count++;
            }
            if (dic.count(s2) == 0){
                dic[s2] = count;
                sss.push_back(s2);
                count++;
            }
            bool f = false;
            for(int j = 0; j < l.size(); j++){
                if (l[j].first == dic[s1] && sec[l[j].second].size() != 1){
                    //cout << sss[l[j].first] <<' ' << sss[l[j].second] << endl;
                    sec[l[j].second].erase(j);
                    l[j].second = dic[s2];
                    sec[dic[s2]].insert(j);
                    fake++;
                    f = true;
                    break;
                }
                if (l[j].second == dic[s2] && fir[l[j].first].size() != 1){
                    //cout << sss[l[j].first] <<' ' << sss[l[j].second] << endl;
                    fir[l[j].first].erase(j);
                    l[j].first = dic[s1];
                    fir[dic[s1]].insert(j);
                    fake++;
                    f = true;
                    break;
                }
            }
            if (!f){
                l.push_back(make_pair(dic[s1],dic[s2]));
                fir[dic[s1]].insert(l.size()-1);
                sec[dic[s2]].insert(l.size()-1);
            }
        }
        out << "Case #" <<cases << ": " <<fake << endl;
    }
    in.close();
    out.close();
    return 0;
}

