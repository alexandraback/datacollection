#include<iostream>
#include<stdio.h>
#include<fstream>



using namespace std;
int main()
{
ifstream fin("B-small-attempt3.in");
ofstream fout("output.txt");
int t,x,y,i;
fin>>t;
for(int m=1;m<=t;m++)
{
fin>>x>>y;
fout<<"Case #"<<m<<": ";
if(x>0&&y>0)
{
for(i=1;i<=x;i++)
{
fout<<"WE";
}
for(i=1;i<=y;i++)
{
fout<<"SN";
}


}
else if(x==0 && y>0)
{
for(i=1;i<=y;i++)
{
fout<<"SN";
}

}

else if(x<0&&y>0)
{
for(i=1;i<=(-x);i++)
{
fout<<"EW";
}
for(i=1;i<=y;i++)
{
fout<<"SN";
}

}
else if(x<0 &&y==0)
{
for(i=1;i<=(-x);i++)
{
fout<<"EW";
}

}
else if(x<0&&y<0)
{
for(i=1;i<=(-x);i++)
{
fout<<"EW";
}
for(i=1;i<=(-y);i++)
{
fout<<"NS";
}

}
else if(x==0&&y<0)
{

for(i=1;i<=(-y);i++)
{
fout<<"NS";
}

}

else if(x>0&&y<0)
{
for(i=1;i<=x;i++)
{
fout<<"WE";
}
for(i=1;i<=(-y);i++)
{
fout<<"NS";
}


}
else if(y==0 && x>0)
{
for(i=1;i<=x;i++)
{
fout<<"WE";
}

}
fout<<"\n";






}
return 0;
}
