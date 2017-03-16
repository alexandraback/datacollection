#include <cstdio>
#include <cstdlib>

long long int gcd ( long long int a, long long int b )
{
    long long int c;
    while ( a != 0 ) {
        c = a;
        a = b%a;
        b = c;
    }
    return b;
}

bool test(long long int a)
{
    while(a>1)
    {
        if(a%2==0)
            a = a/2;
        else
            return false;
    }
    return true;
}

int test1(long long int a, long long int b)
{
    int cnt=0;
    while((a/b)<=1)
    {
        a = a * 2;
        if((a/b)<=1)
            cnt++;
        else
            break;
    }
    return cnt;
}

bool flag = false;
long long int P,Q;
int main()
{
    int T,caseNum=1;
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    scanf("%d", &T);
    while(caseNum<=T)
    {
        long long int P_, Q_;
        scanf("%lld/%lld", &P, &Q);
        long long int x = gcd(P, Q);
        bool test_;
        P_ = P/x;
        Q_ = Q/x;
        test_ = test(Q_);
        if(test_==false)
            printf("Case #%d: impossible\n", caseNum);
        else
        {
            int res;
            res = test1(P_, Q_);
            printf("Case #%d: %d\n", caseNum, res);
        }
        caseNum++;
    }
    return 0;
}




