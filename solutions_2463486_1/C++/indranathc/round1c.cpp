#include <iostream>
#include <string>
#include <map>

using namespace std;

string fs[]={
"1",
"4",
"9",
"121",
"484",
"10201",
"12321",
"14641",
"40804",
"44944",
"1002001",
"1234321",
"4008004",
"100020001",
"102030201",
"104060401",
"121242121",
"123454321",
"125686521",
"400080004",
"404090404",
"10000200001",
"10221412201",
"12102420121",
"12345654321",
"40000800004",
"1000002000001",
"1002003002001",
"1004006004001",
"1020304030201",
"1022325232201",
"1024348434201",
"1210024200121",
"1212225222121",
"1214428244121",
"1232346432321",
"1234567654321",
"4000008000004",
"4004009004004",
"100000020000001"
};

class FairSquare
{
public:
    string low,high;

    FairSquare(istream& is)
    {
        is >> low >> high;
    }

    int compare(string& a, string& b) {
        if (a.length() < b.length()) return -1;
        if (a.length() > b.length()) return 1;
        return a.compare(b);
    }
    
    int count()
    {
        int i=0;
        while(compare(low,fs[i])>0) ++i;
        int j=0;
        while(compare(high,fs[i+j])>=0) ++j;
        return j;
    }
    
};

void readfile(istream& is)
{
    int num_tests;
    is >> num_tests;
    for (int i=1; i<=num_tests; ++i)
    {
        FairSquare f(is);
        cout << "Case #" << i << ": " << f.count() << endl;
    }
}

int main()
{
    readfile(cin);
    return 0;
}
