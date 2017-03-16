'''
Greedy Algorithm:
S := set of all levels
-if S is empty, return
-S2 <- set of levels in which you can get 2 stars currently
	do all those levels
	#stars += 2*|S2|
	recurse
-if S2 is empty, then S1 <- set of levels in which you can get 1 star currently
	pick the level with the maximum 2 star req'm
	#stars += 1
	recurse
-if S1 is empty,
	"Too Bad"


-first pick the level with minimum 2 start rating /if/ it is below # of stars you have
	recurse
-if none exists of the levels in which you have enough stars to get the pick the level with 
'''

from itertools import izip
argmin = lambda array: min(izip(array, xrange(len(array))))[1]

###########################################################
# function defs
###########################################################


###########################################################
# input
###########################################################

input_file = 'B-small-attempt2.in.txt'
#input_file = 'B-large.in.txt'
input_data = open(input_file,'r').readlines()

###########################################################
# cases
###########################################################

output = ''
num_cases = int(input_data[0])
i = 1
for n in xrange(num_cases):
	L = int(input_data[i])
	i+=1
	a=[]
	b=[]
	for j in range(L):
		a.append(int(input_data[i].split()[0]))
		b.append(int(input_data[i].split()[1]))
		i += 1
	
	min_l = 0 #number of levels to complete
	num_s = 0 #number of stars currently
	not_too_bad = True
	infinity = 2*L+1
	while a and not_too_bad:
		if min(b) <= num_s:
			min_l+=1
			rm=argmin(b)
			num_s+=1+(a[rm] < infinity)
			print "Do level %d for %d stars"%(rm,1+(a[rm] < infinity))
			a=a[:rm]+a[rm+1:]
			b=b[:rm]+b[rm+1:]
		elif min(a) <= num_s:
			#find all level with that min
			ai = []
			m = min(a)
			for j in range(len(a)):
				if a[j] == m:
					ai.append(j)
			#find level with maximum 2-star rating
			maxb = -1
			maxbi = -1
			for j in ai:
				if b[j] > maxb:
					maxb = b[j]
					maxbi = j
			min_l+=1
			num_s+=1
			a[maxbi] = infinity 
			print "Do level %d for 1 star"%maxbi
			print a, b
		else:
			not_too_bad=False
	
	if not_too_bad:
		output += 'Case #%d: %d\n'%(n+1,min_l)
	else:
		output += 'Case #%d: Too Bad\n'%(n+1)
	
	print '\n\n'

###########################################################
# output
###########################################################

outfile = open('output_small.txt','w')
#outfile = open('output_large.txt','w')
outfile.write(output)
outfile.close()