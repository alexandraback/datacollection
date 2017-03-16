import sys
import collections

#in_file = "B-sample"
in_file = "B-large"
sys.stdin = open(in_file+".in")
sys.stdout = open(in_file+".out","w")

pow10 = [1]
for i in range(25): pow10.append(pow10[-1]*10)

def addp(p,i,j,tup): return (tup[0]+p*(i-j), tup[1]+p*i, tup[2]+p*j)
def mymin(a,b): return a if abs(a[0])<abs(b[0]) or (abs(a[0])==abs(b[0]) and a[1:]<b[1:]) else b

def dp(lo,s):
	if lo==len(C):
		return (0,0,0)
	if (lo,s) in m: return m[(lo,s)]
	p = pow10[len(C)-1-lo]
	i = int(C[lo]) if C[lo]!='?' else '?'
	j = int(J[lo]) if J[lo]!='?' else '?'
	if i=='?' or j=='?':
		if s==0:
			if i!='?':
				ans = addp(p,i,i,dp(lo+1,0))
				if i>0: ans = mymin(ans, addp(p,i,i-1,dp(lo+1,-1)) )
				if i<9: ans = mymin(ans, addp(p,i,i+1,dp(lo+1,+1)) )
			elif j!='?':
				ans = addp(p,j,j,dp(lo+1,0))
				if j<9: ans = mymin(ans, addp(p,j+1,j,dp(lo+1,-1)) )
				if j>0: ans = mymin(ans, addp(p,j-1,j,dp(lo+1,+1)) )
			else:
				ans = addp(p,0,0,dp(lo+1,0))
				ans = mymin(ans, addp(p,1,0,dp(lo+1,-1)) )
				ans = mymin(ans, addp(p,0,1,dp(lo+1,+1)) )
		else:
			if s==+1:
				if i=='?': i=9
				if j=='?': j=0
			elif s==-1:
				if i=='?': i=0
				if j=='?': j=9
			ans = addp(p,i,j, dp(lo+1,s))
	elif s==0:
		if i==j:
			ans = addp(p,i,j, dp(lo+1,s))
		elif i>j:
			ans = addp(p,i,j, dp(lo+1,-1))
		elif i<j:
			ans = addp(p,i,j, dp(lo+1,+1))
	else:
		ans = addp(p,i,j, dp(lo+1,s))
	m[(lo,s)]=ans
	return ans

ntc = int(input())

for tc in range(ntc):
	C,J = input().split()
	m = dict()
	ans = dp(0,0)
	#print(C,J)
	#print(ans)
	fmt = '%0{}d'.format(len(C))
	print('Case #%d: '%(tc+1) + fmt%(ans[1]) + ' ' + fmt%(ans[2]))
	ans = dp(1,0)
