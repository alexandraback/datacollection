#include<iostream>
#include<vector>
using namespace std;
a_case(int num){
    int n;
    cin>>n;
    vector<string> fi,se;
    string f,s;
    int pof1=0,pof2=0;
    for(int i=0;i<n;i++){
        cin>>f>>s;
        bool a=true;
        for(int j=0;j<fi.size();j++){
            if(fi[j]==f){
                pof1++;
                a=false;
                break;
            }
        }
        if(a)   fi.push_back(f);
        a=true;
        for(int j=0;j<se.size();j++){
            if(se[j]==s){
                pof2++;
                a=false;
                break;
            }
        }
        if(a)   se.push_back(s);
    }
    cout<<"Case #"<<num+1<<": "<<min(pof1,pof2)<<endl;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        a_case(i);
    }
}
