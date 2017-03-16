import ju, math

results = [""]
FILE = "C-test-large"
f = ju.jopen(FILE)

T = int(f.readline())
for t in range(T):
    N,J = map(int,f.readline().split())
    print N,J
    jCount = 0
    for j in xrange(2**(N-1)+1,2**N-1,2):
        divisors = []
        print "====", j, "===="
        for b in range(2,11):
            numBase2 = j
            numBaseB = 0
            power = 0
            numOnes = 0
            while numBase2 > 0:
                numOnes += numBase2 % 2
                numBaseB += ( numBase2 % 2 ) * (b**power)
                numBase2 = numBase2 >> 1
                power += 1
            hasDivisor = False
            if numOnes % 2 != 0 or numOnes % 3 != 0:
                break
            if b % 2 == 1:
                hasDivisor = True
                divisors += [str(2)]
            else:
                for div in range(3,97,2):
                    if numBaseB % div == 0:
                        hasDivisor = True
                        divisors += [str(div)]
                        break
            if not hasDivisor:
                break
            if b == 10:
                results[0] += str(numBaseB) + " " + " ".join(divisors) + "\n"
                jCount += 1
        if jCount == J:
            break
print results

ju.jout(FILE, results, linebreaks=True)
