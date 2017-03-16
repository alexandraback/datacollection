#include <iostream>
#include <set>
#define rep(a,st,ed) for(int a = st;a < ed;a ++)
#include <string>
#include <sstream>
#include <memory>
#include <cstring>
#include <algorithm>

#define BASE 	10	// 基数
#define DIG		1100	// 存储
using namespace std;

class BigNumber
{
public:
     int data[DIG];			// 数据区
     int len;				// 记录长度
public:
     BigNumber()     {len=1;memset(data,0,sizeof(data));data[0]=1;}
     BigNumber(int);          // 输入默认十进制
     BigNumber(const char*);
     BigNumber(const BigNumber &);
     BigNumber(const string sb)  {this->Str_BNum(sb.c_str());}
     // 类型转换
     BigNumber & Num_BNum(int); //把一个整数转换成BigNumber型的
     BigNumber & Str_BNum(const char*); //把一个字符串类型的转换成BigNumber型的
     int Int();
     string Str() const;
     // HPC
     BigNumber & Add(const BigNumber &);
     BigNumber & Sub(const BigNumber &);
     BigNumber & Mul(const BigNumber &);
     BigNumber & Div(int);
     BigNumber & Mod(int);
     BigNumber & operator=(const BigNumber &);
     int Bigger(const BigNumber &) const;
     friend bool operator < (const BigNumber & a,const BigNumber & b){
        return b.Bigger(a) == 1;
     }
     friend bool operator == (const BigNumber & a,const BigNumber & b){
        if(a.len!= b.len)return false;
        int len =a.len;
        for(int i=len-1; i>0 ;i--)
               if(a.data[i] != b.data[i])     return false;
        return true;
     }
     BigNumber operator + (const BigNumber &);
     BigNumber operator - (const BigNumber &);
     BigNumber operator * (const BigNumber &);
     BigNumber operator / (int);
     BigNumber operator % (int);

     BigNumber & operator += (const BigNumber &);
     BigNumber & operator -= (const BigNumber &);
     BigNumber & operator *= (const BigNumber &);
     BigNumber & operator /= (int);
     BigNumber & operator %= (int);

};

BigNumber & BigNumber::Num_BNum(int b)
{
     len=1;     memset(data,0,sizeof(data));
     data[0] = 1;
     if(b < 0) {
          b = -b;
          data[0] = -1;
     }
     while(b > 0) {
          data[ len++ ] = b % BASE;
          b /= BASE;
     }
     return *this;
}

BigNumber & BigNumber::Str_BNum(const char* sb)
{
     int t=0, d=1, b=0, slen=strlen(sb), i;
     len=1;     memset(data,0,sizeof(data));
     data[0] = 1;
     if(sb[0] == '-')     data[0] = -1, b=1;
     for(i=slen-1; i>=b ;i--) {
          while(t >= BASE || d > BASE) {
               data[ len++ ] = t % BASE;
               t /= BASE;
               d = 10;
          }
          t += (sb[i]-'0') * d;
          d *= 10;
     }
     while(t > 0) {
          data[ len++ ] = t % BASE;
          t /= BASE;
     }
     return *this;
}

int BigNumber::Int()
{
     istringstream sin;
     int v;
     sin.str( this->Str() );
     sin >> v;
     return v;
}  //这个函数的用法还是第一次看到，没看懂

string BigNumber::Str() const
{
     int i,base_len=0;
     ostringstream sout;
     if(len == 1) {
          sout << '0';
          //sout << endl;
          return sout.str();
     }
     if(data[0] < 0)     sout << "-";
     sout << data[len-1];
     i = BASE;
     while(i > 1) {
          base_len++;
          i /= 10;
     }
     for(i=len-2; i>0 ;i--) {
          sout.width(base_len);
          sout.fill('0');
          sout << data[i];
     }
     //sout << endl;
     return sout.str();
} //这个函数也没有看懂

BigNumber::BigNumber(int b)
{this->Num_BNum(b);}

BigNumber::BigNumber(const char* sb)
{this->Str_BNum(sb);}
// -1 a<b, 0 a==b, 1 a>b
BigNumber::BigNumber(const BigNumber & b)
{len = b.len;     memcpy(data,b.data,sizeof(data));}

int BigNumber::Bigger(const BigNumber & b) const
{
     int i,flag;
     if(data[0] ==1 && b.data[0] ==1)          flag = 1;
     else if(data[0] ==1 && b.data[0] ==-1)     return 1;
     else if(data[0] ==-1 && b.data[0] ==1)     return -1;
     else                                             flag = -1;

     if(len > b.len)     return flag;
     else if(len == b.len) {
          for(i=len - 1; i>0 ;i--){
               if(data[i] != b.data[i])     return (data[i] > b.data[i])?1:-1;
          }
     }
     if(i == 0)     return 0;
     return -flag;
} //比较函数

BigNumber & BigNumber::Add(const BigNumber & b)
{
     int i;
     if(data[0] * b.data[0] != 1) {
          data[0] = -data[0];
          Sub(b);
          data[0] = -data[0];
          return *this;
     }
     len= len > b.len ? len : b.len;
     for(i=1; i<len ;i++) {
          data[i] += b.data[i];
          if(data[i] >= BASE) {
               data[i+1]++;
               data[i] -= BASE;
          }
     }
     if(data[i] > 0)     len = i+1;
     return *this;
} //加上b这个大数

BigNumber & BigNumber::Sub(const BigNumber & b)
{
     int i;
     if(data[0] * b.data[0] != 1) {
          data[0] = -data[0];
          Add(b);
          data[0] = -data[0];
          return *this;
     }
     len= len > b.len ? len : b.len;
     for(i=1; i<len ;i++) {
          data[i] -= b.data[i];
          if(data[i] < 0) {
               data[i+1]--;
               data[i] += BASE;
          }
     }
     if(data[len] < 0) {
          for(i=0; i<=len ;i++)
               data[i] = -data[i];
          for(i=1; i<len ;i++)
               if(data[i] < 0) {
                    data[i+1]--;
                    data[i] += BASE;
               }
     }
     while(data[len-1] == 0)     len--;
     return *this;
}

BigNumber & BigNumber::Mul(const BigNumber & b)
{
     BigNumber bt;
     int i,j,up;
     int temp,temp1;

     bt.data[0] = data[0] * b.data[0];
     for(i=1; i<len ;i++) {
          up = 0;
          for(j=1; j<b.len ;j++) {
               temp = data[i] * b.data[j] + bt.data[i+j-1] + up;
               if(temp >= BASE) {
                    temp1 = temp % BASE;
                    up = temp / BASE;
                    bt.data[i+j-1] = temp1;
               }
               else {
                    up = 0;
                    bt.data[i+j-1] = temp;
               }
          }
          if(up != 0)     bt.data[i+j-1] = up;
     }
     bt.len = i+j;
     while(bt.data[bt.len-1] == 0){ bt.len--;}
     *this=bt;
     return *this;
}

BigNumber & BigNumber::Div(int b)
{
     BigNumber bt;
     int i,down = 0;

     if(b < 0)     bt.data[0] = -data[0] , b = -b;
     else          bt.data[0] = data[0];
     for(i=len-1; i>=1 ;i--) {
          bt.data[i] = (data[i] + down * BASE) / b;
          down = data[i] + down * BASE - bt.data[i] * b;
     }
     bt.len = len;
     while(bt.data[bt.len-1] == 0)     bt.len--;
     *this=bt;
     return *this;
}

BigNumber & BigNumber::Mod(int b)
{
     int temp = 0, up = 0, i;
     for(i=len-1; i>=1 ;i--) {
          temp = data[i];
          temp += up * BASE;
          up = temp % b;
     }
     if(data[0] < 0)     up = -up;
     *this = up;
     return *this;
}

BigNumber & BigNumber::operator = (const BigNumber & b)
{len = b.len;     memcpy(data,b.data,sizeof(data));     return *this;}

BigNumber BigNumber::operator + (const BigNumber & b)
{BigNumber bt=*this;     return bt.Add(b);}

BigNumber BigNumber::operator - (const BigNumber & b)
{BigNumber bt=*this;     return bt.Sub(b);}

BigNumber BigNumber::operator * (const BigNumber & b)
{BigNumber bt=*this;     return bt.Mul(b);}

BigNumber BigNumber::operator / (int b)
{BigNumber bt=*this;     return bt.Div(b);}

BigNumber BigNumber::operator % (int b)
{BigNumber bt=*this;     return bt.Mod(b);}

BigNumber & BigNumber::operator += (const BigNumber & b)
{return this->Add(b);}

BigNumber & BigNumber::operator -= (const BigNumber & b)
{return this->Sub(b);}

BigNumber & BigNumber::operator *= (const BigNumber & b)
{return this->Mul(b);}

BigNumber & BigNumber::operator /= (int b)
{return this->Div(b);}

BigNumber & BigNumber::operator %= (int b)
{return this->Mod(b);}

typedef BigNumber LL;
set<LL > all;



void solve(int t){   //even digit

    string digit(t,'0');
    digit[0] = '2';
    digit[t - 1] = '2';
    //insert
    all.insert(LL(digit)*LL(digit));
    digit[0] = digit[t - 1] = '1';
    //insert
    all.insert(LL(digit)*LL(digit));

    rep(i,1,t/2 + 1){

        digit[i] = '1';
        digit[t - 1 - i] = '1';
        //insert
        all.insert(LL(digit)*LL(digit));

        digit[i] = '0';
        digit[t - 1 - i ] = '0';
    }
    rep(i,1,t/2+1)rep(j,i + 1,t/2 + 1){
        digit[i] = '1';
        digit[j] = '1';
        digit[t -1 - i] = '1';
        digit[t - 1 - j] = '1';
        //insert
        all.insert(LL(digit)*LL(digit));

        digit[i] = '0';
        digit[j] = '0';
        digit[t -1 - i] = '0';
        digit[t - 1 - j] = '0';
    }
    rep(i,1,t/2+1)rep(j,i + 1,t / 2 + 1) rep(k,j + 1,t / 2 + 1){
        digit[i] = '1';
        digit[j] = '1';
        digit[k] = '1';
        digit[t -1 - i] = '1';
        digit[t - 1 - j] = '1';
        digit[t - 1 - k] = '1';
        //insert
        all.insert(LL(digit)*LL(digit));

        digit[i] = '0';
        digit[j] = '0';
        digit[k] = '0';
        digit[t -1 - i] = '0';
        digit[t - 1 - j] = '0';
        digit[t - 1 - k] = '0';
    }
}

void solve2(int t){
    string digit(t,'0');
    digit[0] = digit[t - 1] = '2';
    //insert
    all.insert(LL(digit)*LL(digit));
     digit[t / 2] = '1';
    //insert
    all.insert(LL(digit)*LL(digit));

    digit[t / 2] = '0';
    digit[0] = digit[t - 1] = '1';
    //insert
    all.insert(LL(digit)*LL(digit));
    rep(i,1,t/2){

        digit[i] = '1';
        digit[t - 1 - i] = '1';
        //insert
        all.insert(LL(digit)*LL(digit));

        digit[i] = '0';
        digit[t - 1 - i ] = '0';
    }
    rep(i,1,t/2)rep(j,i + 1,t/2){
        digit[i] = '1';
        digit[j] = '1';
        digit[t -1 - i] = '1';
        digit[t - 1 - j] = '1';
        //insert
        all.insert(LL(digit)*LL(digit));

        digit[i] = '0';
        digit[j] = '0';
        digit[t -1 - i] = '0';
        digit[t - 1 - j] = '0';
    }
    rep(i,1,t/2)rep(j,i + 1,t / 2 ) rep(k,j + 1,t / 2){
        digit[i] = '1';
        digit[j] = '1';
        digit[k] = '1';
        digit[t -1 - i] = '1';
        digit[t - 1 - j] = '1';
        digit[t - 1 - k] = '1';
        //insert
        all.insert(LL(digit)*LL(digit));

        digit[i] = '0';
        digit[j] = '0';
        digit[k] = '0';
        digit[t -1 - i] = '0';
        digit[t - 1 - j] = '0';
        digit[t - 1 - k] = '0';
    }
    digit[t / 2] = '1';
     all.insert(LL(digit)*LL(digit));

    rep(i,1,t/2){

        digit[i] = '1';
        digit[t - 1 - i] = '1';
        //insert
        all.insert(LL(digit)*LL(digit));

        digit[i] = '0';
        digit[t - 1 - i ] = '0';
    }
    rep(i,1,t/2)rep(j,i + 1,t/2){
        digit[i] = '1';
        digit[j] = '1';
        digit[t -1 - i] = '1';
        digit[t - 1 - j] = '1';
        //insert
        all.insert(LL(digit)*LL(digit));

        digit[i] = '0';
        digit[j] = '0';
        digit[t -1 - i] = '0';
        digit[t - 1 - j] = '0';
    }
    rep(i,1,t/2)rep(j,i + 1,t / 2 ) rep(k,j + 1,t / 2){
        digit[i] = '1';
        digit[j] = '1';
        digit[k] = '1';
        digit[t -1 - i] = '1';
        digit[t - 1 - j] = '1';
        digit[t - 1 - k] = '1';
        //insert
        all.insert(LL(digit)*LL(digit));

        digit[i] = '0';
        digit[j] = '0';
        digit[k] = '0';
        digit[t -1 - i] = '0';
        digit[t - 1 - j] = '0';
        digit[t - 1 - k] = '0';
    }
    digit[t / 2] = '2';
    //insert
     all.insert(LL(digit)*LL(digit));

      rep(i,1,t/2){

        digit[i] = '1';
        digit[t - 1 - i] = '1';
        //insert
        all.insert(LL(digit)*LL(digit));

        digit[i] = '0';
        digit[t - 1 - i ] = '0';
    }



}

int main(){

    LL a("1");
all.insert(a);
a= LL("4");
all.insert(a);
a = LL("9");
all.insert("9");
    for(int i = 2;i <= 50;i ++){
        if(i % 2 == 0){
            solve(i);
        }
        else solve2(i);
    }
  //  for(set<LL >::iterator it= all.begin();it != all.end();it ++){
   //        cout <<(*it).Str() << endl;
    //}
    int T;
    cin >> T;
    int ca = 1;
    while(T --){
        string a,b;
        cin >> a >> b;
        int countf = 0;
        LL aa(a);
        LL bb(b);
        //cout << a << " " << b << endl;
        for(set<LL >::iterator it= all.begin();it != all.end();it ++){
            if((aa < (*it)||aa==(*it)) && ((*it < bb) || (*it == bb))){
         //       cout << (aa < (*it)) << " " << (aa==(*it) )<< " " << ((*it) < bb)<< " " << ((*it) == bb )<< endl;
           //     cout << (*it).Str() << endl;
                countf ++;

            }
        }
        cout << "Case #"<<ca<<": "<<countf << endl;
        ca ++;

    }
}
