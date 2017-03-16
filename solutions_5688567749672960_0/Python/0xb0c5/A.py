n_cases = input()

max = 10**6+1

solutions = [0]

def reverse(n):
    return int(str(n)[::-1])

for n in range(1,max):
    r = reverse(n)
    if n%10 and r < n:
        solutions.append(min(solutions[n-1]+1,solutions[r]+1))
    else:
        solutions.append(solutions[n-1]+1)

for i in range(1, n_cases+1):
    n = input()
    print "Case #%d: %d" % (i, solutions[n])
    
    
