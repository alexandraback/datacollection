#include<cstdio>
#include<cstring>
typedef unsigned long long llu;

struct quater
{
    int val;
    enum{I=2, J=3, K=4};
    quater(const int val=1) : val(val){}
    
    quater(const char c)
    {
        val=c-'i'+2;
    }
    
    quater operator*(const quater& Q) const
    {
        static const int m[5][5]={{0}, {0, 1, 2, 3, 4}, {0, 2, -1, 4, -3}, {0, 3, -4, -1, 2}, {0, 4, 3, -2, -1}};
        return quater(m[ val<0 ? -val : val ][ Q.val<0 ? -Q.val : Q.val ]*(val*Q.val<0 ? -1 : 1));
    }
    
    bool operator==(const quater& Q) const
    {
        return val==Q.val;
    }
    
    bool operator!=(const quater& Q) const
    {
        return val!=Q.val;
    }
    
    quater inv(const quater& Q) const
    {
        for(int i=-4; i<=4; i++)
            if( *this*quater(i)==Q )
                return quater(i);
    }
    
    quater pow(llu p) const
    {
        quater ret;
        
        for(int i=p%4; i>0; i--)
            ret=*this*ret;
        
        return ret;
    }
    
    void print() const
    {
        if( val==1 || val==-1 )
        {
            printf("%d", val);
            return ;
        }
        
        if( val<0 )
            printf("-");
        
        printf("%c", (val<0 ? -val : val)-2+'i');
    }
};

bool check(const char* str, llu len, llu mul)
{
    quater a[12000][2];
    
    for(int i=1; i<=len; i++)
        a[i][0]=a[i-1][0]*quater(str[i-1]);
    
    if( a[len][0].pow(mul)!=quater(-1) )
        return false;
    
    for(int i=0; i<=len; i++)
        a[i][1]=a[i][0].inv(a[len][0]);
    
    if( mul==1 )
    {
        for(int i=0; i<=len; i++)
        {
            if( a[i][0]==quater::I )
            {
                for(int j=i+1; j<=len; j++)
                    if( a[j][1]==quater::K )
                        return true;
                
                return false;
            }
        }
        
        return false;
    }
    
    for(int l=0; l<4; l++)
    for(int r=0; r<4; r++)
        if( l+r<=mul-1 && (l+r)%4==(mul-1)%4 )
        {
            for(int i=0; i<=len; i++)
                if( a[len][0].pow(l)*a[i][0]==quater::I )
                {
                    for(int j=i+1; j<=len; j++)
                        if( a[j][1]*a[len][0].pow(r)==quater::K )
                            return true;
                    
                    break;
                }
        }
    
    for(int l=0; l<4; l++)
    for(int r=0; r<4; r++)
        if( l+r<=mul-2 )
        {
            bool hi=false, hk=false;
            
            for(int i=0; i<=len; i++)
            {
                if( a[len][0].pow(l)*a[i][0]==quater::I )
                    hi=true;
                
                if( a[i][1]*a[len][0].pow(r)==quater::K )
                    hk=true;
                
                if( hi && hk )
                    return true;
            }
        }
    
    return false;
}

int main()
{
    for(int N, Case=scanf("%d", &N); Case<=N; Case++)
    {
        llu len, mul;
        char str[12000];
        scanf("%llu%llu%s", &len, &mul, str);
        printf("Case #%d: %s\n", Case, check(str, len, mul) ? "YES" : "NO");
    }
}