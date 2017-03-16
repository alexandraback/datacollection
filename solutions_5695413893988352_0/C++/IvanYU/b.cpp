#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <math.h> 
using namespace std;
void getallnum1();
void getallnum2();
void pr(int,int);
char s1[100], s2[100];
int num1, num2;
vector<int> list1, list2;

int main()
{
    int T;
    scanf("%d", &T);

    for(int _T = 1; _T <= T; _T++)
    {
        scanf("%s %s", s1, s2);
        int l1 = strlen(s1);
        int l2 = strlen(s2);

        list1.clear();
        list2.clear();

        getallnum1();
        getallnum2();

        int ans = 1e8;
        int a, b;


        for(int i = 0; i < list1.size(); i++)
            for(int j = 0; j < list2.size(); j++)
            {
                if(abs(list1[i] - list2[j]) < ans)
                {
                    ans = abs(list1[i] - list2[j]);
                    a = list1[i];
                    b = list2[j];
                }
            }

        printf("Case #%d:", _T);
        pr(a, l1);
        pr(b, l2);
        printf("\n");
    }
}
void pr(int num , int l)
{
    printf(" ");
    int ol = log10(num) + 1;
    if(num == 0)
        ol = 1;
    //printf("log : %d\n", ol);
    for (int i = ol; i < l; ++i)
    {
        printf("0");
    }
    printf("%d", num);

}

void getallnum1()
{
    int l = strlen(s1);
    if(l == 3)
    {
        if(s1[0] == '?' && s1[1] == '?' &&  s1[2] == '?')
        {
            for(int i = 0; i < 10; i++)
                for(int j = 0; j < 10; j++)
                    for(int k = 0; k < 10; k++)
                    {
                        int t = i * 100 + j * 10 + k;
                        list1.push_back(t);
                    }
        }

        else if(s1[0] == '?' && s1[1] == '?')
        {
            for(int i = 0; i < 10; i++)
                for(int j = 0; j < 10; j++)
                    //for(int k = 0; k < 10; k++)
                    {
                        int t = i * 100 + j * 10 + s1[2] - '0';
                        list1.push_back(t);
                    }
        }

        else if(s1[0] == '?' && s1[2] == '?')
        {
            for(int i = 0; i < 10; i++)
                //for(int j = 0; j < 10; j++)
                    for(int k = 0; k < 10; k++)
                    {
                        int t = i * 100 + (s1[1] - '0') * 10 + k;
                        list1.push_back(t);
                    }
        }

         else if(s1[1] == '?' && s1[2] == '?')
        {
            //for(int i = 0; i < 10; i++)
                for(int j = 0; j < 10; j++)
                    for(int k = 0; k < 10; k++)
                    {
                        int t = (s1[0] - '0') * 100 + j * 10 + k;
                        list1.push_back(t);
                    }
        }

         else if(s1[0] == '?')
        {
            for(int i = 0; i < 10; i++)
                //for(int j = 0; j < 10; j++)
                    //for(int k = 0; k < 10; k++)
                    {
                        int t = i * 100 + (s1[1] - '0') * 10 + (s1[2] - '0');
                        list1.push_back(t);
                    }
        }

         else if(s1[1] == '?')
        {
            //for(int i = 0; i < 10; i++)
                for(int j = 0; j < 10; j++)
                    //for(int k = 0; k < 10; k++)
                    {
                        int t = (s1[0] - '0') * 100 + j * 10 + (s1[2] - '0');
                        list1.push_back(t);
                    }
        }

         else if(s1[2] == '?')
        {
            //for(int i = 0; i < 10; i++)
                //for(int j = 0; j < 10; j++)
                    for(int k = 0; k < 10; k++)
                    {
                        int t = (s1[0] - '0') * 100 + (s1[1] - '0') * 10 + k;
                        list1.push_back(t);
                    }
        }

        else
        {
            int t = (s1[0] - '0') * 100 + (s1[1] - '0') * 10 + (s1[2] - '0');
            list1.push_back(t);
        }

    }
    if(l == 2)
    {
        if(s1[0] == '?' && s1[1] == '?')
        {
            for(int i = 0; i < 10; i++)
                for(int j = 0; j < 10; j++)
                    {
                        int t = i * 10 + j * 1;
                        list1.push_back(t);
                    }
        }

        else if(s1[0] == '?')
        {
            for(int i = 0; i < 10; i++)
                //for(int j = 0; j < 10; j++)
                    {
                        int t = i * 10 + s1[1] - '0';
                        list1.push_back(t);
                    }
        }

        else if(s1[1] == '?')
        {
            //for(int i = 0; i < 10; i++)
                for(int j = 0; j < 10; j++)
                    {
                        int t = (s1[0] - '0') * 10 + j;
                        list1.push_back(t);
                    }
        }

        else
        {
            int t = (s1[0] - '0') * 10 + (s1[1] - '0');
            list1.push_back(t);
        }

    }

    if(l == 1)
    {

        if(s1[0] == '?')
        {
            for(int i = 0; i < 10; i++)
                    {
                        int t = i ;
                        list1.push_back(t);
                    }
        }

        else
        {
            int t = (s1[0] - '0');
            list1.push_back(t);
        }

    }
}

void getallnum2()
{
    int l = strlen(s2);
    if(l == 3)
    {
        if(s2[0] == '?' && s2[1] == '?' && s2[2] == '?')
        {
            for(int i = 0; i < 10; i++)
                for(int j = 0; j < 10; j++)
                    for(int k = 0; k < 10; k++)
                    {
                        int t = i * 100 + j * 10 + k;
                        list2.push_back(t);
                    }
        }

        else if(s2[0] == '?' && s2[1] == '?')
        {
            for(int i = 0; i < 10; i++)
                for(int j = 0; j < 10; j++)
                    //for(int k = 0; k < 10; k++)
                    {
                        int t = i * 100 + j * 10 + s2[2] - '0';
                        list2.push_back(t);
                    }
        }

        else if(s2[0] == '?' && s2[2] == '?')
        {
            for(int i = 0; i < 10; i++)
                //for(int j = 0; j < 10; j++)
                    for(int k = 0; k < 10; k++)
                    {
                        int t = i * 100 + (s2[1] - '0') * 10 + k;
                        list2.push_back(t);
                    }
        }

         else if(s2[1] == '?' && s2[2] == '?')
        {
            //for(int i = 0; i < 10; i++)
                for(int j = 0; j < 10; j++)
                    for(int k = 0; k < 10; k++)
                    {
                        int t = (s2[0] - '0') * 100 + j * 10 + k;
                        list2.push_back(t);
                    }
        }

         else if(s2[0] == '?')
        {
            for(int i = 0; i < 10; i++)
                //for(int j = 0; j < 10; j++)
                    //for(int k = 0; k < 10; k++)
                    {
                        int t = i * 100 + (s2[1] - '0') * 10 + (s2[2] - '0');
                        list2.push_back(t);
                    }
        }

         else if(s2[1] == '?')
        {
            //for(int i = 0; i < 10; i++)
                for(int j = 0; j < 10; j++)
                    //for(int k = 0; k < 10; k++)
                    {
                        int t = (s2[0] - '0') * 100 + j * 10 + (s2[2] - '0');
                        list2.push_back(t);
                    }
        }

         else if(s2[2] == '?')
        {
            //for(int i = 0; i < 10; i++)
                //for(int j = 0; j < 10; j++)
                    for(int k = 0; k < 10; k++)
                    {
                        int t = (s2[0] - '0') * 100 + (s2[1] - '0') * 10 + k;
                        list2.push_back(t);
                    }
        }

        else
        {
            int t = (s2[0] - '0') * 100 + (s2[1] - '0') * 10 + (s2[2] - '0');
            list2.push_back(t);
        }

    }
    if(l == 2)
    {
        if(s2[0] == '?' && s2[1] == '?')
        {
            for(int i = 0; i < 10; i++)
                for(int j = 0; j < 10; j++)
                    {
                        int t = i * 10 + j * 1;
                        list2.push_back(t);
                    }
        }

        else if(s2[0] == '?')
        {
            for(int i = 0; i < 10; i++)
                //for(int j = 0; j < 10; j++)
                    {
                        int t = i * 10 + s2[1] - '0';
                        list2.push_back(t);
                    }
        }

        else if(s2[1] == '?')
        {
            //for(int i = 0; i < 10; i++)
                for(int j = 0; j < 10; j++)
                    {
                        int t = (s2[0] - '0') * 10 + j;
                        list2.push_back(t);
                    }
        }

        else
        {
            int t = (s2[0] - '0') * 10 + (s2[1] - '0');
            list2.push_back(t);
        }

    }

    if(l == 1)
    {

        if(s2[0] == '?')
        {
            for(int i = 0; i < 10; i++)
                    {
                        int t = i ;
                        list2.push_back(t);
                    }
        }

        else
        {
            int t = (s2[0] - '0');
            list2.push_back(t);
        }

    }
}
