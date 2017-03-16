from freq import *
def readline():
    return [int(x) for x in raw_input().split(' ')]
def prod(l):
    m=1
    for i in l:m*=i
    return m
readline()
r,n,m,k=readline()
print "Case #1:"


def facs(a, b):
	i=0
	while a%b==0:
		i+=1
		a/=b
	return i

def maxi(l):
    m=l[0]
    mi=0
    for i in range(len(l)):
        if l[i]>m:
            mi=i
            m=l[i]
    return mi
	
for _ in range(r):
	given = readline()
	prob2 = [1.0]*len(xs2)
	prob3 = [1.0]*len(xs3)
	prob5 = [1.0]*len(xs5)
	prob7 = [1.0]*len(xs7)
	
	
	for k in given:
		fac2,fac3,fac5,fac7 = [facs(k,i) for i in [2,3,5,7]]
		for i in range(len(prob2)):
			prob2[i] *= kxs2[i][fac2] if fac2 in kxs2[i] else 0
			prob2[i] *= ks2[fac2] if fac2 in ks2 else 0
		for i in range(len(prob3)):
			prob3[i] *= kxs3[i][fac3] if fac3 in kxs3[i] else 0
			prob3[i] *= ks3[fac3] if fac3 in ks3 else 0
		for i in range(len(prob5)):
			prob5[i] *= kxs5[i][fac5] if fac5 in kxs5[i] else 0
			prob5[i] *= ks5[fac5] if fac5 in ks5 else 0
		for i in range(len(prob7)):
			prob7[i] *= kxs7[i][fac7] if fac7 in kxs7[i] else 0
			prob7[i] *= ks7[fac7] if fac7 in ks7 else 0
	g2 = xs2[maxi(prob2)]
	g3 = xs3[maxi(prob3)]
	g5 = xs5[maxi(prob5)]
	g7 = xs7[maxi(prob7)]
	
	res = ''
	res += ''.join('5' for x in g5 if x == '1')
	res += ''.join('7' for x in g7 if x == '1')
	t3 = [3 for x in g3 if x=='1']
	t2 = [({'1':2,'2':4,'3':8})[x] for x in g2 if x!='0']
	if len(res)+len(t3)+len(t2) == 12:
		res += ''.join(str(x) for x in t2)
		res += ''.join(str(x) for x in t3)
	elif len(res)+len(t3)+len(t2) < 12:
		res += ''.join(str(x) for x in t2)
		res += ''.join(str(x) for x in t3)
		while len(res)<12: res+='2'
	else:
		over = len(res)+len(t3)+len(t2) - 12
		if over <= len([x for x in t3 if x==3]) and over <= len([x for x in t2 if x==2]):
			for _ in range(over):
				t3.remove(3)
				t2.remove(2)
			res += ''.join(str(x) for x in t2)
			res += ''.join(str(x) for x in t3)
			res += '6'*over
		else:
			res += ''.join(str(x) for x in t2)
			res += ''.join(str(x) for x in t3)
			res = res[:12]
	
	print res

				
				
				