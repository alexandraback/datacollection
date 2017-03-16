
def solve(n,r,c):
	if n==1:
		return True
	elif n==2:
		return not(r%2==1 and c%2==1)
	elif n==3:
		return (r,c) in [(2,3),(3,2),(3,3),(3,4),(4,3)]
	elif n==4:
		return (r,c) in [(3,4),(4,3),(4,4)]

T = int(raw_input())

for casno in range(T):
	n,r,c = [int(x) for x in raw_input().split()]
	print 'Case #%d: %s' %(casno+1, 'GABRIEL' if solve(n,r,c) else 'RICHARD')