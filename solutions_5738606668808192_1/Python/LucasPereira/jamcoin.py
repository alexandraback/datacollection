import itertools

def checkPrime(jamcoin):
    ans = []
    for i in xrange(2, 11):
        temp = int(jamcoin, i)
        found = 0
        j = 3
        if temp % 2 == 0:
            found = 2
        while j < int(temp ** .5) + 1 and j < 100000 and not found:
            if temp % j == 0:
                found = j
            j += 2
        if not found:
            return []
        else:
            ans.append(found)
    if len(ans) < 9:
        return []
    return ans



t = int(raw_input())
tempn = raw_input()
n = int(tempn[:2])
j = int(tempn[3:])
print "Case #1:"
answers = []
for jamcoin in itertools.product(['0','1'], repeat = n - 2):
    if len(answers) >= j:
        break
    jamcoinstr = "1" + "".join(jamcoin) + "1"
    divisors = checkPrime(jamcoinstr)
    if divisors and not jamcoin in answers:
        print "{} {}".format(jamcoinstr, " ".join(str(x) for x in divisors))
        answers.append(jamcoin)
    
