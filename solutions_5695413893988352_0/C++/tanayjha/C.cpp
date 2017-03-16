#include <bits/stdc++.h>
using namespace std;
char rep(int x){
    return char(x+48);
}
int solve(string a, string b){
    if(a.length() == 1)
        return abs(int(a[0]-b[0]));
    else if(a.length() == 2){
        int x = (a[0]-'0')*10 + (a[1]-'0');
        int y = (b[0]-'0')*10 + (b[1]-'0');
        return abs(x-y);
    }
    else{
        int x = (a[0]-'0')*100 + (a[1]-'0')*10 + (a[2]-'0');
        int y = (b[0]-'0')*100 + (b[1]-'0')*10 + (b[2]-'0');
        return abs(x-y);

    }
}
int main()
{
    int n, test;
    cin>>n;
    string s1 ,s2;
    vector <string> ans1, ans2;
    for(int test = 1; test <= n; test++){
        cin>>s1>>s2;
        ans1.clear();
        ans2.clear();
        int c1 = 0, c2 = 0;
        for(int i = 0; i < s1.length(); i++){
            if(s1[i] == '?')
                c1++;
            if(s2[i] == '?')
                c2++;
        }
        string temp;
        if(c1 == 1){
            for(int i = 0; i <= 9; i++){
                temp = s1;
                for(int j = 0; j < s1.length(); j++){
                    if(s1[j] == '?'){
                        temp[j] = rep(i);
                    }
                }
                ans1.push_back(temp);
            }
        }
        if(c2 == 1){
            for(int i = 0; i <= 9; i++){
                temp = s2;
                for(int j = 0; j < s2.length(); j++){
                    if(s2[j] == '?')
                        temp[j] = rep(i);
                }
                ans2.push_back(temp);
            }    
        }
        if(c1 == 2){
            for(int i = 0; i <= 99; i++){
                temp = s1;
                int f = 0;
                for(int j = 0; j < s1.length(); j++){
                    if(s1[j] == '?' && f == 0){
                        temp[j] = rep(i/10);
                        f = 1;
                    }
                    else if(s1[j] == '?' && f == 1){
                        temp[j] = rep(i%10);
                    }
                }
                ans1.push_back(temp);
            }
        }
        if(c2 == 2){
            for(int i = 0; i <= 99; i++){
                temp = s2;
                int f = 0;
                for(int j = 0; j < s2.length(); j++){
                    if(s2[j] == '?' && f == 0){
                        temp[j] = rep(i/10);
                        f = 1;
                    }
                    else if(s2[j] == '?' && f == 1)
                        temp[j] = rep(i%10);
                }
                ans2.push_back(temp);
            }
        }
        if(c1 == 3){
            for(int i = 0; i <= 999; i++){
                s1[0] = rep(i/100);
                s1[1] = rep((i-((i/100)*100))/10);
                s1[2] = rep(i%10);
                ans1.push_back(s1);
            }
            
        }
        if(c2 == 3){
            for(int i = 0; i <= 999; i++){
                s2[0] = rep(i/100);
                s2[1] = rep((i-((i/100)*100))/10);
                s2[2] = rep(i%10);
                ans2.push_back(s2);
            }
        }
        if(ans1.size() == 0)
            ans1.push_back(s1);
        if(ans2.size() == 0)
            ans2.push_back(s2);
        // cout<<ans1.size()<<" "<<ans2.size()<<endl;
        string res1, res2;
        int minval = INT_MAX;
        for(int i = 0; i < ans1.size(); i++){
            for(int j = 0; j < ans2.size(); j++){
                if(solve(ans1[i], ans2[j]) < minval){
                    minval = solve(ans1[i], ans2[j]);
                    res1 = ans1[i];
                    res2 = ans2[j];
                }
            }
        }
        cout<<"Case #"<<test<<": "<<res1<<" "<<res2<<endl;
    }

}