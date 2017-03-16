#include <iostream>
#include <vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#define mp(a,b) make_pair(a,b)
#define xx first
#define yy second
using namespace std;
typedef long long LL;
typedef double db;
char c[20];
char d[20];
char a1[20],a2[20];
char n1[20],n2[20];
LL solve(int p,int n,LL s1,LL s2){
    for(int i=p;i<n;i++){
        n1[i]=c[i];
        if(c[i]!='?') s1=s1*10+c[i]-'0';
        else{
            n1[i]='0';
            s1=s1*10+0;
        }
        n2[i]=d[i];
        if(d[i]!='?'){
            s2=s2*10+d[i]-'0';
        }
        else{
            s2=s2*10+9;
            n2[i]='9';
        }
    }
    return s1-s2;
}
LL solve1(int p,int n,LL s1,LL s2){
    for(int i=p;i<n;i++){
        n1[i]=c[i];
        if(c[i]!='?') s1=s1*10+c[i]-'0';
        else{
            n1[i]='9';
            s1=s1*10+9;
        }
        n2[i]=d[i];
        if(d[i]!='?'){
            s2=s2*10+d[i]-'0';
        }
        else{
            s2=s2*10+0;
            n2[i]='0';
        }
    }
    return s2-s1;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,N=0;
    cin>>t;
    while(t--){
        scanf("%s",c);
        scanf("%s",d);
        LL ans=(LL)1<<60;
        int n=strlen(c);
        int f=0;
        LL s1=0,s2=0;
        n1[n]=n2[n]='\0';
        for(int i=0;i<n;i++){
            if(f) break;
            n1[i]=c[i];
            n2[i]=d[i];
            if(c[i]!='?'){
                if(d[i]!='?'){
                    if(c[i]>d[i]){
                        LL an=solve(i+1,n,s1*10+c[i]-'0',s2*10+d[i]-'0');
                        if(an<ans){
                            ans=an;
                            n1[n]=n2[n]='\0';
                            strcpy(a1,n1);
                            strcpy(a2,n2);
                        }
                        else if(an==ans){
                            if(strcmp(a1,n1)>0){
                                strcpy(a1,n1);
                                strcpy(a2,n2);
                            }
                            else if(strcmp(a1,n1)==0){
                                if(strcmp(a2,n2)>0){
                                    strcpy(a1,n1);
                                    strcpy(a2,n2);
                                }
                            }
                        }
                        f=1;
                    }
                    else if(c[i]<d[i]){
                        LL an=solve1(i+1,n,s1*10+c[i]-'0',s2*10+d[i]-'0');
                        if(an<ans){
                            ans=an;
                            n1[n]=n2[n]='\0';
                            strcpy(a1,n1);
                            strcpy(a2,n2);
                        }
                        else if(an==ans){
                            if(strcmp(a1,n1)>0){
                                strcpy(a1,n1);
                                strcpy(a2,n2);
                            }
                            else if(strcmp(a1,n1)==0){
                                if(strcmp(a2,n2)>0){
                                    strcpy(a1,n1);
                                    strcpy(a2,n2);
                                }
                            }
                        }
                        f=1;
                    }
                }
                else{
                    if(c[i]!='0'){
                        n2[i]=c[i]-1;
                        LL an=solve(i+1,n,s1*10+c[i]-'0',s2*10+n2[i]-'0');
                        if(an<ans){
                            ans=an;
                            n1[n]=n2[n]='\0';
                            strcpy(a1,n1);
                            strcpy(a2,n2);
                        }
                        else if(an==ans){
                            if(strcmp(a1,n1)>0){
                                strcpy(a1,n1);
                                strcpy(a2,n2);
                            }
                            else if(strcmp(a1,n1)==0){
                                if(strcmp(a2,n2)>0){
                                    strcpy(a1,n1);
                                    strcpy(a2,n2);
                                }
                            }
                        }
                    }
                    if(c[i]!='9'){
                        n2[i]=c[i]+1;
                        LL an=solve1(i+1,n,s1*10+c[i]-'0',s2*10+n2[i]-'0');
                        if(an<ans){
                            ans=an;
                            n1[n]=n2[n]='\0';
                            strcpy(a1,n1);
                            strcpy(a2,n2);
                        }
                        else if(an==ans){
                            if(strcmp(a1,n1)>0){
                                strcpy(a1,n1);
                                strcpy(a2,n2);
                            }
                            else if(strcmp(a1,n1)==0){
                                if(strcmp(a2,n2)>0){
                                    strcpy(a1,n1);
                                    strcpy(a2,n2);
                                }
                            }
                        }
                    }
                    n2[i]=c[i];
                }
            }
            else{
                if(d[i]!='?'){
                    if(d[i]!='9'){
                        n1[i]=d[i]+1;
                        LL an=solve(i+1,n,s1*10+n1[i]-'0',s2*10+d[i]-'0');
                        if(an<ans){
                            ans=an;
                            n1[n]=n2[n]='\0';
                            strcpy(a1,n1);
                            strcpy(a2,n2);
                        }
                        else if(an==ans){
                            if(strcmp(a1,n1)>0){
                                strcpy(a1,n1);
                                strcpy(a2,n2);
                            }
                            else if(strcmp(a1,n1)==0){
                                if(strcmp(a2,n2)>0){
                                    strcpy(a1,n1);
                                    strcpy(a2,n2);
                                }
                            }
                        }
                    }
                    if(d[i]!='0'){
                        n1[i]=d[i]-1;
                        LL an=solve1(i+1,n,s1*10+n1[i]-'0',s2*10+d[i]-'0');
                        if(an<ans){
                            ans=an;
                            n1[n]=n2[n]='\0';
                            strcpy(a1,n1);
                            strcpy(a2,n2);
                        }
                        else if(an==ans){
                            if(strcmp(a1,n1)>0){
                                strcpy(a1,n1);
                                strcpy(a2,n2);
                            }
                            else if(strcmp(a1,n1)==0){
                                if(strcmp(a2,n2)>0){
                                    strcpy(a1,n1);
                                    strcpy(a2,n2);
                                }
                            }
                        }
                    }
                    n1[i]=d[i];
                }
                else{
                    n1[i]='1';
                    n2[i]='0';
                    LL an=solve(i+1,n,s1*10+n1[i]-'0',s2*10+n2[i]-'0');
                    if(an<ans){
                        ans=an;
                        n1[n]=n2[n]='\0';
                        strcpy(a1,n1);
                        strcpy(a2,n2);
                    }
                    else if(an==ans){
                        if(strcmp(a1,n1)>0){
                            strcpy(a1,n1);
                            strcpy(a2,n2);
                        }
                        else if(strcmp(a1,n1)==0){
                            if(strcmp(a2,n2)>0){
                                strcpy(a1,n1);
                                strcpy(a2,n2);
                            }
                        }
                    }
                    n1[i]='0';
                    n2[i]='1';
                    an=solve1(i+1,n,s1*10+n1[i]-'0',s2*10+n2[i]-'0');
                    if(an<ans){
                        ans=an;
                        n1[n]=n2[n]='\0';
                        strcpy(a1,n1);
                        strcpy(a2,n2);
                    }
                    else if(an==ans){
                        if(strcmp(a1,n1)>0){
                            strcpy(a1,n1);
                            strcpy(a2,n2);
                        }
                        else if(strcmp(a1,n1)==0){
                            if(strcmp(a2,n2)>0){
                                strcpy(a1,n1);
                                strcpy(a2,n2);
                            }
                        }
                    }
                    n1[i]='0';
                    n2[i]='0';
                }
            }
            s1=s1*10+n1[i]-'0';
            s2=s2*10+n2[i]-'0';
        }
        if(f==0){
            n1[n]='\0';
            n2[n]='\0';
            if(ans>0){
                ans=0;
                strcpy(a1,n1);
                strcpy(a2,n2);
            }
        }
        printf("Case #%d: %s %s\n",++N,a1,a2);
    }
}