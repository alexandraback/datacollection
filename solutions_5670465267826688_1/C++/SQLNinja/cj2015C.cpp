#include<bits/stdc++.h>
using namespace std;
int neg=0;
   string T[60][60];
void init(void){
    T['1'-'0']['1'-'0']="1"; T['1'-'0']['i'-'0']="i" ; T['1'-'0']['j'-'0']="j" ; T['1'-'0']['k'-'0']="k" ;
    T['i'-'0']['1'-'0']="i"; T['i'-'0']['i'-'0']="-1"; T['i'-'0']['j'-'0']="k" ; T['i'-'0']['k'-'0']="-j";
    T['j'-'0']['1'-'0']="j"; T['j'-'0']['i'-'0']="-k"; T['j'-'0']['j'-'0']="-1"; T['j'-'0']['k'-'0']="i" ;
    T['k'-'0']['1'-'0']="k"; T['k'-'0']['i'-'0']="j" ; T['k'-'0']['j'-'0']="-i"; T['k'-'0']['k'-'0']="-1";
}
char equ(char a, char b)
{

    string c=T[a-'0'][b-'0'];
    if(c.length()==2){neg++;return c[1];}
    return c[0];
}
int main()
{
    init();
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    int t,tc=1;
    cin>>t;
    string s;
    bool ok;
    while(true)
    {
    begin:
        int l,x;
        cin>>l>>x;
        cin>>s;
        string a;
        int k = 0;
        ok =true;
        if((l*x %3 && l*x < 3))
        {
                cout<<"Case #"<<tc++<<": "<<"NO"<<endl;
                continue;

        }
        for(int i = 0; i < x;i++) a=a+s;
        char tmp = '1';
        for(int i  =0; i < a.size();i++){
            tmp  = equ(tmp, a[i]);
            if(tmp == 'i' && neg % 2 == 0){
                tmp = '1';
                for(int j = i+1; j <  a.size();j++){
                    tmp = equ(tmp,a[j]);
                    if(tmp == 'j' && neg % 2 == 0){
                        tmp = '1';
                        for(int k = j+1; k <  a.size();k++){
                            tmp = equ(tmp,a[k]);
                            if(tmp == 'k' && neg % 2 == 0)
                            {
                                if(k == a.length() - 1)
                                {cout<<"Case #"<<tc++<<": "<<"YES"<<endl;
                                if(tc==t+1)return 0;
                                goto begin;
                                }}}}}}}
        for(int i  =a.size()-1; i >=0;i--){
            tmp  = equ(tmp, a[i]);
            if(tmp == 'k' && neg % 2 == 0){
                tmp = '1';
                for(int j = i-1; j >=0;j--){
                    tmp = equ(tmp,a[j]);
                    if(tmp == 'j' && neg % 2 == 0){
                        tmp = '1';
                        for(int k = j-1; k >=0;k--){
                            tmp = equ(tmp,a[k]);
                            if(tmp == 'i' && neg % 2 == 0)
                            {
                                if(k ==0)
                                {cout<<"Case #"<<tc++<<": "<<"YES"<<endl;
                                if(tc==t+1)return 0;
                                goto begin;
                                }}}}}}}


    cout<<"Case #"<<tc++<<": "<<"NO"<<endl;
    if(tc==t+1)return 0;

    }

}
