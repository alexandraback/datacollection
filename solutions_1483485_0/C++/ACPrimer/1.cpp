/*#include <stdio.h>
char s[1000024];
char map[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int main()
{
	int i;
	FILE *fin=fopen("A-small-attempt0.in","r");
	FILE *fout=fopen("a.txt","w+");
	int T;
	fscanf(fin,"%d",&T);
	fgets(s,10,fin);
	while(T--)
	{
		fgets(s,1024,fin);
		for(i=0;s[i];i++) s[i]=map[s[i]-'a'];
		fputs(s,fout);
	}
	return 0;
}*/
#include <stdio.h>
#include <string.h>
char s[1000024];
char map[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int main()
{
	int i,ncase=0;
	FILE *fin=fopen("A-small-attempt0.in","r");
	FILE *fout=fopen("a.txt","w+");
	int T;
	scanf("%d",&T);
	gets(s);
	while(T--)
	{
		gets(s);
		fprintf(fout,"Case #%d: ",++ncase);
		for(i=0;i<strlen(s);i++) if(s[i]!=' ')
			s[i]=map[s[i]-'a'];
		fprintf(fout,"%s\n",s);
	}
	return 0;
}
/*
3
ejp mysljylc kd kxveddknmc re jsicpdrysi
our language is impossible to understand
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
there are twenty six factorial possibilities
de kr kd eoya kw aej tysr re ujdr lkgc jv
so it is okay if you want to just give up
y,h,e,s,o,c,v,x,d,u,i,g,l,b,k,r,z,t,n,w,j,p,f,m,a,q,
Press any key to continue
30
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
hello i am the google code jam test data
how are you
aynny iynny aynny iynny aynny iynny aynny iynny aynny iynny aynny iynny aynny iynny aynny ieeeeeeeee
y n f i c w l b k u o m x s e v z p d r j g a t h a q set k oset xa ynfd
schr rkxc tesr aej dksl tkrb xc
njww rpasiyxcpc ysi yxjxj
aej oset aej tysr re
aej tysr dcmm rbksld yr xc neksl qeeex
tbeeeeeeeeeeeeeeeeeeeyyyyyyyyy k oset f vmjd vmjd
set rbyr aej oset leelmcpcdc vmcydc ie ser jdc kr re byfo ksre ejp dadrcxd
eb byk kx ks jp fexvjrcp cyrksl aejp fbccqnjplcpd ysi leelmcpcdksl aejp rchrq
cyfb ew jd byd bkd ets dvcfkym lkwr ysi aej oset rbkd tyd xcysr re nc rpjc
ysi kw aej iesr jsicpcdrkxyrc xc k tesr jsicpcdrkxyrc aej
ymm aejp nydc ypc ncmesl re cppep rbc dveesa nypi
rbyso aej njr rbc pcym leelmcpcdc kd ks yserbcp fydrmc
wep rbedc tbe dvcyo ks y resljc ie ser dvcyo re erbcp vcevmc
seneia jsicpdrysid rbcx dksfc rbca ypc dvcyoksl xadrcpkcd ks rbc dvkpkr
tba ie vpelpyxxcpd ymtyad xkh jv bymmetccs ysi fbpkdrxyd
mcr mkvd ie tbyr bysid ie
rpysdmyrksl rchr kd ser leped drpcslrb
drpcslrb kd leped drpcslrb
set kd rbc djxxcp ew ejp myfo ew ikdfesrcsr
wpkcsid iesr mcr wpkcsid mcr dfkcsrkwkf vpelpcdd le nekso
kr tyd rbc ncdr ew rkxcd kr tyd rbc nmjpdr ew rkxcd
ejp feic uyx kd mkoc rbc varbylepcys rbcepcx
rbcpc kd se ysdtcp
bet ypc aej bemiksl jv ncfyjdc kx y veryre


*/