import sys
def solveprob(i, file):
    frac = [int(x) for x in file.readline().split('/')]
    gen = 0
    if (frac[0] * 2**40)%frac[1] != 0:
        # print('impossible')
        return 'impossible'
    for z in range(1, 40):
        frac[0] = frac[0] * 2
        # print(frac)
        if frac[0] >= frac[1]:
            # print(z)
            return z
    # print('impossible')
    return "impossible"

def solve():
  file = open('A-large.in')
  out = open('AttemptLarge1', 'w')

  t = int(file.readline())

  for i in range(1, t+1):
    result = solveprob(i, file)
    out.write("Case #{0}: {1}\n".format(i, result))

solve()