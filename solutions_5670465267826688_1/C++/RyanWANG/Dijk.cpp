#include <iostream>
#include <fstream>
using namespace std;

const std::string YES = "YES";
const std::string NO = "NO";

ifstream fin("Dijk.in");
ofstream fout("Dijk.out");

//0 means positive and 1 means negative
struct Quad
{
    int sign;
    char digit;
};


int T;

Quad mult(Quad a, char b)
{
    if(a.digit==b)
    {
        a.digit = '1';
        a.sign = (!a.sign);
    }
    else if(a.digit == '1')
    {
        a.digit = b;
    }
    else if((int)(b-a.digit)==1||(int)(b-a.digit)==-2)
    {
        a.digit = char(b+1);
        if(a.digit>'k')
        {
            a.digit = 'i';
        }
    }
    else //reversed adjacent digits
    {
        a.digit = char(a.digit+1);
        if(a.digit>'k')
        {
            a.digit = 'i';
        }
        a.sign = (!a.sign);
    }
    return a;
}

Quad multQ(Quad a, Quad b)
{
    Quad result;
    if(b.digit=='1')
    {
        result.sign = a.sign^b.sign;
        result.digit = a.digit;
    }
    else
    {
        result = mult(a, b.digit);
        result.sign = result.sign^b.sign;   
    }
    return result;
}

Quad getprod(int start, int end, const std::string& L)
{
    Quad result;
    result.sign=0;
    result.digit = '1';
    for(int i=start;i<end;i++)
    {
        result = mult(result, L[i]);
    }
    return result;
}


bool search(long long& outPos, long long& inPos, const std::string& L, long long lLen, long long lNum, char target, Quad Lprod)
{
    Quad result;
    result.sign = 0;
    result.digit = '1';
    for(int outCount=0;outCount<5&&outPos<lNum;outCount++,outPos++)
    {
        long long inCount;
        if(outCount==0)
        {
            inCount = inPos;
        }
        else
        {
            inCount = 0;
        }
        for(;inCount<lLen;inCount++)
        {
            result = mult(result, L[inCount]);
            if(result.sign==0&&result.digit==target)
            {
                inPos = (inCount+1)%lLen;
                if(inPos==0)
                {
                    outPos++;
                }
                return true;
            }
        }
    }
    return false;
}

std::string solve(long long lLen, long long lNum, const std::string& L)
{
    Quad Lprod;
    bool flag;
    Quad lastQuad;

    Lprod = getprod(0, lLen, L);
    long long outPos;
    long long inPos;
    outPos = 0;
    inPos = 0;
    flag = search(outPos, inPos, L, lLen, lNum, 'i', Lprod);
    if(!flag)
    {
        return NO;
    }
    flag = search(outPos, inPos, L, lLen, lNum, 'j', Lprod);
    if(!flag)
    {
        return NO;
    }
    lastQuad = getprod(inPos, lLen, L);
    for(int i=outPos+1; i<lNum; i++)
    {
        if((lNum-i)%4==0)
        {
            break;
        }
        lastQuad = multQ(lastQuad, Lprod);
    }
    if(lastQuad.digit=='k'&&lastQuad.sign==0)
    {
        return YES;
    }
    else
    {
        return NO;
    }

}

int main()
{
    fin>>T;
    for(int curcase=0;curcase<T;curcase++)
    {
        long long lLen;
        long long lNum; 
        std::string L;
        std::string result;
        fin>>lLen>>lNum;
        fin>>L;
        result = solve(lLen, lNum, L);
        fout<<"case #"<<curcase+1<<": "<<result<<'\n';
    }
    return 0;
}
