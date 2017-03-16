fin=open("C:/users/Clement/Desktop/bla.txt","r")
fout=open("C:/users/Clement/Desktop/output.txt","w")
import sys

sys.setrecursionlimit=100000

def min(a,b):
	if a<b:return a
	else:return b

def test(a,t,u):
	if t[len(t)-1]<4:return(u+t[len(t)-1])
	if a==2:
		x=t.pop()
		y=x//2
		t.append(y)
		t.append(y+(x%2))
		t=sorted(t)
		u+=1
	if a==3:
		x=t.pop()
		y=x//3
		t.append(y)
		if (x%3)==0:
			t.append(y)
			t.append(y)
		if (x%3)==1:
			t.append(y)
			t.append(y+1)
		if (x%3)==2:
			t.append(y+1)
			t.append(y+1)
		u+=2
		t=sorted(t)
	t1=list(t)
	return(min(u+t[len(t)-1],min(test(2,t,u),test(3,t1,u))))
	return(min(u+t[len(t)-1],min(test(2,t,u),test(3,t1,u))))

s=fin.read().split("\n")
n=int(s[0])
for i in range(1,n+1):
	n=int(s[2*i-1])
	t=list(map(int,s[2*i].split(" ")))
	t=sorted(t)
	v=t[len(t)-1]
	t1=list(t)
	v=min(v,test(2,t,0))
	v=min(v,test(3,t1,0))
	fout.write("Case #"+str(i)+": "+str(v)+"\n")
	print(v)