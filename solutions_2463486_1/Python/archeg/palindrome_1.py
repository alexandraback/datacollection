__author__ = 'archeg'

glob = []

def isPalindrome(s):
    for i in range(len(s) / 2):
        if s[i] != s[len(s) - i - 1]:
            return False
    return True

def makePalindrome(a, ignoreLastSymb):
    # ignoreLastSymb = true: 123 -> 12321
    # ignoreLastSymb = false: 123 -> 123321
    sa = str(a)
    if not ignoreLastSymb:
        return sa + sa[::-1]
    else:
        return sa + sa[-2::-1]


def solve(a, b):
    import math
    print "---- Solving for %i and %i -----" % (a,b)
    la, lb = int(math.sqrt(a)), int(math.sqrt(b))
    #find all the palindromes between la and lb
    sla = str(la)
    c = sla[:int(len(sla) / 2)] #First part of palindrome
    if len(sla) % 2 != 0:
        midc = sla[len(sla) / 2]
    else:
        midc = ''

    c = int(c + midc)
    c = 0
    count = 0
    while True:
        d = makePalindrome(c, False)
        d2 = makePalindrome(c, True)

        id = int(d)
        id2 = int(d2)
        qid = id * id
        qid2 = id2 * id2
        if (isPalindrome(str(qid)) and a <= qid <= b):
            glob.append(qid)
            #print qid
            count += 1
        if (isPalindrome(str(qid2)) and a <= qid2 <= b):
            glob.append(qid2)
            #print qid2
            count += 1
        if qid > b and qid2 > b:
            break

        c += 1

    return count

def run():
    fi = open('palindrome.in', 'r')
    input = fi.readlines()
    t = int(input[0])
    problems = []
    for i in range(t):
        problems.append([int(x) for x in input[i + 1].split()])

    output = []
    TestCaseN = 1
    for p in problems:
        a,b = p
        c = len([x for x in glob if a <= x <= b])
        output.append("Case #%i: %i\n" %(TestCaseN, c))
        TestCaseN += 1

    with open('palindrome.out', 'w') as fo:
        fo.writelines(output)
    fo.close()

#print solve(9, 121)
print solve(1, 10**15)
run()

# print len(glob)
# with open('palindrome.data', 'w') as foo:
#     foo.writelines([str(x) + ", \n" for x in glob])
# foo.close()
print "DONE!"
