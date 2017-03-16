#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    string temps;
    string ans[200];
    int n;
    cin>>n;
    int i,j;
    for (i=0;i<n;i++){
        cin>>s;
        //ans[i]=""+s[0];
        temps="";
        temps=temps+s[0];
        //cout<<"temps="<<temps<<endl;
        for (j=1;j<s.length();j++){
            //cout<<s[j]<<endl;
            if (s[j]>=temps[0]) temps=s[j]+temps;
            else temps=temps+s[j];
            //cout<<"temps="<<temps<<endl; 
        }
        ans[i]=temps;
    }
    for (i=0;i<n;i++){
        cout<<"Case #"<<i+1<<": "<<ans[i]<<endl;
    }
    //while (1);
}
