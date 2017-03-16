#include <bits/stdc++.h>
using namespace std;

int lett[27];
int res[10];

string order = "ZOWRUVXSGI";
string words[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int remove_digit(int num){
    string s;
    for(int i=0; i<10; i++){
        if(num == i){
            int amount = lett[order[i] - 'A'];
            s = words[i];
            for(int i=0; i<s.size(); i++){
                lett[s[i]-'A'] -= amount;
            }
            res[i] = amount;
        }
    }
}

int numbers[] = {0, 2, 4, 3, 6, 7, 8, 5, 9, 1};
int main()
{
    freopen ("A-large.in","r",stdin);
    freopen ("A-large.out","w",stdout);

    int t;
    cin>>t;
    for(int f=1; f<=t; f++){
        memset(lett, 0, sizeof(lett));
        memset(res, 0, sizeof(res));
        string str;
        cin>>str;
        for(int i=0; i<str.size(); i++){
            lett[str[i]-'A']++;
        }
        for(int i=0; i<10; i++)
            remove_digit(numbers[i]);

        cout<<"Case #"<<f<<": ";
        for(int i=0; i<10; i++){
            cout<<(string(res[i], i+'0'));
        }
        cout<<endl;
    }
    return 0;
}
