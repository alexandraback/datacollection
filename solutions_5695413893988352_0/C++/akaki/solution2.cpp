#include <bits/stdc++.h>

using namespace std;

const long long INF = 1000000000000000000LL;
int i,j,k,l,m,n,t;
string s1, s2;
long long difference;
long long poww[18];
long long ans1 = INF, ans2 = INF; 
int answer1[18], answer2[18];
int b1[18], b2[18], test;

void rec(int pos, int larger){
    int i;
    if (pos == n){
        long long one = 0, two = 0; 
        for (int j = 0; j < n; j++){
            one += b1[j] * poww[n - 1 - j];
            two += b2[j] * poww[n - 1 - j];
        }
        //cout << test << " " << one << " ddddddddd " << two << "\n";
        if ( (difference > abs(one - two)) || ( (difference == abs(one - two)) && (ans1 > one) ) || ( (difference == abs(one - two)) && (ans1 == one) && (ans2 > two) ) ){
            difference = abs(one - two);
            ans1 = one;
            ans2 = two;
            for (int j = 0; j < n; j++){
                answer1[j] = b1[j];
                answer2[j] = b2[j];
            }
        }    
        return;    
    }
    if (s1[pos] == '?' && s2[pos] == '?'){
        if (larger == 0){
            b1[pos] = 0;
            b2[pos] = 0;
            rec(pos + 1, larger);
            b1[pos] = 1;
            b2[pos] = 0;
            rec(pos + 1, 1);
            b1[pos] = 0;
            b2[pos] = 1;
            rec(pos + 1, 2);                        
        } else
        if (larger == 1){
            b1[pos] = 0;
            b2[pos] = 9;
            rec(pos + 1, larger);
        } else
        if (larger == 2){
            b1[pos] = 9;
            b2[pos] = 0;
            rec(pos + 1, larger);        
        }
    } else
    if (s1[pos] == '?'){
        int d = s2[pos] - '0';
        if (larger == 0){
            b1[pos] = d;
            b2[pos] = d;
            rec(pos + 1, larger);
            if (d > 0){
                b1[pos] = d - 1;
                b2[pos] = d;
                rec(pos + 1, 2);
            }
            if (d < 9){
                b1[pos] = d + 1;
                b2[pos] = d;
                rec(pos + 1, 1);
            }
        } else
        if (larger == 1){
            b1[pos] = 0;
            b2[pos] = d;
            rec(pos + 1, larger);
        } else
        if (larger == 2){
            b1[pos] = 9;
            b2[pos] = d;
            rec(pos + 1, larger);            
        }
    } else
    if (s2[pos] == '?'){
        int d = s1[pos] - '0';
        if (larger == 0){
            b1[pos] = d;
            b2[pos] = d;
            rec(pos + 1, larger);
            if (d > 0){
                b1[pos] = d;
                b2[pos] = d - 1;
                rec(pos + 1, 1);
            }
            if (d < 9){
                b1[pos] = d;
                b2[pos] = d + 1;
                rec(pos + 1, 2);
            }
        } else
        if (larger == 1){
            b1[pos] = d;
            b2[pos] = 9;
            rec(pos + 1, larger);
        } else
        if (larger == 2){
            b1[pos] = d;
            b2[pos] = 0;
            rec(pos + 1, larger);            
        }
    } else
    {
        b1[pos] = s1[pos] - '0';
        b2[pos] = s2[pos] - '0';
        if (larger == 0){
            if (b1[pos] == b2[pos]){
                rec(pos + 1, 0);
            } else 
            if (b1[pos] > b2[pos]){
                rec(pos + 1, 1);
            } else 
            if (b1[pos] < b2[pos]){
                rec(pos + 1, 2);
            }            
        } else
        {
            rec(pos + 1, larger);
        }
    }  
}

int main(){
    freopen("output.txt", "w", stdout);
    cin >> t;
    poww[0] = 1;
    for (i = 1; i < 18; i++){
        poww[i] = poww[i - 1] * 10LL;
    }
    for (test = 0; test < t; test++){
        cout << "Case #"<< test+1 << ": ";
        difference = 1000000000000000000LL;
        cin >> s1 >> s2;
        n = s1.length();
        rec(0, 0);
        for (j = 0; j < n; j++){
            cout << answer1[j];
        }
        cout << " ";
        for (j = 0; j < n; j++){
            cout << answer2[j];
        }
        cout << "\n";        
    }
    return 0;
}
