#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    int index=1;
    while(n--){
        string a,b;
        cin >> a >> b;
        string temp1,temp2;
        temp1=a,temp2=b;
        string ans1="",ans2="";
        int flag=0;
        long long int dif=1000000000;
        dif=1000000000*dif;

       // long long int temp1=0,long long int temp2=0;
       for(int i=0;i<=a.size();++i){long long int tdif=0;int j;
            for(j=0;j<a.size();++j){
            if(j<i){
                if(a[j]=='?' && b[j]=='?'){
                    a[j]='0';
                    b[j]='0';
                }
                else if(a[j]!='?' && b[j]=='?')
                    b[j]=a[j];
                else if(b[j]!='?' && a[j]=='?'){
                    a[j]=b[j];
                }
                else if(a[j]!='?' && b[j]!='?' && a[j]!=b[j]){
                    break;
                }


            }
            else if(j==i){
                if(a[i]=='?' && b[i]=='?'){
                    a[i]='1';
                    b[i]='0';
                    tdif=1;
                }
                else if(a[i]!='?' && b[i]=='?'){
                    if(a[i]!='0'){
                        b[i]=a[i]-1;
                        tdif=1;
                    }
                    else
                        break;
                }
                else if(a[i]=='?' && b[i]!='?'){
                    if(b[i]!='9'){
                        a[i]=b[i]+1;
                        tdif=1;
                    }
                    else
                        break;
                }
                else if(a[i]!='?' && b[i]!='?'){
                    if(a[i]<=b[i])
                        break;
                    else
                        tdif=a[i]-b[i];

                }
            }
            else{
            if(a[j]=='?' && b[j]=='?'){
                a[j]='0';
                b[j]='9';
                tdif=10*tdif-9;
            }
            else if(a[j]=='?' && b[j]!='?'){
                a[j]='0';
                tdif=10*tdif+('0'-b[j]);
            }
            else if(a[j]!='?' && b[j]=='?'){
                b[j]='9';
                tdif=10*tdif+(a[j]-'9');
            }
            else{
                tdif=10*tdif+(a[j]-b[j]);
            }
            }

            }
            if(j!=a.size())
                continue;
            if(dif>tdif){
                dif=tdif;
                ans1=a;
                ans2=b;
            }
            else if(dif==tdif){
                if(ans1>a){
                    ans1=a;
                    ans2=b;
                }
                else if(ans1==a){
                    ans2=min(ans2,b);
                }

            }
          //  cout << a << " " << b << endl;
            a=temp1;
            b=temp2;


       }
       a=temp2,b=temp1;
       for(int i=0;i<=a.size();++i){long long int tdif=0;int j;
            for( j=0;j<a.size();++j){
            if(j<i){
                if(a[j]=='?' && b[j]=='?'){
                    a[j]='0';
                    b[j]='0';
                }
                else if(a[j]!='?' && b[j]=='?')
                    b[j]=a[j];
                else if(b[j]!='?' && a[j]=='?'){
                    a[j]=b[j];
                }
                else if(a[j]!='?' && b[j]!='?' && a[j]!=b[j]){
                    break;
                }


            }
            else if(j==i){
                if(a[i]=='?' && b[i]=='?'){
                    a[i]='1';
                    b[i]='0';
                    tdif=1;
                }
                else if(a[i]!='?' && b[i]=='?'){
                    if(a[i]!='0'){
                        b[i]=a[i]-1;
                        tdif=1;
                    }
                    else
                        break;
                }
                else if(a[i]=='?' && b[i]!='?'){
                    if(b[i]!='9'){
                        a[i]=b[i]+1;
                        tdif=1;
                    }
                    else
                        break;
                }
                else if(a[i]!='?' && b[i]!='?'){
                    if(a[i]<=b[i])
                        break;
                    else
                        tdif=a[i]-b[i];

                }
            }
            else{
            if(a[j]=='?' && b[j]=='?'){
                a[j]='0';
                b[j]='9';
                tdif=10*tdif-9;
            }
            else if(a[j]=='?' && b[j]!='?'){
                a[j]='0';
                tdif=10*tdif+('0'-b[j]);
            }
            else if(a[j]!='?' && b[j]=='?'){
                b[j]='9';
                tdif=10*tdif+(a[j]-'9');
            }
            else{
                tdif=10*tdif+(a[j]-b[j]);
            }
            }

            }
            if(j!=a.size())
                continue;
               // cout << tdif << endl;
            if(dif>tdif){
                dif=tdif;
                ans2=a;
                ans1=b;
            }
            else if(dif==tdif){
                if(ans1>b){
                    ans2=a;
                    ans1=b;
                }
                else if(ans1==b){
                    ans2=min(ans2,a);
                }

            }
          // cout << a << " " << b << endl;
            a=temp2;
            b=temp1;


       }
        cout << "Case #" << index++ <<  ": "  <<  ans1 << " " << ans2 << endl;
    }



    return 0;
}
