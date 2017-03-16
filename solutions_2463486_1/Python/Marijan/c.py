from math import factorial as f

i = [0]*5
N =26 
fsq = [0,2**2,3**2,10**102]
for i[0] in range(N):
	b = 1<<i[0]
	d = str(int(bin(b)[2:]))
	fsq.append(int(d+d[-2::-1])**2)
	fsq.append(int(d+d[-1::-1])**2)
for i[0] in range(1,N):
	for i[1] in range(i[0]):
		b = 0
		for j in range(2):
			b |= 1<<i[j]
		d = str(int(bin(b)[2:]))
		fsq.append(int(d+d[-2::-1])**2)
		fsq.append(int(d+d[-1::-1])**2)
for i[0] in range(2,N):
	for i[1] in range(1,i[0]):
		for i[2] in range(i[1]):
			b = 0
			for j in range(3):
				b |= 1<<i[j]
			d = str(int(bin(b)[2:]))
			fsq.append(int(d+d[-2::-1])**2)
			fsq.append(int(d+d[-1::-1])**2)
for i[0] in range(3,N):
	for i[1] in range(2,i[0]):
		for i[2] in range(1,i[1]):
			for i[3] in range(i[2]):
				b = 0
				for j in range(4):
					b |= 1<<i[j]
				d = str(int(bin(b)[2:]))
				fsq.append(int(d+d[-2::-1])**2)
				fsq.append(int(d+d[-1::-1])**2)
for i[0] in range(3,N-1):
	for i[1] in range(2,i[0]):
		for i[2] in range(1,i[1]):
			for i[3] in range(i[2]):
				b = 1
				for j in range(4):
					b |= 1<<(i[j]+1)
				d = str(int(bin(b)[2:]))
				fsq.append(int(d+d[-2::-1])**2)

# ovdje dolaze dvice
for i[0] in range(N):
	b = 1<<i[0]
	d = str(int(bin(b)[2:])<<1)
	fsq.append(int(d+d[-1::-1])**2)
for i[0] in range(N-1):
	b = 1<<i[0]
	d = str(int(bin(b)[2:])<<1)
	fsq.append(int(d+'0'+d[-1::-1])**2)
	fsq.append(int(d+'1'+d[-1::-1])**2)
for i[0] in range(N-1):
	b = 1<<i[0]
	d = str(int(bin(b)[2:]))
	fsq.append(int(d+'2'+d[-1::-1])**2)
for i[0] in range(1,N-1):
	for i[1] in range(i[0]):
		b = 0
		for j in range(2):
			b |= 1<<i[j]
		d = str(int(bin(b)[2:]))
		fsq.append(int(d+'2'+d[-1::-1])**2)
fsq.sort()

T=int(input())
for x in range(1,T+1):
	A, B = (int(i) for i in input().split())
	a = next(i for i in range(len(fsq)) if fsq[i] >= A)
	b =	next(i for i in range(len(fsq)) if B<fsq[i]) 
	print("Case #%d:"%x,b-a)
