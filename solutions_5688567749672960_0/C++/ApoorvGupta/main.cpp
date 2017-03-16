#include <iostream>
#include <stdio.h>

int queue[100000000];
bool check[100000000];
int origin[100000000];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tcase,num,front,back,temp,count,temp2,revtemp,dig,casecount;

    std::cin>>tcase;
    casecount=0;
    while(tcase--)
    {
        std::cin>>num;

        front=0;
        back=1;
        temp=-1;
        queue[front]=1;
        check[1]=1;
        std::fill(check,check+100000000,0);

        while(front<back)
         {
            //pop
            temp=queue[front];
            front++;

            if(temp==num)
            {
                count=1
                ;
                while(temp!=1)
                {
                  count++;
                  temp=origin[temp];
                }
                casecount++;
                std::cout<<"Case #"<<casecount<<": "<<count<<std::endl;
                break;
            }
            else
            {
            if(check[temp+1]!=1)
            {

                queue[back]=temp+1;
                back++;
                origin[temp+1]=temp;
                check[temp+1]=1;

            }

            // push into queue reversed

            temp2=temp;
            revtemp=0;

            while(temp2>0)
            {
                revtemp=revtemp*10;
                dig=temp2%10;
                revtemp=revtemp+dig;
                temp2=temp2/10;
            }

            if(check[revtemp]!=1)
            {

                queue[back]=revtemp;
                back++;
                origin[revtemp]=temp;
                check[revtemp]=1;
            }
            }




        }
    }
    return 0;
}
