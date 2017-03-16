#include <iostream>
#include<gmpxx.h>
#include<string>

static const int THREAD_THRESHOLD=4;

using namespace std;
bool palindrome(const string &str) {
    if(str.size() == 1) {
        return true;
    }
    for(string::const_iterator start=str.begin(), end=str.end() -1; start < end; start++, end-- ) {
        if(*start != *end) {
            return false;
        }
    }
    return true;
}

class Checker {
    mpz_class start;
    mpz_class end;
    size_t count;
    mpz_class childMin;
    mpz_class childMax;
    public:
        Checker(const mpz_class &inStart, const mpz_class &inEnd)
            :start(inStart),
            end(inEnd),
            count(0) {
            childMin = sqrt(start);
            childMax = sqrt(end);
        }

        void operator()() {
            for(int i = childMin.get_str().size();
                    i <= childMax.get_str().size(); i++ ) {
                generate_pal(i);    
            }
        }

        inline size_t getCount() { return count; }
    private:

    void handle(const mpz_class &it) {
        if(it<childMin || it>childMax) {
            return;
        }
        mpz_class res = it * it;
        if(res < start || res > end ) {
            return;
        }
        if(palindrome(res.get_str())) {
            count++;
        }

    }
    void populate(char *buf, int start, int end,
                    int bufSize, int startDigit) {
        if(end <= start) {
            buf[bufSize];
            char res[bufSize + 1];
            res[bufSize] = 0;
            for(int i = 0; i < bufSize; i++ ) {
                res[i]=buf[i];
            }
            handle(mpz_class(res));
            return;
        }
        for(int val = startDigit; val <= 9; val++) {
            buf[start]=(val + '0');
            buf[end]=(val + '0');
            populate(buf, start + 1, end -1, bufSize, 0);
        }
    }

    void generate_pal(int n) {
        char buf[n];

        int mid = n/2 + (n%2);
        if( 1 == n%2 ) {
            for(char i = '0'; i <= '9'; i++ ) {
                buf[mid-1] = i;
                populate(buf, 0, n - 1, n, 1);
            }
        }
        else {
            populate(buf, 0, n - 1, n, 1);
        }
        return;
    }


};


int main() {
    int numTests = 0;
    cin>>numTests;
    for(int i=1; i <= numTests; i++ ) { 
        string start, end;
        cin>>start;
        cin.clear();
        cin.ignore(1);
        cin>>end;
        mpz_class startInt(start.c_str(),10);
        mpz_class endInt(end.c_str(),10);
        Checker checker(startInt, endInt);
        checker();
        cout<<"Case #"<<i<<": "<<checker.getCount()<<endl;
    }
    return 0;
}

