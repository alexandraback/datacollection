
fn = 'B-small-attempt0'
input = open(fn+'.in','r')
output = open(fn+'.out', 'w')

#Vars that don't change during a single case solvingness
maxE = None
R = None
Vs = None

def solve(case):
    global maxE, R, Vs

    E, R, N = [int(n) for n in input.readline().split()]
    Vs = [int(n) for n in input.readline().split()]

    maxE = E
    #Firstly cap R to E, to remove that corner case
    if R > E:
        R = E

    print('Case #{0}: {1}'.format(case, calcValue(E, 0)), file=output)

#Return max value recursive, considering how much to allocate to the ith activity
def calcValue(curE, i):
    #base case
    if i >= len(Vs) - 1:
        return curE * Vs[i]
    else:
        #Try spending from maxE down to the level at which R would overflow our E
        best = 0
        minSpend = max(0, curE+R-maxE)
        for spend in range(minSpend, curE+1):
            value = spend*Vs[i] + calcValue(curE-spend+R, i+1)
            if value > best:
                best = value

        return best

T = int(input.readline())
for i in range(1,T+1):
    solve(i)