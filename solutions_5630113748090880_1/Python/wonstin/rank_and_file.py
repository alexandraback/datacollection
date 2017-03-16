import string
from collections import defaultdict

def solve(N):
    counts = defaultdict(int)

    for i in range(2*N - 1):
        nums = map(int, string.strip(raw_input()).split())
        for num in nums:
            counts[num] += 1
    #for i in range(2*N-1):
    #    nums = map(int,string.strip(raw_input()).split())
    #    for num in nums:
    #        counts[num] += 1

    missing = sorted([num for (num, count) in counts.iteritems() if count % 2 == 1])
    return " ".join(map(str, missing))

def test(inputs, ans):
	b = solve(*inputs)
	if (b != ans):
		print "Failed test! Inputs {} should give answer of {} not {}".format(' '.join(inputs), ans, b)

def main():

    outfile = open('a.out','w')
    T = int(string.strip(raw_input()))    

    for k in xrange(1,T+1):
        print k
        N = map(int,string.strip(raw_input()).split())[0]

        answer = solve(N) # add appropriate arguments
        outfile.write('Case #%d: %s\n' % (k,answer))

if __name__ == '__main__':
    main()