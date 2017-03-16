def solve(S):
    count = 0
    l = 0
    while l < len(S):
        if S[l] == '-':
            r = S.find('+')
            if r >= 0:
                S = "+" * r + S[r:]
                count += 1
                l = r
            else:
                return count + 1  # all -
        else:  # S[l] == "+"
            r = S.find('-')
            if r >= 0:
                S = "-" * r + S[r:]
                count += 1
                l = r
            else:
                return count


with open("revenge_of_the_pancakes.in") as fin:
    T = int(fin.readline())
    for t in xrange(T):
        S = fin.readline()
        print "Case #%d: %s" % (t+1, solve(S))
