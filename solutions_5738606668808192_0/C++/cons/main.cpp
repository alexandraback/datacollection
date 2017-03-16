#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#define MS(x, y) memset(x, y, sizeof(x))
#define FOR(i, x, y) for(int i=x; i<=y; i++)
#define rFOR(i, x, y) for(int i=x; i>=y; i--)
using namespace std;
const int maxn = 1000;
struct bigint
{
    int s[maxn];

    bigint() {MS(s, 0);}
    bigint(int num) {*this = num;}
    bigint(const char* num){*this = num;}

    bigint operator = (const char* num) //字符串赋值
    {
        MS(s, 0);
        if(num[0] == '-')
        {
            num = num + 1;
            s[0] = -1;
        }
        else s[0] = 1;
        while(num[0] == '0') num = num + 1;
        s[0] = s[0] * strlen(num);
        int len = abs(s[0]);
        FOR(i, 1, len) s[i] = num[len - i] - 48;
        return *this;
    }
    bigint operator = (int num)         //整数赋值
    {
        char s[maxn];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }

    string str() const                      //返回字符串
    {
        string res = "";
        FOR(i, 1, abs(s[0])) res = (char)(s[i] + 48) + res;
        if(res == "") return res = "0";
        if(s[0] < 0) res = '-' + res;
        return res;
    }
    //----------以上是构造部分，以下是运算部分----------//
    int comp(const bigint& b) const //a-b的符号
    {
        if(s[0] != b.s[0]) return s[0] - b.s[0];
        int len = abs(s[0]);
        rFOR(i, len, 1)
        if(s[i] != b.s[i])
            return (s[i] - b.s[i]) * (s[0] > 0 ? 1 : -1);
        return 0;
    }
    bool operator < (const bigint& b) const{return comp(b) < 0;}
    bool operator > (const bigint& b) const{return comp(b) > 0;}
    bool operator <= (const bigint& b) const{return comp(b) <= 0;}
    bool operator >= (const bigint& b) const{return comp(b) >= 0;}
    bool operator != (const bigint& b) const{return comp(b) != 0;}
    bool operator == (const bigint& b) const{return comp(b) == 0;}

    friend bigint abs(bigint b)
    {
        b.s[0] = abs(b.s[0]);
        return b;
    }
    bigint operator + (const bigint& b) const
    {
        if(b.s[0] < 0) return *this - abs(b);
        if(s[0] < 0) return b - abs(*this);
        bigint c;
        c.s[0] = max(s[0], b.s[0]);
        FOR(i, 1, c.s[0]) c.s[i] = s[i] + b.s[i];
        FOR(i, 1, c.s[0])
        if(c.s[i] >= 10)
        {
            c.s[i+1]++;
            c.s[i]-=10;
        }
        if(c.s[c.s[0]+1]) ++c.s[0];
        return c;
    }
    bigint operator - (const bigint& b) const
    {
        if(s[0] >= 0 && b.s[0] >= 0 && (*this < b))
        {
            bigint c = b - *this;
            c.s[0] = -c.s[0];
            return c;
        }
        if(b.s[0] < 0) return *this + abs(b);
        if(s[0] < 0)
        {
            bigint c;
            c = abs(*this) + b;
            c.s[0] = -c.s[0];
            return c;
        }

        bigint c;
        c.s[0] = s[0];
        FOR(i, 1, c.s[0]) c.s[i] = s[i] - b.s[i];
        FOR(i, 1, c.s[0])
        if(c.s[i] < 0)
        {
            c.s[i+1]--;
            c.s[i] += 10;
        }
        while(!c.s[c.s[0]] && c.s[0]) --c.s[0];
        return c;
    }
    bigint operator * (const bigint& b) const
    {
        bigint c;
        c.s[0] = abs(s[0]) + abs(b.s[0]);
        FOR(i, 1, abs(s[0]))
        FOR(j, 1, abs(b.s[0]))
            c.s[i + j - 1] += s[i] * b.s[j];
        FOR(i, 1, c.s[0])
        {
            c.s[i+1] += c.s[i] / 10;
            c.s[i] %= 10;
        }
        while(!c.s[c.s[0]] && c.s[0]) --c.s[0];
        if((s[0] > 0) != (b.s[0] > 0)) c.s[0] = -c.s[0];
        return c;
    }
    bigint operator / (const bigint& _b) const
    {
        bigint c, t;
        bigint b = abs(_b);
        c.s[0] = abs(s[0]);
        rFOR(i, c.s[0], 1)
        {
            rFOR(j, t.s[0], 1) t.s[j + 1] = t.s[j];
            t.s[1] = s[i];
            if(t.s[0] || s[i])++t.s[0];

            while(t >= b)
            {
                ++c.s[i];
                t -= b;
            }
        }
        while(!c.s[c.s[0]] && c.s[0]) --c.s[0];
        if((s[0] > 0) != (b.s[0] > 0)) c.s[0] = -c.s[0];
        return c;
    }
    bigint operator % (const bigint& _b) const
    {
        bigint c, t;
        bigint b = abs(_b);
        rFOR(i, abs(s[0]), 1)
        {
            rFOR(j, t.s[0], 1) t.s[j + 1] = t.s[j];
            t.s[1] = s[i];
            if(t.s[0] || s[i])++t.s[0];

            while(t >= b) t -= b;
        }
        if((s[0] < 0)) t.s[0] = -t.s[0];
        return t;
    }

    bigint operator += (const bigint& b) {*this = *this + b;return *this;}
    bigint operator -= (const bigint& b) {*this = *this - b;return *this;}
    bigint operator *= (const bigint& b) {*this = *this * b;return *this;}
    bigint operator /= (const bigint& b) {*this = *this / b;return *this;}
    bigint operator %= (const bigint& b) {*this = *this % b;return *this;}

    friend bigint operator + (int& a, const bigint& b){return (bigint)a + b;}
    friend bigint operator - (int& a, const bigint& b){return (bigint)a - b;}
    friend bigint operator * (int& a, const bigint& b){return (bigint)a * b;}
    friend bigint operator / (int& a, const bigint& b){return (bigint)a / b;}
    friend bigint operator % (int& a, const bigint& b){return (bigint)a % b;}

    friend bigint operator <  (int& a, const bigint& b){return (bigint)a < b;}
    friend bigint operator <= (int& a, const bigint& b){return (bigint)a <=b;}
    friend bigint operator >  (int& a, const bigint& b){return (bigint)a > b;}
    friend bigint operator >= (int& a, const bigint& b){return (bigint)a >=b;}
    friend bigint operator == (int& a, const bigint& b){return (bigint)a ==b;}
    friend bigint operator != (int& a, const bigint& b){return (bigint)a !=b;}
};
istream& operator >> (istream &in, bigint& x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}
ostream& operator << (ostream &out, const bigint& x)
{
    out << x.str();
    return out;
}

bigint qpow(bigint x,bigint y,bigint mod)//快速幂
{
    bigint ans=1,a=x;
    while(y>0)
    {
        if(y%2==1) ans=ans*a%mod;
        a=a*a%mod;
        y/=2;
    }
    return ans;
}
bool MR_prime(bigint a,bigint n)//米勒拉宾
{
    bigint r=0,d=n-1;
    if(n%a==0) return false;//倍数必为合数
    while(d%2==0)//找到奇数
    {
        d/=2;
        r+=1;
    }
    bigint k=qpow(a,d,n);
    if(k==1) return true;//同余1
    for(int i=0;r>i;i++,k=(k%n)*(k%n)%n) if(k==n-1) return true;//同余-1
    return false;
}
bool check_prime(bigint n)
{
    if(n==2||n==3||n==7||n==61) return true;
    if((n%2==0)||n%3==0||n==1) return false;//删掉大量已知情况
    if(MR_prime(2,n)&&MR_prime(3,n)&&MR_prime(5,n)&&MR_prime(7,n)&&MR_prime(11,n)&&MR_prime(61,n)) return true;
    return false;
}

int t,n,j,ans[40];
long long pro;
bool bo;
bigint a[11];

void make(long long num,int n)
{
    long long use;
    bigint base;
    FOR(i,2,10)
    {
        use=num;
        base=1;
        FOR(j,1,n)
        {
            a[i]+=base*(use&1);
            use>>=1;
            base*=i;
        }
        if(check_prime(a[i])) return;
        bigint divisor=3;
        bo=true;
        while(divisor<"99999")
        {
            if(a[i]%divisor==0)
            {
                bo=false;
                break;
            }
            divisor+=1;
        }
        if(bo) return;
    }
    --j;
    FOR(i,1,n)
    {
        ans[i]=num&1;
        num>>=1;
    }
    rFOR(i,n,1) printf("%d",ans[i]);
    FOR(i,2,10)
    {
        bigint divisor=3;
        while(1)
        {
            if(a[i]%divisor==0)
            {
                cout<<" "<<divisor;
                break;
            }
            divisor+=1;
        }
    }
    cout<<endl;
}
int main()
{
    cin>>t;
    FOR(i,1,t)
    {
        cout<<"Case #"<<i<<":\n";
        cin>>n>>j;
        pro=1;
        FOR(i,1,n-1) pro=pro*2;
        pro=pro+1;
        while(j)
        {
            memset(a,0,sizeof(a));
            make(pro,n);
            pro+=2;
        }
    }
    return 0;
}
