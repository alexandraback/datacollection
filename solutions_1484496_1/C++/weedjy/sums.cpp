#include <iostream>

using namespace std;

long long int a[500];

struct LargeInt
{
    long long int d[500];
    LargeInt()
    {
        for(int i = 0; i < 500; i++) d[i]=0;
    }
    LargeInt(int m)
    {
        int i = 0;
        while(i < 500)
        {
            if(m%2) d[i]=a[i];
            m=m>>1;
            if(m == 0) break;
            i++;
        }
    }
    ~LargeInt(){}

    bool IsZero()
    {
        for(int i = 0; i < 500; i++)
        {
            if(this->d[i] > 0) return false;
        }
        return true;
    }

    bool LessThanMax()
    {
        for(int i = 0; i < 500; i++)
        {
            if(this->d[i] == 0) return true;
        }
        return false;
    }

    bool IsEqualDigitExist(const LargeInt& B)
    {
        for(int i = 0; i < 500; i++)
        {
            if((this->d[i] == B.d[i])&&(this->d[i] > 0)) return true;
        }
        return false;
    }

    bool GreaterThanMin()
    {
        for(int i = 499; i >= 0; i--)
        {
            if(this->d[i] > 0) return true;
        }
        return false;
    }

    void MakeMax()
    {
        for(int i = 0; i < 500; i++) d[i] = a[i];
    }

    void Reverse()
    {
        for(int i = 0; i < 500; i++) d[i] = (d[i]>0)?0:a[i];
    }

    int Inc1()
    {
        if(this->d[0] == 0)
        {
            this->d[0] = a[0];
            return 0;
        }
        this->d[0] = 0;
        int i = 1;
        while((this->d[i])&&(i < 500))
        {
            this->d[i] = 0;
            i++;
        }
        if(i < 500)
        { 
            this->d[i] = a[i];
        }
        else return 1;
        return 0;
    }

    int Dec1()
    {
        if(this->d[0] > 0)
        {
            this->d[0] = 0;
            return 0;
        }
        this->d[0] = a[0];
        int i = 1;
        while((this->d[i] == 0)&&(i < 500))
        {
            this->d[i] = a[i];
            i++;
        }
        if(i < 500)
        {
            this->d[i] = 0;
        }
        else return 1;
        return 0;
    }
};

/*
ostream& operator<<(ostream &o, LargeInt sc)
{
    int i = 499;
    while(sc.d[i] == 0) i--;
    for(; i >= 0; i--) o << sc.d[i];
    return o;
};*/


int calc(int I, int n)
{
    for(LargeInt p = (int)1; p.LessThanMax();)//2^20
    {
        long long int s1 = 0;
        int i = 0;
        while(i < n)
        {
            if(p.d[i] > 0) s1 += a[i];
            i++;
        }
        LargeInt q = p;
        q.Reverse();//q = Max - p;
        while(q.GreaterThanMin())
        {
            if(p.IsEqualDigitExist(q))
            {
                if(q.Dec1()) break;
                else continue;
            }
            long long int s2 = 0;
            int j = 0, we = 0;
            while((j < n)&&(we == 0))
            {
                if(q.d[j] > 0) s2 += a[j];
                we = (s2 > s1)?1:0;
                j++;
            }
            if(we)
            {
                if(q.Dec1()) break;
                else continue;
            }
//            cout << p << " " << q << endl;
            else if(s1 == s2)
            {
                int  k = 0;
                cout << "Case #" << I+1 << ":" << endl;
                while(k < n)
                {
                    if(p.d[k] > 0) cout << a[k] << " ";
                    k++;
                }
                cout << endl;
                k = 0;
                while(k < n)
                {
                    if(q.d[k] > 0) cout << a[k] << " ";
                    k++;
                }
                cout << endl;
                return 0;
            }
            if(q.Dec1()) break;
        }
        if(p.Inc1()) break;
    }
    return 1;
}
 
int main(int argc, char *argv[])
{
    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        for(int j = 0; j < 500; j++) a[j] = 0;
        int n;
        cin >> n;
        for(int j = 0; j < n; j++) cin >> a[j];
        if(calc(i, n))
        {
            cout << "Case #" << i+1 << ":" << endl;
            cout << "Impossible" << endl;
        }
    }
   
    return 0;
}
