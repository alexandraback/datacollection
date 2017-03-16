//gskhirtladze

#include <iostream>
#include <stdio.h>

using namespace std;

int nish(char a)
 {
  if (a == '0' || a == 'J' || a == 'I' || a == 'K') return -1;
  if (a == '1' || a == 'j' || a == 'i' || a == 'k') return 1;
 }

char norm(char a)
 {
  if (a == '0') return '1';
  if (a == 'I') return 'i';
  if (a == 'J') return 'j';
  if (a == 'K') return 'k';
  return a;
 }

char chan(char a)
 {
  if (a == '0') return '1';
  if (a == '1') return '0';
  if (a == 'I') return 'i';
  if (a == 'i') return 'I';
  if (a == 'J') return 'j';
  if (a == 'j') return 'J';
  if (a == 'K') return 'k';
  if (a == 'k') return 'K';
 }

char nam(char a,char b)
 {
  int num=nish(a)*nish(b);
  a=norm(a); b=norm(b);
  char c;
  if (a == '1') c=b; else
  if (b == '1') c=a; else
  if (a == b) c='0'; else
  if (a == 'i' && b == 'j') c='k'; else
  if (a == 'i' && b == 'k') c='J'; else
  if (a == 'j' && b == 'i') c='K'; else
  if (a == 'j' && b == 'k') c='i'; else
  if (a == 'k' && b == 'i') c='j'; else
  if (a == 'k' && b == 'j') c='I';
  if (num == -1) c=chan(c);
  return c;
 }

char pow(char a,long long k)
 {
  if (k == 0) return '1';
  char d=pow(a,k/2);
  d=nam(d,d);
  if (k%2) d=nam(d,a);
  return d;
 }

int t,t1;
char num[120200],numr[120200];
string s,q,ans;
int n,i,l,m;
long long k,K;

main()
 {
    freopen("3.in","r",stdin);
 freopen("33.out","w",stdout);

  cin>>t1;
  for (t=1;t<=t1;t++)
   {
    cin>>n>>k>>q; s="";  K=k;k=min(k,12LL); m=n;
    for (i=1;i<=k;i++) s+=q; n=s.size();
    num[0]='1';
    for (i=0;i<n;i++)
     num[i+1]=nam(num[i],s[i]);
    numr[n+1]='1';
    for (i=n-1;i>=0;i--)
     numr[i+1]=nam(s[i],numr[i+2]);

    if (nam(nam('i','j'),'k') != pow(num[m],K))
        { ans="NO"; goto pr; }
    for (i=1;i<=n;i++)
     if (num[i] == 'i') break;
    l=i;
    for (i=n;i>=1;i--)
     if (numr[i] == 'k') break;
    if (l < i) ans="YES"; else ans="NO";

    pr: { cout<<"Case #"<<t<<": "<<ans<<endl; }
   }
 }
