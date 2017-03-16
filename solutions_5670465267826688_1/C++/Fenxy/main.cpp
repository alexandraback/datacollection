#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("C-large.in");
ofstream fout("large-fout.out");

char mul(char a, char b){
    if(a == '1'){
        return b;
    }
    if(b == '1'){
        return a;
    }
    if(b == '2'){
        char t = a;
        a = b;
        b = t;
    }
    if(a == '2'){
        if(b == '2'){
            return '1';
        }
        if(b <= 'k'){
            return b + 3;
        }
        if(b >= 'l'){
            return b - 3;
        }
    }

    int m = 1;

    if(a >= 'l'){
        m *= -1;
        a -= 3;
    }
    if(b >= 'l'){
        m *= -1;
        b -= 3;
    }

    if(a == b){
        if(m == -1)
            return '1';
        else
            return '2';
    }

    char ans;

    if(a == 'i' && b =='j'){
        ans = 'k';
    }
    if(a == 'j' && b =='i'){
        ans = 'n';
    }

    if(a == 'i' && b =='k'){
        ans = 'm';
    }
    if(a == 'k' && b =='i'){
        ans = 'j';
    }

    if(a == 'j' && b =='k'){
        ans = 'i';
    }
    if(a == 'k' && b =='j'){
        ans = 'l';
    }

    if(m == -1){
        if(ans <= 'k'){
            ans += 3;
        }
        else{
            ans -= 3;
        }
    }
    return ans;

}

string calc(){
    int L;
    long long X;
    fin >> L >> X;
    string s;
    fin >> s;
    if(X > 12){
        X = 8 + X % 4;
    }
    string S = "";
    for(int i = 0; i < X; ++i){
        S += s;
    }
    int l = L * X;
    int i = 0, j = l - 1;
    char F = '1', T = '1';
    while(i < j - 1){
        F = mul(F, S[i]);
        while(F != 'i' && i < j - 2){
            ++i;
            F = mul(F, S[i]);
        }
        if(F != 'i')
            break;

        T = mul(S[j], T);
        while(T != 'k' && i < j - 2){
            --j;
            T = mul(S[j], T);
        }
        if(T != 'k')
            break;

        char M = '1';
        for(int k = i + 1; k <= j - 1; ++k){
            M = mul(M, S[k]);
        }
        if(M == 'j')
            return "YES";
        ++i;
        --j;
    }
    return "NO";
}
int main()
{

    int T;
    fin >> T;
    for(int C = 1; C <= T; ++C){
        fout << "Case #" << C << ": " << calc() << endl;
    }
    fin.close();
    fout.close();

    /*while(1){
        char a,b;
        cin >> a >> b;
        cout << mul(a,b) << endl;
    }*/
    return 0;
}
