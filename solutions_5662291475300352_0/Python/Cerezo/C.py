                
        
def Next(s, N):
        # Whatever needs to be done
        # primitive case: two hikers
        if N == 2:
                D = [s[0][0], s[1][0]]
                M = [s[0][2], s[1][2]]
        elif N == 1:
                D = [s[0][0], s[0][0]]
                M = [s[0][2], s[0][2]+1]
        else:
                return 'error'
        arrivals = [M[i]*(360.0-D[i])/360.0 for i in range(len(M))]
        returns = [arrivals[i]+M[i] for i in range(len(M))]
        print arrivals, returns
        if max(arrivals) < min(returns):
                return 0
        else:
                return 1
        
        
####		

input = open(r'./C-small-1-attempt0.in')
#input = open(r'./C-large.in')
#input = open(r'./sample.in')

X = list(input)
C = int(X[0])
Y = [[int(j) for j in x.split()] for x in X[1:]]
#print Y

sol = []



j = 0
i= 0

#C=10
while i < C:
	D = Y[j][0]
	s= Y[j+1:j+D+1]
	j += D+1
	i += 1
	sol += [Next(s, D)]
	#print D, s
	print 'case ', i, 'done'
	#if not i % 100: print 'case ', i+1, 'done'

tofile = True
if tofile:
        with open(r'./outputC.txt', 'w') as output:
                for i in range(len(sol)):
                        output.write('Case #%s: %s\n' % (i+1, sol[i]))
else:
        print sol

	
	
