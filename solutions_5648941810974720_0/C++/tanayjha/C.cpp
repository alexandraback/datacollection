#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, ans;
    cin>>t;
    vector <int> phone;
    for(int test = 1; test <= t; test++){
        int arr[30] = {0};
        string s;
        phone.clear();
        cin>>s; 
        for(int i = 0; i < s.length(); i++){
            arr[s[i]-65] += 1;
        }
        if(arr['Z'-65]){
            ans = min(min(arr['Z'-65], arr['E'-65]), min(arr['R'-65], arr['O'-65]));
            arr['Z'-65] -= ans;
            arr['E'-65] -= ans;
            arr['R'-65] -= ans;
            arr['O'-65] -= ans;
            while(ans--){
                phone.push_back(0);
            }
        }

        if(arr['W'-65]){
            ans = min(min(arr['T'-65], arr['W'-65]), arr['O'-65]);
            arr['T'-65] -= ans;
            arr['W'-65] -= ans;
            arr['O'-65] -= ans;
            while(ans--){
                phone.push_back(2);
            }
        }

        if(arr['U'-65]){
            ans = min(min(arr['F'-65], arr['O'-65]), min(arr['U'-65], arr['R'-65]));
            arr['F'-65] -= ans;
            arr['O'-65] -= ans;
            arr['U'-65] -= ans;
            arr['R'-65] -= ans;
            while(ans--){
                phone.push_back(4);
            }
        }

        if(arr['F'-65]){
            ans = min(min(arr['F'-65], arr['I'-65]), min(arr['V'-65], arr['E'-65]));
            arr['F'-65] -= ans;
            arr['I'-65] -= ans;
            arr['V'-65] -= ans;
            arr['E'-65] -= ans;
            while(ans--){
                phone.push_back(5);
            }
        }

        if(arr['X'-65]){
            ans = min(min(arr['S'-65], arr['I'-65]), arr['X'-65]);
            arr['S'-65] -= ans;
            arr['I'-65] -= ans;
            arr['X'-65] -= ans;
            while(ans--){
                phone.push_back(6);
            }
        }

        if(arr['V'-65]){
            ans = min(min(arr['S'-65], arr['E'-65]/2), min(arr['V'-65], arr['N'-65]));
            arr['S'-65] -= ans;
            arr['E'-65] -= ans;
            arr['V'-65] -= ans;
            arr['E'-65] -= ans;
            arr['N'-65] -= ans;
            while(ans--){
                phone.push_back(7);
            }
        }

        if(arr['G'-65]){
            ans = min(min(min(arr['E'-65], arr['I'-65]), min(arr['G'-65], arr['H'-65])), arr['T'-65]);
            arr['E'-65] -= ans;
            arr['I'-65] -= ans;
            arr['G'-65] -= ans;
            arr['H'-65] -= ans;
            arr['T'-65] -= ans;        
            while(ans--){
                phone.push_back(8);
            }
        }

        if(arr['R'-65]){
            ans = min(min(arr['T'-65], arr['H'-65]), min(arr['R'-65], arr['E'-65]/2));
            arr['T'-65] -= ans;
            arr['H'-65] -= ans;
            arr['R'-65] -= ans;
            arr['E'-65] -= ans;
            arr['E'-65] -= ans;
            while(ans--){
                phone.push_back(3);
            }
        }

        if(arr['I'-65]){
            ans = min(min(arr['N'-65]/2, arr['I'-65]), arr['E'-65]);
            arr['N'-65] -= ans;
            arr['I'-65] -= ans;
            arr['N'-65] -= ans;
            arr['E'-65] -= ans;
            while(ans--){
                phone.push_back(9);
            }
        }

        ans = min(min(arr['O'-65], arr['N'-65]), arr['E'-65]);
        arr['O'-65] -= ans;
        arr['N'-65] -= ans;
        arr['E'-65] -= ans;
        while(ans--){
            phone.push_back(1);
        }

        sort(phone.begin(), phone.end());
        cout<<"Case #"<<test<<": ";
        for(int i = 0; i < phone.size(); i++)
            cout<<phone[i];
        cout<<endl;
    }


}