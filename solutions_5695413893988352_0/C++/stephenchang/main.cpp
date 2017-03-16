#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution{
public:
    void solute(){
        ifstream fin("B-small-attempt0.in");
        ofstream fout("out.txt");
        int T;
        fin>>T;
        string s1, s2;
        vector<int> vv;

        for(int i=0;i<T;i++){
            fin>>s1>>s2;

            vector<int> v1(s1.length()), v2(s2.length());
            for(int index=0;index<s1.length();index++){
                if(s1[index]=='?') v1[index]=-1;
                else v1[index]=s1[index]-'0';
                if(s2[index]=='?') v2[index]=-1;
                else v2[index]=s2[index]-'0';
            }
            vector<int> vv1,vv2;
            get(v1,v2,vv1,vv2);

            int x1,x2,diff=INT32_MAX;
            for(auto item1:vv1){
                for(auto item2:vv2){
                    if(abs(item1-item2)<diff){
                        x1=item1;x2=item2;
                        diff=abs(item1-item2);
                    }else if(abs(item1-item2)==diff){
                        if(item1<x1){
                            x1=item1;x2=item2;
                        }else if(item1==x1){
                            if(item2<x2){
                                x1=item1;x2=item2;
                            }
                        }
                    }
                }
            }
            fout<<"Case #"<<i+1<<": "<<trans(x1, s1.length())<<' '<<trans(x2, s2.length())<<endl;
        }

        fin.close();
        fout.close();
    }

    void get(vector<int>& v1,vector<int>& v2,vector<int>& vv1,vector<int>& vv2){
        int re;
        if(v1.size()==1) re=10;
        else if(v1.size()==2) re=100;
        else re=1000;

        for(int i=0;i<re;i++){
            if(is(v1,i)) vv1.push_back(i);
            if(is(v2,i)) vv2.push_back(i);
        }
    }

    bool is(vector<int>& v, int num){
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]==-1){num/=10; continue;}
            else if(v[i]!=num%10) return false;
            num/=10;
        }
        return true;
    }

    string trans(int num, int size){
        char temp[60];
        sprintf(temp, "%d", num);
        string result(temp);
        while(result.length()<size){
            result = "0" + result;
        }
        return result;
    }

};

int main() {
    Solution solution;
    solution.solute();
    return 0;
}