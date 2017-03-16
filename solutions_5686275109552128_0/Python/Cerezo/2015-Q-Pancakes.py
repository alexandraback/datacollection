

def Time(s):
        maxi = s[0]
        t = maxi
        for i in range(maxi-1): #may stop earlier if too many bigger than something
                top = s[0]
                for x in range(2, top-1):
                        s[0] = top - x
                        s.append(x)
                        s.sort(reverse=True)
                        tnew = s[0] + 1+i
                        if tnew < t:
                                t = tnew
        return t

def aTime(s):
        s.sort(reverse=True)
        if s[0] <= 2:
                return s[0]
        #some small cases, annoying
        elif len(s) > 1 and s[0] <= 4 and s[1] == 3:
                return s[0]
        elif len(s) > 2 and s[0] <= 5 and s[2] == 4:
                return s[0]
        elif len(s) > 2 and s[0] <= 6 and s[2] == 5:
                return s[0]
        elif len(s) > 3 and s[0] <= 7 and s[2] == 6:
                return s[0]
        #elif len(s) > 3 and s[3] == 7: return 7
        time = s[0]
        for x in range(2, s[0]-1):
                t = s[:]
                t[0] -= x
                t.append(x)
                tnew = aTime(t)+1
                if tnew < time:
                        time=tnew
        return time
                
        
def Next(s, D):
        # Whatever needs to be done
        #print s
        #s.sort(reverse=True)
        return aTime(s)
        
####		

input = open(r'./B-small-attempt1.in')
#input = open(r'./B-large.in')
#input = open(r'./sample.in')

X = list(input)
C = int(X[0])
Y = [[int(j) for j in x.split()] for x in X[1:]]
#print Y

sol = []

N=2

j = 0

#C=10
for i in xrange(C):
	D = Y[2*i]
	s= Y[2*i+1]
	sol += [Next(s, D)]
	print 'case ', i, 'done'
	#if not i % 100: print 'case ', i+1, 'done'

tofile = True
if tofile:
        with open(r'./outputB.log', 'w') as output:
                for i in range(len(sol)):
                        output.write('Case #%s: %s\n' % (i+1, sol[i]))
else:
        print sol

	
	
	
	
	
	
	
	
	
	
