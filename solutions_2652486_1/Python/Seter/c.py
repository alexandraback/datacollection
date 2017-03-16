import random
def run():
	a=[int(i) for i in raw_input().split()]
	v=[0]*10
	for i in a:
		for j in range(2,9):
			x=i
			if x%j==0 and (x/j)%j!=0:v[j]+=10
			while x%j==0:
				v[j]+=1
				x/=j
	
	v[2]*=3
	v[4]*=2
	v[6]*=2
	v[3]*=3
	v[7]*=3
	v[5]*=3
	ans=""
	for i in range(2,9):
		v[i]+=v[i-1]
	for i in range(0,12):
		x=random.randint(1,v[8])
		for j in range(7,0,-1):
			if x>=v[j]:
				ans+=str(j+1)
				break
	print ans

raw_input()
print "Case #1:"
t=int(raw_input().split()[0])
while t:
	t-=1
	run()

