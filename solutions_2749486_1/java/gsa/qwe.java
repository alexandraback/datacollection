import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
public class qwe{
public static void main(String [] s) throws FileNotFoundException
	{ 
File f = new File("file.txt");
Scanner f1= new Scanner(f);

int n = f1.nextInt();


for(int i = 1;i<=n;++i)
	
{
	int n1 = f1.nextInt();
	
	
	int n2 = f1.nextInt();
	
	System.out.println("Case #"+i+": "+eval(n1,n2,0));

}
}

static String eval(int x,int y,int n ){
	
String s = "";

if(Math.abs(x)<Math.abs(y)){
	
	int len = 0;
	int sum = 0;
	for(int i = 1;;++i)
	{
		sum =sum+i;
		if(sum>Math.abs(x)){sum =sum -i;break;} else{if(x<0){s =s +"W";len++;} else {s =s +"E";len++;}}
		
		
	}

	int g = Math.abs(x)-sum;
while(g!=0)
{
int h = (int)Math.sqrt(g);	
for(int i = 1;i<=h;++i){
if(x<0){s =s +"E";len++;}	else{s =s +"W";len++;}
	
}

for(int i = 1;i<=h;++i){
if(x<0){s =s +"W";len++;}	else{s =s +"E";len++;}
	
}
	g = g-h*h;
	}

sum = 0;
for(int i = 1;;++i)
{
	sum =sum+i+len;
	if(sum>Math.abs(y)){sum =sum -i-len;break;} else{if(y<0){s =s +"S";} else {s =s +"N";}}
	
	
}

g = Math.abs(y)-sum;
while(g!=0)
{
int h = (int)Math.sqrt(g);	
for(int i = 1;i<=h;++i){
if(y<0){s =s +"N";}	else{s =s +"S";len++;}

}

for(int i = 1;i<=h;++i){
if(y<0){s =s +"S";}	else{s =s +"N";}

}
g = g-h*h;
}




}
	

if(Math.abs(y)<=Math.abs(x)){
	
	int len = 0;
	int sum = 0;
	for(int i = 1;;++i)
	{
		sum =sum+i;
		if(sum>Math.abs(y)){sum =sum -i;break;} else{if(y<0){s =s +"W";len++;} else {s =s +"E";len++;}}
		
		
	}

	int g = Math.abs(y)-sum;
while(g!=0)
{
int h = (int)Math.sqrt(g);	
for(int i = 1;i<=h;++i){
if(y<0){s =s +"E";len++;}	else{s =s +"W";len++;}
	
}

for(int i = 1;i<=h;++i){
if(y<0){s =s +"W";len++;}	else{s =s +"E";len++;}
	
}
	g = g-h*h;
	}

sum = 0;
for(int i = 1;;++i)
{
	sum =sum+i+len;
	if(sum>Math.abs(x)){sum =sum -i-len;break;} else{if(x<0){s =s +"S";} else {s =s +"N";}}
	
	
}

g = Math.abs(x)-sum;
while(g!=0)
{
int h = (int)Math.sqrt(g);	
for(int i = 1;i<=h;++i){
if(x<0){s =s +"N";}	else{s =s +"S";len++;}

}

for(int i = 1;i<=h;++i){
if(x<0){s =s +"S";}	else{s =s +"N";}

}
g = g-h*h;
}




}


	

 
 

return s;	
	}





}