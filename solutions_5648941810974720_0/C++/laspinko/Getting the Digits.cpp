#include<iostream>
using namespace std;
int a_case(int num){
    int how[27]={};
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        how[s[i]-'A']++;
    }
    int ans[10]={};
    ans[0]+=how['Z'-'A'];
    how['E'-'A']-=how['Z'-'A'];
    how['R'-'A']-=how['Z'-'A'];
    how['O'-'A']-=how['Z'-'A'];
    how['Z'-'A']-=how['Z'-'A'];
    ans[2]+=how['W'-'A'];
    how['O'-'A']-=how['W'-'A'];
    how['T'-'A']-=how['W'-'A'];
    how['W'-'A']-=how['W'-'A'];
    //cout<<how['O'-'A']<<endl;
    ans[8]+=how['G'-'A'];
    how['E'-'A']-=how['G'-'A'];
    how['I'-'A']-=how['G'-'A'];
    how['H'-'A']-=how['G'-'A'];
    how['T'-'A']-=how['G'-'A'];
    how['G'-'A']-=how['G'-'A'];
    ans[3]+=how['H'-'A'];
    how['T'-'A']-=how['H'-'A'];
    how['R'-'A']-=how['H'-'A'];
    how['E'-'A']-=2*how['H'-'A'];
    how['H'-'A']-=how['H'-'A'];
    ans[4]+=how['R'-'A'];
    how['F'-'A']-=how['R'-'A'];
    how['O'-'A']-=how['R'-'A'];
    how['U'-'A']-=how['R'-'A'];
    how['R'-'A']-=how['R'-'A'];
    ans[1]+=how['O'-'A'];
    how['N'-'A']-=how['O'-'A'];
    how['E'-'A']-=how['O'-'A'];
    how['O'-'A']-=how['O'-'A'];
    ans[5]+=how['F'-'A'];
    how['I'-'A']-=how['F'-'A'];
    how['V'-'A']-=how['F'-'A'];
    how['E'-'A']-=how['F'-'A'];
    how['F'-'A']-=how['F'-'A'];
    ans[7]+=how['V'-'A'];
    how['S'-'A']-=how['V'-'A'];
    how['E'-'A']-=2*how['V'-'A'];
    how['N'-'A']-=how['V'-'A'];
    how['V'-'A']-=how['V'-'A'];
    ans[6]+=how['X'-'A'];
    how['S'-'A']-=how['X'-'A'];
    how['I'-'A']-=how['X'-'A'];
    how['X'-'A']-=how['X'-'A'];
    ans[9]+=how['I'-'A'];
    how['N'-'A']-=2*how['I'-'A'];
    how['E'-'A']-=how['I'-'A'];
    how['I'-'A']-=how['I'-'A'];
    string otg="";
    for(int i=0;i<10;i++){
        for(int l=0;l<ans[i];l++)   otg+=('0'+i);
    }
    cout<<"Case #"<<num+1<<": "<<otg<<endl;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        a_case(i);
    }
}
