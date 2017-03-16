

def friends(s):
        return max([i-sum(s[:i]) for i in range(1, len(s)+1)]+[0])
                
        
def Next(M,s):
        # Whatever needs to be done
        #print s
        #s.sort(reverse=True)
        return friends(s)
        
####		

input = open(r'./A-small-attempt1.in')
#input = open(r'./A-large.in')
#input = open(r'./sample.in')

X = list(input)
C = int(X[0])
Y = [[j for j in x.split()] for x in X[1:]]
print Y

sol = []

N=2

j = 0

#C=10
for i in xrange(C):
	M, s = Y[i]
	M = int(M)
	s = [int(x) for x in s]
	sol += [Next(M,s)]
	#print 'case ', i, 'done'
	#if not i % 100: print 'case ', i+1, 'done'

tofile = True
if tofile:
        with open(r'./outputA.log', 'w') as output:
                for i in range(len(sol)):
                        output.write('Case #%s: %s\n' % (i+1, sol[i]))
else:
        print sol

	
	
	
	
	
	
	
	
	
	
