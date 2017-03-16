

def Test(X,R,C):
        if X==1:
                return 'G'
        if X==2:
                if (R*C) % 2:
                        return 'R'
                else:
                        return 'G'
        if X==3:
                if R*C % 3:
                        return 'R'
                elif R < 2 or C < 2:
                        return 'R'
                return 'G'
        if X==4:
                if max(R,C) < 4 or min(R,C) <= 2:
                        return 'R'
                else:
                        return 'G'
        
def Next(X,R,C):
        # Whatever needs to be done
        if Test(X,R,C) == 'G':
                return 'GABRIEL'
        else:
                return 'RICHARD'
        
####		

input = open(r'./D-small-attempt1.in')
#input = open(r'./D-large.in')
#input = open(r'./sample.in')

X = list(input)
T = int(X[0])
Y = [[int(j) for j in x.split()] for x in X[1:]]
#print Y

sol = []

N=2

j = 0

#C=10
for i in xrange(T):
	X, R, C = Y[i]
	sol += [Next(X,R,C)]
	#print 'case ', i, 'done'
	#if not i % 10: print 'case ', i+1, 'done'

tofile = True
if tofile:
        with open(r'./outputD.log', 'w') as output:
                for i in range(len(sol)):
                        output.write('Case #%s: %s\n' % (i+1, sol[i]))
else:
        print sol

	
	
	
	
	
	
	
	
	
	
