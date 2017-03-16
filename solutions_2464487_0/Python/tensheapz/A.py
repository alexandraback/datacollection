
fn = 'A-small-attempt0'
input = open(fn+'.in','r')
output = open(fn+'.out', 'w')

def solve(case):
    r, t = [int(n) for n in input.readline().split()]

    reqPaint = 2 * r + 1
    numRings = 0
    while t >= reqPaint:
        numRings += 1
        t -= reqPaint

        r += 2
        reqPaint = 2 * r + 1

    print('Case #{0}: {1}'.format(case, numRings), file=output)

T = int(input.readline())
for i in range(1,T+1):
    solve(i)