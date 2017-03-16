def sign(a, b):
    if a == "1" or b == "1":
        return False

    if a == b:
        return True

    if a == "i" and b == "k" or a =="j" and b == "i" or a == "k" and b=="j":
        return True

    return False

def multiply(a, b):
    if a == "1":
        return b
    if b == "1":
        return a

    if a == b:
        return "1"

    if a == "1":
        if b == "j":
            return "k"
        if b == "k":
            return "j"
    elif a == "j":
        if b == "i":
            return "k"
        if b == "k":
            return "i"
    elif a == "k":
        if b == "i":
            return "k"
        if b == "j":
            return "i"

    return "0"
            
def check(s, ans, negative, found_i, found_j):
    for c in s:
        print "c=%s" % (c)
        negative = negative ^ sign(ans, c)
        ans = multiply(ans, c)

        if ans == "i" and not negative:
            found_i = True

        if found_i and ans == "k" and not negative:
            found_j = True

        return [ans, negative, found_i, found_j]


def solve(X, s):
    found = False
    ans = "1"
    negative = False
    found_i = False
    found_j = False
    for i in xrange(X):
        [ans, negative, found_i, found_j]  = check(s, ans, negative, found_i, found_j)

    print ans, negative, found_i, found_j

    if negative and ans == "1" and found_i and found_j:
        return "YES"
    else:
        return "NO"
        

T = int(raw_input())
for t in xrange(T):
    [L, X] = map(int, raw_input().split())
    s = list(raw_input())
    print "Case #%i: %s" % (t+1, solve(X, s))
