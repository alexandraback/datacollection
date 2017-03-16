
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fs first
#define sc second
typedef long long ll;
const char arr [] = {'Z','W','G','H','X','R','O','F','S','N'};
const string arr2 [] ={"ZERO","TWO","EIGHT","THREE","SIX","FOUR","ONE","FIVE","SEVEN","NINE"};
const int arr3 [] ={0,2,8,3,6,4,1,5,7,9};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
        freopen ("file.out","w",stdout);
        freopen ("file.in","r",stdin);
        int t ;
        string s;

        cin>>t;
        for(int p =1 ; p<=t ;p++){
            cin>>s;
            vector<int> v;
            int com[26];
            memset(com,0,sizeof com);
            for(int i = 0 ;i< s.size();i++)
                com[s[i]-'A']++;
            for(int i = 0 ; i<10;i++){
                while(com[arr[i]-'A']){
                    for(int j = 0 ; j< arr2[i].size();j++){
                        com[arr2[i][j]-'A']--;
                    }
                    v.push_back(arr3[i]);
                }
            }
            sort(v.begin(),v.end());
            cout<<"Case #"<<p<<": ";
            for(int i  =0 ; i< v.size();i++)
              cout<<v[i];
            cout<<'\n';



        }

    return 0;

}

