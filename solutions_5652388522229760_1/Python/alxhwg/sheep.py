import sys
import string
import random

def main():
    # f = open("test.txt", 'w')
    # test = random.sample(range(1000000), 100)
    # for i in test:
    #     n = bruteSolve(i)
    #     if n == None:
    #         n = "INSOMNIA"
    #     f.write("Case #{0}: {1}\n".format(i, n))
    # f.close
    inF = open(sys.argv[1], 'r')
    name = string.split(sys.argv[1], '.', 1)[0]
    ouF = open("{0}.out".format(name), 'w')
    T = int(inF.readline())
    for i in range(T):
        N = int(inF.readline())
        k = bruteSolve(N)
        if k == None:
            k = "INSOMNIA"
        ouF.write("Case #{0}: {1}\n".format(i+1, k))
    inF.close()
    ouF.close()

def bruteSolve(N):
    if N == 0:
        return None
    last = 0
    seen = set()
    while len(seen) < 10:
        last += N
        for n in str(last):
            seen.add(n)
    return last


if __name__ == '__main__':
  main()
