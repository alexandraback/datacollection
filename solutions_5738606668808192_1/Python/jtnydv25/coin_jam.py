'''

if # of 1's is divisible by 6, then number is:
divisible by 2 in Base 3
divisible by 3 in Base 4
divisible by 2 in Base 5
divisible by 2 in Base 7
divisible by 2 in Base 9
divisible by 3 in Base 10
Now we have th check for bases 2,6,8.
Note that if # of 1s at odd position = # of 1s at even position, then the number is:
divisible by 3 in Base 2
divisible by 7 in Base 6
divisible by 3 in Base 8

Hence, we choose numbers with 6 1s, and # of 1s at odd = # of 1s at even.
In our case, there is 1 at beginning and end, and N is even. So, we have to choose 2
even positions and two odd positions from N-2 positions in between

'''

_divs = [0,0,3,2,3,2,7,2,3,2,3]
_str = "3 2 3 2 7 2 3 2 3"
def _numbers(J,N):
	A=[1]
	S = "1"
	for i in range(0,N-2):
		S+="0"
		A.append(0)
	S+="1"
	A.append(1)
	cnt  = 0
	for i in range(1,N-1,2):
		for j in range(i+2,N-1,2):
			for k in range(2,N-1,2):
				for l in range(k+2,N-1,2):
					S1="1"
					num1 = 1
					for y in range(1, N-1):
						x= 0
						if y==i or y==j or y==k or y==l:
							x = 1
						num1<<=1
						num1+=x
						S1+=str(x)
					S1+="1"		
					num1=2*num1+1
					assert(num1%3 == 0)
					f.write(S1 + " "+ _str+ "\n")
					cnt +=1
					if cnt == J:
						return 
f = open('out.txt','w')						
g = open('inp.txt','r')
t = int(g.readline())
for tt in range(1,t+1):
	n, j = map(int,g.readline().split())
	f.write("Case #"+str(tt)+":\n")
	_numbers(j,n)

