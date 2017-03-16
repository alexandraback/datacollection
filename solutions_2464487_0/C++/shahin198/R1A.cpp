//****** Big Number Sqrt ************************//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 1000
/****************************************************************/
void reverse(char* from, char* to)
    {
        int len = strlen(from);
        int l;
        for (l = 0; l < len; l++)
            to[l] = from[len - l - 1];
        to[len] = '\0';
    }
void call_mult(char *first,char *sec,char *result)
{
   // printf("Hell\n");
char F[MAX],S[MAX],temp[MAX];
int f_len,s_len,f,s,r,t_len,hold,res;
f_len=strlen(first);
s_len=strlen(sec);
reverse(first,F);
reverse(sec,S);
t_len=f_len+s_len;
r=-1;
for(f=0;f<=t_len;f++)
temp[f]='0';
temp[f]='\0';
for(s=0;s<s_len;s++){
hold=0;
for(f=0;f<f_len;f++){
res=(F[f]-'0')*(S[s]-'0') + hold+(temp[f+s]-'0');
temp[f+s]=res%10+'0';
hold=res/10;
if(f+s>r) r=f+s;
}
while(hold!=0){
res=hold+temp[f+s]-'0';
hold=res/10;
temp[f+s]=res%10+'0';
if(r<f+s) r=f+s;
f++;
}
}
for(;r>0 && temp[r]=='0';r--);
temp[r+1]='\0';
//printf("hel %s\n",temp);
reverse(temp,result);
}

    int call_minus1(char* large, char* small, char* result)
    {
        char L[MAX], S[MAX];
        int l,s,now,hold,diff;
        l=strlen(large);
        s=strlen(small);
        bool sign = 0;
        if(l<s)
        {
            strcpy(result,large);
            strcpy(large,small);
            strcpy(small,result);
            now=l; l=s; s=now;
            sign = 1;
        }//return 0;
        if(l==s)
        {
            if(strcmp(large, small)<0)
            {
                strcpy(result,large);
                strcpy(large,small);
                strcpy(small,result);
                now=l; l=s; s=now;
                sign =1;
            }//return 0;
        }
        reverse(large,L);
        reverse(small,S);
        for(;s<l;s++)
            S[s]='0';
        S[s]='\0';
        for(now=0,hold=0;now<l;now++)
        {
            diff=L[now]-(S[now]+hold);
            if(diff<0)
            {
                hold=1;
                result[now]=10+diff+'0';
            }
            else
            {
                result[now]=diff+'0';
                hold=0;
            }
        }
        for(now=l-1;now>0;now--)
        {
            if(result[now]!='0')
                break;
        }
        result[now+1]='\0';
        reverse(result,L);
        strcpy(result,L);
        //return 1;
        return sign;
    }
int call_minus(char *large, char *small, char *result){
char L[MAX], S[MAX];
int l,s,now,hold,diff;
l=strlen(large);
s=strlen(small);
if(l<s)
return 0;
if(l==s){
if(strcmp(large, small)<0)
return 0;
}
reverse(large,L);
reverse(small,S);
for(;s<l;s++)
S[s]='0';
S[s]='\0';
for(now=0,hold=0;now<l;now++){
diff=L[now]-(S[now]+hold);
if(diff<0){
hold=1;
result[now]=10+diff+'0';
}
else{
result[now]=diff+'0';
hold=0;
}
}
for(now=l-1;now>0;now--){
if(result[now]!='0')
break;
}
result[now+1]='\0';
reverse(result,L);
strcpy(result,L);
return 1;
}
void call_sum(char *first, char *sec, char *result){
char F[MAX], S[MAX], Res[MAX];
int f,s,sum,extra,now;
f=strlen(first);
s=strlen(sec);
reverse(first,F);
reverse(sec,S);
for(now=0,extra=0;(now<f && now<s);now++){
sum=(F[now]-'0') + (S[now]-'0') + extra;
Res[now]=sum%10 +'0';
extra= sum/10;
}
for(;now<f;now++){
sum=F[now] + extra-'0';
Res[now]=sum%10 +'0';
extra=sum/10;
}
for(;now<s;now++){
sum=F[now] + extra-'0';
Res[now]=sum%10 +'0';
extra=sum/10;
}
if(extra!=0) Res[now++]=extra+'0';
Res[now]='\0';
//printf("%s\n",Res);
if(strlen(Res)==0) strcpy(Res,"0");
reverse(Res,result);
}
/*int main(){
char fir[MAX],sec[MAX],res[MAX];
while(scanf("%s%s",&fir,&sec)==2){
call_sum(fir,sec,res);
int len=strlen(res);
for(int i=0;i<len;i++) printf("%c",res[i]);
printf("\n");
}
return 0;
}*/
/****************************************************************/
void call_sqrt(char *number,char *result,char *extra){
int num,start,e,mul,l,r=0,len;
char left[MAX],after[MAX];
char who[5],temp[MAX],two[5];
len=strlen(number);
if(len%2==0){
num=10*(number[0]-'0') + number[1]-'0';
start=2;
}
else{
num=number[0]-'0';
start=1;
}
mul=(int) sqrt(num);
result[0]=mul+'0';
result[1]='\0';
if(num-mul*mul ==0)
extra[0]='\0';
else
sprintf(extra,"%d",num-mul*mul);
for(;start<len;start+=2){
e=strlen(extra);
extra[e]=number[start];
extra[e+1]=number[start+1];
extra[e+2]='\0';
two[0]='2';
two[1]='\0';
call_mult(result,two,left);
l=strlen(left);
for(mul=9;mul>=0;mul--){
who[0]=mul+'0';
who[1]='\0';
strcat(left,who);
call_mult(left,who,after);
if(call_minus(extra,after,temp)==1){
result[++r]=mul+'0';
result[r+1]='\0';
strcpy(extra,temp);
break;
}
else
left[l]='\0';
}
}
result[++r]='\0';
}
int call_div(char *number,long div,char *result){
int len=strlen(number);
int now;
long extra;
char Res[MAX];
for(now=0,extra=0;now<len;now++){
extra=extra*10 + (number[now]-'0');
Res[now]=extra / div +'0';
extra%=div;
}
Res[now]='\0';
for(now=0;Res[now]=='0';now++);
strcpy(result, &Res[now]);
if(strlen(result)==0)
strcpy(result, "0");
return extra;
}
/******************************************************************/
int main(){
char fir[MAX],sec1[MAX],ex[MAX],res[MAX],res1[MAX],res2[MAX],res3[MAX],res4[MAX];
char ss[10];
ss[0]='1';ss[1]='\0';
freopen("A-small-attempt0.in","r",stdin);
freopen("A-small-attempt0.out","w",stdout);
   long n;
   scanf("%ld",&n);
   for(int i=1;i<=n;i++)
   {
    scanf("%s%s",fir,sec1);
    call_mult(fir,fir,res);
    call_minus1(res,fir,res1);
    call_mult(res1,"4",res);
    call_mult(sec1,"8",res2);
    if(strlen(res)>=strlen(res2))
    call_sum(res,res2,res1);
    else
    call_sum(res2,res,res1);
    call_sum(res1,ss,res);
   call_sqrt(res,res2,ex);
   call_mult(fir,"2",res1);
   call_minus1(res2,res1,res3);
   call_sum(res3,ss,res);
   call_div(res,4,res1);
printf("Case #%ld: ",i);
int len=strlen(res1);
for(int i=0;i<len;i++) printf("%c",res1[i]);
printf("\n");
}
return 0;
}
