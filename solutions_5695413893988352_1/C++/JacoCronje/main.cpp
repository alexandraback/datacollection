#include <bits/stdc++.h>

using namespace std;

int n;
string A,B,oA,oB;
long long bestdiff;
long long besta;
long long bestb;
string bestA, bestB;

void rec(int p)
{
    if (p>=n*2)
    {
        long long a = 0;
        for (int k=0;k<n;k++)
            a = a*(long long)(10) + (long long)(A[k]-'0');
        long long b = 0;
        for (int k=0;k<n;k++)
            b = b*(long long)(10) + (long long)(B[k]-'0');
        long long diff = labs(a-b);
        if (diff<bestdiff)
        {
            bestdiff = diff;
            besta = a;
            bestb = b;
            bestA = A;
            bestB = B;
        } else if (diff==bestdiff)
        {
            if (a<besta)
            {
                bestdiff = diff;
                besta = a;
                bestb = b;
                bestA = A;
                bestB = B;
            } else if (a==besta)
            {
                if (b<bestb)
                {
                    bestdiff = diff;
                    besta = a;
                    bestb = b;
                    bestA = A;
                    bestB = B;
                }
            }
        }
        return;
    }
    if ((p&1)==0)
    {
        if (oA[p>>1]=='?')
        {
            for (int i=0;i<10;i++)
            {
                A[p>>1] = '0'+i;
                rec(p+1);
            }
        }
    } else
    {
        if (oB[p>>1]=='?')
        {
            for (int i=0;i<10;i++)
            {
                B[p>>1] = '0'+i;
                rec(p+1);
            }
        }
    }
    rec(p+1);
}

int main(int argc,char *argv[])
{
    char buf[65536];
    int T;
    cin >> T;
    cin.getline(buf, 65536);
    for (int t=0;t<T;t++)
    {
        cin.getline(buf, 65536);
        string s = buf;
        A = s.substr(0, s.find(' '));
        B = s.substr(s.find(' ')+1, s.length());
        oA = A;
        oB = B;
        n = A.length();

        bestdiff = (long long)(1) <<30;
        besta = (long long)(1) << 30;
        bestb = (long long)(1) << 30;
       // rec(0);
       // A = bestA;
       // B = bestB;

        //if (false)
        for (int i=0;i<n;i++)
        {
            if (A[i]!='?' && B[i]!='?') continue;
            int j = i+1;
            while (j<n && A[j]!='?' && B[j]!='?') j++;
            long long a = 0;
            long long b = 0;
            int besti1,besti2;
            bestdiff = (long long)(1) << 60;
            besta = (long long)(1) << 60;
            bestb = (long long)(1) << 60;
            for (int i1=0;i1<10;i1++)
                for (int i2=0;i2<10;i2++)
                {
                    if (oA[i]=='?')
                    {
                        A[i] = '0'+i1;
                    }
                    if (oB[i]=='?')
                    {
                        B[i] = '0'+i2;
                    }
                    a = 0;
                    for (int k=0;k<j;k++)
                        a = a*(long long)(10) + (long long)(A[k]-'0');
                    b = 0;
                    for (int k=0;k<j;k++)
                        b = b*(long long)(10) + (long long)(B[k]-'0');
                    if (j<n)
                    {
                        for (int i3=0;i3<10;i3++)
                            for (int i4=0;i4<10;i4++)
                            {
                                char chA = oA[j];
                                char chB = oB[j];
                                if (oA[j]=='?')
                                {
                                    chA = '0'+i3;
                                }
                                if (oB[j]=='?')
                                {
                                    chB = '0'+i4;
                                }
                                long long aa = a*(long long)(10) + (long long)(chA-'0');
                                long long bb = b*(long long)(10) + (long long)(chB-'0');

                                int z=j+1;
                                while (z<n && oA[z]!='?' && oB[z]!='?')
                                {
                                    aa = aa*(long long)(10) + (long long)(oA[z]-'0');
                                    bb = bb*(long long)(10) + (long long)(oB[z]-'0');
                                    z++;
                                }

                                long long diff = labs(aa-bb);
                                if (diff<bestdiff)
                                {
                                    bestdiff = diff;
                                    besta = aa;
                                    bestb = bb;
                                    besti1 = i1;
                                    besti2 = i2;
                                } else if (diff==bestdiff)
                                {
                                    if (aa<besta)
                                    {
                                        bestdiff = diff;
                                        besta = aa;
                                        bestb = bb;
                                        besti1 = i1;
                                        besti2 = i2;
                                    } else if (aa==besta)
                                    {
                                        if (bb<bestb)
                                        {
                                            bestdiff = diff;
                                            besta = aa;
                                            bestb = bb;
                                            besti1 = i1;
                                            besti2 = i2;
                                        }
                                    }
                                }
                            }
                    } else
                    {
                        long long diff = labs(a-b);
                        if (diff<bestdiff)
                        {
                            bestdiff = diff;
                            besta = a;
                            bestb = b;
                            besti1 = i1;
                            besti2 = i2;
                        } else if (diff==bestdiff)
                        {
                            if (a<besta)
                            {
                                bestdiff = diff;
                                besta = a;
                                bestb = b;
                                besti1 = i1;
                                besti2 = i2;
                            } else if (a==besta)
                            {
                                if (b<bestb)
                                {
                                    bestdiff = diff;
                                    besta = a;
                                    bestb = b;
                                    besti1 = i1;
                                    besti2 = i2;
                                }
                            }
                        }
                    }
                }
            if (oA[i]=='?')
            {
                A[i] = '0'+besti1;
            }
            if (oB[i]=='?')
            {
                B[i] = '0'+besti2;
            }
        }


        cout << "Case #" << t+1 << ": " << A << " " << B << endl;
    }
    return 0;
}
