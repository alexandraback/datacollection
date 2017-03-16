#include <iostream>
#include <fstream>
#include <utility>

using namespace std;

pair<bool,char> count(bool a_, char a, bool b_, char b){
    if ((a == '1') && (a_))
        return make_pair(b_, b);
    if ((b == '1') && (b_))
        return make_pair(a_, a);
    if ((a == '1') && !(a_))
        return make_pair(!(b_), b);
    if ((b == '1') && !(b_))
        return make_pair(!(a_), a);

    bool result_ = true;
    char result;

    if (a == b){
        result = '1';
        result_ = false;
    }

    if ((a == 'i') && (b == 'j'))  {
        result = 'k';
    }
    if ((a == 'i') && (b == 'k'))  {
        result = 'j';
        result_ = false;
    }
    if ((a == 'j') && (b == 'i'))  {
        result = 'k';
        result_ = false;
    }
    if ((a == 'j') && (b == 'k'))  {
        result = 'i';
    }
    if ((a == 'k') && (b == 'i'))  {
        result = 'j';
    }
    if ((a == 'k') && (b == 'j'))  {
        result = 'i';
        result_ = false;
    }

    if (!(a_))
        result_ = !result_;
    if (!(b_))
        result_ = !result_;

    return make_pair(result_,result);
}

int main()
{
    ifstream in ("C-large.in");
    ofstream out ("output.out");
    string line, result;
    long int T, L, X, finded, j;
    pair<bool,char> c;
    bool plus = true;

    if(in.is_open()){
        in >> T;
        for (int i = 1; i <= T; i++){
            in >> L >> X;
            in >> line;
            finded = 0;
            j = 1;
            plus = true;
            result = "NO";
            c = make_pair(true, line[0]);
            if (c.second == 'i'){
                finded += 1;
                c = make_pair(true, '1');
            }
            if (L > 1){
                while (j < L*X){
                    c = count(c.first, c.second, true, line[j % L]);
                    j++;
                    if (c.second == finded+'i'){
                        finded += 1;
                        if (!(c.first))
                            plus = !plus;
                        if (finded == 3)
                            result = "YES";
                        c = make_pair(c.first, '1');
                    }
                }
                if (c != make_pair(true, '1'))
                    result = "NO";
            }
            out << "Case #" << i << ": " << result << endl;
        }
        in.close();
    }
    out.close();
    return 0;
}

