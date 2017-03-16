#include<iostream>
#include<string>
using namespace std;
int t;
string curr,inp;
int main(){
    cin>>t;
    for(int c=1;c<=t;++c){
        cin>>inp;
        curr="";
        for(int i=0;i<inp.size();++i){
            string first=curr+inp[i];
            string second=inp[i]+curr;
            if(first<second){
                curr=second;
            }
            else{
                curr=first;
            }
        }
        cout<<"Case #"<<c<<": "<<curr<<endl;
    }
}
