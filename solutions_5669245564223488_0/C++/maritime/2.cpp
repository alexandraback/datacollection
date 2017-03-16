#include<string>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
bool valid(string str){
    int l = str.length();
    int a[26];
    for(int i=0;i<26;i++) a[26]  = 0;
    a[str[0]-97] = 1;
    for(int i=1;i<l;i++){
        if(a[str[i]-97] == 1){
            if(str[i-1] != str[i]) return false;
        }
        else a[str[i]-97] = 1;
    }
    return true;
}

int main(){
    int test,n,a[12];
    int cnt;
    string s[12],str;
    for(int i=0;i<12;i++) a[i] = i;
    cin >> test;
    for(int i=0;i<test;i++){
        cin >> n;
        for(int j=0;j<n;j++) cin >> s[j];
        printf("Case #%d: ",i+1);
        sort(a,a+11);
        cnt=0;
        do{
            str = "";
            for(int j=0;j<n;j++)
                str += s[a[j]];
            if(valid(str)) cnt++;
        } while(next_permutation(a,a+n));
        printf("%d\n",cnt);
    }
    return 0;
}
