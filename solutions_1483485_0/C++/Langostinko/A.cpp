#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <set>

using namespace std;

const char c[30]="yhesocvxduiglbkrztnwjpfmaq";
string a;
int n;

int main(){
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

    cin >> n;
    getline(cin,a);
    for (int i=0; i<n; i++){
        a.clear();
        getline(cin,a);
        cout << "Case #" << i+1 << ": ";
        int len  = a.length();
        for (int i=0; i<len; i++)
            if (a[i]>='a' && a[i]<='z')
                cout << c[a[i]-'a'];
            else
                cout << a[i];
        cout << endl;
    }

    return 0;
}
