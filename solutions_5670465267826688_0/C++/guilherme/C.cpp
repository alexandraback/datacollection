#include<cstdio>


struct  quater
{
  char value;
  bool neg;
  quater()
  {
    value = '1';
    neg = false;
  }
  quater (char v, bool n)
  {
    value = v;
    neg = n;
  }
  quater operator * (const quater q)
  {
    char v='1';
    bool t=false;
    if (value == '1')  v=q.value;
    if (value == 'i') {
      if (q.value == '1')v = 'i';
      if (q.value == 'i'){v = '1';t=true;}
      if (q.value == 'j')v = 'k';
      if (q.value == 'k'){v = 'j';t=true;}
    }
    if (value == 'j') {
      if (q.value == '1')v = 'j';
      if (q.value == 'i'){v = 'k';t=true;}
      if (q.value == 'j'){v = '1';t=true;}
      if (q.value == 'k'){v = 'i';}
    }
    if (value == 'k') {
      if (q.value == '1')v = 'k';
      if (q.value == 'i')v = 'j';
      if (q.value == 'j'){v = 'i';t=true;}
      if (q.value == 'k'){v = '1';t=true;}
    }
    return quater(v, (neg^t)^q.neg);
  }
  
  bool operator == (const quater q)
  {
    return value==q.value && neg == q.neg;
  }

  void print ()
  {
    printf("<%s%c>",neg?"-":"",value);
  }
};


char ent[99999];
quater conv[99999];
quater inv[99999];
int main (){
  int tt;
  scanf("%d",&tt);
  for(int rr=1;rr<=tt;rr++){
    int n,m;
    scanf("%d %d",&n,&m);
    scanf(" %s",ent);
    for(int i=0;i<n;i++){
      conv[i]=quater(ent[i],false);
    }

    //small
    for(int i=n;i<n*m;i++){
      ent[i]=ent[i%n];
      conv[i]=conv[i%n];
    }
    inv[n*m] = quater();
    for(int i=n*m-1;i>=0;i--)inv[i]=conv[i]*inv[i+1];
    bool ok = false;

    quater q;
    for(int i=0;!ok && i<n*m;i++){
      q = q*conv[i];
      if (q == quater('i',false)){
	quater r;
	for (int j=i+1;!ok && j<n*m;j++){
	  r = r*conv[j];
	  if (r==quater('j',false)) {
	    if(inv[j+1]==quater('k',false))ok=true;
	  }
	  
	}
      }
    }
    printf("Case #%d: %s\n",rr,ok?"YES":"NO");
  }
  return 0;
}
