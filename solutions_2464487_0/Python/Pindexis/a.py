import time
import sys
import pdb

infile = open("ainput.txt")
outfile = open("aoutput.txt", 'w')

timeit = 1
debugv = 1

def main():
        T = int(infile.readline())
        for case in range(1,T+1):
            doCase(case)
            


def solve(r,t):
    i = r+1
    n = 0
    while True:
        s = i**2 - (i-1)**2
        if s <= t:
            t = t - s
            n += 1
            i = i + 2
        else:
            return n
        
def doCase(case):
    N, K = map(int, infile.readline().strip().split())
    result = solve(N,K)
    debug("{}\n".format(result))
    outfile.write("Case #{}: {}\n".format(case, result))
    

def debug(m):
    if debugv:
        sys.stdout.write(m)

		
if __name__ == '__main__':  
    startTime = time.clock()
    main()
    if timeit:
        sys.stdout.write("Completed in {} seconds.\n".format(time.clock() - startTime))
    outfile.close()
