#include<iostream>
#include<vector>
using namespace std;
string words[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void reduce(char c, int n, int cnt[26], int ansc[10]) {
    if(cnt[c-'A']) {
        ansc[n] = cnt[c-'A'];
        for(auto x:words[n])
            cnt[x-'A']-=ansc[n];
    }
}

int main() {
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        string s;
        cin>>s;
        int cnt[26]={0};
        for(auto x:s) {
            cnt[x-'A']++;
        }
        int ansc[10] = {0};
        reduce('Z', 0, cnt, ansc);
        reduce('U', 4, cnt, ansc);
        reduce('G', 8, cnt, ansc);
        reduce('X', 6, cnt, ansc);
        reduce('H', 3, cnt, ansc);
        reduce('F', 5, cnt, ansc);
        reduce('T', 2, cnt, ansc);
        reduce('V', 7, cnt, ansc);
        reduce('O', 1, cnt, ansc);
        reduce('I', 9, cnt, ansc);
        cout<<"Case #"<<t<<": ";
        for(int i=0;i<10;i++) {
            for(int j=0;j<ansc[i];j++)
                cout<<i;
        }
        cout<<endl;
    }
    return 0;
}
