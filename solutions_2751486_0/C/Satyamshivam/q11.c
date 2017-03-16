#include<stdio.h>
#include<string.h>
main()
{
	freopen("in.in", "r", stdin);
	freopen("output.txt", "w", stdout);
    int count,i=0,numlen=0,counter=0,counter1=1,nvalue=0,j=0,n=0;
    char name[150];
    scanf("%d",&count);
    while(i<count)
    {
        scanf("%s %d",&name,&n);
        numlen=strlen(name);
        for(j=0;j<numlen;j++)
        {
            if(name[j]!='a'&&name[j]!='e'&&name[j]!='i'&&name[j]!='o'&&name[j]!='u')
            {            counter++;}
            else{
                        counter=0;
                        counter1++;}
            if(counter==n)
            {
			if(nvalue==0)
			{
                        nvalue=nvalue+(counter1*(numlen-n));
                        counter1=j;
                        counter=0;
			}
			else
			{
				nvalue=nvalue+(counter1*(j-n+1));
                        counter1=j;
                        counter=0;	
			}
                        }
        }
        printf("Case #%d: %d\n",i+1,nvalue+1);
        numlen=0;
        counter=0;
        counter1=1;
        nvalue=0;
        j=0;
	i++;
    }
    return 0;
}

