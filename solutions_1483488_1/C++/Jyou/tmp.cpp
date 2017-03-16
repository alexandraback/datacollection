#include <iostream>
#include <vector>
using namespace std;



void setBitMap(int num, char *bitMap)
{
    int idx=num/8;
    int off=num%8;
    unsigned char val=0x1<<off;
    bitMap[idx]|=val;
    
}
bool testBitMap(int num, char *bitMap)
{
    int idx=num/8;
    int off=num%8;
    unsigned char val=0x1<<off;
    return (bitMap[idx]&val);
}
int main()
{

    
    int t;
    cin >> t;
    for (int i=0;i<t;++i)
    {

        int rlt=0;
        int a,b;
        cin >> a >> b;
        for (int j=a;j<=b;++j)
        {
            //get number of digits
            //
           // if (testBitMap(j,bitMap)) continue;
           // else setBitMap(j,bitMap);
            int ans=j;
            int digit;
            int mask=1;
            //now the number of digits
            for (digit=1;digit;++digit)
            {
                ans/=10;
                if (ans==0) break;
                mask*=10; 
            }

            ans=j;
            
            bool incr=false;
            vector<int> preList;
            for (int k=0;k<digit-1;++k)
            {
 
                int d=ans/mask;
                int num=ans%mask;
                int newNum=num*10+d;
                ans=newNum;
                if (newNum>=a&&newNum<=b&&newNum>j) {   //how about newnumber has been discovered?
                
                bool found=false;
                for (int l=0;l<preList.size();++l)
                {
                    if (preList[l]==newNum) found=true;
                }
                if (!found)
                {
                  ++rlt;
                  preList.push_back(newNum);
                }
                //cout << j << " " << newNum << " " << rlt << endl;
                //system("pause");
             /*      if (testBitMap(newNum,bitMap)) continue;
                   else 
                   {    setBitMap(newNum,bitMap);*/

                 //  }
                }
            }
            //
        }
        cout << "Case #" << i+1 << ": " << rlt << endl; 

    }


    return 0;
}
