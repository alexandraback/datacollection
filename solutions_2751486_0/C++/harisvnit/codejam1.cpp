#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    int t,q,n,l,count,i,save,total,flag,lsave,temp;
    cin>>t;
    for(q=0; q<t; q++)
    {
        cin>>s;
        cin>>n;
        l=s.length();
        total=0;
        count=0;
        flag=0;
        //lsave=0;
        for(i=0; i<l; i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {

                count=0;
            }

            if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u')
            {

                if(count==0)
                save=i;
                count++;
            }
            if(count==n)
            {
                if(flag==0)
                {
                //total=i+1;

                     temp=save+1;
                   total=total+(temp*(l-i));
                }
                else
                {
                    temp=save-lsave+(n-1);
                   total=total+(temp*(l-i));
                }
                count=0;
                lsave=i;
                flag=1;
                i=save;
            }
        }
        cout<<"Case #"<<q+1<<": "<<total<<endl;
    }




    return 0;
}
