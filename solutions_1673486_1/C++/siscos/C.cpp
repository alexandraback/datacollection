#include <vector>
#include <valarray>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <complex>

bool cmp(const int cmp1,const int cmp2){
     return cmp1>cmp2;
}

int main()
{
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
    int t;
    std::cin>>t;
    for(int i=0;i<t;i++)
    {
        int a,b;
        std::cin>>a>>b;
        double *p=new double[a];
        double min=1000000000;
        double all_cor=1;
        for(int j=0;j<a;j++)
        {
            std::cin>>p[j];
            all_cor*=p[j];
        }
        //다 치고 enter, 다시 처음부터 치기
        double tmp=(double)(b-a+1)*all_cor+(b-a+1+b+1)*(1-all_cor);
        if (min>tmp) 
            min=tmp;
        //enter치고 처음부터 다시치기
        tmp=b+2;
        if (min>tmp)
            min=tmp;
        //이후 한개씩 지우기
        for(int j=0;j<a-1;j++)
        {
            double pre_cor=1;
            for(int k=0;k<a-(j+1);k++)
            {
                pre_cor*=p[k];
            }
            double tmp1=pre_cor*(double)(b-a+1+2*(j+1))+(1-pre_cor)*(double)(b-a+1+2*(j+1)+b+1);
            if (min>tmp1) min=tmp1;
        }
        //다 백스페이스로 지우고 다시
        if (min>(double)(a+b+1)) min=(double)(a+b+1);

        std::cout.setf(std::ios::fixed,std::ios::floatfield);
        std::cout.precision(6);
        std::cout<<"Case #"<<i+1<<": "<<min<<std::endl;
        delete[]p;
    }
}