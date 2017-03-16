#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("myfile.txt","w",stdout);
	int line;
	char harf[100];
	int nice[5]={1,4,9,121,484};
	int puan=0;
	int yer,i,j,k,sayim,uzunluk;
	int gostergec=0;
	int gostergec2=0;
	scanf("%d", &line);
	int sonuc=0;
	for(j=0;line>j;j++)
		{
			scanf("%s", harf);
			scanf("%d", &sayim);
			for(i=0;harf[i];i++);
				uzunluk=i;
			for(i=0;i<uzunluk;i++)
			{
				if(harf[i]=='a'||harf[i]=='e'||harf[i]=='i'||harf[i]=='u'||harf[i]=='o')
					puan=0;
				else puan++;
				if(puan==sayim)
				{
					gostergec2=gostergec;
					gostergec=i-sayim+2;
					sonuc+=	(gostergec-gostergec2)*(uzunluk-i);			
					i=gostergec-1;
					puan=0;
				}				
			}
			cout<<"Case #"<<j+1<<": ";
			printf("%d", sonuc);
			if((j+1)!=line)
			cout<<endl;
			gostergec=0;
			gostergec2=0;
			sonuc=0;
			puan=0;
		}
return 0;
}
