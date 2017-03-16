#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
using namespace std;

typedef int64_t Int64;

Int64 buildEvenPalindrome(Int64 num)
{
    Int64 num1 = num;
    int n = 1;

    Int64 num2 = 0;
    while (num1 > 0) {
        int d = num1 % 10;
        num2 *= 10;
        num2 += d;
        num1 /= 10;
        n *= 10;
    }
    
    return num * n + num2;
}

Int64 buildOddPalindrome(Int64 num, int k)
{
    Int64 num1 = num;
    int n = 1;

    Int64 num2 = 0;
    while (num1 > 0) {
        int d = num1 % 10;
        num2 *= 10;
        num2 += d;
        num1 /= 10;
        n *= 10;
    }
    k *= n;
    n *= 10;
    
    return num * n + k + num2;
}   

bool isPalindrome(Int64 num)
{
    if (num%10==0)
        return false;

    Int64 num2 = 0;
    while(num > num2) {
        int d = num % 10;
        num2 *= 10;
        num2 += d;
        num /= 10;
    }

    if (num == num2)
        return true;

    num2 /= 10;
    if (num == num2)
        return true;

    return false;
}

vector<Int64> fairSquares;

void buildFairSquareVec()
{
    fairSquares.clear();

    int n = 1;
    do {
        for (int i = n/10; i<n; i++) {
            for (int k=0; k<=9; k++) {
                Int64 p = buildOddPalindrome(i, k);
                Int64 pp = p * p;
                if (isPalindrome(pp))
                    fairSquares.push_back(pp);
            }
        }

        n *= 10;
        for (int i = n/10; i<n; i++) {
            Int64 p = buildEvenPalindrome(i);
            Int64 pp = p * p;
            if (isPalindrome(pp))
                fairSquares.push_back(pp);
        }
    } while (n < 10000);
}

int main(){

    ifstream infile("file.in");
    ofstream outfile("file.out");

    int T;
    infile>>T;

    buildFairSquareVec();

//    for (int i=0; i<fairSquares.size(); i++)
//        outfile<<setw(4)<<i<<setw(20)<<fairSquares[i]<<endl;

    for (int t=0; t<T; t++){
        Int64 l, h;
        infile>>l>>h;

        int count = 0;
        for (int i=0; i<fairSquares.size(); i++) {
            if (fairSquares[i]>h)
                break;
            if (fairSquares[i]>=l)
                count++;
        }

        outfile<<"Case #"<<t+1<<": "<<count<<endl;
    }

}
    
