#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

typedef enum {i,j,k,l}Q;

typedef struct
{
    int sign;
    Q q;
}quat;

quat cons(char c)
{
    quat v;
    v.sign = 1;
    if(c=='i') v.q = i;
    else if(c=='j') v.q = j;
    else if(c=='k') v.q = k;
    //else if(c=='l') q.q = l;
    return v;
}

quat mul(quat A, quat B)
{
    quat C;
    C.sign = A.sign * B.sign;
    if(A.q==l && B.q==l) {C.q=l; C.sign *= 1;}
    else if(A.q==l && B.q==i) {C.q=i; C.sign *= 1;}
    else if(A.q==l && B.q==j) {C.q=j; C.sign *= 1;}
    else if(A.q==l && B.q==k) {C.q=k; C.sign *= 1;}

    else if(A.q==i && B.q==l) {C.q=i; C.sign *= 1;}
    else if(A.q==i && B.q==i) {C.q=l; C.sign *= -1;}
    else if(A.q==i && B.q==j) {C.q=k; C.sign *= 1;}
    else if(A.q==i && B.q==k) {C.q=j; C.sign *= -1;}

    else if(A.q==j && B.q==l) {C.q=j; C.sign *= 1;}
    else if(A.q==j && B.q==i) {C.q=k; C.sign *= -1;}
    else if(A.q==j && B.q==j) {C.q=l; C.sign *= -1;}
    else if(A.q==j && B.q==k) {C.q=i; C.sign *= 1;}

    else if(A.q==k && B.q==l) {C.q=k; C.sign *= 1;}
    else if(A.q==k && B.q==i) {C.q=j; C.sign *= 1;}
    else if(A.q==k && B.q==j) {C.q=i; C.sign *= -1;}
    else if(A.q==k && B.q==k) {C.q=l; C.sign *= -1;}

    return C;
}

bool isi(quat q)
{
    if(q.sign==1 && q.q==i) return true;
    else return false;
}

bool isj(quat q)
{
    if(q.sign==1 && q.q==j) return true;
    else return false;
}

bool isk(quat q)
{
    if(q.sign==1 && q.q==k) return true;
    else return false;
}

bool check_k(int X, int L, int z, string s)
{
    //X=min(X,BIG);
    quat pro;
    pro.sign=1;
    pro.q=l;
    for(int i=z; i<L; i++) pro = mul(pro,cons(s.c_str()[i]));
    X--;
    for(int i=X; i>0; i--)
    {
        for(int j=0; j<L; j++) pro = mul(pro,cons(s.c_str()[j]));
    }
    return isk(pro);
}

bool check_jk(int X, int L, int z, string s)
{
    //X=min(X,2*BIG);
    quat pro;
    pro.sign=1;
    pro.q=l;
    for(int i=z; i<L; i++)
    {
        pro = mul(pro,cons(s.c_str()[i]));
        if(isj(pro))
        {
            if(i==L-1){
            if(check_k(X-1,L,(i+1)%L,s)) return true; else return false;}
            else{
                if(check_k(X,L,(i+1)%L,s)) return true; else return false;}
        }
    }
    X--;
    for(int i=X; i>0; i--)
    {
        for(int j=0; j<L; j++)
        {
            pro = mul(pro,cons(s.c_str()[j]));
            if(isj(pro))
            {
                if(j==L-1){
            if(check_k(i-1,L,(j+1)%L,s)) return true; else return false;}
            else{
                if(check_k(i,L,(j+1)%L,s)) return true; else return false;}
            }
        }
    }
    return false;
}

bool check_ijk(int X, int L, string s)
{
    //s_product(L,s);
    X=min(12+(X%4),X);
    quat pro;
    pro.sign=1;
    pro.q=l;
    for(int i=X; i>0; i--)
    {
        //cout<<"yo"<<i<<endl;
        for(int j=0; j<L; j++)
        {
            pro = mul(pro,cons(s.c_str()[j]));
            if(isi(pro))
            {
                if(j==L-1){
            if(check_jk(i-1,L,(j+1)%L,s)) return true; else return false;}
            else {
                if(check_jk(i,L,(j+1)%L,s)) return true; else return false;}
            }
        }
    }
    return false;
}

int main()
{
    ifstream in;
    ofstream out;
    in.open("C-small-attempt0.in");
    out.open("output.txt");
    int T,L,X;
    string s;
    in>>T;
    for(int i=0; i<T; i++)
    {
        in>>L; in>>X; in>>s;
        if(check_ijk(X,L,s)) out<<"Case #"<<i+1<<": "<<"YES"<<endl;
        else out<<"Case #"<<i+1<<": "<<"NO"<<endl;
    }
}
